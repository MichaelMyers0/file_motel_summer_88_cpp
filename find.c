#include "find.h"
void find::open_dir(DIR*& dir, const char* start)
{

	errno = 0;
	dir = opendir(start);
	if (!dir)
	{
		perror("opendir()\n");
		exit(1);
	}
}

void find::close_dir(DIR* dir)
{
	errno = 0;
	auto res = closedir(dir);
	if (res == -1)
	{
		perror("closedir()\n");
		exit(2);
	}
}

void find::gather_files(const char* start, shared_ptr<vector<string>>& vecs)
{
	DIR* dir;
	struct dirent* ent;
	auto len = 0, res = 0;
	struct stat stat_buf;
	open_dir(dir, start);
	while ((ent = readdir(dir)))
	{
		len = strlen(ent->d_name);
		if (0 == strcmp(ent->d_name, ".") || 0 == strcmp(ent->d_name, "..") || *(ent->d_name + len - 1) == 'o')
			continue;
		errno = 0;
		switch (ent->d_type)
		{
			case DT_REG :
				vecs->push_back(ent->d_name);
				break;
		}
	}
	close_dir(dir);
}
