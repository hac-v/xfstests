# CIFS xfstests — Test Results

**Generated**: 2026-03-05 03:42

## Summary

| Result | Samba (localhost) | Windows Server |
|---|---|---|
| ✅ Passed | **146** | **143** |
| ⏭️ Skipped | **35** | **32** |
| ❌ Failed | **6** | **12** |
| **Total** | **187** | **187** |

## Environment

| Parameter | Samba | Windows Server |
|---|---|---|
| **Client Kernel** | 6.19.0-rc1+ | 6.19.0-rc1+ |
| **Server** | Samba 4.21.4 (localhost) | Windows Server |
| **Protocol** | SMB3 (auto) | SMB 3.1.1 |
| **Multichannel** | No (single NIC) | Yes (3 channels) |
| **Mount Options** | credentials, dir_mode=0777, file_mode=0777, serverino, actimeo=1, closetimeo=30, mfsymlinks | credentials, vers=3.1.1, dir_mode=0777, file_mode=0777, serverino, actimeo=1, closetimeo=30, mfsymlinks, reparse=nfs |

## Detailed Results

| Test | Description | Samba | Windows |
|---|---|---|---|
| cifs/100 | Basic create/read smoke test | ✅ 1s | ✅ 2s |
| cifs/101 | vers= negotiation | ✅ 1s | ✅ 1s |
| cifs/102 | sharesock reuse vs nosharesock | ✅ 2s | ✅ 3s |
| cifs/103 | nosharesock in DebugData | ✅ 2s | ✅ 2s |
| cifs/104 | Per-share Stats counters | ✅ 2s | ⏭️ skip |
| cifs/105 | DebugData interfaces/channels | ✅ 1s | ✅ 2s |
| cifs/106 | Multichannel activation | ✅ 2s | ✅ 2s |
| cifs/107 | max_channels=2 | ⏭️ skip | ✅ 1s |
| cifs/108 | nosharesock + multichannel | ✅ 2s | ✅ 2s |
| cifs/109 | mfsymlinks | ✅ 1s | ✅ 2s |
| cifs/110 | prefixpath | ⏭️ skip | ⏭️ skip |
| cifs/111 | Hardlink semantics | ⏭️ skip | ⏭️ skip |
| cifs/112 | mtime/ctime | ✅ 2s | ✅ 2s |
| cifs/113 | Delete-on-close | ✅ 1s | ✅ 2s |
| cifs/114 | Advisory flock | ✅ 1s | ✅ 1s |
| cifs/115 | Unicode filenames | ✅ 1s | ✅ 2s |
| cifs/116 | Sparse/punch-hole | ✅ 1s | ✅ 1s |
| cifs/117 | copy_file_range | ✅ 2s | ✅ 2s |
| cifs/118 | Signing (-o sign) | ⏭️ skip | ⏭️ skip |
| cifs/119 | Encryption (-o seal) | ✅ 2s | ✅ 1s |
| cifs/120 | Byte-range lock | ✅ 2s | ✅ 2s |
| cifs/121 | Path max-length | ✅ 2s | ✅ 2s |
| cifs/122 | Capabilities | ✅ 2s | ✅ 2s |
| cifs/123 | open_files check | ✅ 1s | ✅ 1s |
| cifs/124 | Deferred close | ✅ 34s | ✅ 34s |
| cifs/125 | Deferred close reuse | ❌ fail | ❌ fail |
| cifs/126 | actimeo cache | ✅ 13s | ✅ 12s |
| cifs/127 | Dir lease QueryDirs | ✅ 34s | ❌ fail |
| cifs/128 | nolease QueryDirs | ✅ 2s | ❌ fail |
| cifs/129 | RO mount blocking | ✅ 2s | ✅ 3s |
| cifs/130 | noperm | ✅ 3s | ✅ 2s |
| cifs/131 | serverino | ✅ 2s | ✅ 2s |
| cifs/132 | noserverino | ✅ 1s | ✅ 1s |
| cifs/133 | actimeo=0 | ✅ 3s | ✅ 3s |
| cifs/134 | bsize= statfs | ⏭️ skip | ⏭️ skip |
| cifs/135 | nobrl | ✅ 2s | ✅ 2s |
| cifs/136 | RO chmod/chown | ✅ 1s | ✅ 1s |
| cifs/137 | Signing DebugData | ⏭️ skip | ⏭️ skip |
| cifs/138 | cache=none coherency | ❌ fail | ❌ fail |
| cifs/139 | nosharesock socket | ⏭️ skip | ✅ 1s |
| cifs/140 | mfsymlinks emulation | ✅ 1s | ✅ 2s |
| cifs/141 | uid/gid ownership | ✅ 1s | ✅ 1s |
| cifs/142 | file_mode/dir_mode | ✅ 1s | ✅ 2s |
| cifs/143 | Reconnect writes | ✅ 20s | ✅ 19s |
| cifs/144 | Reconnect reads | ✅ 20s | ✅ 19s |
| cifs/145 | Readdir reconnect | ✅ 12s | ✅ 11s |
| cifs/146 | statfs/df | ✅ 1s | ✅ 2s |
| cifs/147 | Change notify | ✅ 3s | ✅ 2s |
| cifs/148 | acregmax/acdirmax | ✅ 13s | ✅ 13s |
| cifs/149 | DNS re-resolve | ⏭️ skip | ⏭️ skip |
| cifs/150 | Credit pressure | ✅ 52s | ✅ 50s |
| cifs/151 | forcedirectio | ⏭️ skip | ⏭️ skip |
| cifs/152 | Long-path errors | ✅ 3s | ✅ 3s |
| cifs/153 | Credit starvation | ✅ 9s | ✅ 9s |
| cifs/154 | rsize/wsize/rasize | ✅ 1s | ✅ 1s |
| cifs/155 | nodelete | ✅ 1s | ✅ 2s |
| cifs/156 | hard vs soft mount | ⏭️ skip | ⏭️ skip |
| cifs/157 | strictsync | ✅ 1s | ✅ 1s |
| cifs/158 | multiuser | ⏭️ skip | ⏭️ skip |
| cifs/159 | nosparse | ✅ 1s | ✅ 2s |
| cifs/160 | retrans | ✅ 2s | ✅ 1s |
| cifs/161 | Default auth | ✅ 1s | ✅ 2s |
| cifs/162 | Multichannel presence | ✅ 7s | ✅ 7s |
| cifs/163 | Share modes | ⏭️ skip | ⏭️ skip |
| cifs/164 | Hardlink count | ✅ 1s | ✅ 1s |
| cifs/165 | TCP disconnect mid-I/O | ✅ 8s | ❌ fail |
| cifs/166 | Lease-break storm | ✅ 14s | ✅ 16s |
| cifs/167 | Dir lease invalidation | ⏭️ skip | ✅ 2s |
| cifs/168 | ENOSPC recovery | ⏭️ skip | ⏭️ skip |
| cifs/169 | Cipher/key reporting | ✅ 2s | ✅ 2s |
| cifs/170 | Lease downgrade | ⏭️ skip | ⏭️ skip |
| cifs/171 | Lease stress | ✅ 17s | ✅ 16s |
| cifs/172 | Lease reclaim | ⏭️ skip | ⏭️ skip |
| cifs/173 | Open-downgrade locking | ✅ 1s | ✅ 1s |
| cifs/174 | Dir consistency churn | ✅ 27s | ✅ 16s |
| cifs/175 | Multi-IP failover | ⏭️ skip | ⏭️ skip |
| cifs/176 | Compression | ⏭️ skip | ⏭️ skip |
| cifs/177 | Multichannel failover | ⏭️ skip | ⏭️ skip |
| cifs/178 | xattr round-trip | ✅ 1s | ❌ fail |
| cifs/179 | Persistent handle | ⏭️ skip | ⏭️ skip |
| cifs/181 | Mount option overflow | ⏭️ skip | ⏭️ skip |
| cifs/182 | UNC validation | ✅ 1s | ✅ 2s |
| cifs/183 | Lock after reconnect | ✅ 8s | ✅ 8s |
| cifs/184 | Write integrity reconnect | ✅ 11s | ✅ 10s |
| cifs/185 | sloppy options | ⏭️ skip | ⏭️ skip |
| cifs/186 | strict vs none coherency | ✅ 1s | ✅ 2s |
| cifs/187 | max_credits pressure | ✅ 3s | ✅ 8s |
| cifs/188 | Lock persistence | ✅ 12s | ✅ 12s |
| cifs/189 | Guest/sec=none | ❌ fail | ⏭️ skip |
| cifs/190 | Open-file leaks | ✅ 3s | ✅ 3s |
| cifs/191 | Multichannel throughput | ⏭️ skip | ⏭️ skip |
| cifs/192 | Metadata reconnect | ⏭️ skip | ⏭️ skip |
| cifs/193 | Username/domain length | ✅ 2s | ✅ 2s |
| cifs/194 | Password length | ❌ fail | ❌ fail |
| cifs/195 | RO/RW remount | ✅ 2s | ✅ 1s |
| cifs/196 | exec/noexec | ✅ 1s | ✅ 1s |
| cifs/197 | nosuid | ⏭️ skip | ⏭️ skip |
| cifs/198 | Packet-loss tolerance | ✅ 2s | ✅ 19s |
| cifs/199 | Credential precedence | ✅ 1s | ✅ 2s |
| cifs/200 | Space accounting | ✅ 2s | ✅ 2s |
| cifs/201 | max_credits stress | ✅ 8s | ✅ 6s |
| cifs/202 | Lock/open latency | ✅ 11s | ✅ 11s |
| cifs/203 | cifscreds multiuser | ⏭️ skip | ⏭️ skip |
| cifs/206 | xattr cross-mount | ✅ 2s | ❌ fail |
| cifs/207 | Persistent handle open_files | ⏭️ skip | ⏭️ skip |
| cifs/208 | truncate/ftruncate | ✅ 2s | ✅ 2s |
| cifs/209 | mmap read/write | ✅ 3s | ✅ 2s |
| cifs/210 | rename semantics | ✅ 1s | ✅ 1s |
| cifs/211 | pread/pwrite | ✅ 2s | ✅ 2s |
| cifs/212 | O_EXCL/TRUNC/APPEND | ✅ 1s | ✅ 1s |
| cifs/213 | fdatasync | ✅ 3s | ✅ 2s |
| cifs/214 | lseek | ✅ 2s | ✅ 1s |
| cifs/215 | Large files >2G/>4G | ✅ 2s | ✅ 1s |
| cifs/216 | Readdir stress 500 | ✅ 6s | ✅ 7s |
| cifs/217 | stat/fstat consistency | ✅ 1s | ✅ 1s |
| cifs/218 | chmod/chown/chgrp | ✅ 2s | ✅ 2s |
| cifs/219 | forceuid/forcegid | ✅ 1s | ✅ 2s |
| cifs/220 | POSIX ACLs cifsacl | ⏭️ skip | ⏭️ skip |
| cifs/221 | modefromsid | ✅ 2s | ✅ 2s |
| cifs/222 | Symlink/mkfifo reparse | ✅ 2s | ✅ 2s |
| cifs/223 | umask interaction | ✅ 1s | ✅ 1s |
| cifs/224 | SEEK_DATA/SEEK_HOLE | ⏭️ skip | ⏭️ skip |
| cifs/225 | WSL reparse | ⏭️ skip | ✅ 2s |
| cifs/226 | fallocate ZERO_RANGE | ✅ 2s | ✅ 1s |
| cifs/227 | fiemap | ✅ 2s | ✅ 2s |
| cifs/228 | Cached dir handle | ✅ 2s | ✅ 2s |
| cifs/229 | NFS reparse mknod | ⏭️ skip | ✅ 1s |
| cifs/230 | AES-256-GCM | ⏭️ skip | ⏭️ skip |
| cifs/231 | dir_cache_timeout | ✅ 5s | ✅ 4s |
| cifs/232 | nohandlecache | ⏭️ skip | ❌ fail |
| cifs/233 | fallocate collapse/insert | ✅ 1s | ✅ 3s |
| cifs/234 | VSS snapshots | ⏭️ skip | ⏭️ skip |
| cifs/235 | splice/sendfile | ✅ 2s | ✅ 2s |
| cifs/236 | FS-Cache | ✅ 3s | ✅ 4s |
| cifs/237 | Ioctls chattr | ✅ 2s | ✅ 2s |
| cifs/238 | inotify events | ❌ fail | ❌ fail |
| cifs/239 | Error mapping | ✅ 1s | ✅ 2s |
| cifs/240 | Swap-over-SMB | ⏭️ skip | ⏭️ skip |
| cifs/241 | Mount opts batch 1 | ✅ 2s | ✅ 2s |
| cifs/242 | Mount opts batch 2 | ✅ 2s | ✅ 3s |
| cifs/243 | fsfreeze/thaw | ✅ 3s | ✅ 3s |
| cifs/244 | F_SETLEASE | ✅ 1s | ✅ 2s |
| cifs/245 | O_DIRECT | ✅ 2s | ✅ 2s |
| cifs/246 | Windows ACL mapping | ✅ 2s | ✅ 2s |
| cifs/247 | Reparse edge cases | ✅ 2s | ✅ 3s |
| cifs/248 | Compression I/O | ⏭️ skip | ⏭️ skip |
| cifs/249 | Writeback/readahead | ✅ 3s | ✅ 4s |
| cifs/250 | cifsacl deep | ✅ 3s | ✅ 3s |
| cifs/251 | cifsacl SID | ✅ 1s | ✅ 2s |
| cifs/252 | Reparse mknod deep | ⏭️ skip | ✅ 2s |
| cifs/253 | Reparse WSL vs NFS | ✅ 2s | ✅ 2s |
| cifs/254 | xattr deep | ✅ 1s | ❌ fail |
| cifs/255 | Hardlink edge cases | ✅ 2s | ✅ 2s |
| cifs/256 | Huge readdir 10K | ✅ 158s | ✅ 70s |
| cifs/257 | setattr combo | ✅ 3s | ✅ 3s |
| cifs/258 | Remount transitions | ✅ 2s | ✅ 2s |
| cifs/259 | Concurrent open stress | ✅ 14s | ✅ 26s |
| cifs/260 | Sharing violation | ✅ 2s | ✅ 2s |
| cifs/261 | Lease break mid-I/O | ✅ 12s | ✅ 13s |
| cifs/262 | SET_INTEGRITY | ✅ 2s | ✅ 1s |
| cifs/263 | GET_MNT/TCON_INFO | ✅ 2s | ✅ 2s |
| cifs/264 | DUPLICATE_EXTENTS | ✅ 2s | ✅ 2s |
| cifs/265 | SHUTDOWN ioctl | ✅ 1s | ✅ 2s |
| cifs/266 | Cross-mount coherency | ✅ 6s | ✅ 5s |
| cifs/267 | Unicode/i18n stress | ✅ 2s | ✅ 2s |
| cifs/268 | Lock stress 200 | ✅ 2s | ✅ 3s |
| cifs/269 | Encrypt corruption | ✅ 41s | ✅ 42s |
| cifs/270 | smbinfo comprehensive | ✅ 4s | ✅ 4s |
| cifs/271 | NTFS ADS | ✅ 1s | ✅ 2s |
| cifs/272 | Quota + key dump | ✅ 2s | ✅ 1s |
| cifs/273 | Truncate+write race | ✅ 4s | ✅ 4s |
| cifs/274 | mmap+truncate | ✅ 4s | ✅ 3s |
| cifs/275 | Dir lease rsync perf | ✅ 58s | ✅ 97s |
| cifs/276 | Deferred close perf | ✅ 6s | ✅ 7s |
| cifs/277 | Cache mode throughput | ✅ 6s | ✅ 11s |
| cifs/278 | copy_file_range vs cp | ✅ 6s | ✅ 8s |
| cifs/279 | Beyond-EOF DIO | ✅ 3s | ✅ 3s |
| cifs/280 | Writeback boundary | ✅ 8s | ✅ 8s |
| cifs/281 | Reparse hardlink/rename | ✅ 2s | ✅ 1s |
| cifs/282 | O_WRONLY fscache | ✅ 2s | ✅ 2s |
| cifs/283 | Rename open file | ✅ 2s | ✅ 2s |
| cifs/284 | Unlink race | ✅ 2s | ✅ 4s |
| cifs/285 | Read-after-invalidate | ✅ 2s | ✅ 3s |
| cifs/286 | rsize/wsize integrity | ✅ 19s | ✅ 21s |
| cifs/287 | enable_oplocks | ✅ 38s | ✅ 39s |
| cifs/288 | disable_legacy_dialects | ✅ 1s | ✅ 2s |
| cifs/289 | drop_dir_cache | ✅ 2s | ❌ fail |

