#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca element listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja usuwająca pierwszy element z listy
void pop(struct Node** head) {
    if (*head == NULL) {
        printf("Lista jest pusta. Nie można usunąć elementu.\n");
        return;
    }

    // Zapamiętanie referencji do obecnego nagłówka listy
    struct Node* temp = *head;

    // Przesunięcie nagłówka na kolejny element listy
    *head = (*head)->next;

    // Zwolnienie pamięci zajmowanej przez poprzedni nagłówek
    free(temp);
}

// Funkcja dodająca element na początek listy
void push(struct Node** head, int data) {
    // Tworzenie nowego elementu
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Błąd alokacji pamięci\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;

    // Powiązanie nowego elementu z obecnym nagłówkiem listy
    newNode->next = *head;

    // Ustawienie nowego elementu jako nagłówek listy
    *head = newNode;
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
    // Inicjalizacja pustej listy
    struct Node* head = NULL;

    // Dodawanie elementów na początek listy
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    // Wyświetlenie listy przed usunięciem elementu
    printf("Lista przed usunięciem pierwszego elementu: ");
    print_list(head);

    // Usuwanie pierwszego elementu z listy
    pop(&head);

    // Wyświetlenie listy po usunięciu elementu
    printf("Lista po usunięciu pierwszego elementu: ");
    print_list(head);

    return 0;
}
