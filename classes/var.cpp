/**
Copyright (C) 2012, Edward Chernysh
All rights reserved.

This project is part of Zenon Scripting.
Creating Var support for C++.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <EDWARD CHERNYSH> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include "../include/var.h"

using namespace std;

/// <usage>
/// Define a namespace to be used to declare a variable class.
/// To delcare a variable: <var var;> (for example)
/// This class contains 4 different data types: (string, int, char and floating point)
/// They can all be empty or full. This area does not restrict usage in any way.
/// ------------------------------------------------------------------------------
/// To access a data type (int for example):
//  var.value = 107; // this will set var.integer = 107
/// </usage>


/* DEFINED IN variable_DECLARATION_HEADER */

namespace variable {         


void char_int_value(char& _targetchar) { _targetchar=(int)_targetchar; };

/**
*
* ========================== The Linker Struct ========================== *
*
**/


void DATA_LINKERS::link_integers(int *lhs, int& rhs) { lhs = &rhs; };

/**
*
* ========================== Variable Conversions ========================== *
*
**/

char VAR_CONVERTER::integers::ToChar(int integer) { return (char)integer; };
char* VAR_CONVERTER::integers::ToString(int _it) { return (char) _it; };

          
/*------------------------------------var class--------------------------------------------*/  

void var::integer_init(int val) {value = val; };
void var::character_init(char c) { character = c; };
void var::float_init(float f) { floating = f; };

/* class functions */

void mimic(var & _target_class,var &_leader) { _target_class = _leader; };
void link(var *_dependent, var _independent) { _dependent = &_independent; };

/* integer functions */

void var::integer_increment(int i) { value+= i; };
void var::externalIncrement(int& _directed, int _size) { _directed+=_size; }; 
int* var::addressOfInt()
{
    int *p = &value;     
    return p;
}

string var::ToString(int i)
{
    string istr = "";
    istr += i;
    return istr;
}

char var::ToChar() { return (char)value; };
bool var::intCompare(int icmp) { return (value == icmp);  };
void var::intEquals(int t_val) { value = t_val; };

/* character functions */

bool var::chck(char c, char d)
{
   bool retval;
   if (c == d)
      retval = true;
   else retval = false;
  
  return retval;                                          
}

void var::charcpy(char*a, char c[])
{
   c[strlen(a) + 1];  
   strcpy(c,a);
   c[strlen(a)] = '\0';
}

char var::charAddress() { return character; };
bool var::charCompare(char cmp) { return ((int)cmp == character); };
int var::charToInt() { return (int)character; };
void var::charEquals(char nval) { character = nval; };

/* floats */

void var::float_increment(float fval) { floating += fval; };
float* var::addressOfFloat()
{
       float *fpointer = &floating;       
       return fpointer;
}
bool var::floatCompare(float fcmp) { return (int)(floating == fcmp); };
void var::floatEquals(float nv) { floating = nv; };


void var::textStringInit(string str) { text = str; };
bool var::stringCompare(string scmp) { return (text == scmp); };
void var::Clone(string data_holder) { data_holder = text; };

void var::stringConcat(string a) { text+=a; };
void var::stringConcat(string a, string b) { (a+=b); text+=a; };
void var::stringConcat(string a, string b, string c) { (a+=b); (a+=c); text+=a; };
void var::stringConcat(string _first, string _second, string _third, string _fourth)
{
    _first += _second;
    _first += _third;
    _first += _fourth;
    text += _first;
}
void var::CopyTo(string data_holder) { data_holder = text; };

int var::Count() { return text.size(); };
unsigned long var::LongCount() { return (text.size() + 1); };

bool var::stringContains(string _data)
{ 
string::size_type loc = text.find( _data, 0 );  
if (loc != UID)
   return false;
else return true;
}

void var::stringEquals(string new_data) { text = new_data; };
const char *var::ToCStr() { return text.c_str(); };
int var::indexOf(string dt)
{
    int index = text.find(dt, 0);
    return index;   
}
void var::stringJoin(string _iter) { text+=_iter; };
int var::Length() { return text.size() + 1; };
string var::stringReverse()
{
    char chars[text.size() + 1];       
    std::copy(text.begin(), text.end(), chars);
    chars[text.size()] = '\0';
    string reversed;
    for (int i = (sizeof(chars)); i >= 0; i--)
        reversed+=chars[i];
    delete[] chars;
    return reversed;                 
}

string var::removeNullSpaces()
{
    char chars[text.size() + 1];       
    std::copy(text.begin(), text.end(), chars);
    chars[text.size()] = '\0';
    string cleared;    
    for (int i = 0; i < sizeof(chars); i++)
    { 
      if (chars[i] != ' ')
         cleared+=chars[i];
    }  
    delete[] chars;
    return cleared;
}

char var::FirstChar()
{   
   char array[text.size()];
   std::copy(text.begin(), text.end(), array);
   array[text.size()] = '\0';
   return array[0];
   delete[] array;
}

char var::LastChar()
{
   char array[text.size() + 1]; 
   std::copy(text.begin(), text.end(), array);
   array[text.size()] = '\0';
   return array[text.size() -1];
   delete[] array;    
}



void var::ToCharacterArray(char _result[] , unsigned const int buffer_size)
{
    _result[buffer_size + 1];
    std::copy(text.begin(), text.end(), _result);
    _result[buffer_size] = '\0';
	return;
}

string var::ToUpper()
{
  std::string str = text;
  std::transform(str.begin(), str.end(),str.begin(), ::toupper);
  return str;
}

string var::ToLower() 
{
  std::string str = text; 
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
       
}

bool var::Contains(char _iterate) { int cnt = text.find(_iterate, 0); if (cnt != (-1)) return true; else return false; };
bool var::Contains(string s_iterate) { int cnt = text.find(s_iterate, 0); if (cnt != (-1)) return true; else return false; };

bool var::isEmpty() { if (!text.empty()) return false; else return true; };

/**
*
* Notice from developer:
         if any problems occur remove THE FOLLOWING FIRST
         as it is the most volatile part of this program.
*
**/

std::vector<int> *var::ToIntArray() 
{
    char nl[text.size() + 1];
    std::copy(text.begin(), text.end(), nl);          
    nl[text.size()] = '\0';
    
    std::vector<int> _iter (sizeof(nl));
    for (int i = 0; i < sizeof(nl); i++)
        _iter[i] = (int)nl[i];
    return &_iter;   
}
};

namespace abtract_data {
          void link_integers(int *_pointer, int& _data) { _pointer = &_data; };
};
