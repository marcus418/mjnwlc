#include "../include/Instructions.hpp"
#include "../include/RegisterFile.hpp"
#include "../include/ProgramCounter.hpp"
#include <iostream>
using namespace std;

void sll(unsigned short& rd, unsigned short rt, unsigned short shamt){

}

void srl(unsigned short& rd, unsigned short rt, unsigned short shamt){
    
}

void sra(unsigned short& rd, unsigned short rt, unsigned short shamt){

}
void sllv(unsigned short& rd, unsigned short rt, unsigned short rs){

}
void srlv(unsigned short& rd, unsigned short rt, unsigned short rs){

}
void srav(unsigned short& rd, unsigned short rt, unsigned short rs){

}
void jr(unsigned short rs){
    ProgCount = reg.readRegister(rs);
}

void jalr(unsigned short& rd, unsigned short rs){

}
void mfhi(unsigned short& rd){

}
void mthi(unsigned short rs){

}
void mflo(unsigned short& rd){

}
void mtlo(unsigned short rs){

}
void mult(signed short rs, signed short rt){

}
void multu(unsigned short rs, unsigned short rt){

}
void div(signed short rs, signed short rt){

}
void divu(unsigned short rs, unsigned short rt){

}
void add(unsigned short& rd, unsigned short rs, unsigned short rt){
    reg.writeRegister(rd, reg.readRegister(rs) + reg.readRegister(rt));
    cout << endl;
    cout << "rs = " << reg.readRegister(rs) << endl;
    cout << "rt = " << reg.readRegister(rt) << endl;
    cout << "rd = " << reg.readRegister(rd) << endl;
    cout << endl;

}
void addu(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void sub(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void subu(unsigned short& rd, unsigned short rs, unsigned short rt){
    
}
void andd(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void orr(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void xorr(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void slt(unsigned short& rd, unsigned short rs, unsigned short rt){

}
void sltu(unsigned short& rd, unsigned short rs, unsigned short rt){

}