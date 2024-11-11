#include <stdio.h>
#include <stdlib.h>

struct bnode {
    int data;
    struct bnode *l, *r;
};

struct bnode* root = NULL;

struct bnode* nn(int value) {
    struct bnode* temp = (struct bnode*)malloc(sizeof(struct bnode));
    temp->data = value;
    temp->l = temp->r = NULL;
    return temp;
}

struct bnode* insertNode(struct bnode* node, int value) {
    if (node == NULL) {
        return nn(value);
    }
    if (value < node->data) {
        node->l = insertNode(node->l, value);
    } else if (value > node->data) {
        node->r = insertNode(node->r, value);
    }
    return node;
}

struct bnode* deleteNode(struct bnode* root, int value) {
    if (root == NULL)
        return NULL;
    
    if (value > root->data) {
        root->r = deleteNode(root->r, value);
    } 
    
    else if (value < root->data) {
        root->l = deleteNode(root->l, value);
    } else {
        if (root->l == NULL && root->r == NULL) {
            free(root);
            return NULL;
        } else if (root->l == NULL || root->r == NULL) {
            struct bnode* temp;
            if (root->l == NULL) {
                temp = root->r;
            } else {
                temp = root->l;
            }
            free(root);
            return temp;
        } else {
            struct bnode* temp = root->r;
            while (temp && temp->l != NULL) {
                temp = temp->l;
            }
            root->data = temp->data;
            root->r = deleteNode(root->r, temp->data);
        }
    }
    return root;
}

void traverseInOrder(struct bnode* root) {
    if (root != NULL) {
        traverseInOrder(root->l);
        printf("%d ", root->data);
        traverseInOrder(root->r);
    }
}

void traversePreOrder(struct bnode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        traversePreOrder(root->l);
        traversePreOrder(root->r);
    }
}

void traversePostOrder(struct bnode* root) {
    if (root != NULL) {
        traversePostOrder(root->l);
        traversePostOrder(root->r);
        printf("%d ", root->data);
    }
}

void createTree() {
    if (root == NULL) {
        int n, data;
        printf("Enter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            printf("Enter number to be inserted: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            for (int i = 1; i < n; i++) {
                printf("Enter number to be inserted: ");
                scanf("%d", &data);
                insertNode(root, data);
            }
        }
        printf("The tree is created\n");
    } else {
        printf("The tree is already created\n");
    }
}

void searchNode() {
    int key;
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    struct bnode* temp = root;
    while (temp != NULL) {
        if (key == temp->data) {
            printf("Yes, %d is present in the tree.\n", key);
            return;
        } else if (key < temp->data) {
            temp = temp->l;
        } else {
            temp = temp->r;
        }
    }
    printf("No, %d is not present in the tree.\n", key);
}

int main() {
    createTree();
    int choice;
    while (1) {
        printf("\n1. To see tree (in-order)\n");
        printf("2. To see tree (pre-order)\n");
        printf("3. To see tree (post-order)\n");
        printf("4. For insertion of node\n");
        printf("5. For deletion of node\n");
        printf("6. Search an element in tree\n");
        printf("7. To exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverseInOrder(root);
                break;
            case 2:
                traversePreOrder(root);
                break;
            case 3:
                traversePostOrder(root);
                break;
            case 4: {
                int data;
                printf("Enter number to be inserted: ");
                scanf("%d", &data);
                insertNode(root, data);
                break;
            }
            case 5: {
                int value;
                printf("Enter the number to be deleted: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            }
            case 6:
                searchNode();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Incorrect choice\n");
        }
    }
    return 0;
}
