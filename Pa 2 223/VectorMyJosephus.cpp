#include "VectorMyJosephus.hpp"

//Setters and Getters
int VectorMyJosephus::get_M() {
    return M;
}
int VectorMyJosephus::get_N() {
    return N;
}
vector<Destination> VectorMyJosephus::get_container_root() {
    return container;
}
void VectorMyJosephus::set_M(int new_M) {
    M = new_M;
}
void VectorMyJosephus::set_N(int new_N) {
    N = new_N;
}

//Insert and delete
void VectorMyJosephus::insert_at_back(Destination new_destination) {
    container.push_back(new_destination);
}
Destination VectorMyJosephus::eliminateDestination(int position, string* name_destination) {

    //bool complete = false;
    int c = 0;
    Destination temp;
    temp.set_name("");

    //if (position > container.size()) {
    //    cout << "Position attempted to remove was greater than size: " << container.size() << endl;
    //}
    //else{

    for (vector<Destination>::iterator i = container.begin(); i != container.end(); i++) {

        if (c == position) {
            cout << "Removing: " << i->get_destination();
            temp.set_name(i->get_destination());
            temp.set_position(i->get_position());
            *name_destination = temp.get_destination();
            container.erase(i);
            return temp;
            //complete = true;
        }

        c++;
        //    }

    }

    cout << "FAILED TO REMOVE DESTINATION" << endl;
    return temp;
}

//Other required functions
void VectorMyJosephus::clear() {
    container.clear();
}
int VectorMyJosephus::currentSize() {
    return container.size();
}
bool VectorMyJosephus::isEmpty() {
    return container.empty();
}
void VectorMyJosephus::printAllDestinations() {

    for (vector<Destination>::iterator i = container.begin(); i != container.end(); i++) {

        cout << "Name: " << i->get_destination() << endl << "Position: " << i->get_position() << endl << endl;

    }

}


//Iterate and delete function
void VectorMyJosephus::iterate_delete() {

    //Declare time variables or variables needed in time calculations
    clock_t start = clock();
    clock_t last = clock();
    clock_t now = clock();
    int num_deletes = 0;
    double average_time = 0.0;

    //Declare general variables
    int scanned_members = 0;
    string destinations_removed = "";
    Destination temp_destination;
    fstream outputfile;
    string temp_string;
    int temp_int;

    //Open output file
    outputfile.open("results.log", ios::out);

    //Reduce the container to size N starting from the back
    while (container.size() > N) {

        container.pop_back();

    }

    for (int i = 1; container.size() > 1; i++) {

        if (i == container.size()) {
            if (scanned_members == M) {
                cout << endl << "Removing destination: " << i << endl;
                temp_destination = this->eliminateDestination(i, &temp_string);

                destinations_removed = destinations_removed + ", ";
                destinations_removed = destinations_removed + temp_string;

                scanned_members = 0;
                i = 0;
                this->printAllDestinations();

                //For calculating average time
                if (num_deletes != 0) {
                    num_deletes++;
                    last = clock();
                }
                else {
                    now = clock();
                    average_time += (double)(now - last) / CLOCKS_PER_SEC;
                    num_deletes++;
                    last = clock();
                }
            }
            else {
                i = 0;
            }
        }
        else if (scanned_members == M) {

            cout << endl << "Removing destination: " << i << endl;
            temp_destination = this->eliminateDestination(i, &temp_string);
            scanned_members = 0;

            destinations_removed = destinations_removed + ", ";
            destinations_removed = destinations_removed + temp_string;

            this->printAllDestinations();

            //For calculating average time
            if (num_deletes != 0) {
                num_deletes++;
                last = clock();
            }
            else {
                now = clock();
                average_time += (double)(now - last) / CLOCKS_PER_SEC;
                num_deletes++;
                last = clock();
            }
        }

        scanned_members++;
    }

    //Gets the last element's content from the list after all the others have been deleted
    this->pop_back(&temp_string, &temp_int);

    //Marks the end of the sequence
    clock_t end = clock();

    //Calculate Average Time
    average_time = average_time / num_deletes;

    //Print out destination chosen and all deleted destinations in the order they were deleted
    cout << "Destination Chosen: " << temp_string << " (" << temp_int << ") " << "Destinations Removed: " << destinations_removed << endl;

    //Write to output file. (TESTED: SUCCESSFUL 9/25/20)
    //Outputs same information to console
    outputfile << "M=" << to_string(M);
    cout << " M = " << to_string(M);
    outputfile << "|N=" << to_string(N);
    cout << " |N = " << to_string(N);
    outputfile << "|Total Time: " << to_string((double)(end - start) / CLOCKS_PER_SEC);
    cout << "|Total Time: " << to_string((double)(end - start) / CLOCKS_PER_SEC);
    outputfile << "| Average time between deletes: " << to_string(average_time) << endl;
    cout << "| Average time between deletes: " << to_string(average_time) << endl;

    outputfile.close();
    //return container.front();

}

void VectorMyJosephus::pop_back(string* name_destination, int* id) {

    vector<Destination>::iterator i = container.begin();

    //if (position > container.size()) {
    //    cout << "Position attempted to remove was greater than size: " << container.size() << endl;
    //}
    //else{
    if (!container.empty()) {
        cout << "Removing front" << endl;

        *name_destination = i->get_destination();
        *id = i->get_position();
        container.pop_back();
        //return temp;
        //complete = true;
    }
    else {

        cout << "Failed to pop front" << endl;

    }

    //return temp;
}