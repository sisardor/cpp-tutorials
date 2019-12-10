#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char* argv[]) {
  printf("hello world!\n");
  list_t* list = list_create();
  if ( list == NULL ) {
    printf("create: create failed to malloc\n");
    return 1;
  }

  if ( list->head != NULL ) {
    printf("create: head is not null!\n");
    return 1;
  }

  if ( list->tail != NULL ) {
    printf("create: tail is not null!\n");
    return 1;
  }


  // rest of the test
  int res = list_append(list, 2);

  if ( res != 0 ) {
    printf("list_append: head is not null!\n");
    return 1;
  }
  if ( list->head == NULL ) {
    printf("list_append: head is null!\n");
    return 1;
  }
  if ( list->tail == NULL ) {
    printf("list_append: tail is null!\n");
    return 1;
  }
  if ( list->head->val == 3 ) {
    printf("list_append: list->head->val == 2\n");
    return 1;
  }
  printf("Val: %d\n", list->head->val);
  // list_t* list2 = list_create();
  // list_destroy(list);

  list_print(list);
  return 0;
}