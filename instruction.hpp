#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include"TD4_emu.hpp"
#define NOP 0x2 
#define ADD_A_IM 0x3
#define MOV_B_IM 0x7
#define MOV_A_B 0x1
#define MOV_B_A 0x4
#define ADD_B_IM 0x0
#define IN_A 0x5
#define IN_B 0x6
#define OUT_IM 0xb
#define OUT_B 0x9
#define JMP 0xf
#define JNC 0xe

void init_instructions();

typedef void instruction_list(TD4_emulator*);

//2 ^ 6
extern instruction_list* instructions[64];

#endif