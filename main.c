#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    argument 0: execution path
    argument 1: given path
    argument 2: --depth
    if given path not given, use execution path
*/
int main(int argc, char *argv[]) {
    char* path;
    long depth;

    for (int i = 0; i < argc; ++i){
        char* endptr;
        if (strcmp(argv[i], "--depth") == 0){
            char* raw_depth = argv[i+1];
            if (raw_depth == NULL){
                printf("No depth provided");
                return 1;
            }
            depth = strtol(raw_depth, &endptr, 10);
            // strtol error checking
            if (endptr == raw_depth){
                printf("No digits were found.\n");
                return 1;
            } else if (*endptr != '\0'){
                printf("Invalid character: %c\n", *endptr);
                return 1;
            }
        } else if (strcmp(argv[i], "--path") == 0) {
            path = argv[i+1];
            if (path == NULL){
                printf("No path provided");
                return 1;
            }
        }
    }
    printf("depth: %lu\n", depth);
    printf("path: %s", path);

    return 0;
}