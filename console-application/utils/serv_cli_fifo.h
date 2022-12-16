#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "signal.h"
#define QUESTION "fifo1"
#define REPONSE "fifo2"
#define NMAX 10
typedef struct Question
{
    int pid;
    int nombre;
} Question;
typedef struct Reponse
{
    int pid_Serv;
    int tab[NMAX];
} Reponse;