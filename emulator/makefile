SRCS = framework/main.cpp framework/gfx.cpp framework/debugger.cpp sys_processor.cpp hardware.cpp sys_debug_elf.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

EXE_NAME = elf2

%.o: %.cpp *.h
	g++ -c -DINCLUDE_DEBUGGING_SUPPORT -Iframework -I/usr/include/SDL2 -I. -w -o $(patsubst %.cpp,%.o,$<) $<


#This is the target that compiles our executable 
all : $(OBJS) 
	g++ $(OBJS) -lSDL2 -o $(EXE_NAME)

clean:
	rm -f $(OBJS)


