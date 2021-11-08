#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyLinkedList {
  struct DoublyLinkedList *previous;
  int root;
  struct DoublyLinkedList *next;
} DLL;

DLL *insert(DLL *head, int value) {
  head->previous = malloc(sizeof(DLL));
  head->previous->previous = NULL;
  head->previous->root = value;
  head->previous->next = head;
  
  head = head->previous;
  return head;
}

void append(DLL *head, int value) {
  while (head->next != NULL) {
    head = (DLL *) head->next;
  }
  head->next = malloc(sizeof(DLL));
  head->next->previous = head;
  head->next->root = value;
  head->next->next = NULL;
}

int print_list(DLL *head, char mode[]) {
  if (strncmp(mode, "reverse", sizeof(mode) / sizeof(char))) {
    while (head->next != NULL) {
      head = head->next;
    }

    while (head != NULL) {
      printf("%d", head->root);
      head = head->previous;
      if (head != NULL) {
        printf(" -> ");
      }
    }
  }
  else if (strncmp(mode, "normal", sizeof(mode) / sizeof(char))) {
    while (head != NULL) {
      printf("%d", head->root);
      head = head->next;
      if (head != NULL) {
        printf(" -> ");
      }
    }
  }
  else {
    return EXIT_FAILURE;
  }
  printf("\n");
}

int main(void) {
  DLL *head = malloc(sizeof(DLL));
  head->next = NULL;
  head->root = 1;
  head = insert(head, 3);
  head = insert(head, -5);
  append(head, 3);
  append(head, 4);
  append(head, 5);
  print_list(head, "reverse");
  print_list(head, "normal");
}
