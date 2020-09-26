/***************************************************************************************

Creator: John Sbur
Class: CPTS 223
Date Created: 9/22/20
Last Updated: 9/23/20
Assignment: PA 2
Purpose: Provide a basic interface and contain the means to execute all relevant tasks
for PA 2.


***************************************************************************************/

/*
PA 2 QUESTIONS:

1) Does the processor of the machine that is running the algorithms matter? Will you receive the same timing statistics on every machine?
    My thought is that the main way to reduce the runtime of an algorithm would be to optimize how you use your memory and try to condense actions.
    So while the processor might make the program run a little faster, I think the main thing that it comes down to is how optimized your code is. 
    That's what really matters. You'll receive similar time statistics on every machine.

2) Vector itself can take a bit of time when having to insert or remove from the back since that's a O(n) operation while list doesn't since you
    can remove it from the front. With smaller N values, that doesn't matter too much, but with bigger N values it definitely does. I have noticed 
    through testing that vector takes the longest timewise with small N and M values and with larger M and N values compared to list. I think that
    it doesn't matter the input since the N and M values are the same for each so the algorithm should run similarly, but with different runtimes 
    depending on each container's respective functions.

3) How does the running time dependency on the parameter N compare with the dependency on the parameter M?
    Runtime increases proportional to N in that as N increases and vice versa. M effects runtime based on N. If both M and N are large, then runtime 
    will be large or worst case scenario sometimes. If N is small and M is small, then runtime is small or even best case scenario. However, the larger
    N is than M, the shorter the runtime than if M was larger and N was the same since it takes less time between deletions. In general, as N increases,
    so does runtime and as M increases, so does runtime.

*/

#include "VectorMyJosephus.hpp"


int main(){

    //Time variables needed for random numbers
    clock_t t;
    t = clock();
    srand(time(NULL));

    //How many sims the user wants to run
    int option = 1;

    //Variables that stay common through each test functions
    int line = 0;
    int M, N;


    /*do{

        cout << "Enter the number of simulations to run: " << endl;
        cin >> option;

    }while(option <= 0);*/

    //Runs only 1 time, but can be set up to run multiple if the while look is uncommented
    while(option > 0){
        
        //Generate random numbers for test functions
        N = rand() % 1025 + 1;
        M = rand() % N + 1;
        line = rand() % 25 + 1;
        
        //Run list test
        cout << endl << endl << "List Test: " << endl;
        TestListJosephus(line, M, N);
        cout << endl << "Press any button to continue" << endl;
        _getch();

        //Run vector test
        cout << endl << endl << "Vector Test: " << endl;
        TestVectorJosephus(line, M, N);
        cout << endl << "Press any button to continue" << endl;
        _getch();

      
        //Decrement option by 1 to make sure than the loop doesn't go on forever
        option -= 1;

    }
    



    return 0;

}