/*
 * 3035273448.cpp
 *
 *  Created on: 13 Apr, 2017
 *      Author: Lau
 */


//============================================================================
// Name        : 3035273448.cpp
// Author      : Lau Yin Heng Henry
// Version     :
// Copyright   : Please stop abusing programmers
// Description : 2119 programming assignment
//============================================================================

#include <iostream>
#include <string>
#include <assert.h>

#define INT_MAX 100000000

using namespace std;

class Graph {
public:
	int edge;
	int vertex;
	int *matrix;
	int index(int x, int y);
	Graph(int e);
	void addEdge(int aa, int bb, int ww);
	void shortestPath(int uu);
};

Graph::index(int x, int y) {
	return (x + vertex*y);
}

Graph::Graph(int v) {
	vertex = v;
	matrix = new int[v*v];
}

void Graph::addEdge(int aa, int bb, int ww) {
	matrix[index(aa,bb)] = ww;
	edge++;
}

void Graph::shortestPath(int src) {
//	dijkstra algo
//	need weed
	int dist[vertex];

	bool sptSet[vertex];

	for(int i = 0; i < vertex; vertex++) {
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	for(int count = 0; count < vertex - 1;count++){

	}
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
    for(int i = 0; i < l; i++){
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


