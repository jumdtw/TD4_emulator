#include"TD4_emu.hpp"
#include"graphic.hpp"

void dump_registers(TD4_emulator *emu){
    cout << "---------------------------" << endl;
    cout << "Register A  = " << emu->registers[A] << endl;
    cout << "Register B  = " << emu->registers[B] << endl;
    cout << "Register C  = " << emu->registers[C] << endl;
    cout << "Register D  = " << emu->registers[D] << endl;
    cout << "---------------------------" << endl;
    return;
}