#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <unistd.h>


void f(char *path, char* name, long inode){
    struct dirent *dp;
    DIR *dirp = opendir(path);
    printf("%s —– ", name);
    while ((dp = readdir(dirp)) != NULL){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && dp->d_ino==inode){
            printf("%s ",dp->d_name);
        }
    }
    printf("\n");
    closedir(dirp);
}

int main(){
    DIR* dir_tmp = opendir("./tmp");
    chdir("./tmp");
    printf("File —– Hard Links\n");
    struct dirent* dp;
    while ((dp = readdir(dir_tmp)) != NULL) {
        struct stat st;
        if(stat(dp->d_name, &st) < 0){
			continue;
        }
        if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..") && !S_ISDIR(st.st_mode)){
            if(st.st_nlink > 1){
                f(".", dp->d_name, dp->d_ino);
            }
        }
    }
    (void)closedir(dir_tmp);
    return 0;
}