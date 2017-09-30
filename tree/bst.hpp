#include <bits/stdc++.h>
#include "../queue/queue.hpp"
using namespace std;

template<class T>
struct bst_node{
	T data;
	bst_node *left_child;
	bst_node *right_child;

	bst_node(T new_data) : data(new_data), left_child(NULL), right_child(NULL) {};
};

template<class T>
class BST{
private:
	bst_node<T> *node;

	// helper functions 
	int _get_length(bst_node<T> *node){
		if(node == NULL) return 0;
		return 1 + max(_get_length(node->left_child), _get_length(node->right_child));
	}

	void _insert(bst_node<T> *node, T new_data){
		// if node exists
		if(node->data > new_data){
			// go left
			if(node->left_child){
				_insert(node->left_child, new_data);
			}else{
				node->left_child = new bst_node<T>(new_data);
			}
		}else{
			// right
			if(node->right_child){
				_insert(node->right_child, new_data);
			}else{
				node->right_child = new bst_node<T>(new_data);
			}
		}
	}

	void _print(bst_node<T> *node){
		if(!node) return;
		_print(node->left_child);
		cout << node->data << " ";
		_print(node->right_child);
	}

	void _print_post_order(bst_node<T> *node){
		if(!node) return;
		_print_post_order(node->left_child);
		_print_post_order(node->right_child);
		cout << node->data << " ";
	}

	void _print_pre_order(bst_node<T> *node){
		if(!node) return;
		cout << node->data << " ";
		_print_pre_order(node->left_child);
		_print_pre_order(node->right_child);
	}

	int _count_nodes(bst_node<T> *node){
		if(!node) return 0;
		return 1 + _count_nodes(node->left_child) + _count_nodes(node->right_child);
	}

	bool _find(bst_node<T> *node, T data){
		if(node){
			if(node->data == data){
				return true;
			}
			if(node->data > data){
				// go left
				return _find(node->left_child, data);
			}else{
				return _find(node->right_child, data);
			}
		}
		return false;
	}

	void _print_max_path(bst_node<T> *node){
		if(!node) return;
		cout << node->data << ' ';
		if(_get_length(node->left_child)){
			_print_max_path(node->left_child);
		}else{
			_print_max_path(node->right_child);
		}
	}

	T _get_max(bst_node<T> *node){
		if(node == NULL) return '\0';
		bst_node<T> *temp_node = node;
		while(temp_node->right_child){
			temp_node = temp_node->right_child;
		}
		return temp_node->data;
	}

	T _get_min(bst_node<T> *node){
		if(node == NULL) return '\0';
		bst_node<T> *temp_node = node;
		while(temp_node->left_child){
			temp_node = temp_node->left_child;
		}
		return temp_node->data;
	}

	bst_node<T> *_get_min_node(bst_node<T> *node){
		if(node == NULL) return NULL;
		bst_node<T> *temp_node = node;
		while(temp_node->left_child){
			temp_node = temp_node->left_child;
		}
		return temp_node;
	}

	bst_node<T> *_delete_value(bst_node<T> *root, T del_data){
		if(root == NULL) return root;

		if(del_data < root->data){
			root->left_child = _delete_value(root->left_child, del_data);
		}else if(del_data > root->data){
			root->right_child = _delete_value(root->right_child, del_data);
		}else{
			// check if one child is NULL
			if(root->left_child == NULL){
				bst_node<T> *temp_node = root->right_child;
				delete root;
				return temp_node;
			}else if(root->right_child == NULL){
				bst_node<T> *temp_node = root->left_child;
				delete root;
				return temp_node;
			}

			// if the node has both the 
			bst_node<T> *temp_node = _get_min_node(root->right_child);
			cout << "min node " << temp_node->data << endl; 
			root->data = temp_node->data;
			root->right_child = _delete_value(root->right_child, temp_node->data);
		}
		return root;
	}

	int _get_count(bst_node<T> *node){
		if(node == NULL) return 0;
		return 1 + _get_count(node->left_child) + _get_count(node->right_child);
	}

	void _level_order(bst_node<T> *node){
		if(node == NULL) return;
		cout << "Level order traversal:" << endl;
		queuemp<bst_node<T> *> *q = new queuemp<bst_node<T> *>();
		q->push(node);
		while(q->size){
			bst_node<T> *temp = q->pop();
			if(temp->left_child) q->push(temp->left_child);
			if(temp->right_child) q->push(temp->right_child); 
			cout << temp->data << " ";
		}
		cout << endl;
		delete q;
	}
public:
	BST() : node(NULL) {}
	BST(T new_data) : node(new bst_node<T>(new_data)) {}
	~BST();

	T data(){
		return this->node->data;
	}

	void insert(T new_data){
		bst_node<T> *new_node = new bst_node<T>(new_data);
		if(node == NULL){
			node = new bst_node<T>(new_data);
			return;
		}
		_insert(node, new_data);
	}

	int get_length(){
		return _get_length(node);
	}

	void print(){
		cout << "Printing BST (in order):" << endl;
		_print(node);
		cout << endl;
	}

	void print_post_order(){
		cout << "Printing BST (post order):" << endl;
		_print_post_order(node);
		cout << endl;
	}

	void print_pre_order(){
		cout << "Printing BST (pre order):" << endl;
		_print_pre_order(node);
		cout << endl;
	}

	T get_max(){
		return _get_max(node);
	}

	T get_min(){
		return _get_min(node);
	}

	int count_nodes(){
		return _count_nodes(node);
	}

	bool find(T data){
		return _find(node, data);
	}

	void print_max_path(){
		cout << "Max path:" << endl;
		_print_max_path(node);
		cout << endl;
	}

	void delete_value(T del_data){
		this->node = _delete_value(this->node, del_data);
	}

	int get_count(){
		return _get_count(this->node);
	}

	void level_order(){
		_level_order(this->node);
	}
};
