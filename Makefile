CC = g++
OBJS = TD4_emu_main.o instruction.o debug.o
CFLAGS += -Wall -g
TARGET = TD4.exe
#BINFILE = binfile
DEL = del

%.o : %.c Makefile
	$(CC) $*.c -c -o $*.o

$(TARGET) : $(OBJS) Makefile
	$(CC) -o $@ $(OBJS)

run : $(TARGET) #$(BINFILE)
	$(TARGET)

clean :
	$(DEL) $(OBJS) 