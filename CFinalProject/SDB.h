#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED

#include "STD.h"
typedef struct SimpleDb student;
 struct SimpleDb
{
    uint32 Student_ID ;
    uint32 Student_year ;
    uint32 Course1_ID ;
    uint32 Course1_grade ;
    uint32 Course2_ID ;
    uint32 Course2_grade ;
    uint32 Course3_ID ;
    uint32 Course3_grade ;
    student *next ;
} ;

student* head ;

//Checks that the id entered by the user is valid.
Bool checkValidId(uint32 id);


//checks if the data base is full.
Bool SDB_isFull() ;

//Return how many students are in the database.
uint8 SDB_GetUsedSize() ;

//Add entry to the database and return true if the entry added correctly otherwise returns false.
Bool SDB_AddEntry();

//Delete the student data with the given Id.
void SDB_DeleteEntry(uint32 id);

//Print the data of the user with the given Id.
Bool SDB_ReadEntry (uint32 id);

//Returns the number of ids in the count variable and the ids in the array list.
void SDB_GetList(uint8 *count, uint32 *list);

//Checks if the id exists in the database.
Bool SDB_IsIdExit(uint32 id);

//Initializes the list of the students with 3 students.
void init();


#endif // SDB_H_INCLUDED
