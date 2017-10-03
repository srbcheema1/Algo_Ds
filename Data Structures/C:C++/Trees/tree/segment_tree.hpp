#include <iostream>
#include <math.h>

class segment_tree{
private:
    int *st;
    int *ar;
    int len;
    int sz; //size of segment tree

    // function to get middle of a segment
    int _get_mid(int start, int end){
        return start + (end - start) / 2;                
    }

    // util function to contruct segment tree
    int _construct(int *v, int start, int end, int current){
    	// if there is 1 element in stray, store in current 
    	// node and return
    	if(start == end){
    		st[current] = v[start];
    		return v[start];
    	}

    	// for more elements, recur for left & right subtrees
    	// store the sum for values in this node
    	int mid = _get_mid(start, end);
    	st[current] = _construct(v, start, mid, current*2 + 1) + 
    					_construct(v, mid + 1, end, current*2 + 2);
    	return st[current];
    }

    // utility to update a value in segment tree
    void _update_value(int start, int end, int i, int difference, int current){
  		if(i<start || i>end) return;
  		st[current] = st[current] + difference;
  		if(end != start){
  			int mid = _get_mid(start, end);
  			_update_value(start, mid, i, difference, 2*current+1);
  			_update_value(mid+1, end, i, difference, 2*current+2);
  		}
    }

    int _get_sum(int start, int end, int q_start, int q_end, int current){
    	if(q_start <= start && q_end >= end) return st[current];

    	// outside range
    	if(end < q_start || start > q_end) return 0;

    	int mid = _get_mid(start, end);
    	return _get_sum(start, mid, q_start, q_end, 2*current+1) + 
    			_get_sum(mid+1, end, q_start, q_end, 2*current+2);
    }
public:
    segment_tree(int *v, int n){
    	ar = new int[n];
    	this->len = n;
    	for(int i=0;i<n;i++) ar[i] = v[i];
    	// construct tree
    	// height of tree
    	this->sz = 0;
    	int h = (int)ceil(log2(n));
    	int max_size = 2 * (int)pow(2, h) - 1;
    	this->sz = max_size;

    	// allocate memory
    	st = new int[max_size];
    	_construct(v, 0, n-1, 0);
    }

    // update value in 
    void update(int i, int new_val){
    	if(i<0 || i>this->len-1) return;
    	int difference = new_val - ar[i];
    	ar[i] = new_val;

    	// update segment tree
    	_update_value(0, this->len-1, i, difference, 0);
    }

    //get sum of range
    int get_sum(int start, int end){
    	if(start < 0 || end > this->len-1 || start > end) return -1;
    	return _get_sum(0, this->len-1, start, end, 0);
    }

    int get(int n){
    	return st[n];
    }
    void print(){
    	cout << "Printing segment tree" << endl;
    	int n = this->sz;
    	for(int i=0;i<n;i++) cout << st[i] << " ";
    	cout << endl;
    }
};