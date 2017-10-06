#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// util function
void _ts(int v, bool visited[], stack<int> *st, vector< vector<int> > graph){
	visited[v] = true;

	// go to all verices adjacent to this one
	for(int w=0;w<graph[v].size();w++){
		int new_node = graph[v][w];
		if(!visited[new_node]) _ts(new_node, visited, st, graph);
	}

	st->push(v);
}

stack<int> topological_sort(vector< vector<int> > graph){
	int vertices = graph.size();
	stack<int> st;
	
	// mark all vertices as not visited
	bool *visited = new bool[vertices];
	for(int i=0;i<vertices;i++) visited[i] = false;

	// call helper function to store topological sort
	// starting from all vertices one by one
	for(int i=0;i<vertices;i++){
		if(!visited[i]) _ts(i, visited, &st, graph);
	}

	stack<int> st2;
	st2 = st;

	cout << "Printing graph after topological sort: " << endl;
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	return st2;
}