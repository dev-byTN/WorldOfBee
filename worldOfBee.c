#include "worldOfBee.h"


ListOfBee *InitialisationListBee()
{
    ListOfBee *myList = malloc(sizeof(*myList));

    if ( myList == NULL )
    {
        exit(EXIT_FAILURE);
    }
   
    myList->first = NULL;
    myList->fAmoutOfHoney = 0;
    return myList;
}


SDL_Window *CreateWindow ()
{
    SDL_Window *windoww;
    if(SDL_VideoInit(NULL) < 0) // SDL initialisation
    {
        printf("Erreur d'initialisation de la SDL : %s\n",SDL_GetError());
        exit (EXIT_FAILURE);
    }

    // window creation
    windoww = SDL_CreateWindow("SDL" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , WINDOW_W , WINDOW_H , 0);
    if(windoww == NULL) 
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        exit (EXIT_FAILURE);
    }

    return windoww;
}


SDL_Renderer *displayWorld()
{
    SDL_Renderer *renderer;
    SDL_Window *window = CreateWindow();
    SDL_Color black = {0, 0, 0, 0};
    int xCircle = 400;   // x
    int yCircle = 200;  // y
    int radius = 150;  // radius
    int xCoordinate = 0;
    int yCoordinate = 0;

    //creation of Renderer
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    if ( renderer == NULL)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        exit (EXIT_FAILURE);
    }

    //put black background ( BLACK )
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    if(0 != SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, black.a))
    {
        fprintf(stderr, "Erreur SDL_SetRendererDrawColor : %s", SDL_GetError());
        exit (EXIT_FAILURE);
    }

    SDL_RenderClear(renderer);
    if(0 != SDL_RenderClear(renderer))
    {
        fprintf(stderr, "Erreur SDL_RendererClear : %s", SDL_GetError());
        exit (EXIT_FAILURE);
    }

    // creation of beehive ( YELLOW CIRCLE )
    SDL_SetRenderDrawColor(renderer, 255,255,0,255);

    for (double i = 0.0; i < 360; i += PRECISION) // x = xcenter + rcos(pi)  y = ycenter + sin(pi)
    {
        xCoordinate = xCircle + radius * cos(i * PI / 180);  // deg to rad
        yCoordinate = yCircle - radius * sin(i * PI / 180); // deg to rad
        SDL_RenderDrawPoint(renderer, xCoordinate, yCoordinate);
    }

    // we show
    SDL_RenderPresent(renderer);

    return renderer;
}


void displayBeehive ( ListOfBee *myList, ListOfBee *myList2, ListOfBee *myList3, ListOfBee *myList4, int iHoney)
{
    Bee *temp = myList->first;
    Bee *temp2 = myList2->first;
    Bee *temp3 = myList3->first;
    Bee *temp4 = myList4->first;

    if ( temp == NULL )
    {
        exit(EXIT_FAILURE);
    }
    // we show the list for ( same for the 4 types of bees)
    printf("Queen: ");
    while ( temp != NULL )
    {
        printf("Q%d", temp->queen->iIdOfBee);
        temp = temp->queen->next;
        printf(" -> ");
    }
    printf("NULL\n");

    printf("Foragers: ");
    while ( temp2 != NULL )
    {
        printf("F%d", temp2->forager->iIdOfBee);
        temp2 = temp2->forager->next;
        printf(" -> ");
    }
    printf("NULL\n");

    printf("Drones: ");
    while ( temp3 != NULL )
    {
        printf("D%d", temp3->drone->iIdOfBee);
        temp3 = temp3->drone->next;
        printf(" -> ");
    }
    printf("NULL\n");

    printf("Guardians: ");
    while ( temp4 != NULL )
    {
        printf("G%d", temp4->guardian->iIdOfBee);
        temp4 = temp4->guardian->next;
        printf(" -> ");
    }
    printf("NULL\n");
    printf("Honey: %dg\n",iHoney);
    printf("\n");
}


int createGuardians( ListOfBee *myList, int numOfGuardians) //Linked-Stack
{
    static int ID = 0;

    if (myList == NULL) {
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < numOfGuardians; i++ ) 
    {
        Bee *creationOfBee = malloc(sizeof(Bee)); // allocate memory struct 1

        if (creationOfBee == NULL) 
        {
            exit (EXIT_FAILURE);
        }

        creationOfBee->guardian = malloc(sizeof(Guardian)); // allocate memory struct 2
        if (creationOfBee->guardian == NULL) 
        {
            free(creationOfBee);  // free memory 1 struct
            exit (EXIT_FAILURE); // we out
        }

        creationOfBee->guardian->rect = malloc(sizeof(SDL_Rect)); // allocate memory struct 3
        if (creationOfBee->guardian->rect == NULL) 
        {
            free(creationOfBee->guardian); // free memory struct 2
            free(creationOfBee);  // free memory struct 1
            exit (EXIT_FAILURE); // we out
        }

        // Push-Stack (empile en tête)
        creationOfBee->guardian->iIdOfBee = ID;
        creationOfBee->guardian->next = myList->first;
        myList->first = creationOfBee;
        ID++;
    }
    
    return 0; 
}



