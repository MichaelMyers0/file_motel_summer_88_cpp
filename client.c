#include "net.h"
#include "find.h"
enum {client_port = 5000};
enum {server_port = 5001};
sockets s;
int main(int argc, char** argv)
{
	find f;
	shared_ptr<vector<string>> vecs;
	if (argc < 2)
	{
		fprintf(stderr, "ERROR: Provide a path\n");
		exit(1);
	}
	s.creat_socket(AF_INET6, SOCK_STREAM);
	s.bind_socket(client_port);
	s.connectt(server_port);
	vecs = make_shared<vector<string>>();
	f.gather_files(*(argv + 1), vecs);
	s.send_msg("Hello");
	s.close_socket();
	_exit(0);
}

