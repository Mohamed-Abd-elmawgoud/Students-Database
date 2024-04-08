#include "SDB.h"
#include <stdlib.h>
#include <stdio.h>
uint32 size = 0 ; // size tracker for the database.



/*This function grab the list of ids that are already registered
and checks that the new id is not one of them.*/
Bool checkValidId(uint32 id)
{
    uint32 list[10]  ;
    uint8 count = 0;
    SDB_GetList(&count,list);


    //check if the new id exists already or not.
    int i ;
    for(i=0; i<size ;i++){
        if(id == list[i]){
            return 0 ;
        }
    }
    return 1 ;
}

//Compare the size variable with 10.
Bool SDB_isFull()
{
    return (size >= 10)?(1):(0);
}


//returns the size of the list that represents the used size.
uint8 SDB_GetUsedSize()
{
    return size ;
}

//This function is made to initialize the database with minimum of three students.
//This is done by allocating memory for the three students and linking them together through the (next) attribute in the student structure.
void init()
{
    student *student1 = (student*)malloc(sizeof(student));
    student *student2 = (student*)malloc(sizeof(student));
    student *student3 = (student*)malloc(sizeof(student));
    student1->next = student2 ;
    student2->next = student3 ;
    student3->next = NULL ;
    head = student1 ;

    student1->Student_ID = 1 ;
    student1->Student_year = 3 ;
    student1->Course1_ID = 101 ;
    student1->Course1_grade = 95 ;
    student1->Course2_ID = 102 ;
    student1->Course2_grade = 100;
    student1->Course3_ID = 103 ;
    student1->Course3_grade = 73 ;

    student2->Student_ID = 2 ;
    student2->Student_year = 3 ;
    student2->Course1_ID = 101 ;
    student2->Course1_grade = 95 ;
    student2->Course2_ID = 102 ;
    student2->Course2_grade = 100;
    student2->Course3_ID = 103 ;
    student2->Course3_grade = 73 ;

    student3->Student_ID = 3 ;
    student3->Student_year = 3 ;
    student3->Course1_ID = 101 ;
    student3->Course1_grade = 95 ;
    student3->Course2_ID = 102 ;
    student3->Course2_grade = 100;
    student3->Course3_ID = 103 ;
    student3->Course3_grade = 73 ;

    size += 3 ;
}

/*
This function adds a new student at the end of the structure.
This is done by allocating memory for the new student.
Then, we loop through the list using a current pointer until we reach the last element.
Then, we set the next attribute the last student to the new student.
Lastly, we increment the size by 1.
*/
Bool SDB_AddEntry()
{
    if(size >= 10)
    {
        return false ;
    }
    student *new_student = (student*)malloc(sizeof(student))  ;

    int cout = 0 ;
    do{
        printf((cout==0)?("Enter the student's Id: \n"):("This id is already taken.Please, enter a valid one: \n"));
        scanf("%d",& new_student->Student_ID);
        cout++ ;

    }while(checkValidId(new_student->Student_ID) == 0);




    printf("Enter the student's year: \n");
    scanf("%d",& new_student->Student_year);

    printf("Enter course 1 Id: \n");
    scanf("%d",&new_student->Course1_ID);

    printf("Enter course 1 grade: \n");
    scanf("%d",&new_student->Course1_grade);

    printf("Enter course 2 Id: \n");
    scanf("%d",&new_student->Course2_ID);

    printf("Enter course 2 grade: \n");
    scanf("%d",&new_student->Course2_grade);

    printf("Enter course 3 Id: \n");
    scanf("%d",&new_student->Course3_ID );

    printf("Enter course 3 grade: \n");
    scanf("%d",&new_student->Course3_grade);

    // This condition is not important anymore as the minimum size is 3.
    if(size == 0)
    {
        new_student->next = NULL ;
        head = new_student ;
    }else{

    student *current = head ;
    while(current->next != NULL){
        current = current->next ;
    }

    current->next = new_student ;
    }
    size++ ;
    return true ;
}

/*
This function deletes the desired entry by looping through the list until we reach the element before the element that we want to remove
and assign a temp pointer to the desired entry so we can assign the next attribute of the element before the desired entry to the one after the
desired entry and then free the memory of that element.
Then, we decrement the size by 1.
*/
void SDB_DeleteEntry(uint32 id)
{
    if(size <= 3){
        printf("Cannot delete the entry!!");
        return ;
    }
    student *current = head ;
    student *temp = NULL;
    while( current->next != NULL)
    {
        if(current->next->Student_ID == id){
            temp = current->next;
            break ;
        }
        current = current->next ;
    }
    //this condition is not important as the size of the database is never zero.
    if(size>1){
    current->next = temp->next ;
     temp->next = NULL ;
     free(temp);
    }else{
        head = NULL ;
    }
    size-- ;
}

/*
This function works by looping through the list until we reach the student with the given id.
and we print the information of that student.
*/
Bool SDB_ReadEntry (uint32 id)
{
    student *current = head ;
    while(current!= NULL)
    {
        if(current->Student_ID == id)
            break ;
        current = current->next ;
    }
    if(current == NULL)
        return 0 ;

    printf("Student id = %d\nStudent year = %d\nCourse 1 id = %d\nCourse 1 grade = %d\nCourse 2 id = %d\nCourse 2 grade = %d\nCourse 3 id = %d\nCourse 3 grade = %d\n",current->Student_ID,
           current->Student_year,current->Course1_ID,current->Course1_grade,current->Course2_ID,current->Course2_grade,current->Course3_ID,current->Course3_grade) ;
    return 1 ;
}
/*
We return the number of ids in the count pointer by assigning the value inside it to the size of the list.
Then we loop through the list and copy the ids of students in the given array.
*/
void SDB_GetList(uint8 *count, uint32 *list)
{

    *count = size ;
    student *current = head ;
    uint32 i = 0 ;
    while(current != NULL)
    {
        list[i] = current->Student_ID ;
        current = current->next ;
        i++ ;
    }

}

/*
We loop through the list until we find the student with the given id a d return 1
or the id id not in the list and then we return 0.
*/
Bool SDB_IsIdExit(uint32 id)
{
    student *current = head ;
    while(current != NULL)
    {
        if(current->Student_ID == id)
            return 1;
        current = current->next ;
    }

    return 0 ;
}




