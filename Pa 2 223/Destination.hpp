/***************************************************************************************

Creator: John Sbur
Class: CPTS 223
Date Created: 9/22/20
Last Updated: 9/23/20
Assignment: PA 2
Purpose: Declare members of the Destination class and define its Constructors and
Destructor


***************************************************************************************/

#include "declarations.hpp"

class Destination{

    //Private member functions
    private:

        int position;
        string name;


    //Public member functions
    public:

        //Constructor
        Destination(){

            position = 0;
            name = "";

        }

        //Explicit copy constructor
        explicit Destination(int new_position, string new_name){
            
            position = new_position;
            name = new_name;

        }

        //Destructor
        ~Destination(){

            //delete[] &position;
            //delete[] &name;

        }

        Destination operator=(const Destination& destination) {

            Destination copy_data;
            copy_data.set_name(name);
            copy_data.set_position(position);

            return copy_data;
            1;

        }

        //Prints position integer
        void printPosistion();

        //Prints destination name
        void printDestinationName();


        //Setters and Getters
        void set_position(int new_position);
        void set_name(string new_name);
        int get_position();
        string get_destination();


};