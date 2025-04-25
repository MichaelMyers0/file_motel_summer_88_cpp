#ifndef FIND_H
#define FIND_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <vector>
#include <memory>
#include <dirent.h>
#include <cstring>
#include <sys/stat.h>
#include <time.h>
#include <string>
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::string;
class find
{
	void open_dir(DIR*& dir, const char* start);
	void close_dir(DIR* dir);
	void get_path(const char* p);
public:	
	void gather_files(const char* start, shared_ptr<vector<string>>& vecs);
};
#endif
