//Drew Demechko
//Programming II
//Due:September 28, 2015
//infixtopostfix.cpp
//This program reads infix operations from a file and outputs the postfix value
//This program also evaluates the postfix operation which is part 2
#include <cctype>
#include <sstream>
#include <stack>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#include "MyStack.h"
using namespace std;

bool isOperator(char currentChar)
{
    switch (currentChar) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
    default:
        return false;
    }
}

// determines the higher precedence
bool precedence(char leftOperator, char rightOperator)
{
    if ( leftOperator == '^' ) {
        return true;
    } else if ( rightOperator == '^' ) {
        return false;
    } else if ( leftOperator == '*' || leftOperator == '/' ||
      leftOperator == '%' ) {
        return true;
    } else if ( rightOperator == '*' || rightOperator == '/' ||
      rightOperator == '%' ) {
        return false;
    }
    return true;
}

string convertToPostfix(const string& infix)
{
    stringstream postfix;
   // stack<char> stack;
    Stack stack(100);
    stack.push('(');

    for(size_t i = 0, l = infix.size(); i < l; ++i) {
        const char current = infix[i];

        if (isspace(current)) {
            //ignores spaces
        }
        //add digits to the output
        else if(isalnum(current)) {
            postfix << current;
        }
        else if('(' == current) {
            stack.push(current);
        }
        else if(isOperator(current)) {
            char rightOperator = current;
            while(!stack.empty() && isOperator(stack.peek()) &&
            precedence(stack.peek(), rightOperator)) {
                postfix << ' ' << stack.peek();
                stack.pop();
            }
            postfix << ' ';
            stack.push(rightOperator);
        }
        else if(')' == current) {
            while(!stack.empty() && '(' != stack.peek()) {
                postfix << ' ' << stack.peek();
                stack.pop();
            }
            stack.pop();
            postfix << ' ';
    }
}
    while(!stack.empty() && '(' != stack.peek()) {
        postfix << ' ' << stack.peek();
        stack.pop();
    }
    stack.pop();

    return postfix.str();
}

int calculate(int opn1, char token, int opn2)
{
  int result;
  switch(token)
  {
    case '+':
      result = opn1+opn2;
      break;
    case '-': 
      result = opn1-opn2;
      break;
    case '*': 
      result = opn1*opn2;
      break;
    case '/':
      result = opn1/opn2;
      break;
    case '^': 
      result = pow(opn1,opn2);
      break;
  }
  return result;
}

int evaluate(string postfix)
{
  Stack stack(100);
  char token;
  int result;
  bool first = false;
  
  for(size_t i = 0, l = postfix.size(); i < l; ++i)
  {
    token = postfix[i];

    if(isalnum(token))
      {
        stack.push(token);
      }
    else
      if(token == ' ')
        {
          //skip spaces 
        }
      else
      {
        //is operator
        if(!first)
          {
            char temp2 = stack.pop();
            char temp1 = stack.pop();
            int opn2 = temp2 - '0';
            int opn1 = temp1 - '0';
            result = calculate(opn1,token,opn2);
            first = true;
          }
        else
          {
            
            int opn1 = result;
            char temp2 = stack.pop();
            int opn2 = temp2 - '0';
            result = calculate(opn1,token,opn2);
          }
      }
  }
  return result;
}

#if __INCLUDE_LEVEL__ < 1

int main()
{
  ifstream idata;
  string temp;
  string postfixnumber;
  int result;
  idata.open("infix.dat");

    while(getline(idata,temp))
    {
      //Returns the original prefix expression
      cout<<"Prefix: "<<temp<<endl;
      
      //Returns the postfix expression
      postfixnumber = convertToPostfix(temp);
      cout<<"Postfix: "<<postfixnumber<<endl;

      //Returns the result of the postfix number
      result = evaluate(postfixnumber);
      cout<<"Evaluation: "<<result<<endl<<endl;
    }
  idata.close();
}
#endif
