#include<string.h>
#include<stdlib.h>
#include<bitset>
#include"graphic.hpp"
#include"TD4_emu.hpp"
#include"instruction.hpp"
#include"debug.hpp"


TD4_emulator* init_emulator(){
    TD4_emulator *emu = new TD4_emulator;
    cout << "init registers" << endl;
    return emu;
}

int Read_binaryfile(char *filename,TD4_emulator *emu){
    FILE *fp;
    unsigned char buf[100];
    fp = fopen(filename,"rb");
    if(fp==NULL){
        cout << "can`t open file" << endl;
        return -1;
    }
    int size = fread(buf,sizeof(unsigned char),16,fp);
    if(size>16){
        cout << "file size error" << endl;
    }
    for(int i=0;i<=size;i++){
        emu->memory[i] = buf[i];
    }
    return 0;
}

void Delete_emu(TD4_emulator* emu){
    delete emu->memory;
    delete emu;
    cout << "delete emulator" << endl;
    return;
}



int main(int argc,char *argv[]){
    bool debugFlag = false;
    char *filename;
    if(argc>=2){
        for(int i=0;i<argc;i++){
            char *p = argv[i];
            if(*p=='-'){
                p++;
                if(*p=='d'){
                    debugFlag = true;
                }
                if(*p=='h'){

                }
                if(*p=='f'){
                    filename = argv[i+1];
                }
            }
        }
    }
    //init emulator
    int endflag = 0;
    TD4_emulator *emu;
    emu = init_emulator();
    cout << "create emulator" << endl;
    if(Read_binaryfile(filename,emu)==(-1)){
        return -1;
    }
    cout << "read file" << endl;
    init_instructions();
    //execute
    cout << "----------------execute code---------------------" << endl;
    
    /*
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
    oprand = OUT_IM;
    asmcode = (oprand << 4) + 0xf;
    emu->memory[7] = asmcode;
    oprand = OUT_B;
    asmcode = (oprand << 4) + 0x0;
    emu->memory[8] = asmcode;
    oprand = ADD_A_IM;
    asmcode = (oprand <<4 ) + 0xf;
    emu->memory[9] = asmcode;
    oprand = JNC;
    asmcode = (oprand << 4) + 0xD;
    emu->memory[10] = asmcode;
    */


    while(emu->registers[C]<=0x0f){
        unsigned char Mcode = emu->memory[emu->registers[C]];
        unsigned char opcode = Mcode >> 4;
        cout << int(emu->registers[C]) << ",    ";
        instructions[opcode](emu);
        if(debugFlag){
            dump_registers(emu);
            getchar();
        }
    }
    cout << "-------------------------------------------------" << endl;
    cout << "\n" << endl;
    //end emulator
    dump_registers(emu);
    dump_memory(emu);
    Delete_emu(emu);
    return 0;
}