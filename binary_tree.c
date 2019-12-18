#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

void Insert();
void Search();
void RunTreeToInsert();
void RunTreeToSearch();

typedef struct binaryTreeNode {
  struct binaryTreeNode *right, *left;
  int content;
}
binaryTreeNode;

int linked = 0, search_value;

bool break_looping = true;

struct binaryTreeNode *auxiliar, *chain, *root;

int main() {
  int op;

  root = NULL;

  ini:

    printf("\n[1] - insert\n");
  printf("[2] - search\n");
  printf("[0] - close\n");

  printf("Choose an option: ");
  scanf("%i", & op);

  switch (op) {
  case 1:
    Insert();
    break;

  case 2:
    Search();
    break;

  case 0:
    return 0;
    break;
  }

  goto ini;

  return 0;
}

void EnterbinaryTreeNode() {
  printf("\nNumber: ");
  scanf("%i", & chain -> content);
}

void Insert() {
  printf("\n");

  auxiliar = root;

  if (root == NULL) {
    chain = (binaryTreeNode * ) malloc(sizeof(binaryTreeNode));
    root = chain;
    auxiliar = chain;
    auxiliar -> right = NULL;
    auxiliar -> left = NULL;
    EnterbinaryTreeNode();
  } else {

    auxiliar = root;
    chain = (binaryTreeNode * ) malloc(sizeof(binaryTreeNode));
    chain -> right = NULL;
    chain -> left = NULL;
    EnterbinaryTreeNode();

    if (chain -> content == root -> content) {
      printf("\n\nVALUE ALREADY INSERTED\n\n");
    }

    //lado direito
    if (chain -> content > root -> content) {

      if (auxiliar -> right == NULL) {
        auxiliar -> right = chain;
      } else {
        auxiliar = auxiliar -> right;
        RunTreeToInsert();
      }
    }

    //lado esquerdo
    if (chain -> content < root -> content) {

      if (auxiliar -> left == NULL) {
        auxiliar -> left = chain;
      } else {
        auxiliar = auxiliar -> left;
        RunTreeToInsert();
      }
    }
  }
}

void RunTreeToInsert() {
  while (linked == 0) {

    if ((chain -> content > auxiliar -> content) && (auxiliar -> right != NULL)) { //vai pra direita
      auxiliar = auxiliar -> right;
    }

    if ((chain -> content < auxiliar -> content) && (auxiliar -> left != NULL)) { //vai pra esquerda
      auxiliar = auxiliar -> left;
    }

    if ((chain -> content > auxiliar -> content) && (auxiliar -> right == NULL)) { //link pra direita
      auxiliar -> right = chain;
      linked = 1;
    }

    if ((chain -> content < auxiliar -> content) && (auxiliar -> left == NULL)) { //link pra esquerda
      auxiliar -> left = chain;
      linked = 1;
    }

    if (chain -> content == auxiliar -> content) {
      printf("\n\nVALUE ALREADY INSERTED\n\n");
      break;
    }

  }
  linked = 0;
}

void Search() {

  if (root == NULL) {
    printf("\n\nTREE IS EMPTY\n\n");
    return;
  }

  printf("\n\n\nNumber to search: ");
  scanf("%d", & search_value);

  auxiliar = root;
  printf("\n%d   ", auxiliar -> content);

  while (linked == 0) {

    break_looping = true;

    if (search_value == auxiliar -> content) {
      printf("\n\nCONTENT FOUND\n\n");
      break;
    }

    if ((search_value > auxiliar -> content) && (auxiliar -> right != NULL)) { //vai pra direita
      auxiliar = auxiliar -> right;
      printf("\n%i   ", auxiliar -> content);
      break_looping = false;
    }

    if ((search_value < auxiliar -> content) && (auxiliar -> left != NULL)) { //vai pra esquerda
      auxiliar = auxiliar -> left;
      printf("\n%i   ", auxiliar -> content);
      break_looping = false;
    }

    if (break_looping == true) {
      printf("\n\nCONTENT NOT FOUND\n\n");
      break;
    }

  }
  linked = 0;
}
