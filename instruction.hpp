#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include"TD4_emu.hpp"

void init_instructions();

typedef void instruction_list(TD4_emulator*);

extern instruction_list* instructions[13*4];

#endif