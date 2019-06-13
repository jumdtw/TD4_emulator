#include<string.h>
#include<stdlib.h>
#include<bitset>
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
    cout << "----------------execute code---------------------" << endl;
    unsigned char oprand = ADD_A_IM;
    unsigned char asmcode = (oprand << 4) + 0x1;
    emu->memory[0] = asmcode;
    oprand = MOV_B_IM;
    asmcode = (oprand << 4) + 0x5;
    emu->memory[1] = asmcode;
    oprand = MOV_A_B;
    asmcode = (oprand << 4) + 0x0;
    emu->memory[2] = asmcode;
    oprand = MOV_B_A;
    asmcode = (oprand << 4) + 0x0;
    emu->memory[3] = asmcode;
    oprand = ADD_B_IM;
    asmcode = (oprand << 4) + 0x1;
    emu->memory[4] = asmcode;
    oprand = IN_A;
    asmcode = (oprand << 4) + emu->input_date;
    emu->memory[5] = asmcode;
    oprand = IN_B;
    asmcode = (oprand << 4) + emu->input_date;
    emu->memory[6] = asmcode;
    
    while(emu->registers[C]<=0x0f){
        unsigned char Mcode = emu->memory[emu->registers[C]];
        unsigned char opcode = Mcode >> 4;
        cout << int(emu->registers[C]) << ",    ";
        instructions[opcode](emu);
        dump_registers(emu);
        getchar();
        emu->registers[C]++;
    }
    cout << "-------------------------------------------------" << endl;
    cout << "\n" << endl;
    //end emulator
    dump_registers(emu);
    dump_memory(emu);
    Delete_emu(emu);
    return 0;
}