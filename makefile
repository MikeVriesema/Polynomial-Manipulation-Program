##########################################################
# Assignment 3 CE4703
# makefile
# 
# Makefile that compiles targets for polynomial project
# And executes the final file and runs the clean target
# 
# Authors: Mike Vriesema 17212359 
# 			Luke O'Sullivan Griffin 17184614 
# 			Ryan O'Connor 17209382 
# 			Conall McAteer 18173586 
# 			Gearoid Kirwan 17213266
# 
# Date Last Modified: 22.11.2018
##########################################################

# Lists targets to be executed in the makefile
exec := project polynomial.o linkedlist.o mainProgram.o clean

# Sets variables for use in makefile
poly := polynomial
link := linkedlist
main := mainProgram

all: $(exec)

# Compile the polynomial .c & .h files into .o 
polynomial.o: $(poly).c $(poly).h 
	gcc -Wall -ggdb -c $(poly).c 

# Compile the linkelist .c & .h files into .o
linkedlist.o: $(link).c $(link.h)
	gcc -Wall -ggdb -c $(link).c

# Compile the main application .c file into .o 
mainProgram.o: $(main).c
	gcc -Wall -ggdb -c $(main).c

# Link components to create the project executable
# This object has dependency on the other targets 
# Compiles the final project using the 2 other object files and runs the application
project: $(poly).o  $(link).o $(main).o
	gcc -o project $(poly).o $(link).o $(main).o
	./project

# Sets a clean target when finished by removing all .o files and the final project file
clean:
	rm -f *.o project
