//Drew Demechko
//Programming II
//Due:September 21, 2015
//MyStack.cpp
//This is the Stack class used in the main program


#include<iostream>
#include "MyStack.h"
using namespace std;

Stack::Stack(int size) {
   MaxStack = size;
   EmptyStack = -1;
   top = EmptyStack;
   items = new char[MaxStack];
}

Stack::~Stack() {delete[] items;}

void Stack::push(char c) {
   items[++top] = c;
}

char Stack::pop() {
   return items[top--];
}

char Stack::peek() {
   return items[top];
}
int Stack::full()  {
   return top + 1 == MaxStack;
}

int Stack::empty()  {
   return top == EmptyStack;
}

#if __INCLUDE_LEVEL__ < 1
int main()
{
  Stack myStack(100);
  myStack.push('y');
  myStack.push('z');
  cout<<myStack.pop()<<endl;
  cout<<myStack.pop()<<endl;
  cout<<myStack.pop()<<endl;
}
#endif
