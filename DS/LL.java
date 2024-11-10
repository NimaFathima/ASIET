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
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->next = NULL;
            head = newnode;
            temp = head;
            printf("\nEnter number to be inserted : ");
            scanf("%d", &data);
            head->data = data;

            for (int i = 2; i <= n; i++) {
                newnode = (struct node*)malloc(sizeof(struct node));
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
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertAtEnd() {
    int data;
    struct node *temp, *current;
    temp = (struct node*)malloc(sizeof(struct node));
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
    newnode = (struct node*)malloc(sizeof(struct node));
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
        position = (struct node*)malloc(sizeof(struct node));
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
        }
        printf("\nMaximum number is : %d ", max);
    }
}

void mean() {
    int a[10];
    int i;
    struct node* temp;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = head;
        int sum = 0, count = 0;
        float m;
        while (temp != NULL) {
            sum = sum + temp->data;
            temp = temp->next;
            count++;
        }
        m = sum / count;
        printf("\nMean is %f ", m);
    }
}

void sort() {
    struct node* current = head;
    struct node* index = NULL;
    int temp;
    if (head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void reverseLL() {
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        while (head != NULL) {
            t2 = head->next;
            head->next = t1;
            t1 = head;
            head = t2;
        }
        head = t1;
        temp = head;
        printf("Reversed linked list is : ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void search() {
    int found = -1;
    struct node* tr = head;
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        printf("\nEnter the element you want to search: ");
        int key;
        scanf("%d", &key);
        while (tr != NULL) {
            if (tr->data == key) {
                found = 1;
                break;
            } else {
                tr = tr->next;
            }
        }
        if (found == 1) {
            printf("Yes, %d is present in the linked list.\n", key);
        } else {
            printf("No, %d is not present in the linked list.\n", key);
        }
    }
}

int main() {
    createList();
    int choice;
    while (1) {
        printf("\n\t1 To see list\n");
        printf("\t2 For insertion at starting\n");
        printf("\t3 For insertion at end\n");
        printf("\t4 For insertion at any position\n");
        printf("\t5 For deletion of first element\n");
        printf("\t6 For deletion of last element\n");
        printf("\t7 For deletion of element at any position\n");
        printf("\t8 To find maximum among the elements\n");
        printf("\t9 To find mean of the elements\n");
        printf("\t10 To sort element\n");
        printf("\t11 To reverse the linked list\n");
        printf("\t12 Search an element in linked list\n");
        printf("\t13 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                insertAtFront();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deletePosition();
                break;
            case 8:
                maximum();
                break;
            case 9:
                mean();
                break;
            case 10:
                sort();
                break;
            case 11:
                reverseLL();
                break;
            case 12:
                search();
                break;
            case 13:
                exit(1);
                break;
            default:
                printf("Incorrect Choice\n");
        }
    }
    return 0;
}
