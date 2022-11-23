#include <stdio.h>
#include <dirent.h>


int main() {
    DIR *root = opendir("/");
    struct dirent *e;

    while((e = readdir(root))){
        printf("%s\n", e->d_name);
    }
    closedir(root);
    return 0;
}