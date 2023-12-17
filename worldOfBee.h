#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>

#define SizeOfBeehive 10
#define NB_QUEEN 1
#define NB_WORKER 3
#define NB_GUARDIAN 2
#define NB_DRONE 2
#define NB_FORAGER 2


typedef struct Bee Bee;
typedef struct ListOfBee ListOfBee;
typedef struct Queen Queen;
typedef struct Drone Drone;
typedef struct Guardian Guardian;
typedef struct Worker Worker;
typedef struct Forager Forager;

struct Bee
{
    int iLifeTime;
    int iIdOfBee;
    int iNbQueens;
    
    Bee *next;
    Queen *queen;
    Guardian *guardian;
    Drone *drone;
    Worker *worker;
    Forager *forager;

};

struct ListOfBee
{
    Bee *first;
    int iNbOfBee;
};

struct Queen
{
    int iLifeTime;
    int iIdOfBee;
    int iNbQueens;
    Bee *next;
};

struct Guardian
{
    int iLifeTime;
    int iIdOfBee;
    int iNbQueens;
    Bee *next;
};

struct Drone
{
    int iLifeTime;
    int iIdOfBee;
    int iNbQueens;
    Bee *next;

};

struct Worker
{
    int iLifeTime;
    int iIdOfBee;
    int iNbQueens;
    Bee *next;
};

struct Forager
{
    int iLifeTime;
    int iIdOfBee;
    int iNbQueens;
    Bee *next;
};

ListOfBee *InitialisationListBee();
Bee *BirthOfBee ( ListOfBee *myList);
Bee *deathOfBee ( ListOfBee *myList, int idOfBee);
void displayBeehive ( ListOfBee *myList);
int creationOfBeehive ( ListOfBee *myList );
int deathOfTheQueen ( ListOfBee *myList, int yearOfBee);
int deathOfDrone ( ListOfBee *myList);
int deathOfWorker ( ListOfBee *myList);
int varroaDisability(ListOfBee *myList);
