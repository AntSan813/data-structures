/*
  This implementation of a stack includes the basic functions 'push' and 'pop'
  to make the program reflect a FILO (first in, last out) data structure. This implementation
  also includes other functions, such as display, to perform actions wanted by the main file.
*/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

/****************************************************************************************
  What makes the Node structure special, and the reason we use it in this implementation
  is because it is used to tie together each object in the stack by having each object
  contain a pointer to the next object. Each node contains the next pointer and the variables
  pushed in.
****************************************************************************************/
template<typename obj>
struct Node{
  public: //functions contained in the Node structure
    Node(){ //default constructor
      n = NULL;
    }

    Node(obj v, Node* nn){ //constructor with paramaters
      val = v;
      n = nn;
    }

    Node* next(){ //get the next pointer
      return n;
    }

    void set_next(Node* nn){ //set the next pointer
      n = nn;
    }

    obj item(){ //get the item in this node
      return val;
    }

  private: //items contained in the Node structure
    obj val;
    Node* n = NULL;
};

/****************************************************************************************
  The stack class contains the Node struct above. What makes the stack unique is the
  push and pop functions. These functions allow the programmer to "push" objects into the
  stack, and "pop" an object off the stack.
****************************************************************************************/
template<typename obj>
class Stack{
  public:
    Stack(){ //default constructor
      head = NULL;
      count = 0;
    }
    void push(obj arg){ //push function
      Node<obj>* nn = new Node<obj>(arg, head); //dynamically make a new new and set its
                                                //next to the current head pointer
      head = nn; //set the new head pointer to be the Node that was just pushed in
      count++; //increment counter so that we can keep track of how many Nodes are in stack
    }

    obj pop(){ //pop function
      obj tar = head->item(); //get the target argument - which is the item of the header
      Node<obj>* d = head; //create a temporary node pointer
      head = head->next(); //move the head pointer to the next
      delete d; //delete the previous head pointer
      count--; //decrement the counter so that we can keep track of how many nodes are in stack
      return tar; //return the item we saved at beginning of funciton
    }

    ~Stack(){ //deletes all allocated memory and outputs what was in it
      cout << "\n\nDeleting stack..." << endl;
      for(int i = 1; i <= count; ){
        cout << pop() << endl;
      }
    }

  private:
    Node<obj>* head;
    int count;
};

#endif
