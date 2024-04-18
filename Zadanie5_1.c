#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca element listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja dodająca element na początek listy
void add_first(struct Node** head, int data) {
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
    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);

    // Wyświetlenie listy
    printf("Lista po dodaniu elementów na początek: ");
    print_list(head);

    return 0;
}
