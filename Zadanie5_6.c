#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Błąd alokacji pamięci\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

void insert_at_index(struct Node** head, int index, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Błąd alokacji pamięci\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int i = 0;
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Nie można dodać elementu na podanym indeksie.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Lista przed dodaniem elementu na indeksie 2: ");
    print_list(head);

    insert_at_index(&head, 2, 10);

    printf("Lista po dodaniu elementu na indeksie 2: ");
    print_list(head);

    return 0;
}
