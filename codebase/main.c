#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void exit_queue(t_queue* queue, t_queue* attended_queue) {
    char* attended = NULL;
    out(queue, &attended);
    in(attended_queue, attended);
}

int main(int argc, char const *argv[]) {
    t_queue* priority_queue = create_queue(50);
    t_queue* general_queue = create_queue(100);
    t_queue* attended_queue = create_queue(150);

    char line[64];
    char name[32];
    int priority_count = 0;

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(name, line + 2);

        if (line[0] == 'p') {
            in(priority_queue, name);
        } else if (line[0] == 'g') {
            in(general_queue, name);
        } else if (line[0] == 's') {
            
            if (!is_empty(priority_queue) && priority_count < 3) {
                exit_queue(priority_queue, attended_queue);
                priority_count++;
            } else if (!is_empty(general_queue)) {
                exit_queue(general_queue, attended_queue);
                priority_count = 0;
            } else if (!is_empty(priority_queue)) {
                exit_queue(priority_queue, attended_queue);
                priority_queue = 1;
            }

        } else if (line[0] == 'f') {
            print_queue(attended_queue);
            break;    
        }
    }
    
    destroy(priority_queue);
    destroy(general_queue);
    destroy(attended_queue);
    
    return 0;
}
