CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -fpermissive
net.o:net.c
	$(CXX) $(CXXFLAGS) -g -c -O $< -o $@
find.o:find.c
	$(CXX) $(CXXFLAGS) -g -c -O $< -o $@	
client:client.c net.o find.o
	$(CXX) $(CXXFLAGS) -g -O $^ -o $@	
server:server.c net.o
	$(CXX) $(CXXFLAGS) -g -O $^ -o $@	

