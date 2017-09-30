#include <iostream>
using namespace std;

template<typename T>
class heap {
private:
	T *arr;
	int size;
	int capacity;
	int type; // if 1, max heap else if -1 min heap
public:
	heap() : arr(NULL), size(0), capacity(0), type(0) {}
	heap(int capacity, int type) : arr(new T[capacity]), size(0), capacity(capacity), type(type) {}

	// get private values
	int get_size(){ return this->size; }
	int get_capacity(){ return this->capacity; }
	int get_type(){ return this->type; }

	// util functions
	// get index of parent from child index
	int get_parent(int child_index){
		if(child_index <=0 || child_index >= this->capacity) return -1;
		return (child_index-1)/2;
	}

	bool has_left_child(int parent_index){
		return (parent_index * 2 + 1 < this->size) && (parent_index >= 0);
	}

	bool has_right_child(int parent_index){
		return (parent_index * 2 + 2 < this->size) && (parent_index >= 0);
	}

	// get index of left child from parent's index
	int get_left_child(int parent_index){
		int left_child_index = parent_index * 2 + 1;
		if(!has_left_child(parent_index)) return -1;
		return left_child_index;
	}

	// get index of left child from parent's index
	int get_right_child(int parent_index){
		int right_child_index = parent_index * 2 + 2;
		if(!has_right_child(parent_index)) return -1;
		return right_child_index;
	}

	// get max / min, depending on the type of heap
	// get minimum from min heap
	T get_min(){
		// returns null if array is empty or heap type is max
		if(this->size == 0 || this->type == 1) return '\0';
		return this->arr[0];
	}
	// get maximum from max heap
	T get_max(){
		// returns null if array is empty or heap type is min
		if(this->size == 0 || this->type == -1) return '\0';
		return this->arr[0];
	}

	// takes location of element as input and heapifies our array downwards
	// considering max heap
	void down(int parent_index){
		int left_child_index = get_left_child(parent_index), right_child_index = get_right_child(parent_index);
		if(left_child_index == -1 && right_child_index == -1) return;

		// everything is valid, so let's proceed to finding the next max element that can be swapped with the parent
		int max_element = parent_index;
		if(left_child_index != -1){
			if(arr[left_child_index] > arr[parent_index]) max_element = left_child_index;
			else max_element = parent_index;
		} 
		else max_element = parent_index;

		if(right_child_index != -1){
			if(arr[right_child_index] > arr[max_element]) max_element = right_child_index;
		} 

		if(max_element == -1) return;

		// swap max_element with parent
		if(max_element != parent_index){
			int temp = arr[max_element];
			arr[max_element] = arr[parent_index];
			arr[parent_index] = temp;
		}

		down(max_element);
	}

	bool is_full(){
		return this->size == this->capacity;
	}

	bool is_empty(){
		return this->size == 0;
	}

	void resize(){
		T *old_array = this->arr;
		this->arr = static_cast< T* > (malloc(sizeof(T) * this->capacity * 2));
		if(this->arr == NULL){
			cout << "Memory error" << endl;
			return;
		}
		for(int i=0;i<this->capacity;i++) this->arr[i] = old_array[i];
		this->capacity *= 2;
		delete [] old_array;
	}

	void insert(T data){
		if(this->is_full()) this->resize();
		this->size++;
		int i = this->size - 1;
		while(i>0 && data > this->arr[get_parent(i)]){
			this->arr[i] = this->arr[get_parent(i)];
			i = get_parent(i);
		}
		this->arr[i] = data;
	}

	// another constructor to create a heap from an array
	heap(T ar[], int capacity, int type) : arr(new T[capacity]), size(capacity), capacity(capacity), type(type) {
		for(int i=0;i<capacity;i++) this->arr[i] = ar[i];
		for(int i=(capacity-1)/2;i>=0;i--) down(i);
	}

	void print(){
		cout << "Printing heap: " << endl;
		for(int i=0;i<this->size;i++) cout << this->arr[i] << " ";
		cout << endl;
	}

	bool is_heap(){
		int i = 0;
		// assuming max heap
		for(int j=0;j<this->size;j++){
			if(this->has_left_child(j) && this->arr[this->get_left_child(j)] > this->arr[j]) return false; 
			if(this->has_right_child(j) && this->arr[this->get_right_child(j)] > this->arr[j]) return false; 
		}
		return true;
	}
};
