#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	DIR *stream = opendir(argv[1]);
	if (stream == NULL){
		printf("error: %d, message: %s\n", errno, strerror(errno));
		return 0;
	}
	struct dirent *file = readdir(stream);
	int fd = open(file->d_name, O_RDONLY);
	int directorysize = lseek(fd, 0, SEEK_END);
	while((file = readdir(stream)) != NULL){
		printf("file: %s\n", file->d_name);
		fd = open(file->d_name, O_RDONLY);
		directorysize += lseek(fd, 0, SEEK_END);
	}
	printf("directory size: %d %s\n", directorysize, "Bytes");
	return 0;
}
