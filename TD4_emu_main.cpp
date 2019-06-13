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
    int endflag = 0;
    TD4_emulator *emu;
    cout << "create emulator" << endl;
    emu = init_registers();
    init_instructions();
    //execute
    cout << "\n" << endl;
    cout << "----------------execute code---------------------" << endl;
    emu->memory[0] = 0x40;
    emu->registers[A] = 0x0f;
    cout << "set register A" << endl;
    dump_registers(emu);
    while(emu->registers[C]<=0xff&&endflag==0){
        unsigned char Mcode = emu->memory[emu->registers[C]];
        unsigned char opcode = Mcode >> 4;
        instructions[opcode](emu);
        dump_registers(emu);
        emu->registers[C]+=0xff;
        if(emu->registers[C]==0xff){
            endflag = 1;
        }
        
        //emu->registers[C]++;
    }
    cout << "-------------------------------------------------" << endl;
    cout << "\n" << endl;
    //end emulator
    dump_registers(emu);
    dump_memory(emu);
    Delete_emu(emu);
    return 0;
}