#include <iostream>
#include "../queue/queue.hpp"
using namespace std;

template<typename T>
class graph_am {
private:
	int count;
	bool **connections;
	T *vertices;
	bool *visited;
public:
	graph_am(T vertices[], int count) : count(count), vertices(new T[count]), visited(new bool[count]) {
		connections = new bool*[count];
		for(int i=0;i<count;i++){
			connections[i] = new bool[count];
		}
		for(int i=0;i<count;i++){
			this->vertices[i] = vertices[i];
			for(int j=0;j<count;j++){
				connections[i][j] = (i==j);
			}
		}
	}

	void connect(int i, int j){
		connections[i][j] = true;
	}

	void connect_both_sides(int i, int j){
		connect(i, j);
		connect(j, i);
	}

	bool bfs(int i, int j){
		queuemp<int> *q = new queuemp<int>();
		if(connections[i][j]) return true;
		// else, try seraching though the connections
		for(int w=0;w<this->count;w++) visited[w] = false;
		q->push(i);
		visited[i] = true;
		while(q->size){
			int v = q->pop();
			for(int w = 0; w < this->count; w++){
				if(!visited[w] && connections[v][w]){
					if(w == j) return true;
					q->push(w);
					visited[w] = true;
				}
			}
		}
		return false;
	}

	void dfs(int i){
		for(int j=0;j<count;j++){
			if(!visited[j] && connections[i][j]){
				visited[j] = true;
				dfs(j);
			}
		}
	}

	// check if the vertices at i and j are connected.
	bool connected(int i, int j){
		return bfs(i, j);
	}

	int connected_components(){
		for(int i=0;i<count;i++) visited[i] = false;
		int components = 0;
		for(int i=0;i<count;i++){
			if(!visited[i]){
				dfs(i);
				components++;
			}
		}
		return components;
	}
};
