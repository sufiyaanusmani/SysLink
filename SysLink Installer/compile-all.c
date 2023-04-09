#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>

void *command()
{
    system("./command.sh");
    return NULL;
}

void *network()
{
    system("./network.sh");
    return NULL;
}

void *realtime()
{
    system("./realtime.sh");
    return NULL;
}

void *sysinfo()
{
    system("./sysinfo.sh");
    return NULL;
}

void *user()
{
    system("./user.sh");
    return NULL;
}

int main()
{
    pthread_t thread[5];

    pthread_create(&thread[0], NULL, command, NULL);
    pthread_create(&thread[1], NULL, network, NULL);
    pthread_create(&thread[2], NULL, realtime, NULL);
    pthread_create(&thread[3], NULL, sysinfo, NULL);
    pthread_create(&thread[4], NULL, user, NULL);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);
    pthread_join(thread[3], NULL);
    pthread_join(thread[4], NULL);
}