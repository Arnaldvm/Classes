#ifndef __String_H__
#define __String_H__

#include <string.h>
#include <stdio.h>

using namespace std;

class String{

public:
	//Constructors
	String();
	String(const char* format, ...);
	String(const String& a);
	~String();

public:
	//Variables
	char* characters; //cadena de caracters
	unsigned int length_string; //longitud de la cadena


	//Operators
	bool operator == (const String& a) const;
	bool operator == (const char* a) const;

	bool operator != (const String& a)const;
	bool operator != (const char* a)const;

	String& operator = (const String& a);
	String& operator = (const char* a);

	String& operator += (const String& a);
	String& operator += (const char* a);
	
	//Utilities
	unsigned int length() const;//funció per a saber la longitud de la cadena
	unsigned int capacity() const;
	char* getString() const;
	void clear(); 
	

};

#endif