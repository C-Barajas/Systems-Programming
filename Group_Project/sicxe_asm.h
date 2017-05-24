/* 
Members: Christian Barajas, Christian Cosby, Kevin Nguyen, Wanqi Chan
Account: masc0833
Team:    Alabama       
Assignment: prog3
FileName: sicxe_asm.h
Class: CS530, Spring 2016

*/


#ifndef SICXE_ASM_H
#define SICXE_ASM_H
#include <string>	
#include <map>
#include "file_parser.h"
#include "opcodetab.h"
#include "symtab.h"

class sicxe_asm{

	// opcodes we are testing 
	const string directives [] = {
				"START","END","BYTE","WORD","RESB","RESW","BASE","NOBASE","EQU"};
			
	public:
		sicxe_asm(string);
		~sicxe_asm();
		void pass1(file_parser,string);
	private:
		struct Listing_File_Row{
			int line_number;
			string address;
			string label;
			string opcode;
			string operand;
			string machine_code;};
		vector <Listing_File_Row> lis_container;	
	
		opcodetab opcode_table;
		symtab symbol_table;
		
		
		
		
		void write_listing_file(string);
		bool is_directive(string);
		void directive_handler(bool *strt,bool *end,string,string,string,string *addr,unsigned int); 
		
		//directive helpers are called from directive handler method	
		void start_helper(string,string *pntr,unsigned int);
		void byte_helper(string,string *pntr,unsigned int);
		void resb_helper(string,string *pntr,unsigned int);
		void resw_helper(string,string *pntr,unsigned int);
		
		void equ_handler(string,string,string,unsigned int);
		void symtab_handler(string,string,string,unsigned int);
		string increment_address(string,int);
		
		unsigned int string_to_hex(string);
		unsigned int add_hex(unsigned int,unsigned int);
		string hex_to_string(unsigned int);
		string to_upper(string);
		bool is_number(string s);
		bool is_num_hex(string s);
		void operand_safety_check(string,unsigned int);
		void opcode_error_helper(string, unsigned int);
		void symtab_error_helper(string, unsigned int);
		
};

#endif
