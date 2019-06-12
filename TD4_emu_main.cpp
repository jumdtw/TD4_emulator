#include<string.h>
#include<stdlib.h>
#include"graphic.hpp"
#include"TD4_emu.hpp"
#include"instruction.hpp"
#include"debug.hpp"


TD4_emulator* init_registers(){
    TD4_emulator *emu = new TD4_emulator;
    cout << "init registers" << endl;
    return emu;
}

void Delete_emu(TD4_emulator* emu){
    delete emu->memory;
    delete emu;
    cout << "delete emulator" << endl;
}

int main(){
    TD4_emulator *emu;
    cout << "create emulator" << endl;
    emu = init_registers();
    dump_registers(emu);
    init_instructions();
    Delete_emu(emu);
    return 0;
}