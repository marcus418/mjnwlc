#ifndef REGISTERFILE_HPP
#define REGISTERFILE_HPP



class RegisterFile{
    private: 
    long $zero;
    long $at = 0x80000000;
    long $v0 = 0x80000000, $v1 = 0x80000000;
    long $a0 = 0x10000000, $a1, $a2, $a3;
    long $t0, $t1, $t2, $t3, $t4, $t5, $t6, $t7;
    long $s0, $s1, $s2, $s3, $s4, $s5, $s6, $s7;
    long $t8, $t9;
    long $k0, $k1;
    long $gp;
    long $sp;
    long $fp;
    long $ra;

    public:
    long readRegister(int RegisterNumber);
    void writeRegister(int RegisterNumber, long input);
    

};

extern RegisterFile reg;

#endif