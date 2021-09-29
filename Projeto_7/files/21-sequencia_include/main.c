#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "darray.h"


int main(void) {

  char cmd[10];
  float f;

  darray* D = da_alloc(64);
  if (!D) {
    printf("Unable to allocate D.\n");
    exit(1);
  }

  while (1) {
    scanf("%s",cmd);

    if (strcmp(cmd,"push") == 0) {
      scanf("%f",&f);
      int st = da_push(D,f);
      if (!st) {
        printf("Unable to resize at push.\n");
        exit(1);
      }
    }

    else if (strcmp(cmd,"pop") == 0) {
      if (!da_is_empty(D))
        f = da_pop(D);
    }

    else if (strcmp(cmd,"inject") == 0) {
      scanf("%f",&f);
      int st = da_inject(D,f);
      if (!st) {
        printf("Unable to resize at inject.\n");
        exit(1);
      }
    }

    else if (strcmp(cmd,"eject") == 0) {
      if (!da_is_empty(D))
        f = da_eject(D);
    }

    else if (strcmp(cmd,"print-first") == 0) {
      if (!da_is_empty(D))
        printf("first: %g\n",da_first(D));
    }

    else if (strcmp(cmd,"print-last") == 0) {
      if (!da_is_empty(D))
        printf("last: %g\n",da_last(D));
    }

    else if (strcmp(cmd,"is-empty") == 0) {
      if (da_is_empty(D))
        printf("empty\n");
      else
        printf("non-empty\n");
    }

    else if (strcmp(cmd,"exit") == 0) {
      da_free(D);
      return 0;
    }

    else {
      printf("Ups, invalid command %s\n",cmd);
      exit(1);
    }
  }

  return 0;
}
