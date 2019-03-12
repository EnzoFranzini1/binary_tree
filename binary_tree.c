//Code tested in Linux Mint 19 and Windows. Both worked.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//structure to store the data
typedef struct data{
  struct data *right, *left;
  int content;
}data;

int linked = 0, search_value;
bool break_looping = true;

struct data *auxiliar, *chain, *root;

int main()
{
  int op;
  root = NULL;

  ini:

  printf("\n[1] - insert\n");
  printf("[2] - search\n");
  printf("[0] - close\n");

  printf("Choose an option: ");
  scanf("%i", &op);

  switch(op){
    case 1:
    Insert(Insert);
    break;

    case 2:
    Search(Search);
    break;

    case 0:
    system("clear");
    return 0;
    break;
  }

  goto ini;

  return 0;
}

Enterdata(){
  printf("\nNumber: ");
  scanf("%i", &chain -> content);
}

Insert(data**List){
  printf ("\n");
  auxiliar = root;

  if(root == NULL){
    chain = (data*)malloc(sizeof(data));
    root = chain;
    auxiliar = chain;
    auxiliar -> right = NULL;
    auxiliar -> left = NULL;
    Enterdata();
  }else{

    auxiliar = root;
    chain = (data*)malloc(sizeof(data));
    chain -> right = NULL;
    chain -> left = NULL;
    Enterdata();

    if(chain -> content == root -> content){
      printf("\n\nAlready inserted\n\n");
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////right side///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(chain -> content > root -> content){

      if(auxiliar -> right == NULL){
        auxiliar -> right = chain;

      }else{
        auxiliar = auxiliar -> right;

        while(linked == 0){

          if((chain -> content > auxiliar -> content) && (auxiliar -> right != NULL)){//goes right
            auxiliar = auxiliar -> right;
          }

          if((chain -> content < auxiliar -> content) && (auxiliar -> left != NULL)){//goes left
            auxiliar = auxiliar -> left;
          }

          if((chain -> content > auxiliar -> content) && (auxiliar -> right == NULL)){//link right
            auxiliar -> right = chain;
            linked = 1;
          }

          if((chain -> content < auxiliar -> content) && (auxiliar -> left == NULL)){//link left
            auxiliar -> left = chain;
            linked = 1;
          }

          if(chain -> content == auxiliar -> content){
            printf("\n\nAlready inserted\n\n");
            break;
          }

        } //while end
        linked = 0;
      }

    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////left side////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(chain -> content < root -> content){

      if(auxiliar -> left == NULL){
        auxiliar -> left = chain;
      }else{
        auxiliar = auxiliar -> left;

        while(linked == 0){

          if((chain -> content > auxiliar -> content) && (auxiliar -> right != NULL)){//goes to right
            auxiliar = auxiliar -> right;
          }

          if((chain -> content < auxiliar -> content) && (auxiliar -> left != NULL)){//goes to left
            auxiliar = auxiliar -> left;
          }


          if((chain -> content > auxiliar -> content) && (auxiliar -> right == NULL)){//link right
            auxiliar -> right = chain;
            linked = 1;
          }
          if((chain -> content < auxiliar -> content) && (auxiliar -> left == NULL)){//link left
            auxiliar -> left = chain;
            linked = 1;
          }

          if(chain -> content == auxiliar -> content){
            printf("\n\nAlready inserted\n\n");
            break;
          }

        } //while end
        linked = 0;
      }

    }

  }
}

Search(data**List){

  printf("\n\n\nNumber to search: ");
  scanf("%d", &search_value);
  auxiliar = root;
  printf("\n%d   ", auxiliar -> content);

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////right///////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////

  if(search_value > root -> content){//VAI PARA A right

    while(linked == 0){

      break_looping = true;

      if(search_value == auxiliar -> content){
        printf("\n\ncontent found\n\n");
        break;
      }

      if((search_value > auxiliar -> content) && (auxiliar -> right != NULL)){//goes to the right
        auxiliar = auxiliar -> right;
        printf("\n%i   ", auxiliar -> content);
        break_looping = false;
      }

      if((search_value < auxiliar -> content) && (auxiliar -> left != NULL)){//goes to the left
        auxiliar = auxiliar -> left;
        printf("\n%i   ", auxiliar -> content);
        break_looping = false;
      }

      if(break_looping == true){
        printf("\n\ncontent not found\n\n");
        break;
      }

    } //while end
    linked = 0;
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////left////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(search_value < root -> content){

    while(linked == 0){

      break_looping = true;

      if(search_value == auxiliar -> content){
        printf("\n\ncontent found\n\n");
        break;
      }

      if((search_value > auxiliar -> content) && (auxiliar -> right != NULL)){//goes to the right
        auxiliar = auxiliar -> right;
        printf("\n%i   ", auxiliar -> content);
        break_looping = false;
      }

      if((search_value < auxiliar -> content) && (auxiliar -> left != NULL)){//goes to the left
        auxiliar = auxiliar -> left;
        printf("\n%i   ", auxiliar -> content);
        break_looping = false;
      }

      if(break_looping == true){
        printf("\n\ncontent not found\n\n");
        break;
      }

    } //while end
    linked = 0;
  }

}
