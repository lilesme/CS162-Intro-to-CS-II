/******************************************************
** Program: test_queue.c
** Author: Megan Liles
** Date: 06/03/2017
** Description: Resturant comparison of queues
** Input: command line arguments
** Output: times of comparison
******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"
/*********************************************************************
** Function: void print info
** Description: prints info about lists
** Parameters:
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
void print_info(struct list **array, struct list *l, int s){
    int queue=1;
    int i=0;
    for(i=0; i<s; i++){
        int people=size(array[i]);
        printf("\n");
        printf("Self-Select queues have: \n");
        printf("%d ", people);
        printf("people in queue " );
        printf("%d\n", queue);
        printf("\n");
        queue++;
    }
    printf("One queue, Self-Select first available: \n");
    int people=size(l);
    printf("%d", people);
    printf(" people remaining in queue \n");
    printf("\n");
}
/*********************************************************************
** Function: void begin_1
** Description: calls push_front for the 1 hour
** Parameters: struct list *array, struck list *l
** Pre-Conditions: none
** Post-Conditions: things in the list
** Return: none
*********************************************************************/
void begin_1(struct list **array, struct list *l, int arrival_time, int start_time, int end_time, int size){
    //1 hr, one line
    int elapsed=0;
    int total=0;
    printf("1 hour: \n");
    int time_served=0;
    int i=0;
    for(i=0; i<60; i++){
        if(i%arrival_time==0){
            time_served=rand()% (start_time-end_time)+ start_time;
            elapsed= elapsed+time_served;
            total= elapsed+time_served;
            push_front(l, total);
        }
        if(back(l)==total){
            pop_back(l);
        }
    }
    //1 hr, multiple lines
    time_served=0;
    total=0;
    elapsed=0;
    for(i=0; i<60; i++){
        int x=0;
        for(x=0; x<size; x++){
            if(i%arrival_time==0){
                time_served=rand()%(end_time-start_time) + start_time;
                elapsed= elapsed+time_served;
                total= elapsed+time_served;
                push_front(l, total);
            }
            if(back(array[x])==i){
                pop_back(array[x]);
            }
        }
    }
    print_info(array, l, size);
    int x=0;
    for(x=0; x<size; x++){
        delete(array[x]);
    }
    delete(l);
}
/*********************************************************************
** Function: void begin_2
** Description: calls push_front for the 5 hours
** Parameters: struct list *array, struck list *l
** Pre-Conditions: none
** Post-Conditions: things in the list
** Return: none
*********************************************************************/
void begin_2(struct list **array, struct list *l, int arrival_time, int start_time, int end_time, int size){
    //5 hrs, one line
    int elapsed=0;
    int total=0;
    printf("5 hours: \n");
    int time_served=0;
    int i=0;
    for(i=0; i<300; i++){
        if(i%arrival_time==0){
            time_served=rand()%(end_time-start_time) + start_time;
            end_time= i+time_served;
            push_front(l, end_time);
        }
        if(back(l)==i){
            pop_back(l);
        }
    }
    //5 hrs, multiple lines
    time_served=0;
    total=0;
    elapsed=0;
    for(i=0; i<300; i++){
        int x=0;
        for(x=0; x<size; x++){
            if(i%arrival_time==0){
                time_served=rand()%(end_time-start_time) + start_time;
                elapsed= elapsed+time_served;
                total= elapsed+time_served;
                push_front(l, total);
            }
            if(back(array[x])==i){
                pop_back(array[x]);
            }
        }
    }
    print_info(array, l, size);
    int x=0;
    for(x=0; x<size; x++){
        delete(array[x]);
    }
    delete(l);
}
/*********************************************************************
** Function: void begin_3
** Description: calls push_front for the 10hr
** Parameters: struct list *array, struck list *l
** Pre-Conditions: none
** Post-Conditions: things in the list
** Return: none
*********************************************************************/
void begin_3(struct list **array, struct list *l, int arrival_time, int start_time, int end_time, int size){
    //10 hrs, one line
    int elapsed=0;
    int total=0;
    printf("10 hours: \n");
    int time_served=0;
    int i=0;
    for(i=0; i<600; i++){
        if(i%arrival_time==0){
            time_served=rand()%(end_time-start_time) + start_time;
            end_time= i+time_served;
            push_front(l, end_time);
        }
        if(back(l)==i){
            pop_back(l);
        }
    }
    //10 hrs, multiple lines
    time_served=0;
    total=0;
    elapsed=0;
    for(i=0; i<600; i++){
        int x=0;
        for(x=0; x<size; x++){
            if(i%arrival_time==0){
                time_served=rand()%(end_time-start_time) + start_time;
                elapsed= elapsed+time_served;
                total= elapsed+time_served;
                push_front(l, total);
            }
            if(back(array[x])==i){
                pop_back(array[x]);
            }
        }
    }
    print_info(array, l, size);
    int x=0;
    for(x=0; x<size; x++){
        delete(array[x]);
    }
    delete(l);
}
/*********************************************************************
** Function: void make_lists
** Description: makes the lists
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: list is made
** Return: none
*********************************************************************/
void make_lists(int size, int arrival_time, int start_time, int end_time, int round){
    //make array of linked list for multiple lines
    struct list **array= (struct list**)malloc(sizeof(struct list));
    int i=0;
    for(i=0; i<size; i++){
        array[i]= malloc(sizeof(struct list));
        init(array[i]);
    }
    //make one linked list for one line
    struct list *l= malloc(sizeof(struct list));
    init(l);
    if(round==1){
        begin_1(array, l, arrival_time, start_time, end_time, size);
    }
    else if(round==2){
        begin_2(array, l, arrival_time, start_time, end_time, size);
    }
    else if(round==3){
        begin_3(array, l, arrival_time, start_time, end_time, size);
    }
}
/*********************************************************************
** Function: int main
** Description: calls functions
** Parameters: int argc, char *argc[]
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
int main(int argc, char *argv[]){
    int i=0, size=0, start_time=0, end_time=0, arrival_time=0;

    for(i=0; i<argc; i++){
        if(strcmp(argv[i], "-n")==0){
            size=atoi(argv[i+1]);
            printf("size: %d\n", size);
        }
        else if(strcmp(argv[i], "-s")==0){
            start_time=atoi(argv[i+1]);
            printf("start_time: %d\n", start_time);
        }
        else if(strcmp(argv[i], "-e")==0){
            end_time=atoi(argv[i+1]);
            printf("end_time: %d\n", end_time);
        }
        else if(strcmp(argv[i], "-c")==0){
            arrival_time=atoi(argv[i+1]);
            printf("arrival_time: %d\n", arrival_time);
        }
    }
    printf("\n");
    int round=1;
    make_lists(size, arrival_time, start_time, end_time, round);
    round =2;
    make_lists(size, arrival_time, start_time, end_time, round);
    round =3;
    make_lists(size, arrival_time, start_time, end_time, round);





    return 0;
}
