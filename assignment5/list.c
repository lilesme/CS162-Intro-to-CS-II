#include <stdio.h>
#include "list.h"
/*********************************************************************
** Function: void init
** Description: initialize empty list
** Parameters: struct list* l
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void init(struct list *l){
//initialize empty list
    l->head=NULL;
    l->tail=NULL;
}
/*********************************************************************
** Function:int size
** Description: return number of nodes in list
** Parameters: struct list *l
** Pre-Conditions: none
** Post-Conditions: none
** Return: size
*********************************************************************/
int size(struct list *l){
//return number of nodes in list
    node *counter= l->head;
    int size=0;
    while(counter!=NULL){
        counter=counter->next;
        size++;
    }
    return size;
}
/*********************************************************************
** Function: void print
** Description: prints the values in the list
** Parameters: struct list *l
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void print(struct list *l){
//print the values in list
    node* current=l->head;
    while(current->next != NULL){
        printf("%d\n",current->val);
        current=current->next;
    }
}
/*********************************************************************
** Function: void push-front
** Description: push to front of list/adds new node to front
** Parameters: struct list *l, int newvalue
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void push_front(struct list *l, int new_value){
//push to front of list/add to front
    struct node* new_node= malloc(sizeof(struct node));
    new_node->val=new_value;
    new_node->next=l->head;
    l->head=new_node;
}
/*********************************************************************
** Function: void push_back
** Description: push to end/ adds new node to end
** Parameters: struct list *l, int new_value
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void push_back(struct list *l, int new_value){
//push to end of list/add to end
    struct node *new_node= (struct node*)malloc(sizeof(struct node));
    new_node->val=new_value;
    new_node->next=NULL;
    if(l->head==NULL){
        l->tail=new_node;
        l->head=l->tail;
    }
    if(l->tail != NULL){
        l->tail->next=new_node;
        l->tail=l->tail->next;
    }

}
/*********************************************************************
** Function: int front
** Description: returns value at the front of the list
** Parameters: struct list *l
** Pre-Conditions: none
** Post-Conditions: none
** Return: value
*********************************************************************/
int front(struct list *l){
//returns value at the front of the list
    int value= l->head->val;
    return value;
}
/*********************************************************************
** Function: int back
** Description: returns value at the back of the list
** Parameters: struct list *l
** Pre-Conditions: none
** Post-Conditions: none
** Return: value
*********************************************************************/
int back(struct list *l){
//returns value at the back of the list
    if(l->tail==NULL){
        return 0;
    }
    else{
        int value=l->tail->val;
        return value;
    }
}
/*********************************************************************
** Function: int pop_back
** Description: removes a node from the back of the list
** Parameters: struct list *l
** Pre-Conditions: none
** Post-Conditions: none
** Return: head
*********************************************************************/
int pop_back(struct list *l){
//remove node from back and return value
//DOESNT WORK RIGHT NOW

    int value=0;
    if(l->tail==NULL){
        return 0;
    }
    node *current = l->head;

        if(l->head != l->tail){
            while(current->next != l->tail){
                current= current->next;
            }
            l->tail=current;
            value=current->next->val;
            current->next=NULL;
            free(current->next);
        }
        else{
            value=l->tail->val;
            free(l->head);
            current=NULL;
            l->head=NULL;
            l->tail=NULL;
        }
    return value;
    }

/*********************************************************************
** Function: int remove_front
** Description: remove node from front and return value int empty(struct list); //returns true if list is empty
** Parameters:struct list *l
** Pre-Conditions: none
** Post-Conditions: none
** Return: value
*********************************************************************/
int remove_front(struct list *l){
//remove node from front and return value int empty(struct list); //returns true if list is empty
int value=0;
    if(l->head==NULL){
        return 0;
    }
    node* current=l->head;
    value=l->head->val;
    l->head=current->next;
    free(current);
    return value;

}
/*********************************************************************
** Function: void delete
** Description: removes all the nodes from a list
** Parameters: struck list *l
** Pre-Conditions: none
** Post-Conditions: list is gone
** Return: none
*********************************************************************/
void delete(struct list *l){
//remove all nodes from list
    node *current, *temp;
    if(l->head != NULL){
        current=l->head->next;
        l->head->next=NULL;
        while(current != NULL){
            temp=current->next;
            free(current);
            current=temp;
        }
    }
}
/*********************************************************************
** Function: int empty
** Description: //returns true if list is empty
** Parameters: struck list *l
** Pre-Conditions: none
** Post-Conditions: list is gone
** Return: 0
*********************************************************************/
int empty(struct list *l){  //returns true if list is empty
    if(l==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
