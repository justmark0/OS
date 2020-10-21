#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

unsigned int i_node;
char* file_name;

int filter(const struct dirent* entry)
{
    if (entry->d_ino == i_node && strcmp(entry->d_name, file_name))
        return 1;
    return 0;
}

int main()
{
	DIR *tmp;
  	struct dirent *dir;
    tmp = opendir("./tmp/");
    if(tmp) {
    	while ((dir = readdir(tmp)) != NULL) {
        struct dirent **names = NULL;
        i_node = dir->d_ino;
        file_name = dir->d_name;
        int len = scandir("./tmp/", &names, filter, NULL);
        while(len--)
            printf("%s ", names[len]->d_name);
        free(names);
    	}
    	closedir(tmp);
  	}
	return 0;
}
