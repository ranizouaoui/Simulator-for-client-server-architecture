#include "../utils/serv_cli_fifo.h"
void hand_reveil(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("SIGUSR1 has been received \n");
    }
};