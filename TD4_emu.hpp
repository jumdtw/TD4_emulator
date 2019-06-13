#ifndef TD4_EMULATOR_H_
#define TD4_EMULATOR_H_

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>

using namespace std;

enum Register { A, B, C, D, EGISTERS_COUNT};

class TD4_emulator{

public:
    unsigned char registers[EGISTERS_COUNT];
    unsigned char *memory;
    TD4_emulator(){
        for(int i=0;i<EGISTERS_COUNT;i++){
            registers[i] = 0x00;
        }
        memory = (unsigned char*)malloc(16);
        memset(memory,0x20,16);
    }
};

#endif 