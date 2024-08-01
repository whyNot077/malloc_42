#include "malloc.h"

#ifdef BONUS
pthread_mutex_t g_memory_lock = PTHREAD_MUTEX_INITIALIZER;
#endif

void lock()
{
#ifdef BONUS
    pthread_mutex_lock(&g_memory_lock);
#endif
}

void unlock()
{
#ifdef BONUS
    pthread_mutex_unlock(&g_memory_lock);
#endif
}

void destroy_lock()
{
#ifdef BONUS
    pthread_mutex_destroy(&g_memory_lock);
#endif
}

void destroy_file_lock()
{
#ifdef BONUS
    pthread_mutex_destroy(&g_log_lock);
#endif   
}