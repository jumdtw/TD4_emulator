#include"TD4_emu.hpp"
#include"graphic.hpp"
#include<bitset>

void dump_registers(TD4_emulator *emu){
    cout << "----------registers dump-----------" << endl;
    cout << "Register A  = " << bitset<8>(emu->registers[A]) << endl;
    cout << "Register B  = " << bitset<8>(emu->registers[B]) << endl;
    cout << "Register C  = " << bitset<8>(emu->registers[C]) << endl;
    cout << "Register D  = " << bitset<8>(emu->registers[D]) << endl;
    cout << "-----------------------------------" << endl;
    cout << "\n" << endl;
    return;
}

void dump_memory(TD4_emulator *emu){  
    cout << "-----------memory dump ---------" << endl;
    for(int i=0;i<16;i++){
        cout << "memory " << i  << " = " << bitset<8>(emu->memory[i]) << endl; 
    }
    cout << "--------------------------------" << endl; 
    cout << "\n" << endl; 
    return;
}