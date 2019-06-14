CC = g++
OBJS = TD4_emu_main.o instruction.o debug.o
HEAD = TD4_emu.hpp
CFLAGS += -Wall -g
TARGET = TD4.exe
BINFILE = TD4bin.td
RUNOPTION = -d -f 
DEL = del

%.o : %.c Makefile
	$(CC) $*.c -c -o $*.o

$(TARGET) : $(OBJS) $(HEAD) Makefile
	$(CC) -o $@ $(OBJS)

run : $(TARGET) $(BINFILE)
	$(TARGET) $(RUNOPTION) $(BINFILE)

clean :
	$(DEL) $(OBJS) 