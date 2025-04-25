#include "net.h"
enum {client_port = 5000};
enum {server_port = 5001};
sockets s;
int main(int argc, char** argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "ERROR: Provide a message\n");
		exit(1);
	}
	s.creat_socket(AF_INET6, SOCK_STREAM);
	s.bind_socket(client_port);
	s.connectt(server_port);
	s.send_msg(*(argv + 1));
	s.close_socket();
	_exit(0);
}

