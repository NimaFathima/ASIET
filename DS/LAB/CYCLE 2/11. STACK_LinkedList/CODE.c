#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->next = *top;
    *top = new_node;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped_value = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped_value;
}

int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is: %d\n", peek(stack));

    display(stack);

    printf("Popped element is: %d\n", pop(&stack));

    display(stack);

    printf("Stack is empty: %d\n", isEmpty(stack));

    return 0;
}
