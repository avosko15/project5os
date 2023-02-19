#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct llist {
  int value;
  struct llist *next;
};


struct llist *node_alloc(int value) {
  struct llist *node = malloc(sizeof(struct llist));
  if (node != NULL) {
    node->value = value;
    node->next = NULL;
  }
  return node;
}

void node_free(struct llist *node) {
  free(node);
}


void llist_insert_head(struct llist **head, int value) {
  struct llist *node = node_alloc(value);
  if (node != NULL) {
    node->next = *head;
    *head = node;
  }
}

void llist_print(struct llist *head) {
  for (struct llist *node = head; node != NULL; node = node->next) {
    printf("%d ", node->value);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  struct llist *head = NULL;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "print") == 0) {
      llist_print(head);
    } else if (strcmp(argv[i], "insert") == 0 && i + 1 < argc) {
      int value = atoi(argv[i+1]);
      llist_insert_head(&head, value);
      i++;
    } else {
      printf("Unrecognized command: %s\n", argv[i]);
    }
  }

  return 0;
}
