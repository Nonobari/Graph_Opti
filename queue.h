#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

typedef struct _queue
{
    Node *head;
    Node *tail;
} Queue;


Queue *create_queue(void);
void enqueue(Queue *queue, int data);
int dequeue(Queue *queue);
int is_empty(Queue *queue);
int is_full(Queue *queue);
void print_queue(Queue *queue);
void free_queue(Queue *queue);

#endif