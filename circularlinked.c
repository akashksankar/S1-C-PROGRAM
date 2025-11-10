#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (last == NULL) {
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (last == NULL) {
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void deleteNode(int key) {
    if (last == NULL) return;
    
    struct Node *temp = last->next;
    struct Node *prev = last;
    
    if (temp->data == key && temp->next == temp) {
        free(temp);
        last = NULL;
        return;
    }
    
    if (temp->data == key) {
        last->next = temp->next;
        free(temp);
        return;
    }
    
    do {
        if (temp->data == key) {
            prev->next = temp->next;
            if (temp == last) last = prev;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
}

void display() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(head)\n");
}

void search(int key) {
    if (last == NULL) return;
    struct Node* temp = last->next;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("%d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != last->next);
    printf("%d not found\n", key);
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert Beginning\n2. Insert End\n3. Delete\n4. Display\n5. Search\n6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Key to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Key to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 6:
                while (last != NULL) deleteNode(last->next->data);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
