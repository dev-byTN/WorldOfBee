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
    myList->iNbOfBee =0;
    return myList;
}

int creationOfBeehive ( ListOfBee *myList ) // ceration de la ruche avec 10 abeilles
{
    int i;
    
    if ( myList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for ( i = 0; i < SizeOfBeehive; i ++) 
    {
        Bee *creationOfBee = malloc(sizeof(*creationOfBee));
        creationOfBee->iIdOfBee = SizeOfBeehive - i;
        creationOfBee->iLifeTime = 0;
        creationOfBee->next = myList->first;
        myList->first = creationOfBee;
        myList->iNbOfBee ++;
    }

   
}


Bee *BirthofBee(ListOfBee *myList) // chaque abeilles qui naissent apparaitront à la fin de la liste ( ruche)
{

    Bee *newBee = malloc(sizeof(*newBee));
    Bee *temp = myList->first;

    //newBee->iIdOfBee = myList->iNbOfBee;
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
        //if ( temp->iIdOfBee == idOfBee )
        {
            previoustemp->next = temp->next;
            free(temp);
        }
        previoustemp = temp;
        temp = temp->next;
    }
    return BirthofBee(myList);
    
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
        //if ( queen->IYearOfBee == yearOfBee )
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
        printf("%d ", temp->iIdOfBee);
        //printf("%d", temp->queen);
        temp = temp->next;
        printf(" -> ");
    }
    printf("NULL\n");
}


int deathOfDrone ( ListOfBee *myList)
{
    Bee *deathBee = myList->first;
    if ( myList == NULL )
    {
        exit (EXIT_FAILURE);
    }

    while ( deathBee != NULL)
    {
        if ( deathBee->drone->iLifeTime == 14 )
        {
           // return deathOfBee(myList, deathBee->drone->iIdOfBee);
        }
        else deathBee = deathBee->next;
    }
}

int deathOfWorker ( ListOfBee *myList)
{
    Bee *deathBee = myList->first;
    if ( myList == NULL )
    {
        exit (EXIT_FAILURE);
    }

    while ( deathBee != NULL)
    {
        if ( deathBee->worker->iLifeTime == 20 )
        {
            //deathBee->worker = deathBee->forager;
        }
        else deathBee = deathBee->next;
    }
}


int createQueens( ListOfBee *myList, int numQueens) 
{

    if (myList == NULL) {
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < numQueens; i++) 
    {
        Bee *creationOfBee = malloc(sizeof(*creationOfBee));

        if (creationOfBee == NULL) 
        {
            exit (EXIT_FAILURE);
        }

        creationOfBee->queen = malloc(sizeof(Queen));

        if (creationOfBee->queen == NULL) {
            free(creationOfBee); // Libération de la mémoire si l'allocation échoue
            return -1; // Gestion d'erreur : échec de l'allocation mémoire
        }

        creationOfBee->queen->iLifeTime = 0;
        creationOfBee->queen->iIdOfBee = i;
        creationOfBee->queen->next = myList->first;

        /*Initialisation des autres pointeurs à NULL
        creationOfBee->next = NULL;
        creationOfBee->guardian = NULL;
        creationOfBee->drone = NULL;
        creationOfBee->worker = NULL;
        creationOfBee->forager = NULL;*/

        myList->first = creationOfBee;
        myList->iNbOfBee++;
    }

    return 0; 
}

int createDrone( ListOfBee *myList, int numDrone) 
{

    if (myList == NULL) {
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < numDrone; i++) 
    {
        Bee *creationOfBee = malloc(sizeof(*creationOfBee));

        if (creationOfBee == NULL) 
        {
            exit (EXIT_FAILURE);
        }

        creationOfBee->drone = malloc(sizeof(Drone));

        if (creationOfBee->drone == NULL) {
            free(creationOfBee); 
            exit(EXIT_FAILURE); 
        }

        creationOfBee->drone->iLifeTime = 0;
        creationOfBee->drone->iIdOfBee = i;
        creationOfBee->drone->next = myList->first;

        myList->first = creationOfBee;
        myList->iNbOfBee++;
    }

    return 0; 
}
