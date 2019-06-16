CC = g++
OBJS = TD4_emu_main.o instruction.o debug.o
HEAD = TD4_emu.hpp
CFLAGS += -Wall -g
TARGET = TD4.exe
TESTBINFILE = TD4bin
TIMEFILE = timefile
RUNOPTION = -d -f 
DEL = del

%.o : %.c Makefile
	$(CC) $*.c -c -o $*.o

$(TARGET) : $(OBJS) $(HEAD) Makefile
	$(CC) -o $@ $(OBJS)

run : $(TARGET) $(TESTBINFILE)
	$(TARGET) $(RUNOPTION) $(TESTBINFILE)

nodebugrun : $(TARGET) $(TESTBINFILE)
	$(TARGET) -f $(TESTBINFILE)

runtimer : $(TARGET) $(TIMEFILE)
	$(TARGET) -t -f $(TIMEFILE)

readmemory : $(TARGET) $(TIMEFILE)
	$(TARGET) -r -f $(TIMEFILE)


clean :
	$(DEL) $(OBJS) 

delete :
	$(DEL) $(TARGET)