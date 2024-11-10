#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void createList() {
    if (head == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            int data;
            struct node* newnode;
            struct node* temp;
            newnode = malloc(sizeof(struct node));
            newnode->next = NULL;
            head = newnode;
            temp = head;
            printf("\nEnter number to be inserted : ");
            scanf("%d", &data);
            head->data = data;

            for (int i = 2; i <= n; i++) {
                newnode = malloc(sizeof(struct node));
                newnode->next = NULL;

                temp->next = newnode;
                printf("\nEnter number to be inserted : ");
                scanf("%d", &data);
                newnode->data = data;
                temp = temp->next;
            }
        }
        printf("\nThe list is created\n");
    } else {
        printf("\nThe list is already created\n");
    }
}

void traverse() {
    struct node* temp;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("Data = %d\n", temp->data);
            temp = temp->next;
        }
    }
}

void insertAtFront() {
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertAtEnd() {
    int data;
    struct node *temp, *current;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->next = 0;
    temp->data = data;
    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

void insertAtPosition() {
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
    temp = head;
    newnode->data = data;
    newnode->next = 0;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteFirst() {
    struct node* temp;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteEnd() {
    struct node *temp, *prevnode;
    if (head == NULL) {
        printf("\nList is Empty\n");
    } else {
        temp = head;
        while (temp->next != 0) {
            prevnode = temp;
            temp = temp->next;
        }
        free(temp);
        prevnode->next = 0;
    }
}

void deletePosition() {
    struct node *temp, *position;
    int i = 1, pos;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        position = temp->next;
        temp->next = position->next;
        free(position);
    }
}

void maximum() {
    int a[10];
    int i;
    struct node* temp;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = head;
        int max = temp->data;

        while (temp != NULL) {
            if (max < temp->data)
                max = temp->data;
            temp = temp->next;
