#ifndef TD4_EMULATOR_H_
#define TD4_EMULATOR_H_

enum Register { A, B, C, D, EGISTERS_COUNT,};

typedef struct {
    
    char registers[EGISTERS_COUNT];
    char* memory;

} TD4_emulator;
#endif 