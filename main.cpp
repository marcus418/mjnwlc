#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef FSTREAM
#define FSTREAM
#include <fstream>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#include "include/memory.hpp"
#include "include/simulator.hpp"
#include "include/RegisterFile.hpp"
#include "include/ProgramCounter.hpp"
using namespace std;

RAM r;
RegisterFile reg;

int main(){
    cout << "prog started" << endl << endl;
    fstream file;
    unsigned char n;
    cout << "Opening binary" << endl << endl;
    try{
        file.open("binary3.bin", ios::in | ios::binary);

        if (!file.is_open()) {
            throw "Error opening binary file!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Reading binary" << endl << endl;
    file.seekg(0, file.end);
    int lengthofbin = file.tellg();
    file.seekg(0, file.beg);
    cout << "loading instruction to memory" << endl;
    for (int i=0; i<lengthofbin; i++){
        file.read((char *) (&n), sizeof(n));
        r.loadtoMemory(n);
        cout  << (int32_t)n << endl;
    }
    cout << "instruction stored in memory" << endl;
    simulator S;
    cout << " executing simulator" << endl;
    S.execute();

    cout << "Simulator has finished execution successfully" << endl;
    return 0;
}