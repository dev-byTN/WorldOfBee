#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SizeOfBeehive 10


typedef struct Bee Bee;
typedef struct ListOfBee ListOfBee;
typedef struct Queen Queen;
typedef struct Drone Drone;
typedef struct Guardian Guardian;
typedef struct Worker Worker;
typedef struct Seasons Seasons;

struct Bee
{
    int iIdOfBee;
    int IYearOfBee;
    char cTypeOfBee[10];
    Bee *next;
    Queen *queen;
    Guardian *guardian;
    Drone *drone;

};

struct ListOfBee
{
    Bee *first;
    int iNbOfBee;
};

struct Queen
{
    int iLifeTime;

};

struct Guardian
{
    int iLifeTime;

};

struct Drone
{
    int iLifeTime;

};


ListOfBee *InitialisationListBee();
Bee *BirthOfBee ( ListOfBee *myList);
Bee *deathOfBee ( ListOfBee *myList, int idOfBee);
void displayBeehive ( ListOfBee *myList);
int creationOfBeehive ( ListOfBee *myList );