/***************************************************************************************

Creator: John Sbur
Class: CPTS 223
Date Created: 9/22/20
Last Updated: 9/23/20
Assignment: PA 2
Purpose: Define public member functions in the Destination class


***************************************************************************************/

#include "Destination.hpp"



//Prints position integer
void Destination::printPosistion(){

    cout << "Position: " << position << endl;

}

//Prints destination name
void Destination::printDestinationName(){

    cout << "Destination: " << name << endl;
}


//Setters and Getters
void Destination::set_position(int new_position){

    position = new_position;
        
}
void Destination::set_name(string new_name){

    name = new_name;

}
int Destination::get_position(){

    return position;

}
string Destination::get_destination(){

    return name;

}