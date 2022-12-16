#include "../utils/serv_cli_fifo.h"
void hand_reveil(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("SIGUSR1 has been received\n");
    }
}
void fin_serveur(int sig)
{

    if (sig != SIGUSR1)
    {
        printf("End Server!\n");
        unlink(QUESTION);
        unlink(REPONSE);
        exit(2);
    }
}
void doprocessing(int sock)
{
    int n;
    int buffer[256];
    int num;
    FILE *f;
    f = fopen("output.txt", "w");
    bzero(buffer, 256);
    srand(getpid());
    n = read(sock, &num, sizeof(num));
    for (int i = 0; i < num; i++)
    {
        buffer[i] = rand() % NMAX;
    }
    if (n < 0)
    {
        perror("ERROR reading from socket");
        fprintf(f, "ERROR reading from socket\n");
        fclose(f);
        exit(1);
    }

    printf("Here is the message: %d\n", num);
    fprintf(f, "Here is the message: %d\n", num);
    n = write(sock, &buffer, 255);

    if (n < 0)
    {
        perror("ERROR writing to socket");
        fprintf(f, "ERROR reading from socket\n");
        fclose(f);
        exit(1);
    }
    fclose(f);
}