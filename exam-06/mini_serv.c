#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

typedef struct s_client
{
	int id;
	char msg[30000];
} t_client;

t_client clients[1024];
fd_set read_set, write_set, current;
int gid = 0, maxfd = 0;
char recv_buff[300000], send_buff[30000];

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
			if (send(fd, &send_buff, strlen(send_buff), 0) == -1)
				err(NULL);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		err("Wrong number of arguments");
	
	struct sockaddr_in serveraddr;
	socklen_t len;
	int serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverfd == -1) err(NULL);
	maxfd = serverfd;

	FD_ZERO(&current);
	FD_SET(serverfd, &current);
	bzero(clients, sizeof(clients));
	bzero(&serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(atoi(argv[1]));
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1 || listen(serverfd, 100) == -1)
		err(NULL);

	while (1)
	{
		read_set = write_set = current;
		if (select(maxfd + 1, &read_set, &write_set, 0, 0) == -1) continue;

		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (FD_ISSET(fd, &read_set))
			{
				if (fd == serverfd)
				{
					int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len);
					if (clientfd == -1) continue;
					if (clientfd > maxfd) maxfd = clientfd;
					clients[clientfd].id = gid++;
					FD_SET(clientfd, &current);
					sprintf(send_buff, "server: client %d just arrived\n", clients[clientfd].id);
					msg_all(clientfd);
				}
				else
				{
					int rec = recv(fd, recv_buff, sizeof(recv_buff), 0);
					if (rec <= 0)
					{
						sprintf(send_buff, "server: client %d just left\n", clients[fd].id);
						msg_all(fd);
						FD_CLR(fd, &current);
						close(fd);
						bzero(clients[fd].msg, sizeof(clients[fd].msg));
					}
					else
					{
						for (int i = 0, j = strlen(clients[fd].msg); i < rec; j++)
						{
							clients[fd].msg[j] = recv_buff[j];
							if (clients[fd].msg[j] == '\n')
							{
								clients[fd].msg[j] = '\0';
								snprintf(send_buff, strlen(send_buff), "client %d: %s\n", clients[fd].id, clients[fd].msg);
								msg_all(fd);
								bzero(clients[fd].msg, strlen(clients[fd].msg));
								j = -1;
							}
						}
					}
					
				}
				break;
			}
		}
	}
}

