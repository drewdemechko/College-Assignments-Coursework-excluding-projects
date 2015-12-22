//Drew Demechko
//Programming II
//Due: October 9, 2015
//udppacketrecombination.cpp
//This program takes a list of udp packets and sorts them using a linked list

#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

class Link {
  public: string title;
  public: int num;  //holds packet order
  public: Link *next;

  public: Link(int n, string s)
  {
    num = n;
    title = s;
  }
};

class LinkedList {

  public: Link* first = NULL;
 
  public: bool isEmpty()
  {
    return (first == NULL);
  }
 
  public: void addLink(int n, string s)
  {
    //Create a new link
    Link* newLink = new Link(n,s);
    Link* previous = NULL;
    Link* current = first;

    while(current != NULL && n > current->num)
    {
      //Find landing spot for link
      previous = current;
      current = current->next;
    }
   
    if(previous == NULL)
      first = newLink;
    else
      previous->next = newLink;
    newLink->next = current;
  }
  
  public: Link* deleteLink()
  {
    Link* temp = first;
    first = first->next;
    return temp;
  }
  
  public: void displayLinks()
  {
    Link *current = first;
    while(current != NULL)
    {
      cout<<current->title<<"="<<current->num<<endl;
      current = current->next;
    }
  }
};

int main()
{
  LinkedList list;
  
  ifstream idata;
  string temp;
  idata.open("udppackets.dat");

    while(getline(idata,temp))
    {
      int position;
      for(int i = 1; i < 4; i++)
      {
        if(isdigit(temp[i]))
        {
          int tempNum = temp[i] - 48;
          switch(i)
          {
            case 1:
              position += tempNum * 100;//returns int of char value
            break;
            case 2:
                position += tempNum * 10;//returns int of char value
            break;
            case 3:
                position += tempNum;
            break;
            default:
              position += 0;
            break;
          }
        }
      }
    //reset values
    list.addLink(position,temp);
    position = 0;
    }
  
  //Delete link from linkedlist
  while(!list.isEmpty())
  {
    Link* deletedLink = list.deleteLink();
    string title = deletedLink->title;
    int i = 0;
    while(i < 17)
    {
      switch(i)
      {
        case 4 ... 15:
          if(title[i] != '=' && title[i] != '+')
            cout<<title[i];
          else if(title[i] == '+')
            cout<<endl; 
        break;
        default:
          cout<<"";
        break;
      }
    i++;
    }
  }
  idata.close();
}
