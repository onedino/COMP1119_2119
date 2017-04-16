/*
 * 3035273448.cpp
 *
 *  Created on: 13 Apr, 2017
 *      Author: Lau
 */


//============================================================================
// Name        : 3035273448.cpp
// Author      : Lau Yin Heng Henry
// Version     : 1.0
// Copyright   :
// Description : 2119 programming assignment
//============================================================================

#include <iostream>
#include <string>
#include <assert.h>
#include <limits.h>
//asd

using namespace std;

class Graph {
public:
	int edge;
	int vertex;
	int *matrix;
	int *dis;
	int index(int x, int y);
	Graph(int e);
	void addEdge(int V1, int V2, int cost);
	void shortestPath(int src);
	int minDis(int dis[], bool inspectV[]);
	void printShortestPath(int dis[]);
};

int Graph::index(int x, int y) {
	return (x + vertex*y);
}

Graph::Graph(int v) {
	vertex = v;
	matrix = new int[v*v];
	dis = new int[v];
}

void Graph::addEdge(int V1, int V2, int cost) {
	matrix[index(V1,V2)] = cost;
	edge++;
}

int Graph::minDis(int dis[], bool inspectV[] ) {
	int min = INT_MAX, minIndex;

	for(int v = 0; v < vertex; v++) {
		if(inspectV[v] == false && dis[v] <= min) {
			min = dis[v];
			minIndex = v;
		}
	}
	return minIndex;
}

void Graph::printShortestPath(int dis[]){
	cout <<"Vertex	Distance from Source" << endl;
	int shortestPath = INT_MAX;
	int shortestV;
	for (int i = 0; i<vertex; i++) {
		if(shortestPath < dis[i]) {
			shortestPath = dis[i];
			shortestV = i;
		}
	}
	cout << shortestV << "\t" << shortestPath << endl;
}

void Graph::shortestPath(int src) {
//	dijkstra algo

	bool inspectV[vertex];

	for(int i = 0; i < vertex; vertex++) {
		dis[i] = INT_MAX;
		inspectV[i] = false;
	}
	for(int count = 0; count < vertex - 1;count++){
		int u = minDis(dis,inspectV);
		inspectV[u] = true;
		for (int v = 0; v < vertex; v++)
			if (!inspectV[v] && matrix[index(u,v)] && dis[u] != INT_MAX && dis[u]+matrix[index(u,v)] < dis[v])
			dis[v] = dis[u] + matrix[index(u,v)];
	}
	printShortestPath(dis);
}

void NearestDriver(){
    int n, m;

    cin >> n >> m;

    Graph g(n); // implement Graph class by yourself

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        g.addEdge(a, b, w);
    }

    int u;
    cin >> u;
    // implement your own shortest path
    g.shortestPath(u);

    int bestv = -1;
    int l;
    cin >> l;
    int closestCar = INT_MAX;
    for(int i = 0; i < l; i++){
    	int pos;
    	cin >> pos;
    	if(g.dis[pos] < closestCar) {
    		closestCar = g.dis[pos];
    		bestv = i;
    	}
        // scan over every car to get the final answer
    }

    if(bestv == -1)
        cout << "NO" << endl;
    else
        cout << bestv << endl;
    return;
}


void QueryPrice(){
    //your code starts here
}

void Diameter(){
    //your code starts here
}

void DiameterApproximation(){
    //your code starts here
}

int main(){
    string section;
    cin >> section;

    if(section == "NearestDriver")
        NearestDriver();
    else if(section == "QueryPrice")
        QueryPrice();
    else if(section == "Diameter")
        Diameter();
    else if(section == "DiameterApproximation")
        DiameterApproximation();
    else{
        cout << "wrong input file!" << endl;
        assert(0);
    }

    return 0;
}


