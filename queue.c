#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *create_queue(void)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue *q, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (q->head == NULL)
    {
        q->head = new_node;
        q->tail = new_node;
    }
    else
    {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

int dequeue(Queue *q)
{
    if (q->head == NULL)
    {
        printf("Error : Queue is empty\n");
        return -1;
    }
    else
    {
        Node *temp = q->head;
        int value = temp->data;
        q->head = q->head->next;
        free(temp);
        return value;
    }
}

int is_empty(Queue *q)
{
    return q->head == NULL;
}

void print_queue(Queue *q)
{
    Node *temp = q->head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void free_queue(Queue *q)
{
    Node *temp = q->head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(q);
}