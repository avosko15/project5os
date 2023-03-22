#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include <string.h>

void llist_insert_head(struct node **head, struct node *n) {
    n->next = *head;
    *head = n;
}

struct node *llist_delete_head(struct node **head) {
    if (*head == NULL) {
        return NULL;
    } else {
        struct node *temp = *head;
        *head = (*head)->next;
        return temp;
    }
}

void llist_insert_tail(struct node **head, struct node *n) {
    if (*head == NULL) {
        *head = n;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = n;
    }
}

void llist_print(struct node *head) {
    if (head == NULL) { 
        printf("[empty]");
    }
}

void llist_free(struct node **head) {
    while (*head != NULL) {
        struct node *temp = *head;
        *head = (*head)->next;
        node_free(temp);
    }
}

struct node *node_alloc(int value) {
    struct node *n = malloc(sizeof(struct node));
    if (n == NULL) {
        fprintf(stderr, "Error: Failed allocate memory for node.\n");
        exit(EXIT_FAILURE);
    }
    n->value = value;
    n->next = NULL;
    return n;
}

void node_free(struct node *n) {
    free(n);
}

int main(int argc, char **argv) {
    struct node *head = NULL;

    for (int i=1; i < argc;) {
        if ((strcmp(argv[i], "ih")) == 0) {
            struct node *new_node = node_alloc(atoi(argv[i+1]));
            llist_insert_head(&head, new_node);
            i += 2;
        }
        else if ((strcmp(argv[i], "it")) == 0) {
            struct node *new_node = node_alloc(atoi(argv[i+1]));
            llist_insert_tail(&head, new_node);
            i += 2;
        }
        else if ((strcmp(argv[i], "dh")) == 0) {
            llist_delete_head(&head);
            i++;
        }
        else if ((strcmp(argv[i], "f")) == 0) {
            llist_free(&head);
            i++;
        }
        else if ((strcmp(argv[i], "p")) == 0) {
            llist_print(head);
            i++;
        }
        else {
            printf("Error, command not found try again");
        }
    }
}