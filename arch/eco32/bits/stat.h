/*
 * On eco32 we use the generic stat.h for the userspace
 * As asm-generic/stat.h tells us 32 bit architectures use the stat64
 * interface so we add the padding here that it looks like stat64
 */
struct stat {
	dev_t st_dev;
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	unsigned long long __pad1;
	off_t st_size;
	blksize_t st_blksize;
	int __pad2;
	blkcnt_t st_blocks;
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	unsigned int unsused[2];
};
