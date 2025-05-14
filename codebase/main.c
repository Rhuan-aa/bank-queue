#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h";

void enter_queue(char* name, t_queue* queue) {
    in(queue, name);
}

char* exit_queue(t_queue* queue) {
    return out(queue);
}

int main(int argc, char const *argv[]) {
    t_queue* priority_queue = create_queue(50);
    t_queue* public_queue = create_queue(50);
    t_queue* attended_queue = create_queue(100);

    char line[64];
    char nome[32];
    int priority_count = 0;

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';

        if (line[0] == 'f') {
            break;
        } else if (line[0] == 'g' && line[1] == ' ') {
            strcpy(nome, line + 2);
            enter_queue(nome, public_queue);

        } else if (line[0] == 'p' && line[1] == ' ') {
            strcpy(nome, line + 2);
            enter_queue(nome, priority_queue);

        } else if (line[0] == 's') {
            char* attended = NULL;
            
            if (!is_empty(priority_queue) && priority_count < 3) {
                attended = exit_queue(priority_queue);
                priority_count++;
            } else if (!is_empty(public_queue)) {
                attended = exit_queue(public_queue);
                priority_count = 0;
            } else if (!is_empty(priority_queue)) {
                attended = exit_queue(priority_queue);
                priority_count = 1;
            }
            
            if (attended) {
                in(attended_queue, attended);
                free(attended);
            }
        }   
    }

    print_queue(attended_queue);

    destroy(priority_queue);
    destroy(public_queue);
    destroy(attended_queue);
    return 0;
}
