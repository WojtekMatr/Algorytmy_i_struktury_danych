#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

// Funkcja do dodawania nowego elementu na pocz¹tek listy
void add_node(struct LinkedList *list, int value) {
    // Alokuj pamiêæ dla nowego elementu
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    // Przypisz wartoœæ nowemu elementowi
    new_node->value = value;
    // Ustaw wskaŸnik next nowego elementu na obecny head listy
    new_node->next = list->head;
    // Ustaw nowy element jako head listy
    list->head = new_node;
}

// Funkcja do obliczania œredniej wartoœci elementów listy
float average_list(struct LinkedList *list) {
    float sum = 0;
    int count = 0;

    // Ustaw obecny element jako head listy
    struct Node *current = list->head;

    // Iteruj przez wszystkie elementy listy
    while (current != NULL) {
        sum += current->value;
        count++;
        current = current->next;
    }
    return sum / count;
}


void print_list(struct LinkedList *list) {
    struct Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}
void delete_odd_nodes(struct LinkedList *list) {
    struct Node *current = list->head;
    struct Node *previous = NULL;

    while (current != NULL) {
        if (current->value % 2 != 0) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                list->head = current->next;
            }
            struct Node *temp = current;
            current = current->next;
            free(temp);
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    struct LinkedList list;
    list.head = NULL;
    int i;
    for(i=1; i<101;i++)
   { add_node(&list, i);}
    printf("Lista: \n");
    print_list(&list);
    printf("\nSrednia to %f \n",average_list(&list));
    delete_odd_nodes(&list);
     printf("Lista: \n");
     print_list(&list);
        printf("\nSrednia to %f \n",average_list(&list));


    return 0;
}
