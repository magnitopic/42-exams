#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>

typedef struct s_client
{
	int		id;
	char	msg[1000000];
} t_client;

t_client	clients[1024];
fd_set		read_set, write_set, current;
int		maxfd = 0, gid = 0;
char		send_buff[120000], recv_buff[120000];

void err_msg(char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

void send_to_all(int except)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (FD_ISSET(fd, &write_set) && fd != except)
			if (send(fd, send_buff, strlen(send_buff), 0) == -1)
				err_msg(NULL);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		err_msg("Wrong number of arguments");

	struct sockaddr_in	serveraddr;
	socklen_t			len;
	int serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverfd == -1)
		err_msg(NULL);
	maxfd = serverfd;

	FD_ZERO(&current);
	FD_SET(serverfd, &current);
	bzero(clients, sizeof(clients));
	bzero(&serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(atoi(argv[1]));

	if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1 || listen(serverfd, 100) == -1)
		err_msg(NULL);

	while(1)
	{
	
	}

	return (0);
}

