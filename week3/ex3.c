#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FILES_AMOUNT_MAX 256
#define DIR_AMOUNT_MAX 8
#define FILE_NAME_MAX 63
#define PATH_SIZE_MAX 2048
#define FILE_DATA_SIZE_MAX 1024 

struct Directory{
    struct File *files[FILES_AMOUNT_MAX];
    struct Directory *directories[DIR_AMOUNT_MAX];
    int nf;
    int nd;
    char *path;
};

struct File{
    int id;
    char *name;
    double size;
    char *data;
    struct Directory *dir; 
};

void add_to_file(struct File* file, const char* str){
    if (strlen(str) > FILE_DATA_SIZE_MAX){
        printf("add_to_file: str size is greater than allowed\n");
        return;
    }

    char *tmp = malloc(strlen(str) * sizeof(char));
    strcpy(tmp, str);


    file->data = tmp;
    file->size = strlen(tmp);
}

void append_to_file(struct File* file, const char* str){
    char *new_data = malloc((strlen(file->data) + strlen(str)) * sizeof(char));
    strcpy(new_data, file->data);
    strcat(new_data, str);
    if (strlen(new_data) > FILE_DATA_SIZE_MAX){
        free(new_data);
        printf("append_to_file: total size is greater than allowed\n");
        return;
    }
    file->data = new_data;
    file->size = strlen(new_data);
}

void pwd_file(struct File* file){
    printf("%s/%s\n", file->dir->path, file->name);
}

void add_file(struct File* file, struct Directory* dir){
    if (dir->nf + 1 > FILES_AMOUNT_MAX){
        printf("add_file: no place for new file");
        return;
    }
    file->dir = dir;
    dir->nf = dir->nf + 1;
    dir->files[dir->nf] = file;
}

void add_dir(struct Directory* src, struct Directory* dst){
    if (dst->nd + 1 > DIR_AMOUNT_MAX){
        printf("add_file: no place for new sub-directory");
        return;
    }

    dst->directories[dst->nd] = src;
    dst->nd++;

    char *new_path_src = malloc((strlen(src->path) + strlen(dst->path))* sizeof(char));
    if (dst->path != "/"){
        strcpy(new_path_src, dst->path);
    }
    strcat(new_path_src, src->path);

    if (strlen(new_path_src) > PATH_SIZE_MAX){
        printf("add_dir: new path name is too big");
        return;
    }

    src->path = new_path_src;
}

int main(void){
    // Create the root directory (/) with two subdirectories home and bin
    struct Directory *root = malloc(sizeof(struct Directory));
    root->path = "/";

    struct Directory *home = malloc(sizeof(struct Directory));
    home->path = "/home";
    add_dir(home, root);
    
    struct Directory *bin = malloc(sizeof(struct Directory));
    bin->path = "/bin";
    add_dir(bin, root);

    // Add a file bash to the directory bin
    struct File *bash = malloc(sizeof(struct File));
    bash->id = 1;
    bash->name = "bash";
    add_file(bash, bin);

    // Add two files ex3 1.c and ex3 2.c to the directory home. The file
    // ex3 1.c contains the code: “int printf(const char * format, ...);”
    // And the file ex3 2.c contains the code: “//This is a comment in C
    // language”
    struct File *ex3_1_c = malloc(sizeof(struct File));
    ex3_1_c->name = "ex3_1.c";
    ex3_1_c->id = 2;

    struct File *ex3_2_c = malloc(sizeof(struct File));
    ex3_2_c->name = "ex3_2.c";
    ex3_2_c->id = 3;

    add_file(ex3_1_c, home);
    add_file(ex3_2_c, home);

    add_to_file(ex3_1_c, "int printf(const char * format, ...)");
    add_to_file(ex3_2_c, "//This is a comment in C language");

    // Add the content “Bourne Again Shell!!” to the file bash
    add_to_file(bash, "Bourne Again Shell!");

    // Append the content “int main(){printf(”Hello World!”)}” to the file ex3 1.c
    append_to_file(ex3_1_c, "int main(){printf(”Hello World!”)}");

    //Print the path of all files in the system by calling the function pwd
    pwd_file(bash);
    pwd_file(ex3_1_c);
    pwd_file(ex3_2_c);    
    return 0;
}