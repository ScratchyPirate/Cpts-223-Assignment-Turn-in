/***************************************************************************************

Creator: John Sbur
Class: CPTS 223
Date Created: 9/22/20
Last Updated: 9/25/20
Assignment: PA 2
Purpose: Define ListMyJosephus Class and its Constructor, Explicit Constructor, Destructor,
and Declare ListMyJosephus functions


***************************************************************************************/
#include "Destination.hpp"

void TestListJosephus(int line, int M, int N);

class ListMyJosephus{

    private:

        //Interval of Elimination
        int M;
        //Number of Destination Cities at the start of the Simulation
        int N;
        //List of Destinations
        list<Destination> container;

    public:

        ListMyJosephus(){

            M = 0;
            N = 1;

        }

        explicit ListMyJosephus(int new_M, int new_N){

            M = new_M;
            N = new_N;
            

        }   

        ~ListMyJosephus(){
            
            //delete[] &M;
            //delete[] &N;

            while(!container.empty()){

                container.pop_front();

            }

        }

        //Setters and Getters
        int get_M();
        int get_N();
        list<Destination> get_container_root();
        void set_M(int new_M);
        void set_N(int new_N);

        //Insert and delete
        void insert_at_front(Destination new_destination);
        void insert_at_position(Destination new_destination, int index);
        Destination eliminateDestination(int position, string* name_destination);

        //Other required functions
        void clear();
        int currentSize();
        bool isEmpty();
        void printAllDestinations();

        //Iterate Delete
        void iterate_delete();

        //Pop front
        void pop_front(string* name_destination, int* id);

};