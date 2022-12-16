
#include "../headers/Handlers_Serv.h"
#include "../utils/serv_cli_fifo.h"

void traitemant(int fdr, int fdq)

{
    Question Quest;
    Reponse Rep;

    read(fdq, &Quest, sizeof(Quest));
    Rep.pid_Serv = getpid();
    printf(" New message received: %d \n ", Quest.nombre);
    printf("Process identifier : %d \n ", Quest.pid);

    for (int i = 0; i < Quest.nombre; i++)
    {
        Rep.tab[i] = rand() % NMAX;
    }

    write(fdr, &Rep, sizeof(Rep));

    kill(Quest.pid, SIGUSR1);
    pause();
}

int main()
{

    int fdq, fdr;
    unlink(QUESTION);
    unlink(REPONSE);

    if (mkfifo(QUESTION, 0644) == -1 ||
        mkfifo(REPONSE, 0644) == -1)

    {
        perror("Unable to create fifos");
        exit(2);
    }

    srand(getpid());

    fdq = open(QUESTION, O_RDONLY);
    fdr = open(REPONSE, O_WRONLY);
    signal(SIGUSR1, hand_reveil);
    signal(SIGKILL, fin_serveur);
    traitemant(fdr, fdq);
    close(fdq);
    close(fdr);
    unlink(QUESTION);
    unlink(REPONSE);
    return 0;
}
