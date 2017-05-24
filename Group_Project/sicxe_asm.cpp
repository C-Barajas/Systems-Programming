/* 
Members: Christian Barajas, Christian Cosby, Kevin Nguyen, Wanqi Chan
Account: masc0833
Team:    Alabama       
Assignment: prog3
FileName: sicxe_asm.cpp
Class: CS530, Spring 2016

*/


#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <fstream> 

#include "file_parser.h"
#include "file_parse_exception.h"
#include "opcodetab.h"
#include "opcode_error_exception.h"
#include "symtab.h"
#include "symtab_exception.h"
#include "sicxe_asm.h"


using namespace std;


int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "Error, you must supply at least and no more than 1 file name to be processed." << endl;
        	exit(1);
	}
    
	new sicxe_asm(argv[1]);
	return 0;
}


sicxe_asm::sicxe_asm(string filename){
	try{
		file_parser parser(filename);
		pass1(parser,filename);
		BASE_ADDRESS = "";
	}
	catch(file_parse_exception excpt){
		 cout << "**Sorry, error " << excpt.getMessage() << endl;
	}
	catch(opcode_error_exception excpt){
		 cout << "**Sorry, error " << excpt.getMessage() << endl;
	}
	catch(symtab_exception excpt){
		 cout << "**Sorry, error " << excpt.getMessage() << endl;
	}
	
}


sicxe_asm::~sicxe_asm(){}

