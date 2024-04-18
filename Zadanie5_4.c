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

void remove_by_index(struct Node** head, int index) {
    // Sprawdzenie, czy lista jest pusta
    if (*head == NULL) {
        printf("Lista jest pusta. Nie można usunąć elementu.\n");
        return;
    }

    if (index == 0) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }


    struct Node* prev = NULL;
    struct Node* current = *head;
    int i = 0;
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }


    if (current == NULL) {
        printf("Nie można znaleźć elementu o podanym indeksie.\n");
        return;
    }


    prev->next = current->next;
    free(current);
}

// Funkcja wyświetlająca listę
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


    printf("Lista przed usunięciem elementu o indeksie 5: ");
    print_list(head);

    // Usunięcie elementu o indeksie 5
    remove_by_index(&head, 5);


    printf("Lista po usunięciu elementu o indeksie 5: ");
    print_list(head);

    return 0;
}
