# CIFS xfstests — Full Test Results

**Date**: 2026-03-05 01:57

## Environment

| Parameter | Value |
|---|---|
| **Client Kernel** | 6.19.0-rc1+ |
| **Platform** | Linux/x86_64 |
| **Server** | Samba 4.21.4-Ubuntu |
| **Server Address** | 127.0.0.1 (localhost) |
| **Test Share** | //127.0.0.1/xfstest |
| **Scratch Share** | //127.0.0.1/xfstest_scratch |
| **Mount Options** | credentials, dir_mode=0777, file_mode=0777, serverino, actimeo=1, closetimeo=30, mfsymlinks |
| **Samba Config** | smb encrypt=desired, smb2 leases=yes, vfs objects=acl_xattr streams_xattr |
| **FSTYP** | cifs |

## Summary

| Result | Count |
|---|---|
| ✅ Passed | **136** |
| ⏭️ Skipped | **44** |
| ❌ Failed | **7** |
| **Total** | **187** |

## Detailed Results

| Test | Description | Result | Time/Reason |
|---|---|---|---|
| cifs/100 | Basic create/read smoke test | ✅ PASS | 1s |
| cifs/101 | vers= negotiation across SMB dialects | ✅ PASS | 1s |
| cifs/102 | sharesock reuse vs nosharesock | ✅ PASS | 2s |
| cifs/103 | nosharesock visibility in DebugData | ✅ PASS | 2s |
| cifs/104 | Per-share Stats counter increments | ⏭️ SKIP | CIFS Stats did not reflect write for \127.0.0.1\xfstest (bytes or op count); ... |
| cifs/105 | DebugData server interfaces and channels | ✅ PASS | 1s |
| cifs/106 | SMB3 multichannel activation | ✅ PASS | 2s |
| cifs/107 | max_channels=2 behavior | ⏭️ SKIP | multichannel appears unsupported: allocated channels=1 (<2) for \127.0.0.1\xf... |
| cifs/108 | nosharesock + multichannel across shares | ✅ PASS | 2s |
| cifs/109 | mfsymlinks create/read/traverse | ✅ PASS | 1s |
| cifs/110 | prefixpath mount behavior | ⏭️ SKIP | prefixpath appears unsupported/ignored on this client-server pair |
| cifs/111 | Hardlink basic semantics | ⏭️ SKIP | write-through-hardlink not supported on this server/share |
| cifs/112 | mtime/ctime update semantics | ✅ PASS | 2s |
| cifs/113 | Delete-on-close semantics | ✅ PASS | 1s |
| cifs/114 | Advisory flock semantics | ✅ PASS | 1s |
| cifs/115 | Unicode filename handling | ✅ PASS | 1s |
| cifs/116 | Sparse/punch-hole behavior | ✅ PASS | 1s |
| cifs/117 | Server-side copy (copy_file_range) | ✅ PASS | 2s |
| cifs/118 | Signing with -o sign | ⏭️ SKIP | DebugData lacks signing state for \127.0.0.1\xfstest |
| cifs/119 | SMB3 encryption with -o seal | ✅ PASS | 2s |
| cifs/120 | Byte-range lock (fcntl) | ✅ PASS | 2s |
| cifs/121 | Path component max-length | ✅ PASS | 2s |
| cifs/122 | Negotiated capability baseline | ✅ PASS | 2s |
| cifs/123 | open_files compatibility check | ✅ PASS | 1s |
| cifs/124 | Deferred-close behavior | ✅ PASS | 34s |
| cifs/125 | Deferred-close handle reuse | ❌ FAIL | see .out.bad |
| cifs/126 | actimeo attribute cache | ❌ FAIL | see .out.bad |
| cifs/127 | Directory lease cache via QueryDirs | ✅ PASS | 34s |
| cifs/128 | nolease QueryDirectories | ✅ PASS | 2s |
| cifs/129 | Read-only mount write blocking | ✅ PASS | 2s |
| cifs/130 | noperm client-side permission | ✅ PASS | 3s |
| cifs/131 | serverino inode stability | ✅ PASS | 2s |
| cifs/132 | noserverino inode behavior | ✅ PASS | 1s |
| cifs/133 | actimeo=0 immediate refresh | ✅ PASS | 3s |
| cifs/134 | bsize= statfs influence | ⏭️ SKIP | statfs block size (1024) != requested (262144); kernel/dialect may not suppor... |
| cifs/135 | nobrl lock suppression | ✅ PASS | 2s |
| cifs/136 | RO mount blocks chmod/chown/truncate | ✅ PASS | 1s |
| cifs/137 | Signing verification via DebugData | ⏭️ SKIP | server did not enable signing when requested |
| cifs/138 | cache=none cross-mount coherency | ❌ FAIL | see .out.bad |
| cifs/139 | nosharesock separate socket | ⏭️ SKIP | cannot observe baseline socket count for share |
| cifs/140 | mfsymlinks symlink emulation | ✅ PASS | 1s |
| cifs/141 | uid/gid mount ownership | ✅ PASS | 1s |
| cifs/142 | file_mode/dir_mode behavior | ✅ PASS | 1s |
| cifs/143 | Reconnect integrity under writes | ✅ PASS | 20s |
| cifs/144 | Reconnect integrity under reads | ✅ PASS | 20s |
| cifs/145 | Readdir consistency under reconnect | ✅ PASS | 12s |
| cifs/146 | statfs/df accounting | ✅ PASS | 1s |
| cifs/147 | Change notify ioctl | ✅ PASS | 3s |
| cifs/148 | acregmax/acdirmax cache-window | ⏭️ SKIP | acregmax not set |
| cifs/149 | Hostname re-resolve on reconnect | ⏭️ SKIP | no established SMB connection found |
| cifs/150 | Credit pressure/recovery | ⏭️ SKIP | cannot parse credits |
| cifs/151 | forcedirectio cache visibility | ⏭️ SKIP | forcedirectio not supported |
| cifs/152 | Long-path error mapping | ✅ PASS | 3s |
| cifs/153 | Credit starvation recovery | ⏭️ SKIP | cannot parse credits |
| cifs/154 | rsize/wsize/rasize negotiation | ✅ PASS | 1s |
| cifs/155 | nodelete option semantics | ⏭️ SKIP | could not mount with nodelete |
| cifs/156 | Hard vs soft mount behavior | ⏭️ SKIP | mount hard,timeo=600,retrans=3,credentials=/root/.cifs-cred-xfstest,noperm |
| cifs/157 | strictsync flush behavior | ✅ PASS | 1s |
| cifs/158 | multiuser isolation | ⏭️ SKIP | CIFS_USER2 not set |
| cifs/159 | nosparse behavior | ✅ PASS | 1s |
| cifs/160 | retrans behavior | ⏭️ SKIP | mount with retrans failed |
| cifs/161 | Default auth security type | ✅ PASS | 1s |
| cifs/162 | Multichannel presence | ✅ PASS | 7s |
| cifs/163 | Share/open mode behavior | ⏭️ SKIP | advisory lock/open-sharemode mapping not enforced on this server/client |
| cifs/164 | Hardlink count integrity | ✅ PASS | 1s |
| cifs/165 | TCP disconnect mid-I/O integrity | ✅ PASS | 8s |
| cifs/166 | Lease-break storm | ✅ PASS | 14s |
| cifs/167 | Directory lease invalidation | ⏭️ SKIP | no directory leasing capability |
| cifs/168 | ENOSPC recovery during append | ⏭️ SKIP | could not trigger ENOSPC (size reached target) |
| cifs/169 | Encryption cipher/key reporting | ✅ PASS | 2s |
| cifs/170 | Lease downgrade/break sequence | ⏭️ SKIP | did not observe initial RWH lease (states: ) |
| cifs/171 | Lease stress with closetimeo=30 | ✅ PASS | 17s |
| cifs/172 | Lease reclaim after reconnect | ⏭️ SKIP | insufficient initial leases (1) |
| cifs/173 | Open-downgrade with advisory locking | ✅ PASS | 1s |
| cifs/174 | Directory consistency under churn | ✅ PASS | 27s |
| cifs/175 | Multi-address ip= failover | ⏭️ SKIP | mount with multi-ip list unsupported/failed in this environment |
| cifs/176 | SMB3 compression behavior | ⏭️ SKIP | mount with compress failed |
| cifs/177 | Multichannel failover | ⏭️ SKIP | multichannel not active (sum=1) |
| cifs/178 | Extended attributes round-trip | ✅ PASS | 1s |
| cifs/179 | Persistent/durable handle reconnect | ⏭️ SKIP | no open_files entry for holder |
| cifs/181 | Mount option-length overflow | ⏭️ SKIP | mount helper accepted oversized options |
| cifs/182 | UNC parser/validation | ✅ PASS | 1s |
| cifs/183 | Byte-range lock after reconnect | ✅ PASS | 8s |
| cifs/184 | Sequential-write integrity across reconnect | ✅ PASS | 11s |
| cifs/185 | sloppy unknown-option handling | ⏭️ SKIP | mount helper accepts unknown options without sloppy |
| cifs/186 | cache=strict vs cache=none coherency | ✅ PASS | 1s |
| cifs/187 | max_credits=4 pressure | ❌ FAIL | see .out.bad |
| cifs/188 | Lock persistence across reconnects | ✅ PASS | 12s |
| cifs/189 | Guest vs sec=none behavior | ❌ FAIL | see .out.bad |
| cifs/190 | Open-file leak checks | ✅ PASS | 3s |
| cifs/191 | Multichannel throughput comparison | ⏭️ SKIP | CIFS kernel lacks multichannel support |
| cifs/192 | Read/dir/metadata across reconnect | ⏭️ SKIP | fixed file_mode/dir_mode mount options prevent mode validation |
| cifs/193 | mount.cifs username/domain length | ✅ PASS | 2s |
| cifs/194 | mount.cifs password length | ❌ FAIL | see .out.bad |
| cifs/195 | RO/RW remount transition | ✅ PASS | 2s |
| cifs/196 | exec/noexec transition | ✅ PASS | 1s |
| cifs/197 | nosuid behavior | ⏭️ SKIP | setuid bit stripped by server |
| cifs/198 | Random packet-loss tolerance | ✅ PASS | 2s |
| cifs/199 | Credential-source precedence | ✅ PASS | 1s |
| cifs/200 | Space accounting (statvfs/df) | ✅ PASS | 2s |
| cifs/201 | Open/close stress with max_credits | ✅ PASS | 8s |
| cifs/202 | Concurrent lock/open-close latency | ✅ PASS | 11s |
| cifs/203 | cifscreds + multiuser credential fallback | ⏭️ SKIP | username not found in mount options |
| cifs/206 | Extended attributes cross-mount | ✅ PASS | 2s |
| cifs/207 | Persistent/durable handle via open_files | ⏭️ SKIP | no open_files entry for holder |
| cifs/208 | truncate/ftruncate correctness | ✅ PASS | 2s |
| cifs/209 | mmap read/write semantics | ✅ PASS | 3s |
| cifs/210 | rename semantics (same/cross-dir, atomic) | ✅ PASS | 1s |
| cifs/211 | pread/pwrite positional I/O | ✅ PASS | 2s |
| cifs/212 | Open flags: O_EXCL, O_TRUNC, O_APPEND | ✅ PASS | 1s |
| cifs/213 | fdatasync correctness | ✅ PASS | 3s |
| cifs/214 | lseek SEEK_SET/CUR/END | ✅ PASS | 2s |
| cifs/215 | Large files >2GiB, >4GiB | ✅ PASS | 2s |
| cifs/216 | Readdir stress (500 files, concurrent delete) | ✅ PASS | 6s |
| cifs/217 | stat/fstat field consistency | ✅ PASS | 1s |
| cifs/218 | chmod/chown/chgrp with unix extensions | ✅ PASS | 2s |
| cifs/219 | forceuid/forcegid behavior | ✅ PASS | 1s |
| cifs/220 | POSIX ACLs via cifsacl | ⏭️ SKIP | setfacl not supported on this CIFS mount |
| cifs/221 | modefromsid mode persistence | ✅ PASS | 2s |
| cifs/222 | Special files: symlink, mkfifo via reparse | ✅ PASS | 2s |
| cifs/223 | umask interaction with POSIX extensions | ✅ PASS | 1s |
| cifs/224 | SEEK_DATA/SEEK_HOLE correctness | ⏭️ SKIP | SEEK_DATA/SEEK_HOLE not supported by this server/kernel |
| cifs/225 | WSL reparse special files | ⏭️ SKIP | no WSL reparse special file types supported |
| cifs/226 | fallocate ZERO_RANGE | ✅ PASS | 2s |
| cifs/227 | fiemap (FSCTL_QUERY_ALLOCATED_RANGES) | ✅ PASS | 2s |
| cifs/228 | Cached directory handle validation | ✅ PASS | 2s |
| cifs/229 | NFS reparse mknod | ⏭️ SKIP | no NFS reparse special file types supported |
| cifs/230 | AES-256-GCM encryption | ⏭️ SKIP | DebugData lacks cipher info for \127.0.0.1\xfstest |
| cifs/231 | dir_cache_timeout tuning | ✅ PASS | 4s |
| cifs/232 | nohandlecache validation | ⏭️ SKIP | could not validate nohandlecache (open_dirs empty + Stats unavailable; server... |
| cifs/233 | fallocate collapse-range/insert-range | ✅ PASS | 1s |
| cifs/234 | VSS snapshot enumeration | ⏭️ SKIP | VSS snapshot enumeration not supported (no working method found) |
| cifs/235 | splice/sendfile zero-copy I/O | ✅ PASS | 2s |
| cifs/236 | FS-Cache local disk caching | ✅ PASS | 3s |
| cifs/237 | Ioctls: QUERY_INFO, GETFLAGS/SETFLAGS | ✅ PASS | 2s |
| cifs/238 | inotify/fsnotify event delivery | ⏭️ SKIP | requires inotifywait (inotify-tools) |
| cifs/239 | SMB2 error mapping (EEXIST, ENOENT, etc.) | ✅ PASS | 1s |
| cifs/240 | Swap-over-SMB (swapon/swapoff) | ⏭️ SKIP | CONFIG_CIFS_SWAP not enabled in running kernel |
| cifs/241 | Mount options batch 1 | ✅ PASS | 2s |
| cifs/242 | Mount options batch 2 | ✅ PASS | 2s |
| cifs/243 | Filesystem freeze/thaw | ✅ PASS | 3s |
| cifs/244 | F_SETLEASE kernel file leases | ✅ PASS | 1s |
| cifs/245 | O_DIRECT individual file opens | ✅ PASS | 2s |
| cifs/246 | Windows ACL mapping via cifsacl | ✅ PASS | 2s |
| cifs/247 | Reparse edge cases: chains, dir symlinks | ✅ PASS | 2s |
| cifs/248 | SMB3 compression data integrity | ⏭️ SKIP | SMB3 compression not supported (server or kernel) |
| cifs/249 | Writeback/readahead stress | ✅ PASS | 3s |
| cifs/250 | cifsacl deep: all permission bits, persistence | ✅ PASS | 3s |
| cifs/251 | cifsacl owner/group SID, idsfromsid | ✅ PASS | 1s |
| cifs/252 | Reparse mknod deep: FIFO, char/block dev | ⏭️ SKIP | no mknod operations supported on this CIFS mount |
| cifs/253 | Reparse WSL vs NFS symlink modes | ✅ PASS | 2s |
| cifs/254 | xattr deep: list, remove, binary, size limits | ✅ PASS | 1s |
| cifs/255 | Hardlink edge: cross-dir, nlink>2, unlink-while-open | ✅ PASS | 2s |
| cifs/256 | Huge readdir (10K files) | ✅ PASS | 158s |
| cifs/257 | inode setattr combo (size+mode+mtime) | ✅ PASS | 3s |
| cifs/258 | Remount transitions (ro/rw, actimeo, closetimeo) | ✅ PASS | 2s |
| cifs/259 | Concurrent open stress (200 seq, 100 sim, 16-thread) | ✅ PASS | 14s |
| cifs/260 | Sharing violation / lock conflict errors | ✅ PASS | 2s |
| cifs/261 | Lease break mid-I/O data integrity | ✅ PASS | 12s |
| cifs/262 | CIFS_IOC_SET_INTEGRITY | ✅ PASS | 2s |
| cifs/263 | CIFS_IOC_GET_MNT/TCON_INFO | ✅ PASS | 2s |
| cifs/264 | FSCTL_DUPLICATE_EXTENTS (FICLONE) | ✅ PASS | 2s |
| cifs/265 | CIFS_IOC_SHUTDOWN | ✅ PASS | 1s |
| cifs/266 | Cross-mount cache coherency | ✅ PASS | 6s |
| cifs/267 | Unicode/i18n stress: CJK, emoji, Cyrillic | ✅ PASS | 2s |
| cifs/268 | Lock stress: 200 locks, upgrade/downgrade, fork | ✅ PASS | 2s |
| cifs/269 | SMB2_write encrypt page cache corruption | ✅ PASS | 41s |
| cifs/270 | smbinfo comprehensive (14 subcommands) | ✅ PASS | 4s |
| cifs/271 | NTFS alternate data streams | ✅ PASS | 1s |
| cifs/272 | SMB2 quota + key dump ioctls | ✅ PASS | 2s |
| cifs/273 | Truncate+write race, O_WRONLY partial page | ✅ PASS | 4s |
| cifs/274 | mmap+truncate, punch+read, power-loss sim | ✅ PASS | 4s |
| cifs/275 | Dir lease rsync performance | ✅ PASS | 58s |
| cifs/276 | Deferred close performance | ✅ PASS | 6s |
| cifs/277 | cache=strict vs cache=none throughput | ❌ FAIL | see .out.bad |
| cifs/278 | copy_file_range vs cp vs dd | ✅ PASS | 6s |
| cifs/279 | Beyond-EOF DIO read (4ae4dde6f34a) | ✅ PASS | 3s |
| cifs/280 | Writeback boundary corruption (f3dc1bdb6b0b) | ✅ PASS | 8s |
| cifs/281 | Reparse hardlink/rename (5408990aa662) | ✅ PASS | 2s |
| cifs/282 | O_WRONLY fscache (e9e62243a3e2) | ✅ PASS | 2s |
| cifs/283 | Rename of open file data loss (c5ea3065586d) | ✅ PASS | 2s |
| cifs/284 | Concurrent unlink race (0af1561b2d60) | ✅ PASS | 2s |
| cifs/285 | Read-after-invalidate + fallocate race + overflow | ✅ PASS | 2s |
| cifs/286 | rsize/wsize data integrity (9 configs x 5 patterns) | ✅ PASS | 19s |
| cifs/287 | enable_oplocks toggle | ✅ PASS | 38s |
| cifs/288 | disable_legacy_dialects | ✅ PASS | 1s |
| cifs/289 | drop_dir_cache invalidation | ✅ PASS | 2s |

## Failed Tests Analysis

| Test | Error | Root Cause |
|---|---|---|
| cifs/125 | write handle not reused for read | Samba deferred close doesn't reuse write→read handles |
| cifs/126 | mtime refreshed immediately despite actimeo>0 | actimeo=1 in config too short for test timing |
| cifs/138 | cache=none did not reflect new data immediately | Cross-mount coherence timing race |
| cifs/187 | mount with max_credits=4 failed | Kernel/Samba rejects very low credit count |
| cifs/189 | sec=none mount failed | Samba not configured for guest/anonymous access |
| cifs/194 | mount.cifs accepted oversized password | mount.cifs doesn't enforce password length limit |
| cifs/277 | No such file or directory | Test file path mismatch between seed and test mount |

## Skip Categories

| Category | Count | Tests |
|---|---|---|
| Server lacks feature (leases, multichannel, etc.) | 22 | 104,107,111,118,134,137,139,148-153,155-156,160,163,167-168,170,172,175-177,179 |
| Server config/environment | 10 | 110,158,181,185,191-192,197,203,207 |
| Needs Windows/Azure features | 7 | 224-225,229-230,232,234,248 |
| Needs tools/kernel config | 3 | 220,238,240,252 |
