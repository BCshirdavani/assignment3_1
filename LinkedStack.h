//****************************************************
//
//	Author:		Beau Shirdavani
//	Date:		11-23-2017
//	Title:		Assignment 3_1
//				LinkedStack.h
//
//****************************************************


#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
using namespace std;



template <class T>
struct node{
	T data;
	node<T>* next;
}

template <class T>
class LinkedStack{
	Node<T>* top;
public:
	// provide function prototypes for a Stack here
	LinkedStack();
	bool isEmpty();
	void push(T&);
	T pop();
	template <class U>
	friend ostream& operator<<(ostream& os, LinkedStack<U>& lStack);
	T seeTop();
	~LinkedStack();
}

// provide function implementations here

//****************************************************
//										constructor
template <class T>
LinkedStack<T>::LinkedStack(){
	top = NULL;
}

//****************************************************
//										isEmpty()
template <class T>
LinkedStack<T>::isEmpty(){
	return ( top == NULL );
}

//****************************************************
//										push(T&)
template <class T>
void LinkedStack<T>::push(T& item){
	Node<T>* newNode = new node<T>();
	newNode->data = item;
	newNode->next = top;
	top = newNode;
}

//****************************************************
//										pop()
template <class T>
T LinkedStack<T>::pop(){
	if ( !( this.isEmpty() ) ){
		T topData = top->data;
		top = top->next;
		return topData;
	}
	else {
		cout << "Stack is empty, nothing to pop..." << endl;
	}
}

//****************************************************
//										<< operator
template <class T>
ostream& operator<<(ostream& os, LinkedStack<T>& lStack){
	for( int i=0; i < lStack.top; i++ ){
		os << lStack.array[i] << " ";
	}
	return os;
}


//****************************************************
//										seeTop()
template <class T>
T LinkedStack<T>::seeTop(){
	if ( !( this.isEmpty() ) ){
		return top->data;
	} 
}





#endif /*LINKEDSTACK_H_*/








