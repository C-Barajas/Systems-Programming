# Members: Christian Barajas, Christian Cosby, Kevin Nguyen, Wanqi Chan
# Team:    Alabama       
# Account: masc0833
# Assignment: prog1
# FileName: Makefile
# Class: CS530, Spring 2016


TORM = file_parser.o driver.o driver
CC = g++
CCFLAGS = -g -O3 -Wall

driver: driver.o file_parser.o
	${CC} ${CCFLAGS} -o driver driver.o file_parser.o

driver.o: driver.cpp
	${CC} ${CCFLAGS} -c driver.cpp

file_parser.o: file_parser.h file_parse_exception.h file_parser.cc
	${CC} ${CCFLAGS} -c file_parser.cc

clean: 
	rm -f ${TORM}