int showGuardians( ListOfBee *myList, int numOfGuardians, SDL_Renderer* renderer) //Linked-Stack
{
    static int ID = 0;
    if(renderer == NULL)
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    
    if (myList == NULL) {
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < numOfGuardians; i++ ) 
    {
        SDL_SetRenderDrawColor(renderer, 255,0,255,255); // PINK COLOR
        Bee *creationOfBee = myList->first; // allocate memory struct 1

        // visual creation of guardians Bee around the beehive
        creationOfBee->guardian->rect->h = 15;
        creationOfBee->guardian->rect->w = 15;
        // no random coordinate cause guardians are static they protect the beehive
        creationOfBee->guardian->rect->x = 400 + 150 * cos((i * 100) * PI / 180);
        creationOfBee->guardian->rect->y = 200 - 150 * sin((i * 100) * PI / 180);

        // we fill the rectangle
        SDL_RenderDrawRect(renderer, creationOfBee->guardian->rect);
        SDL_RenderFillRect(renderer, creationOfBee->guardian->rect);
        
    }

    SDL_RenderPresent(renderer); // we show
    
    return 0; 
}


int createForagers (ListOfBee *myList, int numOfForagers) //Linked-Stack
{

    static int ID = 0;
    if (myList == NULL) {
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < numOfForagers; i++ ) 
    {
        Bee *creationOfBee = malloc(sizeof(Bee)); // allocate memory struct 1

        if (creationOfBee == NULL) 
        {
            exit (EXIT_FAILURE);
        }

        creationOfBee->forager = malloc(sizeof(Forager)); // allocate memory struct 2
        if (creationOfBee->forager == NULL) 
        {
            free(creationOfBee);  // free memory 1 struct
            exit (EXIT_FAILURE); // we out
        }

        // Push-Stack (empile en tête)
        creationOfBee->forager->iIdOfBee = ID; // having a different iD
        creationOfBee->forager->next = myList->first;
        myList->first = creationOfBee;
        ID ++;
    }

    return 0; 
}


int createDrones (ListOfBee *myList, int numOfDrone) //Linked-Stack
{
    static int ID = 0;

    if (myList == NULL) {
        exit (EXIT_FAILURE);
    }

    for (int i = 0; i < numOfDrone; i++ ) 
    {
        Bee *creationOfBee = malloc(sizeof(Bee)); // allocate memory struct 1

        if (creationOfBee == NULL) 
        {
            exit (EXIT_FAILURE);
        }

        creationOfBee->drone = malloc(sizeof(Drone)); // allocate memory struct 2
        if (creationOfBee->drone == NULL) 
        {
            free(creationOfBee);  // free memory 1 struct
            exit (EXIT_FAILURE); // we out
        }

        // Push-Stack (insertion en tête)
        creationOfBee->drone->iIdOfBee = ID; // having a different iD
        creationOfBee->drone->next = myList->first;
        myList->first = creationOfBee;
        ID ++;
    }

    return 0; 
}



