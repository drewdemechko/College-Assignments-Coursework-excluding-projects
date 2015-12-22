#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class StackX
{
  private: int maxSize;
  private: char stackArray[]; 
  private: int top;

 // public: StackX(int s)
  public: StackX(int s)
  {
    maxSize = s;
    stackArray[maxSize];
    top = -1;
  }

  public: void push(char j)
  { stackArray[++top] = j; }
  
  public: char pop()
  { return stackArray[top--]; }

  public: char peek()
  { return stackArray[top]; };

  public: bool isEmpty()
  { return (top == -1); } 

  public: int size()
  { return top + 1; }

  public: char peekN(int n)
  { return stackArray[n]; }

  public: void displayStack(string s)
  {
    cout<<s;
    cout<<"Stack (bottom -> top): ";
    for(int j = 0; j < size(); j++)
    {
      cout<<peekN(j);
      cout<<' ';
    }
  cout<<endl;
  }
};

class InToPost
{
private: StackX theStack(20);
private: string input;
private: string output;

  public: InToPost(string in)
  {
    input = in;
    //int stackSize = input.size();
  }

  public: string doTrans()
  {
    for(int j = 0; j < input.size(); j++)
    {
      char ch = input[j];
      //theStack.displayStack("For " + input + " ");
      theStack.displayStack("test, will change");
      switch(ch)
      {
        case '+':
        case '-':
          gotOper(ch, 1);
          break;
        case '*':
        case '/':
          gotOper(ch, 2);
          break;
        case '(':
          theStack.push(ch);
          break;
        case ')':
          gotParen(ch);
          break;
        default:
          output = output + ch;
          break; 
      }
    }
    while(!theStack.isEmpty())
    {
      theStack.displayStack("While ");
      output = output + theStack.pop();
    }
  theStack.displayStack("End ");
  return output;
  }

  public: void gotOper(char opThis, int prec1)
  {
    while(!theStack.isEmpty())
    {
      char opTop = theStack.pop();
      if(opTop == '(')
      {
        theStack.push(opTop);
        break;
      }
      else
      {
        int prec2;

        if(opTop=='+' || opTop=='-')
          prec2 = 1;
        else
          prec2 = 2;
        if(prec2 < prec1)
        {
          theStack.push(opTop);
          break;
        }
        else
          output = output + opTop;
      }
    }
  theStack.push(opThis);
  }

  public: void gotParen(char ch)
  {
    while(!theStack.isEmpty())
    {
      char chx = theStack.pop();
      if(chx == '(')
        break;
      else
        output = output + chx;
    }
  }
};

int main()
{
//ifstream idata("infix.dat");  
//string temp;

 // while(getline(idata,temp))
  //{
    //cout<<"infix: "<<temp<<endl;
    //InToPost theTrans(temp);
    //cout<<"postfix: "<<theTrans.doTrans()<<endl;    
  //}
  string input, output;
  while(true)
  {
    cout<<"Enter infix: ";
    cin>>input;
    if(input == "")
      break;
    
    InToPost theTrans(input);
    output = theTrans.doTrans();
    cout<<"postfixis "<<output<<endl;
  }
}
