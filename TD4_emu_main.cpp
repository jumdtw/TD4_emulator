#include<string.h>
#include<stdlib.h>
#include"graphic.hpp"
#include"TD4_emu.hpp"
#include"instruction.hpp"
#include"debug.hpp"


TD4_emulator* init_registers(){
    TD4_emulator *emu = (TD4_emulator*)malloc(sizeof(TD4_emulator));
    memset(emu->registers, 0x41, sizeof(emu->registers));
    cout << "init registers" << endl;
    return emu;
}

int main(){
    TD4_emulator *emu;
    cout << "create emulator" << endl;
    emu = init_registers();
    dump_registers(emu);
    init_instructions();
    return 0;
}