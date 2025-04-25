#include "net.h"
enum {client_port = 5000};
enum {server_port = 5001};
enum {log = 5};
enum {sleep_t = 10};
enum {msg_len = 512};
sockets s;
int main()
{
	int fd, len;
	char msg[msg_len];
	s.creat_socket(AF_INET6, SOCK_STREAM);
	s.bind_socket(server_port);
	s.listenn(log);
	s.acceptt(fd);
	sleep(sleep_t);
	for (;;)
	{
		s.read_msg(fd, msg);
		len = strlen(msg);
		if (len)
		{
			printf("%s\n", msg);
			break;
		}
	}
	s.close_socket();
	_exit(0);
}

