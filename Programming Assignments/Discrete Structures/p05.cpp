/*
Author:        Mr. Drew Demechko
Student ID:    *20348325
E-Mail:        ddemechko@uco.edu
Course:        CMSC 2123 - Discrete Structures
CRN:           11786 Fall 2015
Project:       p05
Due:           October 14, 2015
Account:       tt009
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct CommandLineException
{
  CommandLineException(int max,int actual)
  {
    cout << endl << "Too many command line arguments." << endl;
    cout << "A maximum of " << max << " arguments are permitted." << endl;
    cout << actual << " arguments were entered." << endl;
  }
};

struct FileException
{
  FileException(const char* fn)
  {
    cout << endl << "File " << fn << " could not be opened." << endl;
  }
};

int ef5(int num)
{
  int cost = 0;
  int sum = 0; cost++;
  int i = 0; cost++;

  while (i < num){ cost++;
    i++; cost++;
    int j = 0; cost++;
    while(j < i){ cost++;
      j++; cost++;
      sum ++; cost++;
    } cost++;
  } cost++;
  return cost;
}

double af5(int num)
{
  return (3.0/2)*(pow(num,2)) + (11.0/2)*num + 3;
}

void print(ostream& o, int n, double a, int e)
{
//prints computed values
  o << endl;
  o << setw(5) << n;
  o << " ";
  o << setw(10) << a;
  o << " ";
  o << setw(10) << e;
}

void title(ostream& o)
{
//prints headers
  o << endl;
  o << setw(5) << "n";
  o << " ";
  o << setw(10) << "analytical";
  o << " ";
  o << setw(10) << "empirical";
}

void FunctionManager(istream& i, ostream& o)
{
  title(o);
  for(;;)
   {
     int n;
     i >> n;
     if(i.eof())
     break;
     print(o,n,af5(n),ef5(n));
   }
   o<<endl;
}

int main(int argc, char* argv[])
{
  try
  {
    char ifn[255], ofn[255]; //Input and output file names
    switch (argc)
    {
      case 1: //Prompt for both file names
      cout << "Enter the input file name. ";
      cin >> ifn;
      cout << "Enter the output file name. ";
      cin >> ofn;
      break;
      case 2: //Prompt for the output file name
      strcpy(ifn,argv[1]);
      cout << "Enter the output file name. ";
      cin >> ofn;
      break;
      case 3: //Both file names are arguments
      strcpy(ifn,argv[1]);
      strcpy(ofn,argv[2]);
      break;
      default:
      throw CommandLineException(2,argc-1);
      break;
    }
      ifstream i(ifn); if (!i) throw FileException(ifn);
      ofstream o(ofn); if (!o) throw FileException(ofn);

      //Find the cost
      FunctionManager(i,o);
      //Read the input file, process input data, and write to the output file
      o.close();
      i.close();
    } catch (...) {
      cout << "Program terminated." << endl;
      exit(EXIT_FAILURE);
    }
return 0;
}