## Failed Tests Analysis

| Test | Description | Samba | Windows | Notes |
|---|---|---|---|---|
| cifs/125 | Deferred close reuse | ❌ | ❌ | |
| cifs/126 | actimeo cache | ✅ 13s | ✅ | |
| cifs/127 | Dir lease QueryDirs | ✅ | ❌ | |
| cifs/128 | nolease QueryDirs | ✅ | ❌ | |
| cifs/138 | cache=none coherency | ❌ | ❌ | |
| cifs/165 | TCP disconnect mid-I/O | ✅ | ❌ | |
| cifs/178 | xattr round-trip | ✅ | ❌ | |
| cifs/187 | max_credits pressure | ✅ 3s | ✅ | |
| cifs/189 | Guest/sec=none | ❌ | ⏭️ | |
| cifs/194 | Password length | ❌ | ❌ | |
| cifs/206 | xattr cross-mount | ✅ | ❌ | |
| cifs/232 | nohandlecache | ⏭️ | ❌ | |
| cifs/238 | inotify events | ❌ fail | ❌ | |
| cifs/254 | xattr deep | ✅ | ❌ | |
| cifs/277 | Cache mode throughput | ✅ 6s | ✅ | |
| cifs/289 | drop_dir_cache | ✅ | ❌ | |
