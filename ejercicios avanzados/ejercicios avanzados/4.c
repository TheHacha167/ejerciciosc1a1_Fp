/*
Enunciado del Ejercicio:

Escriba un programa en C que implemente una cola (queue) con las operaciones enqueue, dequeue y display usando una lista enlazada.

Sugerencia: Una cola es una estructura de datos que sigue la disciplina FIFO (First In First Out). Las operaciones enqueue y dequeue se realizan en los extremos frontal y trasero de la cola, respectivamente.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(int k) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp; 
}

struct Queue *createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue *q, int k) {
    struct Node *temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct Queue *q) {
    if (q->front == NULL)
        return;

    struct Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void display(struct Queue *q) {
    struct Node *temp = q->front;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Queue* q = createQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    printf("Queue: ");
    display(q);

    printf("\nDespués de hacer dequeue: ");
    deQueue(q);
    display(q);

    return 0;
}
