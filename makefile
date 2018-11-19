
###################################################
# Assignment 2 CE4703
# 
# makefile
# makefile that compiles and runs all the targets for the shape project.

# Author: Mike Vriesema 17212359
# Date Last Modified: 19.11.2018
###################################################

# Lists targets to be executed in the makefile
exec := project twoDimensions.o threeDimensions.o mainProgram.o clean

# Sets variables for use in makefile
twoD := twoDimensions
threeD := threeDimensions
main := mainProgram

all: $(exec)

# Compile the 2D functions .c & .h files into .o 
twoDimensions.o: $(twoD).c $(twoD).h 
	gcc -Wall -ggdb -c $(twoD).c 

# Compile the 3D functions .c & .h files into .o 
threeDimensions.o: $(threeD).c $(threeD).h 
	gcc -Wall -ggdb -c $(threeD).c

# Compile the main application .c file into .o 
mainProgram.o: $(main).c
	gcc -Wall -ggdb -c $(main).c

# Link components to create the project executable
# This object has dependency on the other targets 
# Compiles the final project using the 3 other object files and runs the application
project: $(twoD).o $(threeD).o $(main).o
	gcc -o project $(twoD).o $(threeD).o $(main).o
	./project

# Sets a clean target when finished by removing all .o files and the final project file
clean:
	rm -f *.o project