int showDroneAndForager ( int nbForager, int nbDrone, SDL_Renderer *renderer)
{
    SDL_Rect droneRect[nbDrone];
    SDL_Rect foragerRect[nbForager];
    srand(time(NULL));
    double angle = 0;
    int countHoney = 0;

    if(renderer == NULL)
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        exit (EXIT_FAILURE);
    }
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // we put a black rectangle to delete the current one
    SDL_RenderClear(renderer);

    for ( int i = 0; i <nbDrone; i ++)
    {
        //random coordinate between 0 and 2pi
        angle = (rand() / 2) * 2 * PI;
        droneRect[i].h = 20;
        droneRect[i].w = 20;
        droneRect[i].x = 400 + (rand()%130) * cos(angle); // radius must be < at center's radius
        droneRect[i].y = 200 + (rand()%130) * sin(angle);

        // we fill and show the rectangle
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // BLUE COLOR 
        SDL_RenderDrawRect(renderer, &droneRect[i]); 
        SDL_RenderFillRect(renderer, &droneRect[i]);
        
    }

    // we want random coordinate in the whole window
    for(int i = 0; i < nbForager; i++) 
    {
        foragerRect[i].h = 15;
        foragerRect[i].w = 15;
        foragerRect[i].x += rand() % WINDOW_H;  //for the 4 part of the window ( NORTH-WEST, NORTH-EAST, SOUTH-WEST, SOUTH-EAST)
        foragerRect[i].y += rand() % WINDOW_H;  
        foragerRect[i].x -= rand() % WINDOW_H;
        foragerRect[i].y -= rand() % WINDOW_H;

        // if the coordinates aren't in the window we put an other one
        if(foragerRect[i].x < 0) foragerRect[i].x = rand() % WINDOW_W;
        if(foragerRect[i].x > WINDOW_W) foragerRect[i].x = rand() % WINDOW_W;
        if(foragerRect[i].y < 0) foragerRect[i].y = rand() % WINDOW_H;
        if(foragerRect[i].y > WINDOW_H) foragerRect[i].y = rand() % WINDOW_H;

        // if the forager come to the beehive we add honey ( 1 forager produce 7g of honey during her life (5second here) )
        if ( (foragerRect[i].x < 400 + 150 * cos(angle)) && (foragerRect[i].y < 200 + 150 * sin(angle)) )
        {
            countHoney += 1;
        }

        // we fill and show the rectangle
        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255); // ORANGE COLOR
        SDL_RenderDrawRect(renderer, &foragerRect[i]); 
        SDL_RenderFillRect(renderer, &foragerRect[i]);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(300);

    return countHoney;
}


int createQueen (ListOfBee *myList) //Linked-Stack
{
    static int ID = 0;
    
    if (myList == NULL) {
        exit (EXIT_FAILURE);
    }

    Bee *creationOfBee = malloc(sizeof(Bee)); // allocate memory struct 1

    if (creationOfBee == NULL) 
    {
        exit (EXIT_FAILURE);
    }

    creationOfBee->queen = malloc(sizeof(Queen)); // allocate memory struct 2
    if (creationOfBee->queen == NULL) 
    {
        free(creationOfBee);  // free memory 1 struct
        exit (EXIT_FAILURE); // we out
    }

    creationOfBee->queen->rect = malloc(sizeof(SDL_Rect)); // allocate memory struct 3
    if (creationOfBee->queen->rect == NULL) 
    {
        free(creationOfBee->queen); // free memory struct 2
        free(creationOfBee);  // free memory struct 1
        exit (EXIT_FAILURE); // we out
    }

    // Push-Stack (insertion en tête)
    creationOfBee->queen->iIdOfBee = ID;
    creationOfBee->queen->next = myList->first;
    myList->first = creationOfBee;
    ID++;
        
    return 0;
}


int showQueen ( ListOfBee *mylist, SDL_Renderer *renderer)
{
    Bee *myQueen = mylist->first;
    double angle = 0;
    srand(time(NULL));

    //random coordinate between 0 and 2pi
    angle = (rand() / 2) * 2 * PI;
    myQueen->queen->rect->h = 25;
    myQueen->queen->rect->w = 25;
    myQueen->queen->rect->x = 400 + (rand()%120) * cos(angle); // radius must be < at center's radius
    myQueen->queen->rect->y = 200 + (rand()%120) * sin(angle);

    // we fill the rectangle
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // GREEN COLOR  
    SDL_RenderDrawRect(renderer, myQueen->queen->rect); 
    SDL_RenderFillRect(renderer, myQueen->queen->rect);
    SDL_RenderPresent(renderer);

    // we delete after showing
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // BLACK COLOR  
    SDL_RenderDrawRect(renderer, myQueen->queen->rect); 
    SDL_RenderFillRect(renderer, myQueen->queen->rect);
    
    SDL_Delay(500);  

}

