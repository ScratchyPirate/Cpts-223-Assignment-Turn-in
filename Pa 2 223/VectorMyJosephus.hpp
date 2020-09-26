#include "ListMyJosephus.hpp"

void TestVectorJosephus(int line, int M, int N);

class VectorMyJosephus {

private:

	int M;
	int N;

	vector<Destination> container;



public:

    VectorMyJosephus() {

        M = 0;
        N = 1;

    }

    explicit VectorMyJosephus(int new_M, int new_N) {

        M = new_M;
        N = new_N;


    }

    ~VectorMyJosephus() {

        //delete[] &M;
        //delete[] &N;

        while (!container.empty()) {

            container.pop_back();

        }

    }

    //Setters and Getters
    int get_M();
    int get_N();
    vector<Destination> get_container_root();
    void set_M(int new_M);
    void set_N(int new_N);

    //Insert and delete
    void insert_at_back(Destination new_destination);
    void insert_at_position(Destination new_destination, int index);
    Destination eliminateDestination(int position, string* name_destination);

    //Other required functions
    void clear();
    int currentSize();
    bool isEmpty();
    void printAllDestinations();

    //Iterate Delete
    void iterate_delete();

    //Pop back
    void pop_back(string* name_destination, int* id);


};