#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_client
{
	int id;
	char msg[100000];
}	t_client;

t_client clients[1024];
fd_set read_set, write_set, current;
int gid = 0, maxfd = 0;
char send_buff[300000], recv_buff[300000];

void err(char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

void msg_all(int except)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (FD_ISSET(fd, &write_set) && fd != except)
			if (send(fd, send_buff, strlen(send_buff), 0) == -1)
				err(NULL);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		err("Wrong number of arguments");

	struct sockaddr_in serveraddr;
	socklen_t len;
	int serverfd = socket(PF_INET, SOCK_STREAM, 0);
	if (serverfd == -1) err(NULL);
	maxfd = serverfd;

	FD_ZERO(&current);
	FD_SET(serverfd, &current);
	bzero(&clients, sizeof(clients));
	bzero(&serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = atoi(argv[1]);
	serveraddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(serverfd, serversocket, sizeof(serversocket) == -1 || listen(serverfd, 100) == -1)
		err(NULL);

	while (1)
	{
	
		read_set = write_set = current;
		if (select(maxfd + 1, read_set, write_set, 0, 0) == -1) continue;
		
		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (FD_ISSET(fd, read_set))
			{
				if (fd == serverfd)
				{
					int clientfd = accept(fd, (struct *restrict addtress)serveradd, len);
					if (clientfd == -1) err(NULL);

				}
				else
				{
					
				}
				break;
			}
		}

	}
	return 0;
}

