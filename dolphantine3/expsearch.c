
typedef unsigned int size_t;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;
__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
__extension__ typedef __u_quad_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __u_quad_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __quad_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __u_quad_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;
__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;
__extension__ typedef int __clockid_t;
__extension__ typedef void * __timer_t;
__extension__ typedef long int __blksize_t;
__extension__ typedef long int __blkcnt_t;
__extension__ typedef __quad_t __blkcnt64_t;
__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __u_quad_t __fsblkcnt64_t;
__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __u_quad_t __fsfilcnt64_t;
__extension__ typedef int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
__extension__ typedef int __intptr_t;
__extension__ typedef unsigned int __socklen_t;
struct _IO_FILE;

typedef struct _IO_FILE FILE;









typedef struct _IO_FILE __FILE;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t; struct _IO_FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};
enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
struct _IO_FILE {
  int _flags;
  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     size_t __n);
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn (void *__cookie);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));

typedef _G_fpos_t fpos_t;

extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int remove (__const char *__filename) __attribute__ ((__nothrow__));
extern int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));

extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) __attribute__ ((__nothrow__));

extern FILE *tmpfile (void) ;







extern char *tmpnam (char *__s) __attribute__ ((__nothrow__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__)) ;
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;

extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);

extern int fflush_unlocked (FILE *__stream);

extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes) ;
extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream) ;

extern FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__)) ;
extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  __attribute__ ((__nothrow__)) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__)) ;

extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__));

extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));

extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);
extern int printf (__const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));


extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

extern int vdprintf (int __fd, __const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));

extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;
extern int scanf (__const char *__restrict __format, ...) ;
extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int fscanf (FILE *__restrict __stream, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern int scanf (__const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern int sscanf (__const char *__restrict __s, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__));


extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf")
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));


extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);

extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);

extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);

extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);

extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
extern char *gets (char *__s) ;

extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;

extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);
extern int puts (__const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);

extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);

extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;

extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, __const fpos_t *__pos);


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern void perror (__const char *__s);

extern int sys_nerr;
extern __const char *__const sys_errlist[];
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern FILE *popen (__const char *__command, __const char *__modes) ;
extern int pclose (FILE *__stream);
extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));

typedef int wchar_t;


typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;


__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;

extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__)) ;

extern double atof (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;


__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;


extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;


extern float strtof (__const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern long double strtold (__const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;


extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern char *l64a (long int __n) __attribute__ ((__nothrow__)) ;
extern long int a64l (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;

typedef __time_t time_t;


typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));
typedef int register_t __attribute__ ((__mode__ (__word__)));
typedef int __sig_atomic_t;
typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
typedef __sigset_t sigset_t;
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);

__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__));
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[36];
  long int __align;
} pthread_attr_t;
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;
    int __kind;
    unsigned int __nusers;
    __extension__ union
    {
      int __spins;
      __pthread_slist_t __list;
    };
  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
typedef union
{
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;
  char __size[32];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[20];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;

extern long int random (void) __attribute__ ((__nothrow__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern int rand (void) __attribute__ ((__nothrow__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__));

extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__));
extern double drand48 (void) __attribute__ ((__nothrow__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *malloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;


extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__warn_unused_result__));
extern void free (void *__ptr) __attribute__ ((__nothrow__));

extern void cfree (void *__ptr) __attribute__ ((__nothrow__));

extern void *alloca (size_t __size) __attribute__ ((__nothrow__));

extern void *valloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern void abort (void) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

extern void exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));


extern void _Exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));


extern char *getenv (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern char *__secure_getenv (__const char *__name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (__const char *__name, __const char *__value, int __replace)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (__const char *__name) __attribute__ ((__nothrow__));
extern int clearenv (void) __attribute__ ((__nothrow__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern int system (__const char *__command) ;





extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__)) ;






typedef int (*__compar_fn_t) (__const void *, __const void *);

extern void *bsearch (__const void *__key, __const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int mblen (__const char *__s, size_t __n) __attribute__ ((__nothrow__)) ;
extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__)) ;
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__)) ;
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__));
extern size_t wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__));

extern int rpmatch (__const char *__response) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int posix_openpt (int __oflag) ;
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

