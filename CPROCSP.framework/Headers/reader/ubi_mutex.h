#ifndef UBI_MUTEX_H
#define UBI_MUTEX_H 1

#include <sys/param.h>

#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif /* HAVE_LIMITS_H */

#include <pthread.h>

#if defined( __cplusplus )
extern "C" {
#endif /* defined( __cplusplus ) */

typedef struct ubi_named_mutex_t_{
  pthread_mutex_t *mutex;
  unsigned flags;
  unsigned recursion;
  pthread_t t_owner;
  pthread_t t_liberator;
  char      p_mypid[16];
  int sem_fd;
  char name[PATH_MAX];
  struct ubi_named_mutex_t_* next;
  struct ubi_named_mutex_t_* prev;
  int count;
} ubi_named_mutex_t;

typedef struct ubi_mutex_t_{
  ubi_named_mutex_t* named_mutex;
} ubi_mutex_t;

/* wrapper к pthread_mutex_init() с установкой атрибута RECURSIVE */
int support_mutex_init_recursive(pthread_mutex_t *mutex);

int ubi_mutex_open(ubi_mutex_t *ubi_mutex, const char *name, unsigned flags);
int ubi_mutex_close(ubi_mutex_t *ubi_mutex);
int ubi_mutex_lock(ubi_mutex_t *ubi_mutex);
int ubi_mutex_trylock(ubi_mutex_t *ubi_mutex);
int ubi_mutex_unlock(ubi_mutex_t *ubi_mutex);
int ubi_mutex_copy(ubi_mutex_t *ubi_mutex1, const ubi_mutex_t *ubi_mutex2);

#if defined( __cplusplus )
}
#endif /* defined( __cplusplus ) */

#endif /* UBI_MUTEX_H */
