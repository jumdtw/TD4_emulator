#include<string.h>
#include<stdlib.h>
#include<bitset>
#include<windows.h>
#include"graphic.hpp"
#include"TD4_emu.hpp"
#include"instruction.hpp"
#include"debug.hpp"

bool aa = true;

TD4_emulator* init_emulator(){
    TD4_emulator *emu = new TD4_emulator;
    cout << "init registers" << endl;
    return emu;
}

char onbit_register(char D){
    char num = 0;
    if(D&1>=1){num++;}
    if(D&2>=1){num++;}
    if(D&4>=1){num++;}
    if(D&8>=1){num++;}
    return num;
}

void output_LED(char onled){
    char LED_num = 4;
    char offled = LED_num - onled;
    if(aa){
        for(char i=1;i<=offled;i++){
        cout << "o ";
        }
        for(char i=1;i<=onled;i++){
            cout << "0 ";
        }
        aa = false;
    }else{
        for(char i=1;i<LED_num;i++){
            cout << "o ";
        }
        aa = true;
    }
    
    cout << "\r";
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
    
    bool debugFlag = false,timerflag = false,readonlyflag = false;
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
                if(*p=='t'){
                    timerflag = true;
                }
                if(*p=='r'){
                    readonlyflag = true;
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


    while(emu->registers[C]<=0x0f&&readonlyflag==false){
        unsigned char Mcode = emu->memory[emu->registers[C]];
        unsigned char opcode = Mcode >> 4;
        if(timerflag){
            output_LED(onbit_register(emu->registers[D]));
            Sleep(500);
        }
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