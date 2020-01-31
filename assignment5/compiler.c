/******************************************************
** Program: Mini Compiler
** Author: Megan Liles
** Date: 06/03/2017
** Description:
** Input: strings of brackets, braces and parenthesis
** Output: message
******************************************************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*********************************************************************
** Function: void check_input
** Description: checks the input of the user
** Parameters: char *input, struct list *l
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
**********************************************************************/
void check_input(char *input, struct list *l){
    int i=0;
    for(;i<strlen(input); i++)
        if(input[i]=='['){
            push_back(l, 0);
            print(l);
        }
        else if(input[i]=='{'){
            push_back(l, 1);
        }
        else if(input[i]=='('){
            push_back(l, 2);
        }
        else if(input[i]==']'){
            if(empty(l)==0 && pop_back(l)!=0){
                printf("Input Rejected ] \n");
                return;
            }
        }
        else if(input[i]=='}'){
            if(empty(l)==0 && pop_back(l)!=1){
                printf("Input Rejected } \n");
                return;
            }
        }
        else if(input[i]==')'){
            if(empty(l)==0 && pop_back(l)!=2){
                printf("Input Rejected ) \n");
                return;
            }
        }
        if(empty(l)!=0){
            printf("Error!");
            return;
        }
printf("Input Accepted!\n");
}
/*********************************************************************
** Function: void main
** Description: calls functions and creates list
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
**********************************************************************/
int main(){

    char *input;
    struct list *l= malloc(sizeof(struct list));
    init(l);
    input=malloc(sizeof(char)*256);
    int done=0;
    printf("Please enter your input:\n");
    fgets(input,256,stdin);
    check_input(input, l);
    delete(l);
    free(l);




    return 0;
}
