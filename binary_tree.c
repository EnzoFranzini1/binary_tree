//Code tested in Linux Mint 19 and Windows. Both are working.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Structure to store the data
typedef struct data{
  struct data *right, *left;
  int content;
}data;

//Variable used to determine if a data structure has been linked to another data structure
//Variable used to store the value to be searched
int linked = 0, search_value;

//Variable to indicate if a search looping must be stopped
bool break_looping = true;

//Declaration of pointers that travel throught the tree to find and set values
struct data *auxiliar, *chain, *root;

int main()
{
  //Variable to store the choosen made by the user (insert, serach or quit)
  int op;

  //Pointer to set tree's start point
  root = NULL;

  //GoTo flag
  ini:

  printf("\n[1] - insert\n");
  printf("[2] - search\n");
  printf("[0] - close\n");

  printf("Choose an option: ");
  //Get the option provided by the user's input
  scanf("%i", &op);

  //Switch to the apropriate method choosed by the user
  switch(op){
    case 1:
    Insert(Insert);
    break;

    case 2:
    Search(Search);
    break;

    case 0:
    //Close the application
    return 0;
    break;
  }

  //Goes to the "ini" position
  goto ini;

  return 0;
}

//Method to insert in the structure the value of the content
Enterdata(){
  printf("\nNumber: ");
  //Set in the data structure a value
  scanf("%i", &chain -> content);
}

//Method to travel throught the tree and determine where the new data structure will be defined
Insert(data**List){
  printf ("\n");

  //Set the pointer in the beginning of the tree
  auxiliar = root;


  if(root == NULL){
    //This conditional is executed if the tree is empty
    chain = (data*)malloc(sizeof(data));
    //Set the root pointer in the first data structure
    root = chain;
    //Set the auxiliar pointer in the first data structure
    auxiliar = chain;
    //Define the root pointer links
    auxiliar -> right = NULL;
    auxiliar -> left = NULL;
    Enterdata();
  }else{

    //Set the auxiliar pointer in the beginning of the tree
    auxiliar = root;
    //Create a new data structure
    chain = (data*)malloc(sizeof(data));
    //Define his links
    chain -> right = NULL;
    chain -> left = NULL;
    Enterdata();

    //If the number inserted already exists in the root value
    if(chain -> content == root -> content){
      printf("\n\nAlready inserted\n\n");
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////right side of the tree///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(chain -> content > root -> content){

      if(auxiliar -> right == NULL){
        //Link the auxiliar pointer in the new structure data
        auxiliar -> right = chain;

      }else{
        //Conditional to start a looping until the auxiliar pointer reach a new possibility to link a new data structure
        auxiliar = auxiliar -> right;

        while(linked == 0){

          //Conditional to walk throught the structures
          if((chain -> content > auxiliar -> content) && (auxiliar -> right != NULL)){//goes right
            auxiliar = auxiliar -> right;
          }

          //Conditional to walk throught the structures
          if((chain -> content < auxiliar -> content) && (auxiliar -> left != NULL)){//goes left
            auxiliar = auxiliar -> left;
          }

          //Conditional to link the new structure by the right side of the previous structure
          if((chain -> content > auxiliar -> content) && (auxiliar -> right == NULL)){//link right
            auxiliar -> right = chain;
            linked = 1;
          }

          //Conditional to link the new structure by the left side of the previous structure
          if((chain -> content < auxiliar -> content) && (auxiliar -> left == NULL)){//link left
            auxiliar -> left = chain;
            linked = 1;
          }

          //If the number inserted by the user already exists
          if(chain -> content == auxiliar -> content){
            printf("\n\nAlready inserted\n\n");
            break;
          }

        } //While end
        linked = 0;
      }

    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////left side of the tree////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(chain -> content < root -> content){

      if(auxiliar -> left == NULL){
        //Link the auxiliar pointer in the new structure data
        auxiliar -> left = chain;
      }else{
        //Conditional to start a looping until the auxiliar pointer reach a new possibility to link a new data structure
        auxiliar = auxiliar -> left;

        while(linked == 0){

          //Conditional to walk throught the structures
          if((chain -> content > auxiliar -> content) && (auxiliar -> right != NULL)){//goes to right
            auxiliar = auxiliar -> right;
          }

          //Conditional to walk throught the structures
          if((chain -> content < auxiliar -> content) && (auxiliar -> left != NULL)){//goes to left
            auxiliar = auxiliar -> left;
          }

          //Conditional to link the new structure by the right side of the previous structure
          if((chain -> content > auxiliar -> content) && (auxiliar -> right == NULL)){//link right
            auxiliar -> right = chain;
            linked = 1;
          }

          //Conditional to link the new structure by the left side of the previous structure
          if((chain -> content < auxiliar -> content) && (auxiliar -> left == NULL)){//link left
            auxiliar -> left = chain;
            linked = 1;
          }

          //If the number inserted by the user already exists
          if(chain -> content == auxiliar -> content){
            printf("\n\nAlready inserted\n\n");
            break;
          }

        } //While end
        linked = 0;
      }

    }

  }
}

//Method to search in the tree a number inserted by the user
Search(data**List){

  printf("\n\n\nNumber to search: ");
  //Get the value to be searched
  scanf("%d", &search_value);
  //Restore the auxiliar to the beginning of the tree
  auxiliar = root;
  printf("\n%d   ", auxiliar -> content);

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////right side of the tree///////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////

  if(search_value > root -> content){

    //Looping to keep searching for the inserted number until find him, or reach the end of the tree
    while(linked == 0){

      //Variable to indicate if the looping must been broken
      break_looping = true;

      //If the number inserted match with a content's data structure
      if(search_value == auxiliar -> content){
        printf("\n\ncontent found\n\n");
        break;
      }

      //Goes to the right side of a data structure
      if((search_value > auxiliar -> content) && (auxiliar -> right != NULL)){//goes to the right
        auxiliar = auxiliar -> right;
        printf("\n%i   ", auxiliar -> content);
        //Continue to do the search looping
        break_looping = false;
      }

      //Goes to the left side of a data structure
      if((search_value < auxiliar -> content) && (auxiliar -> left != NULL)){//goes to the left
        auxiliar = auxiliar -> left;
        printf("\n%i   ", auxiliar -> content);
        //Continue to do the search looping
        break_looping = false;
      }

      //If the number inserted in the search was not found
      if(break_looping == true){
        printf("\n\ncontent not found\n\n");
        break;
      }

    } //While end
    linked = 0;
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////left side of the tree////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(search_value < root -> content){

    //Looping to keep searching for the inserted number until find him, or reach the end of the tree
    while(linked == 0){

      //Variable to indicate if the looping must been broken
      break_looping = true;

      //If the number inserted match with a content's data structure
      if(search_value == auxiliar -> content){
        printf("\n\ncontent found\n\n");
        break;
      }

      //Goes to the right side of a data structure
      if((search_value > auxiliar -> content) && (auxiliar -> right != NULL)){//goes to the right
        auxiliar = auxiliar -> right;
        printf("\n%i   ", auxiliar -> content);
        //Continue to do the search looping
        break_looping = false;
      }

      //Goes to the left side of a data structure
      if((search_value < auxiliar -> content) && (auxiliar -> left != NULL)){//goes to the left
        auxiliar = auxiliar -> left;
        printf("\n%i   ", auxiliar -> content);
        //Continue to do the search looping
        break_looping = false;
      }

      //If the number inserted in the search was not found
      if(break_looping == true){
        printf("\n\ncontent not found\n\n");
        break;
      }

    } //While end
    linked = 0;
  }

}
