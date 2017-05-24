/* 
Members: Christian Barajas, Christian Cosby, Kevin Nguyen, Wanqi Chan
Account: masc0833
Team:    Alabama       
Assignment: prog3
FileName: symtab.cc
Class: CS530, Spring 2016

*/

#include <string>
#include <map>
#include <sstream>
#include "symtab.h"
#include "symtab_exception.h"

using namespace std;	

symtab::symtab(){}
symtab::~symtab(){}

// adds to symbol table and assigns an address to each line of code.
void symtab::insert_symbol(string label,string address,unsigned int lineNum){
	map<string,string>::iterator symbol_iter = symbol_table.find(label);
	if(symbol_iter != symbol_table.end()){ 
		string Error = "Symbol " + label + " already exists at that line. ";
		error_help(Error,lineNum);
	}
	symbol_table[label] = address;
}

// checks symbol table to see if a specific string exists in the table 
bool symtab::contains_symbol(string s){
	map<string,string>::iterator contains_iter = symbol_table.find(s);
	if (contains_iter != symbol_table.end()){
		return true;
	}
	else{
		return false;
	}
	
}

// returns value using its associated key pair.
string symtab::get_value(string key){
	map<string,string>::iterator iter = symbol_table.find(key);
	if( iter == symbol_table.end()){
		return "";
	}
	return symbol_table[key];
	
}
	
		

void symtab::error_help(string s,unsigned int lineNum){
	stringstream sstream;
	sstream << lineNum;
	string lineString = sstream.str();
	throw symtab_exception(s + lineString + ".");
}

