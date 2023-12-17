#include "worldOfBee.c"

int main()
{
    ListOfBee *oneBee = InitialisationListBee();

    creationOfBeehive(oneBee);
    displayBeehive(oneBee);
    //BirthofBee(oneBee);
    //displayBeehive(oneBee);
    //deathOfBee(oneBee,6);
    //displayBeehive(oneBee);
    

    return 0;
}/*

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialisez le générateur de nombres aléatoires avec le temps actuel
    srand(time(NULL));

    // Définissez le nombre total d'itérations
    int totalIterations = 10;

    for (int i = 1; i <= totalIterations; ++i) {
        // Générez un nombre aléatoire entre 1 et 10
        int randomIteration = rand() % totalIterations + 1;

        // Vérifiez si le nombre aléatoire correspond à l'itération actuelle
        if (randomIteration == i) {
            printf("Message à l'itération %d : C'est une itération aléatoire !\n", i);
        } else {
            printf("Message à l'itération %d : Rien d'aléatoire ici.\n", i);
        }
    }

    return 0;
}*/
