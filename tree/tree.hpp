#include <bits/stdc++.h>
using namespace std;

template<class T>
struct tree_node{
	T data;
	tree_node *left_child;
	tree_node *right_child;

	tree_node(T new_data) : data(new_data), left_child(NULL), right_child(NULL) {};

	void insert_left(T new_data){
		tree_node<T> *new_node = new tree_node<T>(new_data);
		this->left_child = new_node;
	}

	void insert_right(T new_data){
		tree_node<T> *new_node = new tree_node<T>(new_data);
		this->right_child = new_node;
	}
};

template<class T>
int get_length(tree_node<T> *top){
	if(top == NULL) return 0;
	return 1 + max(get_length(top->left_child), get_length(top->right_child));
}
