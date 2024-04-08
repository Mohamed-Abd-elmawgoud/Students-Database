#include "SDBAPP.h"
#include <stdio.h>
#include <stdlib.h>

uint8 should_exit  = 8 ;
uint32 list[10] ;
uint8 count_of_ids = 0 ;
uint32 id ;

void printList();

void SDB_APP()
{

    init();

    while(should_exit != 0)
    {
        printf("Options:\nPlease enter a single character or digit!!!\nTo add entry, enter 1\nTo get used size in database, enter 2\nTo read student data, enter 3\nTo get the list of all student IDs, enter 4\nTo check is ID is existed, enter 5\nTo delete student data, enter 6\nTo check is database is full, enter 7\nTo exit enter 0\ntype anything else to clear the console:\n ");
        scanf(" %c",&should_exit) ;
        SDB_action(should_exit);
    }
}


void SDB_action(uint8 choice)
{
    switch(choice)
    {
        case '0' : should_exit = 0;
        break ;


        case '1' : if(SDB_AddEntry()){printf("Entry added successfully.");}else{printf("Entry cannot be added");}break ;


        case '2' : printf("Used size: %d\n",SDB_GetUsedSize());break ;


        case '3' :
        printf("Enter the Id of the student: \n");
        scanf("%d",&id);
       if( SDB_ReadEntry(id)==0){printf("Id does not exist\n");}break;


        case '4' :
        SDB_GetList(&count_of_ids,list);
        printf("The list contains %d ids\n",count_of_ids);
        printList();

        break;


        case '5' :  printf("Enter the Id of the student: \n");
        scanf("%d",&id);
        (SDB_IsIdExit(id))?(printf("Id is valid!\n")):(printf("Id is not valid\n"));break;


        case '6' : printf("Enter the Id of the student: \n");
        scanf("%d",&id);
        SDB_DeleteEntry(id);break ;


        case '7' :(SDB_isFull())?(printf("The list is full\n")):(printf("The list is not full yet!\n"));break;

        default : ; break ;
    }
    if(should_exit > '7')
    {
        system("clear");
    }
}

void printList()
{
    uint32 i ;
    for(i=0 ;i < count_of_ids; i++)
    {
        SDB_ReadEntry(list[i]);
        printf("\n");
    }
}

