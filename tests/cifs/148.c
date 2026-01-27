// SPDX-License-Identifier: GPL-2.0
// CIFS: direct SMB change notify ioctl test (CIFS_IOC_NOTIFY_INFO)
//
// Derives from MS-SMB2 2.2.35 change notify; exercises CIFS_IOC_NOTIFY_INFO
// to request notification and dumps returned records after a create.
//
// Flow:
// 1. Open watched directory passed as argv[1].
// 2. Issue CIFS_IOC_NOTIFY_INFO with filter mask (0xFFF) not recursive.
// 3. In a child process create a new file in that directory after small delay.
// 4. Ioctl should return; print returned length and hex dump.
// 5. Simple success criteria: non-zero returned data_len and no error from ioctl.
//
// The xfstest wrapper script will compile and run this helper then evaluate output.
//
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct __attribute__((__packed__)) smb3_notify {
    uint32_t completion_filter;
    uint8_t  watch_tree; // bool in uapi header, use byte for portability
    uint32_t data_len;   // in/out
    uint8_t  data[];
} __attribute__((__packed__));

#ifndef CIFS_IOC_NOTIFY_INFO
#define CIFS_IOC_NOTIFY_INFO 0xc009cf0b
#endif

static void dumpmem(FILE *out, const void *ptr, size_t size)
{
    const size_t BYTES_PER_LINE = 16;
    const unsigned char *p = ptr;
    for (size_t off = 0; off < size; off += BYTES_PER_LINE) {
        size_t n = (size - off) < BYTES_PER_LINE ? (size - off) : BYTES_PER_LINE;
        fprintf(out, "%08zx: ", off);
        for (size_t i = 0; i < n; i++) {
            fprintf(out, "%02x ", p[off + i]);
            if (i == 7) fputc(' ', out);
        }
        if (n < BYTES_PER_LINE) {
            for (size_t i = n; i < BYTES_PER_LINE; i++) {
                fputs("   ", out);
                if (i == 7) fputc(' ', out);
            }
        }
        fputc(' ', out);
        for (size_t i = 0; i < n; i++) {
            unsigned char c = p[off + i];
            fputc((c >= 32 && c < 127) ? c : '.', out);
        }
        fputc('\n', out);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 2;
    }

    const char *dir = argv[1];
    int dfd = open(dir, O_RDONLY | O_DIRECTORY);
    if (dfd < 0) {
        perror("open directory");
        return 3;
    }

    size_t buflen = 512; // buffer for returned notify records
    struct smb3_notify *req = malloc(sizeof(*req) + buflen);
    if (!req) {
        perror("malloc");
        return 4;
    }
    memset(req, 0, sizeof(*req) + buflen);
    req->completion_filter = 0x0FFF; // broad filter
    req->watch_tree = 0;             // no recursion
    req->data_len = buflen;

    pid_t child = fork();
    if (child < 0) {
        perror("fork");
        return 5;
    }
    if (child == 0) {
        // child: wait a bit then create file
        usleep(200000); // 200ms
        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/notify_test_created.txt", dir);
        int f = open(path, O_CREAT|O_WRONLY|O_TRUNC, 0644);
        if (f >= 0) {
            write(f, "x", 1);
            close(f);
        }
        _exit(0);
    }

    int rc = ioctl(dfd, CIFS_IOC_NOTIFY_INFO, req);
    if (rc < 0) {
        printf("IOCTL_ERROR %d\n", errno);
        return 6;
    }

    printf("NOTIFY_OK returned_len=%u\n", req->data_len);
    if (req->data_len > 0 && req->data_len <= buflen)
        dumpmem(stdout, req->data, req->data_len);

    return 0;
}
