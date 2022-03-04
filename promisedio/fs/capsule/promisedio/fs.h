// Auto-generated

#ifndef CAPSULE_FS_API
#define CAPSULE_FS_API

static int fs_api_a4e5331fd176c59333d6074116f92ebd__LOADED = 0;
static void *fs_api_a4e5331fd176c59333d6074116f92ebd__API[33];

#define FS_API fs_api_a4e5331fd176c59333d6074116f92ebd

#include <promisedio_uv.h>
#include "promisedio/promise.h"

#define FS_STAT_ID 0
#define Fs_Stat(...) \
  ((Promise * (*) (void*, const char *path))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_STAT_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_LSTAT_ID 1
#define Fs_Lstat(...) \
  ((Promise * (*) (void*, const char *path))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_LSTAT_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_FSTAT_ID 2
#define Fs_Fstat(...) \
  ((Promise * (*) (void*, int fd))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_FSTAT_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_SEEK_ID 3
#define Fs_Seek(...) \
  ((Promise * (*) (void*, int fd, Py_off_t pos, int how))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_SEEK_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_OPEN_ID 4
#define Fs_Open(...) \
  ((Promise * (*) (void*, const char *path, int flags, int mode))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_OPEN_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_READ_ID 5
#define Fs_Read(...) \
  ((Promise * (*) (void*, int fd, Py_ssize_t size, Py_off_t offset))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_READ_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_READALL_ID 6
#define Fs_Readall(...) \
  ((Promise * (*) (void*, int fd))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_READALL_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_WRITE_ID 7
#define Fs_Write(...) \
  ((Promise * (*) (void*, int fd, PyObject *data, Py_off_t offset))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_WRITE_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_CLOSE_ID 8
#define Fs_Close(...) \
  ((Promise * (*) (void*, int fd))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_CLOSE_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_UNLINK_ID 9
#define Fs_Unlink(...) \
  ((Promise * (*) (void*, const char *path))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_UNLINK_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_MKDIR_ID 10
#define Fs_Mkdir(...) \
  ((Promise * (*) (void*, const char *path, int mode))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_MKDIR_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_RMDIR_ID 11
#define Fs_Rmdir(...) \
  ((Promise * (*) (void*, const char *path))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_RMDIR_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_MKDTEMP_ID 12
#define Fs_Mkdtemp(...) \
  ((Promise * (*) (void*, const char *tpl))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_MKDTEMP_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_MKSTEMP_ID 13
#define Fs_Mkstemp(...) \
  ((Promise * (*) (void*, const char *tpl))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_MKSTEMP_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_SCANDIR_ID 14
#define Fs_Scandir(...) \
  ((Promise * (*) (void*, const char *path))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_SCANDIR_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_RENAME_ID 15
#define Fs_Rename(...) \
  ((Promise * (*) (void*, const char *path, const char *new_path))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_RENAME_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_FSYNC_ID 16
#define Fs_Fsync(...) \
  ((Promise * (*) (void*, int fd))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_FSYNC_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_FTRUNCATE_ID 17
#define Fs_Ftruncate(...) \
  ((Promise * (*) (void*, int fd, Py_ssize_t length))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_FTRUNCATE_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_FDATASYNC_ID 18
#define Fs_Fdatasync(...) \
  ((Promise * (*) (void*, int fd))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_FDATASYNC_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_COPYFILE_ID 19
#define Fs_Copyfile(...) \
  ((Promise * (*) (void*, const char *path, const char *new_path, int flags))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_COPYFILE_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_SENDFILE_ID 20
#define Fs_Sendfile(...) \
  ((Promise * (*) (void*, int out_fd, int in_fd, Py_off_t in_offset, size_t length))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_SENDFILE_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_ACCESS_ID 21
#define Fs_Access(...) \
  ((Promise * (*) (void*, const char *path, int mode))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_ACCESS_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_CHMOD_ID 22
#define Fs_Chmod(...) \
  ((Promise * (*) (void*, const char *path, int mode))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_CHMOD_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_FCHMOD_ID 23
#define Fs_Fchmod(...) \
  ((Promise * (*) (void*, int fd, int mode))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_FCHMOD_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_UTIME_ID 24
#define Fs_Utime(...) \
  ((Promise * (*) (void*, const char *path, double atime, double mtime))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_UTIME_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_LUTIME_ID 25
#define Fs_Lutime(...) \
  ((Promise * (*) (void*, const char *path, double atime, double mtime))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_LUTIME_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_FUTIME_ID 26
#define Fs_Futime(...) \
  ((Promise * (*) (void*, int fd, double atime, double mtime))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_FUTIME_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_LINK_ID 27
#define Fs_Link(...) \
  ((Promise * (*) (void*, const char *path, const char *new_path))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_LINK_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_SYMLINK_ID 28
#define Fs_Symlink(...) \
  ((Promise * (*) (void*, const char *path, const char *new_path, int flags))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_SYMLINK_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_READLINK_ID 29
#define Fs_Readlink(...) \
  ((Promise * (*) (void*, const char *path))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_READLINK_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_CHOWN_ID 30
#define Fs_Chown(...) \
  ((Promise * (*) (void*, const char *path, uv_uid_t uid, uv_gid_t gid))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_CHOWN_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_LCHOWN_ID 31
#define Fs_Lchown(...) \
  ((Promise * (*) (void*, const char *path, uv_uid_t uid, uv_gid_t gid))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_LCHOWN_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#define FS_FCHOWN_ID 32
#define Fs_Fchown(...) \
  ((Promise * (*) (void*, int fd, uv_uid_t uid, uv_gid_t gid))(fs_api_a4e5331fd176c59333d6074116f92ebd__API[FS_FCHOWN_ID]))( \
    _ctx->fs_api_a4e5331fd176c59333d6074116f92ebd__CTX, __VA_ARGS__)

#endif