int deathOfDrone ( ListOfBee *myList) 
{
    Bee *temp = myList->first;
    Bee *previoustemp = myList->first;
    SDL_Renderer *renderer;

    if ( myList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (temp->drone->next != NULL )
    {

        previoustemp = temp;
        temp = temp->drone->next;
        
    }
    previoustemp->drone->next = NULL;
    free(temp);

    return createDrones(myList,1);
}


int deathOfGuardian ( ListOfBee *myList) 
{
    Bee *temp = myList->first;
    Bee *previoustemp = myList->first;

    if ( myList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (temp->guardian->next != NULL )
    {

        previoustemp = temp;
        temp = temp->guardian->next;
        
    }
    previoustemp->guardian->next = NULL;
    free(temp);

    return createGuardians(myList,1);
}


int deathOfForager ( ListOfBee *myList) 
{
    Bee *temp = myList->first;
    Bee *previoustemp = myList->first;

    if ( myList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (temp->forager->next != NULL )
    {

        previoustemp = temp;
        temp = temp->forager->next;
        
    }
    previoustemp->forager->next = NULL;
    free(temp);

    return createForagers(myList,1);
}


int deathOfQueen ( ListOfBee *myList) 
{
    Bee *temp = myList->first;
    SDL_Renderer *renderer;

    if ( myList == NULL)
    {
        exit(EXIT_FAILURE);
    }
    myList->first = temp->queen->next;
    free(temp->queen);

    return createQueen(myList);
}

int freeForager ( ListOfBee *myList)
{
    Bee *myBee = myList->first;

    while (myBee != NULL)
    {
        free(myBee->forager);
        free(myBee);
        myBee = myBee->forager->next;
    }

}

int freeGuardian ( ListOfBee *myList)
{
    Bee *myBee = myList->first;

    while (myBee != NULL)
    {
        free(myBee->guardian);
        free(myBee);
        myBee = myBee->guardian->next;
    }

    return 0;
}


int freeDrone ( ListOfBee *myList)
{
    Bee *myBee = myList->first;

    while (myBee != NULL)
    {
        free(myBee->drone);
        free(myBee);
        myBee = myBee->drone->next;
    }

    return 0;
}

int freeQueen ( ListOfBee *myList)
{
    Bee *myBee = myList->first;

    while (myBee != NULL)
    {
        free(myBee->queen);
        free(myBee);
        myBee = myBee->queen->next;
    }

    return 0;
}


int runTheWorld ()
{
    ListOfBee *queenList = InitialisationListBee();
    ListOfBee *foragerList = InitialisationListBee();
    ListOfBee *droneList = InitialisationListBee();
    ListOfBee *guardianList = InitialisationListBee();

    SDL_Renderer *renderer;

    // the timer of the bees
    time_t foragerTime = time(NULL);
    time_t droneTime = time(NULL);
    time_t queenTime = time(NULL);
    time_t guardianTime = time(NULL);
    time_t globalTime = time(NULL);
    
    // our event tools
    SDL_Event events;
    int run = 0;
    int iHoney = 0;
    int iTotalAmount = 0;

    // creation of beehive with 35 Bees
    createGuardians(guardianList,NB_GUARDIAN);
    createDrones(droneList,NB_DRONE);
    createQueen(queenList);
    createForagers(foragerList,NB_FORAGER);
    displayBeehive(queenList, foragerList, droneList, guardianList, iTotalAmount); // to follow what's in the beehive
    showGuardians(guardianList,NB_GUARDIAN,renderer); // the static guardians

    while ( !run ) // infinite loop cause we want moving bees
    {
        globalTime = time(NULL);

        while (SDL_PollEvent(&events) != 0) // if we click on the cross on the top of the window
        {
            if (events.type == SDL_QUIT)
            {
                run = 1;
            }
        } 

        if ((globalTime - foragerTime) >= FORAGER_LIFETIME) // if timer = forager lifetime
        {
            deathOfForager(foragerList);
            displayBeehive(queenList, foragerList, droneList, guardianList, iTotalAmount += iHoney);
            foragerTime = globalTime; // reset forager timer at 0 seconds
        }

        if ((globalTime - droneTime) >= DRONE_LIFETIME) 
        {
            deathOfDrone(droneList);
            displayBeehive(queenList, foragerList, droneList, guardianList, iTotalAmount += iHoney);
            droneTime = globalTime; // reset drone timer at 0 seconds
        }

        if ((globalTime - guardianTime) >= GUARDIAN_LIFETIME) // if timer = guardian lifetime
        {
            deathOfGuardian(guardianList);
            displayBeehive(queenList, foragerList, droneList, guardianList, iTotalAmount += iHoney);
            guardianTime = globalTime; 
        }

        if ((globalTime - queenTime) >= QUEEN_LIFETIME) 
        {
            deathOfQueen(queenList);
            displayBeehive(queenList, foragerList, droneList, guardianList, iTotalAmount += iHoney);
            queenTime = globalTime; 
        }

        // WARNING I CAN'T SHOW THE ENTIRE BEES ON ONE WINDOW SO COMMENT showQueen to see the beehive with the Guardians
        // showDroneAndForager AREN'T SHOW WITH THE BEEHIVE
        showQueen(queenList,renderer); // the moving queen
        iHoney = showDroneAndForager(NB_FORAGER,NB_DRONE,renderer); // the moving foragers
    }

    return 0;
}
