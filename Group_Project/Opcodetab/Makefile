#Members: Christian Barajas, Christian Cosby, Kevin Nguyen, Wanqi Chan
#Account: masc0833
#Team:    Alabama       
#Assignment: prog2
#FileName: opcodetab.h
#Class: CS530, Spring 2016


TORM = file_parser.o opcodetab.o
CC = g++
CCFLAGS = -g -O3 -Wall

opcodetab.o:   opcodetab.cc opcodetab.h opcode_error_exception.h
	${CC} ${CCFLAGS} -c opcodetab.cc

file_parser.o: file_parser.h file_parse_exception.h file_parser.cc
	${CC} ${CCFLAGS} -c file_parser.cc

clean: 
	rm -f ${TORM}
