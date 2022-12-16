#include "../utils/serv_cli_fifo.h"
#include "../headers/Handlers_Cli.h"

void trait(int fdr, int fdq, int n)
{
    Question Quest;
    Reponse Rep;

    if (n <= 0)
    {
        printf("Enter a number: ");
        scanf("%d", &n);
        while (n >= NMAX)
        {
            printf("Enter a number: ");
            scanf("%d", &n);
        }
    }

    Quest.pid = getpid();
    Quest.nombre = n;

    write(fdq, &Quest, sizeof(Quest));
    signal(SIGUSR1, hand_reveil);
    pause();

    read(fdr, &Rep, sizeof(Rep));

    kill(Rep.pid_Serv, SIGUSR1);

    for (int i = 0; i < n; i++)
    {
        printf("Server -> Number(%d) =  %d \n", i + 1, Rep.tab[i]);
    }
}

int main(int argc, char *argv[])
{
    int fdq, fdr, x;
    fdq = open(QUESTION, O_WRONLY);
    if (fdq == -1)
    {
        fprintf(stderr, "Impossible to open fifo %s\n", QUESTION);
        fprintf(stderr, "Start server first?\n");
        exit(2);
    }
    fdr = open(REPONSE, O_RDONLY);
    if (fdr == -1)
    {
        fprintf(stderr, "Impossible to open fifo %s\n", REPONSE);
        fprintf(stderr, "Start server first?\n");
        exit(2);
    }
    if (argv[1])
    {
        trait(fdr, fdq, atoi(argv[1]));
    }
    else
    {
        trait(fdr, fdq, 0);
    }

    close(fdq);
    close(fdr);
}
