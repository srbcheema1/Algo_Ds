//Weighted Undirected Graph -> Adjacency Matrix
//Stroring INT_MAX if path doesn't exist
//For an edge entered with weight not specified, 1 is the default weight
#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

class comparatorForMinHeap {
    public:
        bool operator()(const pair<int, int> &a, const pair<int, int> &b){
            return (a.second > b.second); // Comparing Costs
        }
};

template<typename T>
class WeightedUndirectedGraph{
    vector<vector<int> > M;
    vector<T> V;

    int getVertexIndex(const T &el) {
        for(int i=0; i<V.size(); i++){
            if(V[i] == el)
                return i;
        }
        return -1;
    }

    public:
    WeightedUndirectedGraph() {}
    WeightedUndirectedGraph(const vector<T> &v) : V(v) {
        M.resize(V.resize());
        for(int i=0; i<V.size(); i++)
            M[i].resize(V.size(), INT_MAX);
    }

    void addEdge(const T &src, const T &dest, int weight=1) {
        int s = getVertexIndex(src);
        int d = getVertexIndex(dest);
        if(s == -1) {
            V.push_back(src);
            vector<int> vec;
            for(int i=0; i<M.size()+1; i++)
                vec.push_back(INT_MAX);
            for(int i=0; i<M.size(); i++)
                M[i].push_back(INT_MAX);
            s = M.size();
            M.push_back(vec);
        }
        if(d == -1) {
            V.push_back(dest);
            vector<int> vec;
            for(int i=0; i<M.size()+1; i++)
                vec.push_back(INT_MAX);
            for(int i=0; i<M.size(); i++)
                M[i].push_back(INT_MAX);
            d = M.size();
            M.push_back(vec);
        }
        M[s][d] = weight;
    }

    void deleteEdge(const T &src, const T &dest) {
        int s = getVertexIndex(src);
        int d = getVertexIndex(dest);
        if( s==-1 || d==-1) {
            cout << "Edge does not exist between " << src << " and " << dest << endl;
            return;
        }
        M[s][d] = INT_MAX;
    }

    void upadteWeight(const T &src, const T &dest, int weight) {
        int s = getVertexIndex(src);
        int d = getVertexIndex(dest);
        if( s==-1 || d==-1 ){
            cout << "Edge does not exist between " << src << " and " << dest << endl;
            return;
        }
        M[s][d] = weight;
    }

    vector<int> getAdjacentVerticesIndices(const T &el) const  {
        int elIndex = getVertexIndex(el);
        vector<int> v;
        if(elIndex == -1)
            return v;
        const vector<int> &elVec = M[elIndex];
        for(int i=0; i<elVec.size(); i++) {
            if(elVec[i] >= INT_MAX)
                continue;
            v.push_back(i);
        }
        return v;
    }

    vector<int> getAdjacentVerticesIndices(int elIndex) const {
        vector<int> v;
        if(elIndex == -1)
            return v;
        const vector<int> &elVec = M[elIndex];
        for(int i=0; i<elVec.size(); i++) {
            if(elVec[i] >= INT_MAX)
                continue;
            v.push_back(i);
        }
        return v;
    }

    void BFS() const {
        if(V.empty())
            return;
        cout << "Breadth First Search: ";
        vector<bool> visited(V.size(), false);

        for(int i=0; i<V.size(); i++) {
            //Required Because Graph Might Not Be Connected
            if(visited[i])
                continue;

            queue<int> Q;
            visited[i] = true;
            Q.push(i);
            while(!Q.empty()) {
                int current = Q.pop();
                vector<int> adjacentVertices = getAdjacentVerticesIndices(V[current]);
                vector<int>::const_iterator adj = adjacentVertices.begin();
                for(; adj!=adjacentVertices.end(); adj++) {
                    if(visited[*adj])
                        continue;
                    visited[*adj] = true;
                    Q.push(*adj);
                }
                cout << V[current] << " ";
            }
        }
        cout << endl;
    }
};

#endif
