#include"graphic.hpp"
#include"TD4_emu.hpp"
#include"instruction.hpp"

//2 ^ 6
instruction_list* instructions[64];

static void add_A_Im(TD4_emulator *emu){
    cout << "execute add A Im" << endl;
}

static void mov_A_B(TD4_emulator *emu){
    cout << "execute mov A B" << endl;
}

static void in_A(TD4_emulator *emu){
    cout << "execute in A" << endl;
}

static void mov_A_Im(TD4_emulator *emu){
    cout << "execute mov A Im" << endl;
}

static void mov_B_A(TD4_emulator *emu){
    emu->registers[B] = emu->registers[A];
    cout << "execute mov B A" << endl;
}

static void add_B_Im(TD4_emulator *emu){
    cout << "execute add B Im" << endl;
}

static void in_B(TD4_emulator *emu){
    cout << "execute in B" << endl;
}

static void mov_B_Im(TD4_emulator *emu){
    cout << "execute mov B Im" << endl;
}

static void out_B(TD4_emulator *emu){
    cout << "execute out B" << endl;
}

static void out_Im(TD4_emulator *emu){
    cout << "execute out Im" << endl;
}

static void jnc(TD4_emulator *emu){
    cout << "execute jnc" << endl;
}

static void jmp(TD4_emulator *emu){
    cout << "execute jmp" << endl;
}

void init_instructions(){
    instructions[0x3] = add_A_Im; 
    instructions[0x7] = mov_B_Im;
    instructions[0x1] = mov_A_B;
    instructions[0x4] = mov_B_A;
    instructions[0x0] = add_A_Im;
    instructions[0x5] = in_A;
    instructions[0x6] = in_B;
    instructions[0xb] = out_Im;
    instructions[0x9] = out_B;
    instructions[0xf] = jmp;
    instructions[0xe] = jnc;
    cout << "init instructions" << endl;
    return;
}