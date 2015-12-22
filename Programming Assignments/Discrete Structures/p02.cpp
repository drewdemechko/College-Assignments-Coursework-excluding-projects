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

//File p02.cpp
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

#include "List02.h"
using namespace std;

  struct CommandLineException{
    CommandLineException(int max, int actual)
    {
      cout<<endl<<"Too many command line arguments."<<endl;
      cout<<"A maximum of"<<max<<" arguments are permitted."<<endl;
      cout<<actual<<" arguments were entered."<<endl;
    }
  };

  struct FileException{
    FileException(const char* fn)
    {
      cout<<endl<<"File "<<fn<<" could not be opened."<<endl;
    }
  };

  string Pair(string x, string y)
  {
    return "(" + x + "," + y + ")";
  }

  void CartesianProduct(List& L1, List& L2, List& C)
  {
    for(L1.First(); !L1.isEoi(); L1.Next())
    {
      for(L2.First(); !L2.isEoi(); L2.Next())
      {
        C.Insert(Pair(L1.Member(), L2.Member()));
      }
    }
  }

  void CartesianMgr(istream& i1, istream& i2, ostream& o)
  {
    List L1(i1,100); L1.Print(o,"L1");
    List L2(i2,100); L2.Print(o,"L2");
    List C;
    CartesianProduct(L1,L2,C);
    C.Print(o,"L1 X L2 ");
  }

  int main(int argc, char* argv[])
  {
  try
  {
    char ifn1[255],ifn2[255],ofn[255]; //Input and output file names
    switch(argc)
    {
      case 1:               //Prompt for all three file names
        cout<<"Enter the first input file name.";
        cin>>ifn1;
        cout<<"Enter the second input file name.";
        cin>>ifn2;
        cout<<"Enter the output file name.";
        cin>>ofn;
        break;
      case 2:               //Prompt for the second input and output file name
        strcpy(ifn1,argv[1]);
        cout<<"Enter the second input file name.";
        cin>>ifn2;
        cout<<"Enter the output file name.";
        cin>>ofn;
        break;
      case 3:               //Both input file names are arguments
        strcpy(ifn1,argv[1]);
        strcpy(ifn2,argv[2]);
        cout<<"Enter the output file name.";
        cin>>ofn;
        break;
      case 4:              //Read all three file names
        strcpy(ifn1,argv[1]);
        strcpy(ifn2,argv[2]);
        strcpy(ofn,argv[3]);
        break;
      default:
        throw CommandLineException(3,argc-1);
    }  

    ifstream i1(ifn1);if(!i1)throw FileException(ifn1);
    ifstream i2(ifn2);if(!i2)throw FileException(ifn2);
    ofstream o(ofn);if(!o)throw FileException(ofn);
    CartesianMgr(i1,i2,o);
    //Read the input file, process input data, and write to the output file
    o.close();
    i1.close();
    i2.close();
  }catch(...){
    cout<<"Program terminated."<<endl;
    exit(EXIT_FAILURE);
  }
    return 0;
  }
