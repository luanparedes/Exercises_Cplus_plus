
# Name of the project
PROJ_NAME=matrix

# .c files
C_SOURCE=$(wildcard ./Source/*.cpp)

# Object files
OBJ=$(subst .cpp,.o,$(subst source,objects,$(C_SOURCE)))

# Compiler
CC=g++

# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic  \
		 -lstdc++

#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./Objects/%.o: ./Source/%.cpp
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '
	
./Objects/$(PROJ_NAME).o: ./Source/$(PROJ_NAME).cpp
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ if not exist "Objects" mkdir "Objects"

cleanExe:
	del $(PROJ_NAME).exe
	
cleanObj:
	rmdir /s Objects

clean:
	del $(PROJ_NAME).exe
	rmdir /s Objects

.PHONY: all clean