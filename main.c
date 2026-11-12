#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curses.h>

/*
    arguments:
    --path : execution path, (if . then just grab the current path)
    --depth : how far to open folders.
*/
int main(int argc, char *argv[]) {
    char* path;
    long depth;

    for (int i = 0; i < argc; ++i){
        char* endptr;
        // parse for depth argument
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

        // parse for path argument
        } else if (strcmp(argv[i], "--path") == 0) {
            path = argv[i+1];
            if (path == NULL){
                printf("No path provided");
                return 1;
            } else if (strcmp(path, ".") == 0){
                path = argv[0];
            }
        }
    }

    printf("depth: %lu\n", depth);
    printf("path: %s", path);

    // terminal draw loop

    initscr();
    cbreak();
    if (start_color() == ERR){
        endwin();
        return 1;
    }

    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    refresh();

    int ch;
    while((ch = getch()) != 'q'){
    }

    endwin();
    return 0;
}