typedef unsigned long int mp_limb_t;
typedef long int mp_limb_signed_t;
typedef struct
{
  int _mp_alloc;
  int _mp_size;
  mp_limb_t *_mp_d;
} __mpz_struct;
typedef __mpz_struct MP_INT;
typedef __mpz_struct mpz_t[1];
typedef mp_limb_t * mp_ptr;
typedef const mp_limb_t * mp_srcptr;
typedef long int mp_size_t;
typedef long int mp_exp_t;
typedef struct
{
  __mpz_struct _mp_num;
  __mpz_struct _mp_den;
} __mpq_struct;
typedef __mpq_struct MP_RAT;
typedef __mpq_struct mpq_t[1];
typedef struct
{
  int _mp_prec;
  int _mp_size;
  mp_exp_t _mp_exp;
  mp_limb_t *_mp_d;
} __mpf_struct;
typedef __mpf_struct mpf_t[1];
typedef enum
{
  GMP_RAND_ALG_DEFAULT = 0,
  GMP_RAND_ALG_LC = GMP_RAND_ALG_DEFAULT
} gmp_randalg_t;
typedef struct
{
  mpz_t _mp_seed;
  gmp_randalg_t _mp_alg;
  union {
    void *_mp_lc;
  } _mp_algdata;
} __gmp_randstate_struct;
typedef __gmp_randstate_struct gmp_randstate_t[1];
typedef const __mpz_struct *mpz_srcptr;
typedef __mpz_struct *mpz_ptr;
typedef const __mpf_struct *mpf_srcptr;
typedef __mpf_struct *mpf_ptr;
typedef const __mpq_struct *mpq_srcptr;
typedef __mpq_struct *mpq_ptr;
 void __gmp_set_memory_functions (void *(*) (size_t), void *(*) (void *, size_t, size_t), void (*) (void *, size_t)) ;
 void __gmp_get_memory_functions (void *(**) (size_t), void *(**) (void *, size_t, size_t), void (**) (void *, size_t)) ;
 extern const int __gmp_bits_per_limb;
 extern int __gmp_errno;
 extern const char * const __gmp_version;
 void __gmp_randinit (gmp_randstate_t, gmp_randalg_t, ...);
 void __gmp_randinit_default (gmp_randstate_t);
 void __gmp_randinit_lc_2exp (gmp_randstate_t, mpz_srcptr, unsigned long int, unsigned long int);
 int __gmp_randinit_lc_2exp_size (gmp_randstate_t, unsigned long);
 void __gmp_randinit_mt (gmp_randstate_t);
 void __gmp_randinit_set (gmp_randstate_t, const __gmp_randstate_struct *);
 void __gmp_randseed (gmp_randstate_t, mpz_srcptr);
 void __gmp_randseed_ui (gmp_randstate_t, unsigned long int);
 void __gmp_randclear (gmp_randstate_t);
 unsigned long __gmp_urandomb_ui (gmp_randstate_t, unsigned long);
 unsigned long __gmp_urandomm_ui (gmp_randstate_t, unsigned long);
 int __gmp_asprintf (char **, const char *, ...);
 int __gmp_fprintf (FILE *, const char *, ...);
 int __gmp_printf (const char *, ...);
 int __gmp_snprintf (char *, size_t, const char *, ...);
 int __gmp_sprintf (char *, const char *, ...);
 int __gmp_fscanf (FILE *, const char *, ...);
 int __gmp_scanf (const char *, ...);
 int __gmp_sscanf (const char *, const char *, ...);
 void *__gmpz_realloc (mpz_ptr, mp_size_t);
 void __gmpz_abs (mpz_ptr, mpz_srcptr);
 void __gmpz_add (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_add_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_addmul (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_addmul_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_and (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_array_init (mpz_ptr, mp_size_t, mp_size_t);
 void __gmpz_bin_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_bin_uiui (mpz_ptr, unsigned long int, unsigned long int);
 void __gmpz_cdiv_q (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_cdiv_q_2exp (mpz_ptr, mpz_srcptr, unsigned long);
 unsigned long int __gmpz_cdiv_q_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_cdiv_qr (mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);
 unsigned long int __gmpz_cdiv_qr_ui (mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_cdiv_r (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_cdiv_r_2exp (mpz_ptr, mpz_srcptr, unsigned long);
 unsigned long int __gmpz_cdiv_r_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_cdiv_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpz_clear (mpz_ptr);
 void __gmpz_clrbit (mpz_ptr, unsigned long int);
 int __gmpz_cmp (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_cmp_d (mpz_srcptr, double) __attribute__ ((__pure__));
 int __gmpz_cmp_si (mpz_srcptr, signed long int) __attribute__ ((__pure__));
 int __gmpz_cmp_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 int __gmpz_cmpabs (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_cmpabs_d (mpz_srcptr, double) __attribute__ ((__pure__));
 int __gmpz_cmpabs_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpz_com (mpz_ptr, mpz_srcptr);
 void __gmpz_combit (mpz_ptr, unsigned long int);
 int __gmpz_congruent_p (mpz_srcptr, mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_congruent_2exp_p (mpz_srcptr, mpz_srcptr, unsigned long) __attribute__ ((__pure__));
 int __gmpz_congruent_ui_p (mpz_srcptr, unsigned long, unsigned long) __attribute__ ((__pure__));
 void __gmpz_divexact (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_divexact_ui (mpz_ptr, mpz_srcptr, unsigned long);
 int __gmpz_divisible_p (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_divisible_ui_p (mpz_srcptr, unsigned long) __attribute__ ((__pure__));
 int __gmpz_divisible_2exp_p (mpz_srcptr, unsigned long) __attribute__ ((__pure__));
 void __gmpz_dump (mpz_srcptr);
 void *__gmpz_export (void *, size_t *, int, size_t, int, size_t, mpz_srcptr);
 void __gmpz_fac_ui (mpz_ptr, unsigned long int);
 void __gmpz_fdiv_q (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_fdiv_q_2exp (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_fdiv_q_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_fdiv_qr (mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);
 unsigned long int __gmpz_fdiv_qr_ui (mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_fdiv_r (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_fdiv_r_2exp (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_fdiv_r_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 unsigned long int __gmpz_fdiv_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));
 void __gmpz_fib_ui (mpz_ptr, unsigned long int);
 void __gmpz_fib2_ui (mpz_ptr, mpz_ptr, unsigned long int);
 int __gmpz_fits_sint_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_slong_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_sshort_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_uint_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_ulong_p (mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_fits_ushort_p (mpz_srcptr) __attribute__ ((__pure__));
 void __gmpz_gcd (mpz_ptr, mpz_srcptr, mpz_srcptr);
 unsigned long int __gmpz_gcd_ui (mpz_ptr, mpz_srcptr, unsigned long int);
 void __gmpz_gcdext (mpz_ptr, mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);
 double __gmpz_get_d (mpz_srcptr) __attribute__ ((__pure__));
 double __gmpz_get_d_2exp (signed long int *, mpz_srcptr);
 long int __gmpz_get_si (mpz_srcptr) __attribute__ ((__pure__));
 char *__gmpz_get_str (char *, int, mpz_srcptr);
 unsigned long int __gmpz_get_ui (mpz_srcptr) __attribute__ ((__pure__));
 mp_limb_t __gmpz_getlimbn (mpz_srcptr, mp_size_t) __attribute__ ((__pure__));
 unsigned long int __gmpz_hamdist (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 void __gmpz_import (mpz_ptr, size_t, int, size_t, int, size_t, const void *);
 void __gmpz_init (mpz_ptr);
 void __gmpz_init2 (mpz_ptr, unsigned long);
 void __gmpz_init_set (mpz_ptr, mpz_srcptr);
 void __gmpz_init_set_d (mpz_ptr, double);
 void __gmpz_init_set_si (mpz_ptr, signed long int);
 int __gmpz_init_set_str (mpz_ptr, const char *, int);
 void __gmpz_init_set_ui (mpz_ptr, unsigned long int);
 size_t __gmpz_inp_raw (mpz_ptr, FILE *);
 size_t __gmpz_inp_str (mpz_ptr, FILE *, int);
 int __gmpz_invert (mpz_ptr, mpz_srcptr, mpz_srcptr);
 void __gmpz_ior (mpz_ptr, mpz_srcptr, mpz_srcptr);
 int __gmpz_jacobi (mpz_srcptr, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_kronecker_si (mpz_srcptr, long) __attribute__ ((__pure__));
 int __gmpz_kronecker_ui (mpz_srcptr, unsigned long) __attribute__ ((__pure__));
 int __gmpz_si_kronecker (long, mpz_srcptr) __attribute__ ((__pure__));
 int __gmpz_ui_kronecker (unsigned long, mpz_srcptr) __attribute__ ((__pure__));
 void __gmpz_lcm (mpz_ptr, mpz_srcptr, mpz_srcptr);

 void __gmpz_lcm_ui (mpz_ptr, mpz_srcptr, unsigned long);




 void __gmpz_lucnum_ui (mpz_ptr, unsigned long int);


 void __gmpz_lucnum2_ui (mpz_ptr, mpz_ptr, unsigned long int);


 int __gmpz_millerrabin (mpz_srcptr, int) __attribute__ ((__pure__));


 void __gmpz_mod (mpz_ptr, mpz_srcptr, mpz_srcptr);




 void __gmpz_mul (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_mul_2exp (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_mul_si (mpz_ptr, mpz_srcptr, long int);


 void __gmpz_mul_ui (mpz_ptr, mpz_srcptr, unsigned long int);



 void __gmpz_neg (mpz_ptr, mpz_srcptr);



 void __gmpz_nextprime (mpz_ptr, mpz_srcptr);



 size_t __gmpz_out_raw (FILE *, mpz_srcptr);




 size_t __gmpz_out_str (FILE *, int, mpz_srcptr);



 int __gmpz_perfect_power_p (mpz_srcptr) __attribute__ ((__pure__));



 int __gmpz_perfect_square_p (mpz_srcptr) __attribute__ ((__pure__));




 unsigned long int __gmpz_popcount (mpz_srcptr) __attribute__ ((__pure__));



 void __gmpz_pow_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_powm (mpz_ptr, mpz_srcptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_powm_ui (mpz_ptr, mpz_srcptr, unsigned long int, mpz_srcptr);


 int __gmpz_probab_prime_p (mpz_srcptr, int) __attribute__ ((__pure__));


 void __gmpz_random (mpz_ptr, mp_size_t);


 void __gmpz_random2 (mpz_ptr, mp_size_t);


 void __gmpz_realloc2 (mpz_ptr, unsigned long);


 unsigned long int __gmpz_remove (mpz_ptr, mpz_srcptr, mpz_srcptr);


 int __gmpz_root (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_rootrem (mpz_ptr,mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_rrandomb (mpz_ptr, gmp_randstate_t, unsigned long int);


 unsigned long int __gmpz_scan0 (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));


 unsigned long int __gmpz_scan1 (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));


 void __gmpz_set (mpz_ptr, mpz_srcptr);


 void __gmpz_set_d (mpz_ptr, double);


 void __gmpz_set_f (mpz_ptr, mpf_srcptr);



 void __gmpz_set_q (mpz_ptr, mpq_srcptr);



 void __gmpz_set_si (mpz_ptr, signed long int);


 int __gmpz_set_str (mpz_ptr, const char *, int);


 void __gmpz_set_ui (mpz_ptr, unsigned long int);


 void __gmpz_setbit (mpz_ptr, unsigned long int);



 size_t __gmpz_size (mpz_srcptr) __attribute__ ((__pure__));



 size_t __gmpz_sizeinbase (mpz_srcptr, int) __attribute__ ((__pure__));


 void __gmpz_sqrt (mpz_ptr, mpz_srcptr);


 void __gmpz_sqrtrem (mpz_ptr, mpz_ptr, mpz_srcptr);


 void __gmpz_sub (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_sub_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_ui_sub (mpz_ptr, unsigned long int, mpz_srcptr);


 void __gmpz_submul (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_submul_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_swap (mpz_ptr, mpz_ptr) ;


 unsigned long int __gmpz_tdiv_ui (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));


 void __gmpz_tdiv_q (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_tdiv_q_2exp (mpz_ptr, mpz_srcptr, unsigned long int);


 unsigned long int __gmpz_tdiv_q_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_tdiv_qr (mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr);


 unsigned long int __gmpz_tdiv_qr_ui (mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long int);


 void __gmpz_tdiv_r (mpz_ptr, mpz_srcptr, mpz_srcptr);


 void __gmpz_tdiv_r_2exp (mpz_ptr, mpz_srcptr, unsigned long int);


 unsigned long int __gmpz_tdiv_r_ui (mpz_ptr, mpz_srcptr, unsigned long int);


 int __gmpz_tstbit (mpz_srcptr, unsigned long int) __attribute__ ((__pure__));


 void __gmpz_ui_pow_ui (mpz_ptr, unsigned long int, unsigned long int);


 void __gmpz_urandomb (mpz_ptr, gmp_randstate_t, unsigned long int);


 void __gmpz_urandomm (mpz_ptr, gmp_randstate_t, mpz_srcptr);



 void __gmpz_xor (mpz_ptr, mpz_srcptr, mpz_srcptr);






 void __gmpq_abs (mpq_ptr, mpq_srcptr);



 void __gmpq_add (mpq_ptr, mpq_srcptr, mpq_srcptr);


 void __gmpq_canonicalize (mpq_ptr);


 void __gmpq_clear (mpq_ptr);


 int __gmpq_cmp (mpq_srcptr, mpq_srcptr) __attribute__ ((__pure__));


 int __gmpq_cmp_si (mpq_srcptr, long, unsigned long) __attribute__ ((__pure__));


 int __gmpq_cmp_ui (mpq_srcptr, unsigned long int, unsigned long int) __attribute__ ((__pure__));


 void __gmpq_div (mpq_ptr, mpq_srcptr, mpq_srcptr);


 void __gmpq_div_2exp (mpq_ptr, mpq_srcptr, unsigned long);


 int __gmpq_equal (mpq_srcptr, mpq_srcptr) __attribute__ ((__pure__));


 void __gmpq_get_num (mpz_ptr, mpq_srcptr);


 void __gmpq_get_den (mpz_ptr, mpq_srcptr);


 double __gmpq_get_d (mpq_srcptr) __attribute__ ((__pure__));


 char *__gmpq_get_str (char *, int, mpq_srcptr);


 void __gmpq_init (mpq_ptr);



 size_t __gmpq_inp_str (mpq_ptr, FILE *, int);



 void __gmpq_inv (mpq_ptr, mpq_srcptr);


 void __gmpq_mul (mpq_ptr, mpq_srcptr, mpq_srcptr);


 void __gmpq_mul_2exp (mpq_ptr, mpq_srcptr, unsigned long);



 void __gmpq_neg (mpq_ptr, mpq_srcptr);




 size_t __gmpq_out_str (FILE *, int, mpq_srcptr);



 void __gmpq_set (mpq_ptr, mpq_srcptr);


 void __gmpq_set_d (mpq_ptr, double);


 void __gmpq_set_den (mpq_ptr, mpz_srcptr);


 void __gmpq_set_f (mpq_ptr, mpf_srcptr);


 void __gmpq_set_num (mpq_ptr, mpz_srcptr);


 void __gmpq_set_si (mpq_ptr, signed long int, unsigned long int);


 int __gmpq_set_str (mpq_ptr, const char *, int);


 void __gmpq_set_ui (mpq_ptr, unsigned long int, unsigned long int);


 void __gmpq_set_z (mpq_ptr, mpz_srcptr);


 void __gmpq_sub (mpq_ptr, mpq_srcptr, mpq_srcptr);


 void __gmpq_swap (mpq_ptr, mpq_ptr) ;





 void __gmpf_abs (mpf_ptr, mpf_srcptr);


 void __gmpf_add (mpf_ptr, mpf_srcptr, mpf_srcptr);


 void __gmpf_add_ui (mpf_ptr, mpf_srcptr, unsigned long int);

 void __gmpf_ceil (mpf_ptr, mpf_srcptr);


 void __gmpf_clear (mpf_ptr);


 int __gmpf_cmp (mpf_srcptr, mpf_srcptr) __attribute__ ((__pure__));


 int __gmpf_cmp_d (mpf_srcptr, double) __attribute__ ((__pure__));


 int __gmpf_cmp_si (mpf_srcptr, signed long int) __attribute__ ((__pure__));


 int __gmpf_cmp_ui (mpf_srcptr, unsigned long int) __attribute__ ((__pure__));


 void __gmpf_div (mpf_ptr, mpf_srcptr, mpf_srcptr);


 void __gmpf_div_2exp (mpf_ptr, mpf_srcptr, unsigned long int);


 void __gmpf_div_ui (mpf_ptr, mpf_srcptr, unsigned long int);


 void __gmpf_dump (mpf_srcptr);


 int __gmpf_eq (mpf_srcptr, mpf_srcptr, unsigned long int) __attribute__ ((__pure__));


 int __gmpf_fits_sint_p (mpf_srcptr) __attribute__ ((__pure__));


 int __gmpf_fits_slong_p (mpf_srcptr) __attribute__ ((__pure__));


 int __gmpf_fits_sshort_p (mpf_srcptr) __attribute__ ((__pure__));


 int __gmpf_fits_uint_p (mpf_srcptr) __attribute__ ((__pure__));


 int __gmpf_fits_ulong_p (mpf_srcptr) __attribute__ ((__pure__));


 int __gmpf_fits_ushort_p (mpf_srcptr) __attribute__ ((__pure__));


 void __gmpf_floor (mpf_ptr, mpf_srcptr);


 double __gmpf_get_d (mpf_srcptr) __attribute__ ((__pure__));


 double __gmpf_get_d_2exp (signed long int *, mpf_srcptr);


 unsigned long int __gmpf_get_default_prec (void) __attribute__ ((__pure__));


 unsigned long int __gmpf_get_prec (mpf_srcptr) __attribute__ ((__pure__));


 long __gmpf_get_si (mpf_srcptr) __attribute__ ((__pure__));


 char *__gmpf_get_str (char *, mp_exp_t *, int, size_t, mpf_srcptr);


 unsigned long __gmpf_get_ui (mpf_srcptr) __attribute__ ((__pure__));


 void __gmpf_init (mpf_ptr);


 void __gmpf_init2 (mpf_ptr, unsigned long int);


 void __gmpf_init_set (mpf_ptr, mpf_srcptr);


 void __gmpf_init_set_d (mpf_ptr, double);


 void __gmpf_init_set_si (mpf_ptr, signed long int);


 int __gmpf_init_set_str (mpf_ptr, const char *, int);


 void __gmpf_init_set_ui (mpf_ptr, unsigned long int);



 size_t __gmpf_inp_str (mpf_ptr, FILE *, int);



 int __gmpf_integer_p (mpf_srcptr) __attribute__ ((__pure__));


 void __gmpf_mul (mpf_ptr, mpf_srcptr, mpf_srcptr);


 void __gmpf_mul_2exp (mpf_ptr, mpf_srcptr, unsigned long int);


 void __gmpf_mul_ui (mpf_ptr, mpf_srcptr, unsigned long int);


 void __gmpf_neg (mpf_ptr, mpf_srcptr);



 size_t __gmpf_out_str (FILE *, int, size_t, mpf_srcptr);



 void __gmpf_pow_ui (mpf_ptr, mpf_srcptr, unsigned long int);


 void __gmpf_random2 (mpf_ptr, mp_size_t, mp_exp_t);


 void __gmpf_reldiff (mpf_ptr, mpf_srcptr, mpf_srcptr);


 void __gmpf_set (mpf_ptr, mpf_srcptr);


 void __gmpf_set_d (mpf_ptr, double);


 void __gmpf_set_default_prec (unsigned long int) ;


 void __gmpf_set_prec (mpf_ptr, unsigned long int);


 void __gmpf_set_prec_raw (mpf_ptr, unsigned long int) ;


 void __gmpf_set_q (mpf_ptr, mpq_srcptr);


 void __gmpf_set_si (mpf_ptr, signed long int);


 int __gmpf_set_str (mpf_ptr, const char *, int);


 void __gmpf_set_ui (mpf_ptr, unsigned long int);


 void __gmpf_set_z (mpf_ptr, mpz_srcptr);


 size_t __gmpf_size (mpf_srcptr) __attribute__ ((__pure__));


 void __gmpf_sqrt (mpf_ptr, mpf_srcptr);


 void __gmpf_sqrt_ui (mpf_ptr, unsigned long int);


 void __gmpf_sub (mpf_ptr, mpf_srcptr, mpf_srcptr);


 void __gmpf_sub_ui (mpf_ptr, mpf_srcptr, unsigned long int);


 void __gmpf_swap (mpf_ptr, mpf_ptr) ;


 void __gmpf_trunc (mpf_ptr, mpf_srcptr);


 void __gmpf_ui_div (mpf_ptr, unsigned long int, mpf_srcptr);


 void __gmpf_ui_sub (mpf_ptr, unsigned long int, mpf_srcptr);


 void __gmpf_urandomb (mpf_t, gmp_randstate_t, unsigned long int);
 mp_limb_t __gmpn_add (mp_ptr, mp_srcptr, mp_size_t, mp_srcptr,mp_size_t);
 mp_limb_t __gmpn_add_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t) ;
 mp_limb_t __gmpn_add_n (mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_addmul_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);
 mp_limb_t __gmpn_bdivmod (mp_ptr, mp_ptr, mp_size_t, mp_srcptr, mp_size_t, unsigned long int);
 int __gmpn_cmp (mp_srcptr, mp_srcptr, mp_size_t) __attribute__ ((__pure__));
 mp_limb_t __gmpn_divexact_by3c (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);
 mp_limb_t __gmpn_divrem (mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_divrem_1 (mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_limb_t);
 mp_limb_t __gmpn_divrem_2 (mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr);
 mp_size_t __gmpn_gcd (mp_ptr, mp_ptr, mp_size_t, mp_ptr, mp_size_t);
 mp_limb_t __gmpn_gcd_1 (mp_srcptr, mp_size_t, mp_limb_t) __attribute__ ((__pure__));
 mp_limb_t __gmpn_gcdext_1 (mp_limb_signed_t *, mp_limb_signed_t *, mp_limb_t, mp_limb_t);
 mp_size_t __gmpn_gcdext (mp_ptr, mp_ptr, mp_size_t *, mp_ptr, mp_size_t, mp_ptr, mp_size_t);
 size_t __gmpn_get_str (unsigned char *, int, mp_ptr, mp_size_t);
 unsigned long int __gmpn_hamdist (mp_srcptr, mp_srcptr, mp_size_t) __attribute__ ((__pure__));
 mp_limb_t __gmpn_lshift (mp_ptr, mp_srcptr, mp_size_t, unsigned int);
 mp_limb_t __gmpn_mod_1 (mp_srcptr, mp_size_t, mp_limb_t) __attribute__ ((__pure__));
 mp_limb_t __gmpn_mul (mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_mul_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);
 void __gmpn_mul_n (mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);
 void __gmpn_sqr (mp_ptr, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_neg_n (mp_ptr, mp_srcptr, mp_size_t);
 int __gmpn_perfect_square_p (mp_srcptr, mp_size_t) __attribute__ ((__pure__));
 unsigned long int __gmpn_popcount (mp_srcptr, mp_size_t) __attribute__ ((__pure__));
 mp_size_t __gmpn_pow_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t, mp_ptr);
 mp_limb_t __gmpn_preinv_mod_1 (mp_srcptr, mp_size_t, mp_limb_t, mp_limb_t) __attribute__ ((__pure__));
 void __gmpn_random (mp_ptr, mp_size_t);
 void __gmpn_random2 (mp_ptr, mp_size_t);
 mp_limb_t __gmpn_rshift (mp_ptr, mp_srcptr, mp_size_t, unsigned int);
 unsigned long int __gmpn_scan0 (mp_srcptr, unsigned long int) __attribute__ ((__pure__));
 unsigned long int __gmpn_scan1 (mp_srcptr, unsigned long int) __attribute__ ((__pure__));
 mp_size_t __gmpn_set_str (mp_ptr, const unsigned char *, size_t, int);
 mp_size_t __gmpn_sqrtrem (mp_ptr, mp_ptr, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_sub (mp_ptr, mp_srcptr, mp_size_t, mp_srcptr,mp_size_t);
 mp_limb_t __gmpn_sub_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t) ;
 mp_limb_t __gmpn_sub_n (mp_ptr, mp_srcptr, mp_srcptr, mp_size_t);
 mp_limb_t __gmpn_submul_1 (mp_ptr, mp_srcptr, mp_size_t, mp_limb_t);
 void __gmpn_tdiv_qr (mp_ptr, mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t);
extern __inline__ void
__gmpz_abs (mpz_ptr __gmp_w, mpz_srcptr __gmp_u)
{
  if (__gmp_w != __gmp_u)
    __gmpz_set (__gmp_w, __gmp_u);
  __gmp_w->_mp_size = ((__gmp_w->_mp_size) >= 0 ? (__gmp_w->_mp_size) : -(__gmp_w->_mp_size));
}
extern __inline__
int
__gmpz_fits_uint_p (mpz_srcptr __gmp_z)
{
  mp_size_t __gmp_n = __gmp_z->_mp_size; mp_ptr __gmp_p = __gmp_z->_mp_d; return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= (~ (unsigned) 0)));;
}
extern __inline__
int
__gmpz_fits_ulong_p (mpz_srcptr __gmp_z)
{
  mp_size_t __gmp_n = __gmp_z->_mp_size; mp_ptr __gmp_p = __gmp_z->_mp_d; return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= (~ (unsigned long) 0)));;
}
extern __inline__
int
__gmpz_fits_ushort_p (mpz_srcptr __gmp_z)
{
  mp_size_t __gmp_n = __gmp_z->_mp_size; mp_ptr __gmp_p = __gmp_z->_mp_d; return (__gmp_n == 0 || (__gmp_n == 1 && __gmp_p[0] <= ((unsigned short) ~0)));;
}
extern __inline__
unsigned long
__gmpz_get_ui (mpz_srcptr __gmp_z)
{
  mp_ptr __gmp_p = __gmp_z->_mp_d;
  mp_size_t __gmp_n = __gmp_z->_mp_size;
  mp_limb_t __gmp_l = __gmp_p[0];
  return (__gmp_n != 0 ? __gmp_l : 0);
}
extern __inline__
mp_limb_t
__gmpz_getlimbn (mpz_srcptr __gmp_z, mp_size_t __gmp_n)
{
  mp_limb_t __gmp_result = 0;
  if (__builtin_expect ((__gmp_n >= 0 && __gmp_n < ((__gmp_z->_mp_size) >= 0 ? (__gmp_z->_mp_size) : -(__gmp_z->_mp_size))) != 0, 1))
    __gmp_result = __gmp_z->_mp_d[__gmp_n];
  return __gmp_result;
}
extern __inline__ void
__gmpz_neg (mpz_ptr __gmp_w, mpz_srcptr __gmp_u)
{
  if (__gmp_w != __gmp_u)
    __gmpz_set (__gmp_w, __gmp_u);
  __gmp_w->_mp_size = - __gmp_w->_mp_size;
}
extern __inline__
int
__gmpz_perfect_square_p (mpz_srcptr __gmp_a)
{
  mp_size_t __gmp_asize;
  int __gmp_result;
  __gmp_asize = __gmp_a->_mp_size;
  __gmp_result = (__gmp_asize >= 0);
  if (__builtin_expect ((__gmp_asize > 0) != 0, 1))
    __gmp_result = __gmpn_perfect_square_p (__gmp_a->_mp_d, __gmp_asize);
  return __gmp_result;
}
extern __inline__
unsigned long
__gmpz_popcount (mpz_srcptr __gmp_u)
{
  mp_size_t __gmp_usize;
  unsigned long __gmp_result;
  __gmp_usize = __gmp_u->_mp_size;
  __gmp_result = (__gmp_usize < 0 ? (~ (unsigned long) 0) : 0);
  if (__builtin_expect ((__gmp_usize > 0) != 0, 1))
    __gmp_result = __gmpn_popcount (__gmp_u->_mp_d, __gmp_usize);
  return __gmp_result;
}
extern __inline__
void
__gmpz_set_q (mpz_ptr __gmp_w, mpq_srcptr __gmp_u)
{
  __gmpz_tdiv_q (__gmp_w, (&((__gmp_u)->_mp_num)), (&((__gmp_u)->_mp_den)));
}
extern __inline__
size_t
__gmpz_size (mpz_srcptr __gmp_z)
{
  return ((__gmp_z->_mp_size) >= 0 ? (__gmp_z->_mp_size) : -(__gmp_z->_mp_size));
}
extern __inline__ void
__gmpq_abs (mpq_ptr __gmp_w, mpq_srcptr __gmp_u)
{
  if (__gmp_w != __gmp_u)
    __gmpq_set (__gmp_w, __gmp_u);
  __gmp_w->_mp_num._mp_size = ((__gmp_w->_mp_num._mp_size) >= 0 ? (__gmp_w->_mp_num._mp_size) : -(__gmp_w->_mp_num._mp_size));
}
extern __inline__ void
__gmpq_neg (mpq_ptr __gmp_w, mpq_srcptr __gmp_u)
{
  if (__gmp_w != __gmp_u)
    __gmpq_set (__gmp_w, __gmp_u);
  __gmp_w->_mp_num._mp_size = - __gmp_w->_mp_num._mp_size;
}
extern __inline__
mp_limb_t
__gmpn_add (mp_ptr __gmp_wp, mp_srcptr __gmp_xp, mp_size_t __gmp_xsize, mp_srcptr __gmp_yp, mp_size_t __gmp_ysize)
{
  mp_limb_t __gmp_c;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x; __gmp_i = (__gmp_ysize); if (__gmp_i != 0) { if (__gmpn_add_n (__gmp_wp, __gmp_xp, __gmp_yp, __gmp_i)) { do { if (__gmp_i >= (__gmp_xsize)) { (__gmp_c) = 1; goto __gmp_done; } __gmp_x = (__gmp_xp)[__gmp_i]; } while ((((__gmp_wp)[__gmp_i++] = (__gmp_x + 1) & ((~ ((mp_limb_t) (0))) >> 0)) == 0)); } } if ((__gmp_wp) != (__gmp_xp)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_xsize); __gmp_j++) (__gmp_wp)[__gmp_j] = (__gmp_xp)[__gmp_j]; } while (0); (__gmp_c) = 0; __gmp_done: ; } while (0);
  return __gmp_c;
}
extern __inline__
mp_limb_t
__gmpn_add_1 (mp_ptr __gmp_dst, mp_srcptr __gmp_src, mp_size_t __gmp_size, mp_limb_t __gmp_n)
{
  mp_limb_t __gmp_c;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x, __gmp_r; __gmp_x = (__gmp_src)[0]; __gmp_r = __gmp_x + (__gmp_n); (__gmp_dst)[0] = __gmp_r; if (((__gmp_r) < ((__gmp_n)))) { (__gmp_c) = 1; for (__gmp_i = 1; __gmp_i < (__gmp_size);) { __gmp_x = (__gmp_src)[__gmp_i]; __gmp_r = __gmp_x + 1; (__gmp_dst)[__gmp_i] = __gmp_r; ++__gmp_i; if (!((__gmp_r) < (1))) { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; break; } } } else { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (1); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; } } while (0);
  return __gmp_c;
}
extern __inline__
int
__gmpn_cmp (mp_srcptr __gmp_xp, mp_srcptr __gmp_yp, mp_size_t __gmp_size)
{
  int __gmp_result;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x, __gmp_y; (__gmp_result) = 0; __gmp_i = (__gmp_size); while (--__gmp_i >= 0) { __gmp_x = (__gmp_xp)[__gmp_i]; __gmp_y = (__gmp_yp)[__gmp_i]; if (__gmp_x != __gmp_y) { (__gmp_result) = (__gmp_x > __gmp_y ? 1 : -1); break; } } } while (0);
  return __gmp_result;
}
extern __inline__
mp_limb_t
__gmpn_sub (mp_ptr __gmp_wp, mp_srcptr __gmp_xp, mp_size_t __gmp_xsize, mp_srcptr __gmp_yp, mp_size_t __gmp_ysize)
{
  mp_limb_t __gmp_c;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x; __gmp_i = (__gmp_ysize); if (__gmp_i != 0) { if (__gmpn_sub_n (__gmp_wp, __gmp_xp, __gmp_yp, __gmp_i)) { do { if (__gmp_i >= (__gmp_xsize)) { (__gmp_c) = 1; goto __gmp_done; } __gmp_x = (__gmp_xp)[__gmp_i]; } while ((((__gmp_wp)[__gmp_i++] = (__gmp_x - 1) & ((~ ((mp_limb_t) (0))) >> 0)), __gmp_x == 0)); } } if ((__gmp_wp) != (__gmp_xp)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_xsize); __gmp_j++) (__gmp_wp)[__gmp_j] = (__gmp_xp)[__gmp_j]; } while (0); (__gmp_c) = 0; __gmp_done: ; } while (0);
  return __gmp_c;
}
extern __inline__
mp_limb_t
__gmpn_sub_1 (mp_ptr __gmp_dst, mp_srcptr __gmp_src, mp_size_t __gmp_size, mp_limb_t __gmp_n)
{
  mp_limb_t __gmp_c;
  do { mp_size_t __gmp_i; mp_limb_t __gmp_x, __gmp_r; __gmp_x = (__gmp_src)[0]; __gmp_r = __gmp_x - (__gmp_n); (__gmp_dst)[0] = __gmp_r; if (((__gmp_x) < ((__gmp_n)))) { (__gmp_c) = 1; for (__gmp_i = 1; __gmp_i < (__gmp_size);) { __gmp_x = (__gmp_src)[__gmp_i]; __gmp_r = __gmp_x - 1; (__gmp_dst)[__gmp_i] = __gmp_r; ++__gmp_i; if (!((__gmp_x) < (1))) { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (__gmp_i); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; break; } } } else { if ((__gmp_src) != (__gmp_dst)) do { mp_size_t __gmp_j; ; for (__gmp_j = (1); __gmp_j < (__gmp_size); __gmp_j++) (__gmp_dst)[__gmp_j] = (__gmp_src)[__gmp_j]; } while (0); (__gmp_c) = 0; } } while (0);
  return __gmp_c;
}
extern __inline__
mp_limb_t
__gmpn_neg_n (mp_ptr __gmp_rp, mp_srcptr __gmp_up, mp_size_t __gmp_n)
{
  mp_limb_t __gmp_ul, __gmp_cy;
  __gmp_cy = 0;
  do {
      __gmp_ul = *__gmp_up++;
      *__gmp_rp++ = -__gmp_ul - __gmp_cy;
      __gmp_cy |= __gmp_ul != 0;
  } while (--__gmp_n != 0);
  return __gmp_cy;
}
enum
{
  GMP_ERROR_NONE = 0,
  GMP_ERROR_UNSUPPORTED_ARGUMENT = 1,
  GMP_ERROR_DIVISION_BY_ZERO = 2,
  GMP_ERROR_SQRT_OF_NEGATIVE = 4,
  GMP_ERROR_INVALID_ARGUMENT = 8
};


extern void *memcpy (void *__restrict __dest,
       __const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, __const void *__src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (__const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

typedef struct __locale_struct
{
  struct locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
} *__locale_t;
typedef __locale_t locale_t;
extern int strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
extern char *strdup (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (__const char *__string, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));

extern char *strchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern size_t strcspn (__const char *__s, __const char *__reject)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

extern char *__strtok_r (char *__restrict __s,
    __const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));

extern size_t strlen (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

extern size_t strnlen (__const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

extern char *strerror (int __errnum) __attribute__ ((__nothrow__));

extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__));
extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void bcopy (__const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *index (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsep (char **__restrict __stringp,
       __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__));
extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

typedef int ptrdiff_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
__extension__
typedef unsigned long long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
__extension__
typedef long long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
__extension__
typedef unsigned long long int uint_least64_t;
typedef signed char int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
__extension__
typedef long long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
__extension__
typedef unsigned long long int uint_fast64_t;
typedef int intptr_t;
typedef unsigned int uintptr_t;
__extension__
typedef long long int intmax_t;
__extension__
typedef unsigned long long int uintmax_t;
typedef int __gwchar_t;

typedef struct
  {
    long long int quot;
    long long int rem;
  } imaxdiv_t;
extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern intmax_t strtoimax (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__));
extern uintmax_t strtoumax (__const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__));
extern intmax_t wcstoimax (__const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__));
extern uintmax_t wcstoumax (__const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__));

typedef struct UT_hash_bucket {
   struct UT_hash_handle *hh_head;
   unsigned count;
   unsigned expand_mult;
} UT_hash_bucket;
typedef struct UT_hash_table {
   UT_hash_bucket *buckets;
   unsigned num_buckets, log2_num_buckets;
   unsigned num_items;
   struct UT_hash_handle *tail;
   ptrdiff_t hho;
   unsigned ideal_chain_maxlen;
   unsigned nonideal_items;
   unsigned ineff_expands, noexpand;
   uint32_t signature;
} UT_hash_table;
typedef struct UT_hash_handle {
   struct UT_hash_table *tbl;
   void *prev;
   void *next;
   struct UT_hash_handle *hh_prev;
   struct UT_hash_handle *hh_next;
   void *key;
   unsigned keylen;
   unsigned hashv;
} UT_hash_handle;
typedef struct value_pair
{
    long long int u;
    long long int v;
    struct value_pair *next, *prev;
} value_pair;
value_pair *
new_value_pair () {
    return (value_pair *) malloc (sizeof(value_pair));
}
struct uv_struct {
    char *uv_str;
    value_pair *head;
    UT_hash_handle hh;
};
void print_intemediary(long long int count, long long int u, long long int v, mpz_t mp_sum) {
    printf("%lld value = %lld %lld ", count, u, v);
    __gmpz_out_str (stdout, 10, mp_sum);
    printf("\n");
}
int
perform_lookup_uv(
        int rank, int numproc,
        int coeff_a, int coeff_b, int coeff_c, int coeff_d,
        long long int height, long long int lower,
        long int hash_chunk_size) {
    struct uv_struct *s, *uv_hash_table = ((void *)0);
    struct uv_struct *current_uv, *uv_htmp;
    value_pair *uv_list, *elt, *eltmp;
    unsigned long long int count = 0;
    char * key_char;
    long long int current_u;
    long long int current_v;
    mpz_t key_u_mpz;
    mpz_t key_v_mpz;
    __gmpz_init(key_u_mpz);
    __gmpz_init(key_v_mpz);
    current_u = -height + rank;
    while (current_u <= height) {
        current_v = -height;
        while (current_v <= height) {
            printf("loop: %lld, %lld\n", current_v, height);
            uv_list = (value_pair*)malloc(sizeof(value_pair));
            uv_list->u = current_u;
            uv_list->v = current_v;
            __gmpz_set_si(key_u_mpz, current_u);
            __gmpz_pow_ui(key_u_mpz, key_u_mpz, 3);
            __gmpz_mul_si(key_u_mpz, key_u_mpz, coeff_c);
            __gmpz_set_si(key_v_mpz, current_v);
            __gmpz_pow_ui(key_v_mpz, key_v_mpz, 3);
            __gmpz_mul_si(key_v_mpz, key_v_mpz, coeff_d);
            __gmpz_add(key_u_mpz, key_u_mpz, key_v_mpz);
            print_intemediary(count, current_u, current_v, key_u_mpz);
            printf("mpz_get_str...");
            key_char = __gmpz_get_str(((void *)0), 10, key_u_mpz);
            printf("looking up str %s len = %d\n", key_char, strlen(key_char));
            do { unsigned _hf_bkt,_hf_hashv;
 s=((void *)0);
 if (uv_hash_table) { do { unsigned _hj_i,_hj_j,_hj_k;
 char *_hj_key=(char*)(key_char);
 _hf_hashv = 0xfeedbeef;
 _hj_i = _hj_j = 0x9e3779b9;
 _hj_k = strlen(key_char);
 while (_hj_k >= 12) { _hj_i += (_hj_key[0] + ( (unsigned)_hj_key[1] << 8 ) + ( (unsigned)_hj_key[2] << 16 ) + ( (unsigned)_hj_key[3] << 24 ) );
 _hj_j += (_hj_key[4] + ( (unsigned)_hj_key[5] << 8 ) + ( (unsigned)_hj_key[6] << 16 ) + ( (unsigned)_hj_key[7] << 24 ) );
 _hf_hashv += (_hj_key[8] + ( (unsigned)_hj_key[9] << 8 ) + ( (unsigned)_hj_key[10] << 16 ) + ( (unsigned)_hj_key[11] << 24 ) );
 do { _hj_i -= _hj_j;
 _hj_i -= _hf_hashv;
 _hj_i ^= ( _hf_hashv >> 13 );
 _hj_j -= _hf_hashv;
 _hj_j -= _hj_i;
 _hj_j ^= ( _hj_i << 8 );
 _hf_hashv -= _hj_i;
 _hf_hashv -= _hj_j;
 _hf_hashv ^= ( _hj_j >> 13 );
 _hj_i -= _hj_j;
 _hj_i -= _hf_hashv;
 _hj_i ^= ( _hf_hashv >> 12 );
 _hj_j -= _hf_hashv;
 _hj_j -= _hj_i;
 _hj_j ^= ( _hj_i << 16 );
 _hf_hashv -= _hj_i;
 _hf_hashv -= _hj_j;
 _hf_hashv ^= ( _hj_j >> 5 );
 _hj_i -= _hj_j;
 _hj_i -= _hf_hashv;
 _hj_i ^= ( _hf_hashv >> 3 );
 _hj_j -= _hf_hashv;
 _hj_j -= _hj_i;
 _hj_j ^= ( _hj_i << 10 );
 _hf_hashv -= _hj_i;
 _hf_hashv -= _hj_j;
 _hf_hashv ^= ( _hj_j >> 15 );
 } while (0);
 _hj_key += 12;
 _hj_k -= 12;
 } _hf_hashv += strlen(key_char);
 switch ( _hj_k ) { case 11: _hf_hashv += ( (unsigned)_hj_key[10] << 24 );
 case 10: _hf_hashv += ( (unsigned)_hj_key[9] << 16 );
 case 9: _hf_hashv += ( (unsigned)_hj_key[8] << 8 );
 case 8: _hj_j += ( (unsigned)_hj_key[7] << 24 );
 case 7: _hj_j += ( (unsigned)_hj_key[6] << 16 );
 case 6: _hj_j += ( (unsigned)_hj_key[5] << 8 );
 case 5: _hj_j += _hj_key[4];
 case 4: _hj_i += ( (unsigned)_hj_key[3] << 24 );
 case 3: _hj_i += ( (unsigned)_hj_key[2] << 16 );
 case 2: _hj_i += ( (unsigned)_hj_key[1] << 8 );
 case 1: _hj_i += _hj_key[0];
 } do { _hj_i -= _hj_j;
 _hj_i -= _hf_hashv;
 _hj_i ^= ( _hf_hashv >> 13 );
 _hj_j -= _hf_hashv;
 _hj_j -= _hj_i;
 _hj_j ^= ( _hj_i << 8 );
 _hf_hashv -= _hj_i;
 _hf_hashv -= _hj_j;
 _hf_hashv ^= ( _hj_j >> 13 );
 _hj_i -= _hj_j;
 _hj_i -= _hf_hashv;
 _hj_i ^= ( _hf_hashv >> 12 );
 _hj_j -= _hf_hashv;
 _hj_j -= _hj_i;
 _hj_j ^= ( _hj_i << 16 );
 _hf_hashv -= _hj_i;
 _hf_hashv -= _hj_j;
 _hf_hashv ^= ( _hj_j >> 5 );
 _hj_i -= _hj_j;
 _hj_i -= _hf_hashv;
 _hj_i ^= ( _hf_hashv >> 3 );
 _hj_j -= _hf_hashv;
 _hj_j -= _hj_i;
 _hj_j ^= ( _hj_i << 10 );
 _hf_hashv -= _hj_i;
 _hf_hashv -= _hj_j;
 _hf_hashv ^= ( _hj_j >> 15 );
 } while (0);
 _hf_bkt = _hf_hashv & ((uv_hash_table)->hh.tbl->num_buckets-1);
 } while(0);
 if ((1)) { do { if ((uv_hash_table)->hh.tbl->buckets[ _hf_bkt ].hh_head) do { (s) = (__typeof(s))(((void*)(((char*)((uv_hash_table)->hh.tbl->buckets[ _hf_bkt ].hh_head)) - (((uv_hash_table)->hh.tbl)->hho))));
 } while(0);
 else s=((void *)0);
 while (s) { 
     if (s->hh.keylen == strlen(key_char)) { 
         if ((memcmp(s->hh.key,key_char,strlen(key_char))) == 0) break;
     } 
     if (s->hh.hh_next) do { (s) = (__typeof(s))(((void*)(((char*)(s->hh.hh_next)) - (((uv_hash_table)->hh.tbl)->hho)))); } while(0);
        else s = ((void *)0);
    }
 } while(0);
 } } } while (0);

            printf("finished lokup\n");
            if (s) {
                printf("hash values already exists.\n\n");
            }
            else {
                printf("make new!");
                s = (struct uv_struct*)malloc(sizeof(struct uv_struct));
                if (s == ((void *)0)) {
                    exit(1);
                }
                s->uv_str = key_char;
                s->head = ((void *)0);
            }
            printf("create element");
            printf("now append!");
            do { __typeof(s->head) _tmp; (uv_list)->next=((void *)0); if (s->head) { _tmp = s->head; while (_tmp->next) { _tmp = _tmp->next; } _tmp->next=(uv_list); } else { (s->head)=(uv_list); } } while (0);
            printf("now add!");
            do { unsigned _ha_bkt; (s)->hh.next = ((void *)0); (s)->hh.key = (char*)s->uv_str; (s)->hh.keylen = strlen(s->uv_str); if (!(uv_hash_table)) { uv_hash_table = (s); (uv_hash_table)->hh.prev = ((void *)0); do { (uv_hash_table)->hh.tbl = (UT_hash_table*)malloc(sizeof(UT_hash_table)); if (!((uv_hash_table)->hh.tbl)) { exit(-1); } memset((uv_hash_table)->hh.tbl, 0, sizeof(UT_hash_table)); (uv_hash_table)->hh.tbl->tail = &((uv_hash_table)->hh); (uv_hash_table)->hh.tbl->num_buckets = 32; (uv_hash_table)->hh.tbl->log2_num_buckets = 5; (uv_hash_table)->hh.tbl->hho = (char*)(&(uv_hash_table)->hh) - (char*)(uv_hash_table); (uv_hash_table)->hh.tbl->buckets = (UT_hash_bucket*)malloc(32*sizeof(struct UT_hash_bucket)); if (! (uv_hash_table)->hh.tbl->buckets) { exit(-1); } memset((uv_hash_table)->hh.tbl->buckets, 0, 32*sizeof(struct UT_hash_bucket)); ; (uv_hash_table)->hh.tbl->signature = 0xa0111fe1; } while(0); } else { (uv_hash_table)->hh.tbl->tail->next = (s); (s)->hh.prev = ((void*)(((char*)((uv_hash_table)->hh.tbl->tail)) - (((uv_hash_table)->hh.tbl)->hho))); (uv_hash_table)->hh.tbl->tail = &((s)->hh); } (uv_hash_table)->hh.tbl->num_items++; (s)->hh.tbl = (uv_hash_table)->hh.tbl; do { unsigned _hj_i,_hj_j,_hj_k; char *_hj_key=(char*)(s->uv_str); (s)->hh.hashv = 0xfeedbeef; _hj_i = _hj_j = 0x9e3779b9; _hj_k = strlen(s->uv_str); while (_hj_k >= 12) { _hj_i += (_hj_key[0] + ( (unsigned)_hj_key[1] << 8 ) + ( (unsigned)_hj_key[2] << 16 ) + ( (unsigned)_hj_key[3] << 24 ) ); _hj_j += (_hj_key[4] + ( (unsigned)_hj_key[5] << 8 ) + ( (unsigned)_hj_key[6] << 16 ) + ( (unsigned)_hj_key[7] << 24 ) ); (s)->hh.hashv += (_hj_key[8] + ( (unsigned)_hj_key[9] << 8 ) + ( (unsigned)_hj_key[10] << 16 ) + ( (unsigned)_hj_key[11] << 24 ) ); do { _hj_i -= _hj_j; _hj_i -= (s)->hh.hashv; _hj_i ^= ( (s)->hh.hashv >> 13 ); _hj_j -= (s)->hh.hashv; _hj_j -= _hj_i; _hj_j ^= ( _hj_i << 8 ); (s)->hh.hashv -= _hj_i; (s)->hh.hashv -= _hj_j; (s)->hh.hashv ^= ( _hj_j >> 13 ); _hj_i -= _hj_j; _hj_i -= (s)->hh.hashv; _hj_i ^= ( (s)->hh.hashv >> 12 ); _hj_j -= (s)->hh.hashv; _hj_j -= _hj_i; _hj_j ^= ( _hj_i << 16 ); (s)->hh.hashv -= _hj_i; (s)->hh.hashv -= _hj_j; (s)->hh.hashv ^= ( _hj_j >> 5 ); _hj_i -= _hj_j; _hj_i -= (s)->hh.hashv; _hj_i ^= ( (s)->hh.hashv >> 3 ); _hj_j -= (s)->hh.hashv; _hj_j -= _hj_i; _hj_j ^= ( _hj_i << 10 ); (s)->hh.hashv -= _hj_i; (s)->hh.hashv -= _hj_j; (s)->hh.hashv ^= ( _hj_j >> 15 ); } while (0); _hj_key += 12; _hj_k -= 12; } (s)->hh.hashv += strlen(s->uv_str); switch ( _hj_k ) { case 11: (s)->hh.hashv += ( (unsigned)_hj_key[10] << 24 ); case 10: (s)->hh.hashv += ( (unsigned)_hj_key[9] << 16 ); case 9: (s)->hh.hashv += ( (unsigned)_hj_key[8] << 8 ); case 8: _hj_j += ( (unsigned)_hj_key[7] << 24 ); case 7: _hj_j += ( (unsigned)_hj_key[6] << 16 ); case 6: _hj_j += ( (unsigned)_hj_key[5] << 8 ); case 5: _hj_j += _hj_key[4]; case 4: _hj_i += ( (unsigned)_hj_key[3] << 24 ); case 3: _hj_i += ( (unsigned)_hj_key[2] << 16 ); case 2: _hj_i += ( (unsigned)_hj_key[1] << 8 ); case 1: _hj_i += _hj_key[0]; } do { _hj_i -= _hj_j; _hj_i -= (s)->hh.hashv; _hj_i ^= ( (s)->hh.hashv >> 13 ); _hj_j -= (s)->hh.hashv; _hj_j -= _hj_i; _hj_j ^= ( _hj_i << 8 ); (s)->hh.hashv -= _hj_i; (s)->hh.hashv -= _hj_j; (s)->hh.hashv ^= ( _hj_j >> 13 ); _hj_i -= _hj_j; _hj_i -= (s)->hh.hashv; _hj_i ^= ( (s)->hh.hashv >> 12 ); _hj_j -= (s)->hh.hashv; _hj_j -= _hj_i; _hj_j ^= ( _hj_i << 16 ); (s)->hh.hashv -= _hj_i; (s)->hh.hashv -= _hj_j; (s)->hh.hashv ^= ( _hj_j >> 5 ); _hj_i -= _hj_j; _hj_i -= (s)->hh.hashv; _hj_i ^= ( (s)->hh.hashv >> 3 ); _hj_j -= (s)->hh.hashv; _hj_j -= _hj_i; _hj_j ^= ( _hj_i << 10 ); (s)->hh.hashv -= _hj_i; (s)->hh.hashv -= _hj_j; (s)->hh.hashv ^= ( _hj_j >> 15 ); } while (0); _ha_bkt = (s)->hh.hashv & ((uv_hash_table)->hh.tbl->num_buckets-1); } while(0); do { (uv_hash_table)->hh.tbl->buckets[_ha_bkt].count++; (&(s)->hh)->hh_next = (uv_hash_table)->hh.tbl->buckets[_ha_bkt].hh_head; (&(s)->hh)->hh_prev = ((void *)0); if ((uv_hash_table)->hh.tbl->buckets[_ha_bkt].hh_head) { ((uv_hash_table)->hh.tbl->buckets[_ha_bkt]).hh_head->hh_prev = (&(s)->hh); } ((uv_hash_table)->hh.tbl->buckets[_ha_bkt]).hh_head=&(s)->hh; if ((uv_hash_table)->hh.tbl->buckets[_ha_bkt].count >= (((uv_hash_table)->hh.tbl->buckets[_ha_bkt].expand_mult+1) * 10) && (&(s)->hh)->tbl->noexpand != 1) { do { unsigned _he_bkt; unsigned _he_bkt_i; struct UT_hash_handle *_he_thh, *_he_hh_nxt; UT_hash_bucket *_he_new_buckets, *_he_newbkt; _he_new_buckets = (UT_hash_bucket*)malloc(2 * (&(s)->hh)->tbl->num_buckets * sizeof(struct UT_hash_bucket)); if (!_he_new_buckets) { exit(-1); } memset(_he_new_buckets, 0, 2 * (&(s)->hh)->tbl->num_buckets * sizeof(struct UT_hash_bucket)); (&(s)->hh)->tbl->ideal_chain_maxlen = ((&(s)->hh)->tbl->num_items >> ((&(s)->hh)->tbl->log2_num_buckets+1)) + (((&(s)->hh)->tbl->num_items & (((&(s)->hh)->tbl->num_buckets*2)-1)) ? 1 : 0); (&(s)->hh)->tbl->nonideal_items = 0; for(_he_bkt_i = 0; _he_bkt_i < (&(s)->hh)->tbl->num_buckets; _he_bkt_i++) { _he_thh = (&(s)->hh)->tbl->buckets[ _he_bkt_i ].hh_head; while (_he_thh) { _he_hh_nxt = _he_thh->hh_next; do { _he_bkt = ((_he_thh->hashv) & (((&(s)->hh)->tbl->num_buckets*2) - 1)); } while(0); _he_newbkt = &(_he_new_buckets[ _he_bkt ]); if (++(_he_newbkt->count) > (&(s)->hh)->tbl->ideal_chain_maxlen) { (&(s)->hh)->tbl->nonideal_items++; _he_newbkt->expand_mult = _he_newbkt->count / (&(s)->hh)->tbl->ideal_chain_maxlen; } _he_thh->hh_prev = ((void *)0); _he_thh->hh_next = _he_newbkt->hh_head; if (_he_newbkt->hh_head) _he_newbkt->hh_head->hh_prev = _he_thh; _he_newbkt->hh_head = _he_thh; _he_thh = _he_hh_nxt; } } free((&(s)->hh)->tbl->buckets); (&(s)->hh)->tbl->num_buckets *= 2; (&(s)->hh)->tbl->log2_num_buckets++; (&(s)->hh)->tbl->buckets = _he_new_buckets; (&(s)->hh)->tbl->ineff_expands = ((&(s)->hh)->tbl->nonideal_items > ((&(s)->hh)->tbl->num_items >> 1)) ? ((&(s)->hh)->tbl->ineff_expands+1) : 0; if ((&(s)->hh)->tbl->ineff_expands > 1) { (&(s)->hh)->tbl->noexpand=1; ; } ; } while(0); } } while(0); ; ; ; } while(0);
            count++;
            if (count % hash_chunk_size == 0) {
                printf("count = chunksize %ld ", hash_chunk_size);
                test_against_ab(coeff_a, coeff_b, height, lower, uv_hash_table, rank);
                printf("destroying hash on count '%lld'\n", count);
                for((current_uv)=(uv_hash_table),(uv_htmp)=(uv_hash_table)?(uv_hash_table)->hh.next:((void *)0); current_uv; (current_uv)=(uv_htmp),(uv_htmp)=(uv_htmp)?(uv_htmp)->hh.next:((void *)0)) {
                    for((elt)=(current_uv->head);(elt) && (eltmp = (elt)->next, 1); (elt) = eltmp) {
                        do { __typeof(s->head) _tmp; if ((s->head) == (elt)) { (s->head)=(s->head)->next; } else { _tmp = s->head; while (_tmp->next && (_tmp->next != (elt))) { _tmp = _tmp->next; } if (_tmp->next) { _tmp->next = ((elt)->next); } } } while (0);
                        free(elt);
                    }
                    do { unsigned _hd_bkt; struct UT_hash_handle *_hd_hh_del; if ( ((current_uv)->hh.prev == ((void *)0)) && ((current_uv)->hh.next == ((void *)0)) ) { free((uv_hash_table)->hh.tbl->buckets); ; free((uv_hash_table)->hh.tbl); uv_hash_table = ((void *)0); } else { _hd_hh_del = &((current_uv)->hh); if ((current_uv) == ((void*)(((char*)((uv_hash_table)->hh.tbl->tail)) - (((uv_hash_table)->hh.tbl)->hho)))) { (uv_hash_table)->hh.tbl->tail = (UT_hash_handle*)((char*)((current_uv)->hh.prev) + (uv_hash_table)->hh.tbl->hho); } if ((current_uv)->hh.prev) { ((UT_hash_handle*)((char*)((current_uv)->hh.prev) + (uv_hash_table)->hh.tbl->hho))->next = (current_uv)->hh.next; } else { do { (uv_hash_table) = (__typeof(uv_hash_table))((current_uv)->hh.next); } while(0); } if (_hd_hh_del->next) { ((UT_hash_handle*)((char*)_hd_hh_del->next + (uv_hash_table)->hh.tbl->hho))->prev = _hd_hh_del->prev; } do { _hd_bkt = ((_hd_hh_del->hashv) & (((uv_hash_table)->hh.tbl->num_buckets) - 1)); } while(0); ((uv_hash_table)->hh.tbl->buckets[_hd_bkt]).count--; if (((uv_hash_table)->hh.tbl->buckets[_hd_bkt]).hh_head == _hd_hh_del) { ((uv_hash_table)->hh.tbl->buckets[_hd_bkt]).hh_head = _hd_hh_del->hh_next; } if (_hd_hh_del->hh_prev) { _hd_hh_del->hh_prev->hh_next = _hd_hh_del->hh_next; } if (_hd_hh_del->hh_next) { _hd_hh_del->hh_next->hh_prev = _hd_hh_del->hh_prev; }; (uv_hash_table)->hh.tbl->num_items--; } ; } while (0);
                    free(current_uv);
                }
            }
            current_v = current_v + 1;
            if (current_v > - lower && current_v < lower) {
                current_v = lower;
            }
            printf("now finish\n");
        }
        current_u = current_u + numproc;
        if (current_u > - lower && current_u < lower) {
            current_u = lower + rank;
        }
    }
    __gmpz_clear(key_u_mpz);
    __gmpz_clear(key_v_mpz);
    return 0;
}
int test_against_ab () {
    return 0;
}
void usage (char * progname) {
    printf("need more command line arguments\n");
    printf("example: %s 2 3 -5 -7 1000 0 2500000 /path/for/logfiles\n\n", progname);
}
int main(int argc, char *argv[]) {
    if (argc != 9) {
        usage(argv[0]);
        return 1;
    }
    int coeff_a = atoi(argv[1]);
    int coeff_b = atoi(argv[2]);
    int coeff_c = atoi(argv[3]);
    int coeff_d = atoi(argv[4]);
    long long int h_height = atoi(argv[5]);
    long long int l_height = atoi(argv[6]);
    long int chunk_size = atoi(argv[7]);
    perform_lookup_uv(0, 1, coeff_a, coeff_b, coeff_c, coeff_d, h_height, l_height, chunk_size);
    return 0;
}
