#include <bits/stdc++.h>
#include "../linked_list/ll.hpp"
using namespace std;

template<class T>
struct stackmp{
	ll_node<T> *top;
	int capacity; // number of elements the stack can contain
	int size; // number of elements in the stack

	stackmp(int cap) : capacity(cap),size(0) {}

	void push(T new_data){
		if(size == capacity){
			cout << "Stack is full! Cannot push new element" << endl;
			return;
		}
		ll_node<T> *new_node = create_node(new_data);
		ll_node<T> *temp_node = this->top;
		new_node->next = temp_node;
		this->top = new_node; // here "this" pointer is used to access the current class's object's parameters
		size++;
	}

	void print(){
		ll_node<T> *temp_node = this->top;
		if(size == 0){
			cout << "Stack is empty" << endl;
			return;
		}
		cout << "Printing stack:" << endl;
		for(int i=0;i<this->size;i++){
			cout << temp_node->data << ' ';
			temp_node = temp_node->next;
		}
		cout << endl;
	}

	T pop(){
		if(size == 0){
			cout << "Stack is empty, can't pop" << endl;
			return '\0';
		}
		T data = this->top->data;
		this->top = this->top->next;
		size--;
		return data;
	}

	T peek(){
		return this->top->data;
	}
};

template<class T>
int get_size(stackmp<T> *s){
	return s->size;
}

template<class T>
int get_capacity(stackmp<T> *s){
	return s->capacity;
}

