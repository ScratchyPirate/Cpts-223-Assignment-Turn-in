#include "VectorMyJosephus.hpp"

void TestVectorJosephus(int line, int M, int N){

    //General Variables
    string temp1, temp2;
    Destination temp;
    fstream input_file;
    fstream output_file;
    VectorMyJosephus destination_vector;

    //Chose random line to read from
    input_file.open("destinations.csv", ios::in);

    //line = rand() % 25 + 1;

    destination_vector.set_M(M);
    destination_vector.set_N(N);

    //The following sequence fills the list with content from the random line
    while (line > 1) {

        //getline(input_file, temp1, ',');
        getline(input_file, temp1, '\n');
        line -= 1;

    }
    temp.set_position(1);
    for (int i = 0; i < 16262; i++) {
        getline(input_file, temp1, ',');
        getline(input_file, temp2, ',');
        temp1 = temp1 + temp2;
        temp.set_name(temp1);
        destination_vector.insert_at_back(temp);
        temp.set_position(temp.get_position() + 1);
        //cout << temp1 << ": " << temp.get_position() << endl;
    }
    getline(input_file, temp1, ',');
    getline(input_file, temp2, '\n');
    temp1 = temp1 + temp2;
    temp.set_name(temp1);
    destination_vector.insert_at_back(temp);
    //cout << temp1 << endl;

    input_file.close();

    //cout << "List size: " << destination_vector.currentSize() << endl;
    cout << "M: " << M << endl << "N: " << N << endl;

    destination_vector.iterate_delete();
    //_getch();





}