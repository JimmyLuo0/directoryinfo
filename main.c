#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	DIR *stream = opendir(".");
	if (stream == NULL){
		printf("error: %d, message: %s\n", errno, strerror(errno));
		return 0;
	}
	struct dirent *file = readdir(stream);
	struct stat *fileinfo;
	stat(file->d_name, fileinfo);
	while(file != NULL){
		printf("file: %s, size: %ld\n", file->d_name, fileinfo->st_size);
		file = readdir(stream);
		stat(file->d_name, fileinfo);
	}
	return 0;
}
