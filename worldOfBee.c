#include "worldOfBee.h"

ListOfBee *InitialisationListBee()
{
    ListOfBee *myList = malloc(sizeof(*myList));
    //Bee *newBee = malloc(sizeof(*newBee));

    if ( myList == NULL )
    {
        exit(EXIT_FAILURE);
    }

    
    myList->first = NULL;
    myList->iNbOfBee ++;
    return myList;
}

int creationOfBeehive ( ListOfBee *myList ) // ceration de la ruche avec 10 abeilles
{
    

    if ( myList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for ( int i = 0; i < SizeOfBeehive; i ++)
    {
        Bee *creationOfBee = malloc(sizeof(*creationOfBee));
        creationOfBee->iIdOfBee = SizeOfBeehive - i;
        creationOfBee->next = myList->first;
        myList->first = creationOfBee;
        myList->iNbOfBee ++;
    }
}


Bee *BirthofBee(ListOfBee *myList) // chaque abeilles qui naissent apparaitront à la fin de la liste ( ruche)
{

    Bee *newBee = malloc(sizeof(*newBee));
    Bee *temp = myList->first;

    newBee->iIdOfBee = myList->iNbOfBee;
    newBee->next = NULL;

    if (myList == NULL )
    {
        return newBee;
    }
    
    while( temp->next != NULL )
    {
        temp = temp->next;
    }
    
    temp->next = newBee;
    myList->iNbOfBee ++; // on va assigné des id qui se suivent dans la liste chainée
    return newBee;
    
}


Bee *deathOfBee ( ListOfBee *myList, int idOfBee)
{
    Bee *temp = myList->first;
    Bee *previoustemp = myList->first;

    if ( myList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (temp->next != NULL )
    {
        if ( temp->iIdOfBee == idOfBee )
        {
            previoustemp->next = temp->next;
            free(temp);
        }
        previoustemp = temp;
        temp = temp->next;
    }
    BirthofBee(myList);
    
}


int deathOfTheQueen ( ListOfBee *myList, int yearOfBee)
{
    Bee *queen = myList->first;

    if ( myList == NULL )
    {
        exit(EXIT_FAILURE);
    }

    while ( queen != NULL)
    {
        if ( queen->IYearOfBee == yearOfBee )
        {
            
        }
    }
}

void displayBeehive ( ListOfBee *myList)
{
    Bee *temp = myList->first;

    if ( temp == NULL )
    {
        exit(EXIT_FAILURE);
    }

    while ( temp != NULL )
    {
        printf("%d", temp->iIdOfBee);
        //printf("%d", temp->queen);
        temp = temp->next;
        printf(" -> ");
    }
    printf("NULL\n");
}