#include <vector>
#include <queue>
#include <utility> // for pair, make_pair etc
using namespace std;

/*
 * Shortest path in Unweighted graph 
 */
pair< vector<int>, vector<int> > unweighted_shortest_path(vector< vector<int> > graph, int s){
	vector<int> distance(graph.size(), -1);
	vector<int> path(graph.size());
	queue<int> q;
	int v, w;
	q.push(s);
	distance[s] = 0;

	while(!q.empty()) {
		v = q.front();
		q.pop();
	    for(int k = 0; k < graph[v].size(); k++){
	    	w = graph[v][k];
	    	if(distance[w] == -1){
	    		distance[w] = distance[v] + 1;
	    		path[w] = v;
	    		q.push(w);
	    	}
	    }
	}
	return make_pair(distance, path);
}

