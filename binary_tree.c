#include <stdio.h>
#include <stdlib.h>

//structure to store the data
typedef struct data{
  struct data *right, *left;
  int content;
}data;

int linked =0;

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
