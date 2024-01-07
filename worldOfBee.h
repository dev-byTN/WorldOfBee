#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>

#define QUEEN_LIFETIME 60
#define FORAGER_LIFETIME 5
#define DRONE_LIFETIME 7
#define GUARDIAN_LIFETIME 10
#define NB_GUARDIAN 10
#define NB_DRONE 10
#define NB_FORAGER 15
#define WINDOW_W 800
#define WINDOW_H 800
#define PRECISION 0.001
#define PI 3.14


typedef struct Bee Bee;
typedef struct ListOfBee ListOfBee;
typedef struct Queen Queen;
typedef struct Drone Drone;
typedef struct Guardian Guardian;
typedef struct Forager Forager;

struct Bee
{   
    Bee *next;
    Queen *queen;
    Guardian *guardian;
    Drone *drone;
    Forager *forager;
};

struct ListOfBee
{
    Bee *first;
    float fAmoutOfHoney;
};

struct Queen
{
    int iIdOfBee;
    int iNbQueens;
    SDL_Rect *rect;
    Bee *next;
};

struct Guardian
{
    int iIdOfBee;
    int iNbGuardians;
    SDL_Rect *rect;
    Bee *next;
};

struct Drone
{
    int iIdOfBee;
    int iNbDrones;
    SDL_Rect *rect;
    Bee *next;

};

struct Forager
{
    int iIdOfBee;
    int iNbForagers;
    SDL_Rect *rect;
    Bee *next;
};


#ifndef WORLDOFBEE_H_INCLUDED
#define WORLDOFBEE_H_INCLUDED

ListOfBee *InitialisationListBee();
SDL_Window *CreateWindow ();
SDL_Renderer *displayWorld();
void displayBeehive ( ListOfBee *myList, ListOfBee *myList2, ListOfBee *myList3, ListOfBee *myList4, int iHoney);
int deathOfDrone ( ListOfBee *myList);
int deathOfForager ( ListOfBee *myList);
int deathOfGuardian ( ListOfBee *myList); 
int deathOfQueen ( ListOfBee *myList); 
int createGuardians( ListOfBee *myList, int numOfGuardians);
int createQueen( ListOfBee *myList); 
int createForagers( ListOfBee *myList, int numOfForagers);
int createDrones (ListOfBee *myList, int numOfDrone);
int showDroneAndForager ( int nbForager, int nbDrone, SDL_Renderer *renderer);
int showQueen ( ListOfBee *mylist, SDL_Renderer *renderer);
int showGuardians( ListOfBee *myList, int numOfGuardians, SDL_Renderer* renderer);
int freeForager ( ListOfBee *myList);
int freeGuardian ( ListOfBee *myList);
int freeDrone ( ListOfBee *myList);
int freeQueen ( ListOfBee *myList);
int runTheWorld ();

#endif