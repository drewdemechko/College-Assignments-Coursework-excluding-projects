/*
Author Identification Block
Author:      Mr. Drew Demechko
Student ID:  *20348325
E-Mail:      ddemechko@uco.edu
Course:      CMSC 2833 - Computer Organization I
CRN:         11241 Fall 2015
Project:     p01
Due:         September 14, 2015
Account:     tt027
*/

#include<cstdlib>
#include<cstring>
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<sstream>
#include<iomanip>

using namespace std;

  struct CommandLineException
  {
    CommandLineException(int max, int actual)
    {
      cout<<endl<<"Too many arguments."<<endl;
      cout<<"A maximum of "<<max<<" arguments are permited."<<endl;
      cout<<actual<<" arguments were entered."<<endl;
    }
  };

  struct FileException
  {
    FileException(const char* fn)
    {
      cout<<endl<<"File "<<fn<<" could not be opened."<<endl;
    }
  };
  
  struct PairNotFoundException
  {
    PairNotFoundException()
    {
      cout<<"A foreign base was not found."<<endl;
      cout<<"The file does not contain a foreign base with every decimal value."
      <<endl;
    }
  };

  struct ForeignBaseOutOfRange
  {
    ForeignBaseOutOfRange(string s)
    {
      cout<<"The foreign base "<<s<<" does not fall in range!"<<endl;
    }
  };

  string radixMultiply(float f, int b)
  {
    string floatingportion;
    int radix = b;
    float fp = f;
    stringstream out;

    if(radix == 2)
    {
      while(fp != 0)
      {
        fp = fp * radix;
        if(fp < 1)
        {
          out<<"0";
        }
        else if(fp >= 1)
        {
          fp = fp - 1;
          out<<"1";
        }
      }
    } 
    else if(radix == 16)
    {
      out<<fp*16;
    }
    else if(radix == 8)
    {
      out<<fp*8;
    } 
  floatingportion = out.str();
  return "." + floatingportion;      
  }

  string radixDivide(int i, int b)
  {
    string integerportion;
    int radix = b;
    int ip = i;
    stringstream out;
    
    if(radix == 2)
    {
      while(ip != 0)
      {
        ip = ip / 2;
        out<<(ip%radix);
      }
    }
    else if(radix == 16)
    {
      out<<hex<<ip;
    }
    else if(radix == 8)
    {
      out<<oct<<ip;
    }
  integerportion = out.str();
  return integerportion;
  }

  string tofb(string v)
  {
    //Convert decimal numbers depending on the base
    int ip;
    float fp;
    int radix;
    string foreign;
    string temp;
    bool fractionalportion = false;

    //Split string up to decimal with a base
    int i = 0;
    while(v[i] != '.')
    {
      temp += v[i++];
    }

    const char * c = temp.c_str();
    ip = atoi(c);
    temp = "";

    while(v[i] != ' ')
    {
      temp += v[i++];
    }

    const char * a = temp.c_str();
    fp = atof(a);
    temp = "";
    i++;

    while(v[i] != 0)
    {
      temp += v[i++];
    }

    const char * l = temp.c_str();
    radix = atoi(l);
    temp = "";
   
   //Create strings of digits to represent the fraction and integer portion
     //and concatenate
  return radixDivide(ip,radix) + radixMultiply(fp,radix);
  }

  void ConversionMgr(char iname[], char oname[])
  {
    ifstream i(iname);if(!i)throw FileException(iname);
    ofstream o(oname);if(!o)throw FileException(oname);
    int countLines = 0;
    string temp;
    string decimal;
    string radix;
    int count = 0;

    while(getline(i,temp))
    {
      //Reads in decimal value and foreign base from input file
      while(temp[count] != ' ')
      {
        decimal += temp[count++];
      }
      count++;
      while(temp[count] != 0)
      {
        radix += temp[count++];
      }
      
      //Throws an exception when end of file is found before the foreign base
      if(radix == "")
      {
        throw PairNotFoundException();
      }
      //Throws an exception when the foreign base does not fall within range
      else if(radix != "2" && radix != "8" && radix != "16")
      {
        throw ForeignBaseOutOfRange(radix);
      }

    //Convert from decimal to a foreign base
    string foreign = tofb(temp);
    //Write the new foreign value to the output file
    o<<right<<setw(20)<<decimal<<" "<<right<<setw(2)<<radix<<" "<<right
    <<setw(20)<<foreign<<endl; 
    
    //Clear out previous line from temp data
    decimal = "";
    radix = "";
    count = 0;    
    }

    i.close();
    o.close();
  }

  int main(int argc, char* argv[])
  {
    try{
      char ifn[255],ofn[255];  //Input and output file names
      switch(argc){
        case 1:       //Prompt for both file names
          cout<<"Enter the input file name.";
          cin>>ifn;
          cout<<"Enter the output file name.";
          cin>>ofn;
          break;
        case2:
          strcpy(ifn,argv[1]);
          cout<<"Enter the output file name.";
          cin>>ofn;
          break;
        case3:      //Both file names are arguments
          strcpy(ifn,argv[1]);
          strcpy(ofn, argv[2]);
          break;
        default:
          throw CommandLineException(2,argc-1);
          break;
      }
      //ifstream i(ifn);if(!i)throw FileException(ifn);
     // ofstream o(ofn);if(!o)throw FileException(ofn);
      //Read the input file, process input data, and write to the output file
      ConversionMgr(ifn,ofn);
      //o.close();
      //i.close();
    }catch(...){
      cout<<"Program terminated."<<endl;
      exit(EXIT_FAILURE);
    }
    return 0;
  }
