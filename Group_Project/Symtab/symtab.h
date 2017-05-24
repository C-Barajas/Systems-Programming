/* 
Members: Christian Barajas, Christian Cosby, Kevin Nguyen, Wanqi Chan
Account: masc0833
Team:    Alabama       
Assignment: prog3
FileName: symtab.h
Class: CS530, Spring 2016

*/


#ifndef OPCODETAB_H
#define OPCODETAB_H
#include <string>
#include <map>


using namespace std;

class file_parser {
    public:
        // constructor
	symtab();
	
	// destructor
	~symtab();
	
	void insert_symbol(string,string,unsigned int);
	bool contains_symbol(string);
	string get_value(string);
        
    private:
        // your variables and private methods go here
	
	map<string,string> symbol_table;
	void error_help(string,unsigned int);
};

#endif 
