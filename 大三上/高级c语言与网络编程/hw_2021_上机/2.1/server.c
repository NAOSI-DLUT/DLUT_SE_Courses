#include	"unp.h"

int
main(int argc, char **argv)
{
	int					i, maxi, maxfd, listenfd, connfd, sockfd, stdineof;
	int					nready, client[FD_SETSIZE];
	ssize_t				n;
	fd_set				rset, allset;
	char				buf[MAXLINE];
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
    in_port_t           port[FD_SETSIZE];
    struct in_addr      addr[FD_SETSIZE];

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	maxfd = listenfd;			/* initialize */
	maxi = -1;					/* index into client[] array */
	for (i = 0; i < FD_SETSIZE; i++)
		client[i] = -1;			/* -1 indicates available entry */
	stdineof = 0;
	FD_ZERO(&allset);
	// FD_SET(listenfd, &allset);

	for ( ; ; ) {
		rset = allset;		/* structure assignment */
        
		if (stdineof == 0)
			FD_SET(fileno(stdin), &rset);
	    FD_SET(listenfd, &rset);

		nready = Select(maxfd+1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(listenfd, &rset)) {	/* new client connection */
			clilen = sizeof(cliaddr);
			connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);

			for (i = 0; i < FD_SETSIZE; i++)
				if (client[i] < 0) {
					client[i] = connfd;	/* save descriptor */
                    addr[i] = cliaddr.sin_addr;
                    port[i] = cliaddr.sin_port;
					break;
				}
			if (i == FD_SETSIZE)
				err_quit("too many clients");

			FD_SET(connfd, &allset);	/* add new descriptor to set */
			if (connfd > maxfd)
				maxfd = connfd;			/* for select */
			if (i > maxi)
				maxi = i;				/* max index in client[] array */

			if (--nready <= 0)
				continue;				/* no more readable descriptors */
		}
        
        if (FD_ISSET(fileno(stdin), &rset)) {  /* input is readable */
            if ( (n = Read(fileno(stdin), buf, MAXLINE)) == 0) {
                stdineof = 1;
                // Shutdown(sockfd, SHUT_WR);	/* send FIN */
                FD_CLR(fileno(stdin), &rset);
                continue;
            }
            // printf("0000 %s", buf);
                
            for (i = 0; i <= maxi; i++) {	/* check all clients for data */
                if ( (sockfd = client[i]) < 0)
                    continue;
                Writen(sockfd, buf, n);
            }
        }
        
		bzero(&buf, MAXLINE);
        for (i = 0; i <= maxi; i++) {	/* check all clients for data */
			if ( (sockfd = client[i]) < 0)
				continue;
			if (FD_ISSET(sockfd, &rset)) {
				if ( (n = Read(sockfd, buf, MAXLINE)) == 0) {
						/*4connection closed by client */
					Close(sockfd);
					FD_CLR(sockfd, &allset);
					client[i] = -1;
				} else{
                    printf("New message from %s:%d: %s", inet_ntoa(addr[i]), port[i], buf);
					// Writen(sockfd, buf, n);
                }
                
				if (--nready <= 0)
					break;				/* no more readable descriptors */
			}
		}
	}
}