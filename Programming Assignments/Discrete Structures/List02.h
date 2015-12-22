#ifndef List02_h
#define List02_h 1
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

//file List02.h
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

  class List
  {
    int size;    //Number of available elements
    int count;   //Index of the next available element
                 //number of occupied elements
    string *L;   //Pointer to an array of strings used to implement the list
    int cursor;  //Index of the current element

  public:
    List(int sz=100);
    List(istream& i, int sz = 100);
    ~List();
    bool isFull(void);
    void Insert(string v);
    void Scan(istream& i);
    void Print(ostream& o, const char* title);
    void First(void);
    void Next(void);
    bool isEoi(void);
    string Member(void);
  };
#endif
