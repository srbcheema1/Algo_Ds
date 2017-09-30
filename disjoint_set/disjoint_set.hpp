#include <iostream>
using namespace std;

class disjoint_set {
private:
	int *id, *size, count;
public:
	disjoint_set(int n) : id(new int[n]), size(new int[n]), count(n) {
		// set ids for all e;ements, size = 1
		for(int i=0;i<n;i++){
			id[i] = i;
			size[i] = 1;
		}
	}

	~disjoint_set(){
		delete [] id;
		delete [] size;
	}

	int get_count(){
		return this->count;
	}

	// return id of component corresponding to object n
	int find(int n){
		int root = n;
		while(root != this->id[root]) root = this->id[root];
		while(n != root){
			int new_n = this->id[n];
			this->id[n] = root;
			n = new_n;
		}
		return root;
	}

	void merge(int x, int y){
		int i = this->find(x);
		int j = this->find(y);
		if(i == j) return;

		// make smaller root opint to larger one
		if(this->size[i] < this->size[j]){
			this->id[i] = j;
			this->size[j] += this->size[i];
		}else{
			this->id[j] = i;
			this->size[i] += this->size[j];
		}

		this->count--;
	}

	bool connected(int x, int y){
		return this->find(x) == this->find(y);
	}
};
