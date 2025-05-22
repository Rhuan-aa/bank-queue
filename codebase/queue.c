#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

t_queue* create_queue(int size) {
    t_queue* queue = (t_queue*) malloc(sizeof(t_queue));
    queue->vector = (char**) malloc(sizeof(char*) * size);
    queue->size = size;
    queue->start = 0;
    queue->end = -1;
    return queue;
}

int is_empty (t_queue* queue) {
    return queue->end == -1;
}

int size(t_queue* queue) {
    if (is_empty(queue)) return 0;
    if (queue->end >= queue->start) {
        return queue->end - queue->start + 1;
    }
    return queue->size - queue->start + queue->end + 1;
}

int is_full(t_queue* queue) {
    return size(queue) == queue->size;
}

int in(t_queue* queue, char* value) {
    if (is_full(queue)) {
        return 0;
    }
    
    char* name = (char*) malloc(strlen(value) + 1);
    strcpy(name, value);

    if (is_empty(queue)) {
        queue->start = 0;
        queue->end = 0;
    } else {
        queue->end = (queue->end + 1) % queue->size;
    }
    
    queue->vector[queue->end] = name;
}

int out(t_queue* queue, char** value){
    if (is_empty(queue)) {
        return 0;
    }
    
    *value = queue->vector[queue->start];

    if (queue->start == queue->end) {
        queue->start = 0;
        queue->end = -1;
    } else {
        queue->start = (queue->start + 1) % queue->size;
    }
    
    return 1;
}

void print_queue(t_queue* queue) {
    if (is_empty(queue)) {
        return;
    }

    int queue_size = size(queue);
    for (int i = 0; i < queue_size; i++) {
        int index = (queue->start + i) % queue->size;
        printf("%s \n", queue->vector[index]);
    }

    printf("\n");
}

void destroy(t_queue* queue) {
    if (!is_empty(queue)) {
        int queue_size = size(queue);
        for (int i = 0; i < queue_size; i++) {
            int index = (queue->start + i) % queue->size;
            free(queue->vector[index]);
        }
    }

    free(queue->vector);
    free(queue);
}