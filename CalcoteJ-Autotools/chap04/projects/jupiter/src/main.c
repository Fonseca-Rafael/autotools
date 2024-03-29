#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#if HAVE_PTHREAD_H
#include <pthread.h>
#endif

static void* print_it(void *data)
{
    printf("Hello from %s!\n", (const char*) data);
    return NULL;
}

int main(int argc, char **argv)
{
#if ASYNC_EXEC_H
    pthread_t   tid;
    pthread_create(&tid, 0, print_it, argv[0]);
    pthread_join(tid, 0);
#else
    print_it(argv[0]);
#endif
    return 0;
}
