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

void remove_by_value(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Lista jest pusta. Nie można usunąć elementu.\n");
        return;
    }

    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = *head;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Nie można znaleźć elementu o podanej wartości.\n");
        return;
    }

    prev->next = current->next;
    free(current);
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
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    push(&head, 10);

    printf("Lista przed usunięciem elementu o wartości 5: ");
    print_list(head);

    remove_by_value(&head, 5);

    printf("Lista po usunięciu elementu o wartości 5: ");
    print_list(head);

    return 0;
}
