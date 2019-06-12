#ifndef TD4_EMULATOR_H_
#define TD4_EMULATOR_H_

#include<iostream>
#include<cstring>

using namespace std;

enum Register { A, B, C, D, EGISTERS_COUNT};

class TD4_emulator{

public:
    char registers[EGISTERS_COUNT];
    char* memory;
    TD4_emulator(){
        for(int i=0;i<EGISTERS_COUNT;i++){
            registers[i] = 0x41;
        }
        memory = new char(16);
        memset(memory,0,sizeof(memory));
    }
};

#endif 