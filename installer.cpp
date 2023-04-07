#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int main()
{
    const char animation[] = "|/-\\";
    const int total = 100;
    int i;
    for (i = 0; i < 20; i++)
    {
        printf("\rLoading %c", animation[i % 4]);
        fflush(stdout);
        usleep(100000); // Sleep for 100ms
    }
    printf("\n");
    for (i = 0; i < 20; i++)
    {
        printf("\rExtracting %c", animation[i % 4]);
        fflush(stdout);
        usleep(100000); // Sleep for 100ms
    }
    printf("\n");
    system("tar -xvf syslink.tar");
    printf("\n");
    for (i = 0; i <= total; i++)
    {
        printf("\rInstalling [");
        int j;
        for (j = 0; j < i; j++)
        {
            printf("=");
        }
        for (j = i; j <= total; j++)
        {
            printf(" ");
        }
        printf("] %d%%", i);
        fflush(stdout);
        usleep(30000);
    }
    printf("\n");
    printf("SysLink Installed Successfully\n");
    return 0;
}