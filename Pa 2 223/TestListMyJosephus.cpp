#include "ListMyJosephus.hpp"

void TestListJosephus(int line, int M, int N){


    //General Variables
    string temp1, temp2;
    Destination temp;
    fstream input_file;
    fstream output_file;
    ListMyJosephus destination_list;
    
    //Chose random line to read from
    input_file.open("destinations.csv", ios::in);
    
    //line = rand() % 25 + 1;

    destination_list.set_M(M);
    destination_list.set_N(N);

    //The following sequence fills the list with content from the random line
    while(line > 1){
              
        //getline(input_file, temp1, ',');
        getline(input_file, temp1,'\n');
        line -= 1;

    }
    temp.set_position(N);
    for(int i = 0; i < 16262; i++){
        getline(input_file,temp1,',');
        getline(input_file,temp2,',');
        temp1 = temp1 + temp2;
        temp.set_name(temp1);
        destination_list.insert_at_front(temp);
        temp.set_position(temp.get_position() - 1);
        //cout << temp1 << ": " << temp.get_position() << endl;
    }
    getline(input_file,temp1,',');
    getline(input_file,temp2,'\n');
    temp1 = temp1 + temp2;
    temp.set_name(temp1);
    destination_list.insert_at_front(temp);
    //cout << temp1 << endl;

    input_file.close();

    //cout << "List size: " << destination_list.currentSize() << endl;
    cout << "M: " << M << endl << "N: " << N << endl;
    
    destination_list.iterate_delete();
    //_getch();
    
}