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
    return;
}

int main(){
    //init emulator
    TD4_emulator *emu;
    cout << "create emulator" << endl;
    emu = init_registers();
    init_instructions();
    //execute
    cout << "\n" << endl;
    cout << "----------------execute code---------------------" << endl;
    // A = 0x0f
    emu->registers[A] = 0x0f;
    dump_registers(emu);
    instructions[0x4](emu);
    dump_registers(emu);
    cout << "-------------------------------------------------" << endl;
    cout << "\n" << endl;
    //end emulator
    dump_registers(emu);
    dump_memory(emu);
    Delete_emu(emu);
    return 0;
}