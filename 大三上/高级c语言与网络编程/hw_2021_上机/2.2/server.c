#include	"unp.h"

int
main(int argc, char **argv)
{
	int					n, sockfd;
	socklen_t	        len;
	struct sockaddr_in	servaddr, cliaddr;
	char		        mesg[MAXLINE], retn[MAXLINE];

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	Bind(sockfd, (SA *) &servaddr, sizeof(servaddr));

    for ( ; ; ) {
		len = sizeof(cliaddr);
        strcpy(retn,"Receive: ");
		n = Recvfrom(sockfd, mesg, MAXLINE, 0, (SA *) &cliaddr, &len);
        strcat(retn, mesg);
        printf("New message from %s:%d: %s\r", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port, mesg);
        
		Sendto(sockfd, retn, n+9, 0, (SA *) &cliaddr, len);
	}
}
