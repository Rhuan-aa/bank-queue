#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int start;
    int end;
    int size;
    char** vector;
} t_queue;

t_queue* create_queue(int size);
int is_empty(t_queue* queue);
int is_full(t_queue* queue);
int size(t_queue* queue);
int in(t_queue* queue, char* value);
int out(t_queue* queue, char** value);
void print_queue(t_queue* queue);
void destroy(t_queue* queue);

#endif