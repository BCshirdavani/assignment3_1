//****************************************************
//
//    Author:        Beau Shirdavani
//    Date:        11-23-2017
//    Title:        Assignment 3_1
//                LinkedStack.h
//
//****************************************************


#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
#include <cassert>
using namespace std;



template <class T>
struct node{
    T data;
    node<T>* next;
};

template <class T>
class LinkedStack{
    node<T>* top;
public:
    // provide function prototypes for a Stack here
    LinkedStack();
    bool isEmpty();
    void push(T&);
    int length;
    int getLength();
    T pop();
    // T sTop();
    template <class U>
    friend ostream& operator<<(ostream& os, LinkedStack<U>& lStack);
    T seeTop();
    ~LinkedStack();
};

// provide function implementations here

//****************************************************
//                                        constructor
template <class T>
LinkedStack<T>::LinkedStack(){
    top = NULL;
    length = 0;
}

//****************************************************
//                                        desctructor
template <class T>
LinkedStack<T>::~LinkedStack(){
    while ( top != NULL ){
        node<T>* temp;
        temp = top;
        top = top->next;
        delete temp;
    }
}

//****************************************************
//                                        isEmpty()
template <class T>
bool LinkedStack<T>::isEmpty(){
    return ( top == NULL );
}

//****************************************************
//                                        push(T&)
template <class T>
void LinkedStack<T>::push(T& item){
    node<T>* newNode = new node<T>();
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    length++;
}

//****************************************************
//                                        pop()
template <class T>
T LinkedStack<T>::pop(){
    assert( !(this->isEmpty()) );
    T topData = top->data;
    top = top->next;
    length--;
    return topData;
    
    // old approach,
    // failed because control may reach end of non-void function
    // solution is use use assert.
//    if ( !( this->isEmpty() ) ){
//        T topData = top->data;
//        top = top->next;
//        length--;
//        return topData;
//    }
//    else {
//        cout << "Stack is empty, nothing to pop..." << endl;
//        // conntrol may reach end of non-void function...............
//        return NULL;
//    }
    
    
}

//****************************************************
//                                        << operator
template <class T>
ostream& operator<<(ostream& os, LinkedStack<T>& lStack){
    node<T>* temp1;
    temp1 = lStack.top;
    for( int i=0; i < lStack.length; i++ ){
        os << temp1->data << " ";
        temp1 = temp1->next;
    }
    return os;
}


//****************************************************
//                                        seeTop()
template <class T>
T LinkedStack<T>::seeTop(){
    if ( !( this->isEmpty() ) ){
        return top->data;
    }
}

//****************************************************
//                                        ssTop()
// not sure if I need this function...


//****************************************************
//                                        getLength()
template <class T>
int LinkedStack<T>::getLength(){
    return length;
}

#endif /*LINKEDSTACK_H_*/









