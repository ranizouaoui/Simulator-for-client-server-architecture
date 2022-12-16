#include "../utils/serv_cli_fifo.h"
int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int buffer[256];
    int num;

    portno = 5001;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");

    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    /* Now ask for a message from the user, this message
     * will be read by server
     */
    if (argv[1])
    {
        num = atoi(argv[1]);
    }
    else
    {
        printf("Enter a number: ");
        scanf("%d", &num);
    }

    /* Send message to the server */
    n = write(sockfd, &num, sizeof(num));

    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
    n = read(sockfd, buffer, 255);

    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    for (int i = 0; i < num; i++)
    {
        printf("Server -> Number(%d) =  %d \n", i + 1, buffer[i]);
    }
    return 0;
}