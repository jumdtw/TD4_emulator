#include<bitset>
#include"graphic.hpp"
#include"TD4_emu.hpp"
#include"instruction.hpp"

//2 ^ 6
instruction_list* instructions[64];

static void add_A_Im(TD4_emulator *emu){
    unsigned char buf_low_4bit,Mcode = emu->memory[emu->registers[C]],p;
    buf_low_4bit = Mcode << 4;
    unsigned char ImDate = buf_low_4bit >> 4;
    emu->registers[A] += ImDate;
    buf_low_4bit = 0x00;
    if(emu->registers[A] >= 0x100){
        emu->Cflag = true;
    }
    emu->registers[C]++;
    cout << "execute add A Im" << endl;
}

static void mov_A_B(TD4_emulator *emu){
    emu->registers[A] = emu->registers[B];
    emu->registers[C]++;
    cout << "execute mov A B" << endl;
}

static void in_A(TD4_emulator *emu){
    emu->registers[A] = emu->input_date;
    emu->registers[C]++;
    cout << "execute in A" << endl;
}

static void mov_A_Im(TD4_emulator *emu){
    unsigned char buf_low_4bit,Mcode = emu->memory[emu->registers[C]];
    buf_low_4bit = Mcode << 4;
    unsigned char ImDate = buf_low_4bit >> 4;
    emu->registers[A] = ImDate;
    emu->registers[C]++;
    cout << "execute mov A Im" << endl;
}

static void mov_B_A(TD4_emulator *emu){
    emu->registers[B] = emu->registers[A];
    emu->registers[C]++;
    cout << "execute mov B A" << endl;
}

static void add_B_Im(TD4_emulator *emu){
    unsigned char buf_low_4bit,Mcode = emu->memory[emu->registers[C]];
    buf_low_4bit = Mcode << 4;
    unsigned char ImDate = buf_low_4bit >> 4;
    emu->registers[B] += ImDate;
    emu->registers[C]++;
    cout << "execute add B Im" << endl;
}

static void in_B(TD4_emulator *emu){
    emu->registers[B] = emu->input_date;
    emu->registers[C]++;
    cout << "execute in B" << endl;
}

static void mov_B_Im(TD4_emulator *emu){
    unsigned char buf_low_4bit,Mcode = emu->memory[emu->registers[C]];
    buf_low_4bit = Mcode << 4;
    unsigned char ImDate = buf_low_4bit >> 4;
    emu->registers[B] = ImDate;
    emu->registers[C]++;
    cout << "execute mov B Im" << endl;
}

static void out_B(TD4_emulator *emu){
    emu->registers[D] = emu->registers[B];
    emu->registers[C]++;
    cout << "execute out B" << endl;
}

static void out_Im(TD4_emulator *emu){
    unsigned char buf_low_4bit,Mcode = emu->memory[emu->registers[C]];
    buf_low_4bit = Mcode << 4;
    unsigned char ImDate = buf_low_4bit >> 4;
    emu->registers[D] = ImDate;
    emu->registers[C]++;
    cout << "execute out Im" << endl;
}

static void jnc(TD4_emulator *emu){
    unsigned char buf_low_4bit,Mcode = emu->memory[emu->registers[C]];
    buf_low_4bit = Mcode << 4;
    unsigned char ImDate = buf_low_4bit >> 4;
    // if Cflag==0 than jmp 
    if(!emu->Cflag){
        buf_low_4bit = emu->registers[A] << 4;
        emu->registers[A] = buf_low_4bit >> 4;
        emu->registers[C] = ImDate;
    }else{
        // if exexute jnc, Cflag is zero.
        emu->Cflag = false;
        emu->registers[C]++;
    }
    cout << "execute jnc" << endl;
}

static void jmp(TD4_emulator *emu){
    unsigned char buf_low_4bit,Mcode = emu->memory[emu->registers[C]];
    buf_low_4bit = Mcode << 4;
    unsigned char ImDate = buf_low_4bit >> 4;
    emu->registers[C] = ImDate;
    cout << "execute jmp" << endl;
}

static void nop(TD4_emulator *emu){
    emu->registers[C]++;
    cout << "execute nop" << endl;
}

void init_instructions(){
    instructions[NOP] = nop;
    instructions[ADD_A_IM] = add_A_Im; 
    instructions[MOV_B_IM] = mov_B_Im;
    instructions[MOV_A_B] = mov_A_B;
    instructions[MOV_B_A] = mov_B_A;
    instructions[ADD_B_IM] = add_B_Im;
    instructions[IN_A] = in_A;
    instructions[IN_B] = in_B;
    instructions[OUT_IM] = out_Im;
    instructions[OUT_B] = out_B;
    instructions[JMP] = jmp;
    instructions[JNC] = jnc;
    cout << "init instructions" << endl;
    return;
}