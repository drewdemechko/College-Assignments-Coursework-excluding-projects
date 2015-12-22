/*
Author Identification Block
Author:        Mr. Drew Demechko
Student ID:    *20348325
E-Mail:        ddemechko@uco.edu
Course:        CMSC 2123 - Discrete Structures
CRN:           11786 Fall 2015
Project:       p02
Due:           September 18, 2015
Account:       tt009
*/

//File List02.cpp
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<fstream>
#include<string>
#include "List02.h"
using namespace std;

struct ListException {
  ListException(const char* m)
  {
    cout<<endl;
    cout<<"List "<<m<<" contains an error."<<endl;
  }
};

List::List(int size):size(size),count(0),cursor(0)//(int size);
//(int size(0))//,int count(0))//int cursor(0))
{
  L = new string[size];
}

List::List(istream& i, int size):size(size),count(0),cursor(0)
{
  L = new string[size]; Scan(i);
}

List::~List()
{
if(L) delete[] L;
}

bool List::isFull(void)
{
return (count >= size-1);
}

void List::Insert(string v)
{
  if(isFull()) 
    throw ListException("full");
  L[count++] = v;
}

void List::Scan(istream& i)
{
  for(;;)
  {
   string v;
   i>>v;
   if(i.eof())
     break;
   Insert(v);
  }
}

void List::Print(ostream& o, const char* title)
{
  o<<endl<<title;
  o<<"={";
  for(int a = 0; a < count; a++)
  {
    if(a>0) o<< ",";
    o <<L[a];
  }  
  o << "}" <<endl;
}

void List::First(void)
{
  cursor = 0;
}

void List::Next(void)
{
  if(cursor<=count)cursor++;
}

bool List::isEoi(void)
{
  return cursor>=count;
}
string List::Member(void)
{
  return L[cursor];
}
