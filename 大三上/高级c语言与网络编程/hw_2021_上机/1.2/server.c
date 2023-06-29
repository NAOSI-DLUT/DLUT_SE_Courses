#include    "unp.h"

void
str_echo(int sockfd)
{
    ssize_t     n;
    char        buf[MAXLINE], tmp;
    int         top, end;

again:
    while ( (n = read(sockfd, buf, MAXLINE)) > 0) {
        top = 0;
        end = n-2;
        while (top < end){
		    tmp = buf[top];
		    buf[top] = buf[end];
    		buf[end] = tmp;
	    	top++;
		    end--;
        }
        // printf("inverted order string:%s",buf);

        Writen(sockfd, buf, n);
        
        if (n < 0 && errno == EINTR){
            memset(buf, 0, sizeof(buf));
            goto again;
        }

        else if (n < 0)
            err_sys("str_echo: read error");
    }

}

void
sig_chld(int signo)
{
    pid_t   pid;
    int     stat;
    while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("child %d terminated\n", pid);
    return;
}

int
main(int argc, char **argv)
{
    int     listenfd, connfd, reuse=1;
    pid_t   childpid;
    socklen_t   clilen;
    struct sockaddr_in  cliaddr, servaddr;
    void    sig_chld(int);

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(8888);


    Setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));

    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);
    Signal(SIGCHLD, sig_chld);
    for ( ; ; ) {
        clilen=sizeof(cliaddr);
        if ( (connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0){
            if (errno == EINTR)
                continue;
			else
				err_sys("accept error");
        }

        printf("New connection from: %s:%d\r\n", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port);
        
        if ( (childpid = fork()) == 0) {
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(connfd);
    }
}