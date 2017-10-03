#include <bits/stdc++.h>
#include "../linked_list/ll.hpp"
using namespace std;

template<class T>
struct queuemp{
	ll_node<T> *head;
	int size; // number of elements in the queue

	queuemp() : size(0) {}

	void push(T new_data){
		ll_node<T> *new_node = create_node(new_data);
		ll_node<T> *temp_node = this->head;
		new_node->next = temp_node;
		this->head = new_node;
		this->size++;
	}

	void print(){
		if(this->size == 0){
			cout << "queue is empty" << endl;
			return;
		}
		ll_node<T> *temp_node = this->head;
		cout << "Printing queue:" << endl;
		for(int i=0;i<this->size;i++){
			cout << temp_node->data << " ";
			temp_node = temp_node->next;
		}
		cout << endl;
	}

	T pop(){
		if(this->size == 0){
			cout << "queue is empty, can't pop" << endl;
			return '\0';
		}
		if(this->size == 1){
			T data = this->head->data;
			this->head = NULL;
			this->size = 0;
			return data;
		}
		ll_node<T> *new_node = this->head;
		// move to second last element
		for(int i=0;i<this->size-2;i++) new_node = new_node->next;
		//cout << new_node->data << endl;
		T data = new_node->next->data;
		new_node->next = NULL;
		this->size--;
		return data;
	}

	T peek(){
		return this->head->data;
	}
};

template<class T>
int get_size(queuemp<T> *s){
	return s->size;
}
