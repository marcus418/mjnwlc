#include "include/memory.hpp"
#include <iostream>
#include <iterator>

RAM::RAM(){
    /*for(int i=ADDR_INSTR_OFFSET; i<(ADDR_INSTR_OFFSET+0x1000000); i+=4){
        memory[i] = '\0';
    }

    for(int i=ADDR_DATA_OFFSET; i<(ADDR_DATA_OFFSET+0x4000000); i+=4){
        stack[i] = 0;
    }*/
}

RAM::~RAM(){
    cout << "Clearing RAM and stack memory" << endl;
}

void RAM::loadtoMemory(unsigned char binstr){
    unsigned int addr = ADDR_INSTR_OFFSET + offset;

    try{
        if(addr<ADDR_INSTR_OFFSET || addr>=(ADDR_INSTR_OFFSET+0x1000000)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        return;
    }

    memory[addr] = binstr;
    offset++;
}

unsigned int RAM::pullfromMemory(unsigned int& ProgCount){
    unsigned int data;

    if((ProgCount-1) == (ADDR_INSTR_OFFSET + offset)){
        ProgCount = 0;
        return 1;
    }

    try{
        if(ProgCount<ADDR_INSTR_OFFSET || ProgCount>=(ADDR_INSTR_OFFSET+0x1000000)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        return 1;
    }

    try{
        if(ProgCount%4 == 0){
            data = (((unsigned int)memory[ProgCount] << 8) + (unsigned int)memory[ProgCount+1]) << 8;
            data = (data + (unsigned int)memory[ProgCount+2]) << 8;
            data = data + (unsigned int)memory[ProgCount+3];
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        return 1;
    }

    return data;
}

unsigned int RAM::get_addr(unsigned int data){
    unordered_map<int, unsigned char>::iterator it;

    for(it = memory.begin(); it != memory.end(); it++){
        if(it->second == data){
            return it->first;
        }
    }

    try{
        throw "Data not found!";
    } catch(const char* msg){
        cerr << msg << endl;
        return 1;
    }
}

void RAM::jump(int& ProgCount, unsigned int addr){
    try{
        if(addr%4 == 0){
            ProgCount = addr;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        return;
    }
}

void RAM::loadtoStack(unsigned int data){
    unsigned int addr = ADDR_DATA_OFFSET + sp;

    try{
        if(addr<ADDR_DATA_OFFSET || addr>=(ADDR_DATA_OFFSET+0x1000000)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        return;
    }

    unsigned int lsb = data << 24 >> 24;
    unsigned int xlsb = data << 16 >> 24;
    unsigned int xmsb = data << 8 >> 24;
    unsigned int msb = data >> 24;

    stack[addr] = msb;
    stack[addr+1] = xmsb;
    stack[addr+2] = xlsb;
    stack[addr+3] = lsb;

    sp+=4;
}

unsigned int RAM::getfromStack(unsigned int addr){
    unsigned int data;

    try{
        if(addr<ADDR_DATA_OFFSET || addr>=(ADDR_DATA_OFFSET+0x1000000)){
            throw "Accessing out of bounds memory!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        return 1;
    }

    try{
        if(addr%4 == 0){
            data = ((stack[addr] << 8) + stack[addr+1]) << 8;
            data = (data + stack[addr+2]) << 8;
            data = data + stack[addr+3];

            stack.erase(addr+3);
            stack.erase(addr+2);
            stack.erase(addr+1);
            stack.erase(addr);

            sp-=4;
        }

        else{
            throw "Invalid address!";
        }
    } catch(const char* msg){
        cerr << msg << endl;
        return 1;
    }

    return data;
}