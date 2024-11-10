#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

typedef struct Queue {
    Node *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    }
    return 0;
}

void enqueue(Queue* q, int new_data) {
    Node* new_node = createNode(new_data);
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

int getFront(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

int getRear(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->rear->data;
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);

    int front = getFront(q);
    int rear = getRear(q);
    if (front != -1) {
        printf("Queue Front: %d\n", front);
    }

    if (rear != -1) {
        printf("Queue Rear: %d\n", rear);
    }

    dequeue(q);
    dequeue(q);

    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    dequeue(q);

    front = getFront(q);
    rear = getRear(q);

    if (front != -1) {
        printf("Queue Front: %d\n", front);
    }

    if (rear != -1) {
        printf("Queue Rear: %d\n", rear);
    }

    return 0;
}
