#include "worldOfBee.c"
// TO COMPILE THE PROGAMM MAKE SURE YOU INSTALL THE LIBRARY SDL2 AND COMPILE WITH -lSDL2 -lm
                                                                                 
 /*                 =@#-:::-*@@*:                                                  
                 @-            #@#                                               
                =%                =@*                                            
                +*                   *@-                                         
                .@                     -@+                                       
                .@+-::.                  :@+                                     
           :@@#-       :+#@@@=.            -@:                                   
         :@-                  .=%@+.         ##                                  
         @                         .@@-       -@                                 
        .@                             *@=     .@-            ##. .==            
         @-                              .@@     @:          %+     .@*..-%.     
          @-                                #%    @.        **     +%            
           ##                                 %+  =%     *@@#:::-#@@-            
            .@+                                +%  @. -@+ .@        .@@          
              :@*                               +%-@-@=   @-           @=        
                 %@=                            .@@@@.                @%#*       
              .%#   *@+.                        .@@@.         **@#   +:@:#+      
            .@=      @@@@@#:                   :@@@*         +* =@*  #@@-.@      
           #@-      :@@@@@@@@@@@#-:.       :-@@@@@@.         #@@@@%  :@@  %:     
          @@%       =@@@@@@@@@@@   :------:*@@@@@@@.         .@@@@:       %-     
         #@@*       +@@@@@@@@@@@.          -@@@@@@@-                      @.     
         @@@*       =@@@@@@@@@@@-           @@@@@@@@     :-.             =#      
       %@@@@@       -@@@@@@@@@@@#           @@@@@@@@*     -  -          =@       
      +%@@@@@-      .@@@@@@@@@@@@:          *@@@@@@@@#      :          -@.       
         .@@@%       #@@@@@@@@@@@#           @@@@@@@@@@=      .-:     @*         
          :@@@+      :@@@@@@@@@@@@=          -@@@@@@@@@@@@:       .*@*           
            %@@-      *@@@@@@@@@@@@.          -@@@@@@@@@@@@%*%@%#=:              
              %@=      @@@@@@@@@@@@@           .@@@@@@@@@@                       
                -@*.    %@@@@@@@@@@@@-           :%@@@@=                         
                    *@%- #@@@@@@@@@@@@@         :%@#.                            
                        .+#%@@@@@@@@@@@@@*%@%#+.                */                 
                                                                     


int main(int argc, char *argv[])
{
    // our linked-stack of bee
    ListOfBee *queenList = InitialisationListBee();
    ListOfBee *foragerList = InitialisationListBee();
    ListOfBee *droneList = InitialisationListBee();
    ListOfBee *guardianList = InitialisationListBee();

    // our window/world
    SDL_Window* myWindow = CreateWindow();
    SDL_Renderer* myRenderer = displayWorld();

    //we show displayWorld()
    SDL_RenderClear(myRenderer);
    SDL_RenderPresent(myRenderer);

    // the launch of the program
    runTheWorld();

    // liberation of memory
    freeForager(foragerList);
    freeDrone(droneList);
    freeGuardian(guardianList);
    freeQueen(queenList);

    //we destroy our window and leave it
    SDL_DestroyRenderer(myRenderer);
    SDL_DestroyWindow(myWindow);
    SDL_Quit(); 

    return 0;
}