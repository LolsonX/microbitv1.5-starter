#include <sys/stat.h>
#include <errno.h>
#include <reent.h>
#include <sys/types.h>

int _close(int file) { (void)file; return -1; }
int _close_r(struct _reent *r, int file) { (void)r; (void)file; return -1; }

int _isatty(int file) { (void)file; return 1; }
int _isatty_r(struct _reent *r, int file) { (void)r; (void)file; return 1; }

_off_t _lseek_r(struct _reent *r, int file, _off_t ptr, int dir) { (void)r; (void)file; (void)ptr; (void)dir; return 0; }

_ssize_t _read_r(struct _reent *r, int file, void *ptr, size_t len) { (void)r; (void)file; (void)ptr; (void)len; return 0; }

_ssize_t _write_r(struct _reent *r, int file, const void *ptr, size_t len) { (void)r; (void)file; (void)ptr; return len; }

int _getpid(void) { return 1; }
int _getpid_r(struct _reent *r) { (void)r; return 1; }

int _kill(int pid, int sig) { (void)pid; (void)sig; return -1; }
int _kill_r(struct _reent *r, int pid, int sig) { (void)r; (void)pid; (void)sig; return -1; }

void _exit(int status) { (void)status; while (1) {} }
