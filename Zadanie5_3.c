#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca element listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja dodająca element na koniec listy
void push(struct Node** head, int data) {
    // Tworzenie nowego elementu
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Błąd alokacji pamięci\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    // Jeśli lista jest pusta, nowy element staje się jej nagłówkiem
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // W przeciwnym razie szukamy ostatniego elementu
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Nowy element zostaje dodany na końcu listy
    last->next = newNode;
}


void remove_last(struct Node** head) {
    // Sprawdzenie, czy lista jest pusta
    if (*head == NULL) {
        printf("Lista jest pusta. Nie można usunąć ostatniego elementu.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }


    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }


    free(temp->next);
    temp->next = NULL;
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


    printf("Lista przed usunięciem ostatniego elementu: ");
    print_list(head);


    remove_last(&head);


    printf("Lista po usunięciu ostatniego elementu: ");
    print_list(head);

    return 0;
}

