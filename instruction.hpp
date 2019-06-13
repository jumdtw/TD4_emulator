#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include"TD4_emu.hpp"

void init_instructions();

typedef void instruction_list(TD4_emulator*);

//2 ^ 6
extern instruction_list* instructions[64];

#endif