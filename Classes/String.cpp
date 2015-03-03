#include "String.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>


String::String(){

	length_string = 1; 
	characters = new char[length_string];
	characters[0] = '\0';

}

String::String(const char* format, ...){

	length_string = 0;
	if (format != NULL) {
		char vars[4096];
		va_list args;
		va_start(args, format);
		int len = vsnprintf_s(vars, 4096, format, args);
		va_end(args);
		if (len > 0) {
			length_string = len + 1;
			characters = new char[length_string];
			strcpy_s (characters, length_string, vars);
		}
	}
	if (length_string == 0){

		length_string = 1;
		characters = new char[length_string];
		characters[0] = '\0';
	}
		
	
}

String::String(const String& a){

	length_string = strlen(a.characters) + 1;
	characters = new char[length_string];
	strcpy_s(characters, length_string, a.characters);


}

String::~String(){
	delete[] characters;
}


bool String::operator == (const String& a) const {

	if (strcmp(a.characters, characters) == 0)
		return 1;
	else
		return 0;
}

bool String::operator == (const char* a)  const {

	if (a != NULL) {
		if (strcmp(characters, a) == 0)
			return 1;
	}
	return 0;
	

}

bool String::operator != (const String& a) const {

	if (strcmp(a.characters, characters) == 0)
		return 0;
	else
		return 1;

}

bool String::operator != (const char* a) const {

	if (a != NULL) {
		if (strcmp(characters, a) == 0)
			return 0;
	}
	return 1;
	
}


String& String::operator = (const String& a) {

	if (strlen(a.characters) + 1 > length_string) {
			delete[] characters;
			characters = new char[strlen(a.characters) + 1];	
		}

		else 
		clear();
	strcpy_s(characters, length_string, a.characters);
	return(*this);
	
}

String& String::operator = (const char* a) {

		if (a != NULL){
			if (strlen(a) + 1 > length_string) {
				delete[] characters;
				characters = new char[strlen(a) + 1];
			}
			else {
				clear();
				strcpy_s(characters, length_string, a);
			}
		}
		else{
			clear();
		}
		return(*this);

}

String& String::operator += (const String& a){

	if (length_string < strlen(characters) + strlen(a.characters))
		{
			char* string_aux = new char[strlen(characters) + 1];
			strcpy_s(string_aux, strlen(characters) + 1, characters);
			length_string = strlen(characters) + strlen(a.characters) + 1;
			delete[] characters;
			characters = new char[length_string];
			strcpy_s(characters, strlen(string_aux), string_aux);
			delete[] string_aux;
		}

	strcat_s(characters, length_string, a.characters);
	return (*this);
	
}

String& String::operator += (const char* a){
	if (a != NULL)
	{
		if (length_string < strlen(characters) + strlen(a))
		{
			char* string_aux = new char[strlen(characters) + 1];
			strcpy_s(string_aux, strlen(characters) + 1, characters);
			length_string = strlen(characters) + strlen(a) + 1;
			delete[] characters;
			characters = new char[length_string];
			strcpy_s(characters, strlen(string_aux), string_aux);
			delete[] string_aux;
		}

		strcat_s(characters, length_string, a);

	}
	return (*this);
}



unsigned int String::length()const {
	return strlen(characters);
}

unsigned int String::capacity()const {
	return length_string;
}

char* String::getString()const {
	return (characters);
}

void String::clear() {
	
	for (unsigned int i = 0; i < length_string; i++)
		characters[i] = '\0';
}


	


