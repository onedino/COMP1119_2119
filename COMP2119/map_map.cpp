/*
 * map_map.cpp
 *
 *  Created on: 20 Apr, 2017
 *      Author: Lau
 */

#include <iostream>
#include <string>
#include <assert.h>
#include <limits.h>
#include <map>
#include <algorithm>
//asd

using namespace std;

class Graph {
public:
	int edge;
	int vertex;
	map <int, map<int, int> > graph_t;
	int *dis;
	bool *inspectV;
	int index(int x, int y);
	Graph(int e);
	void addEdge(int V1, int V2, int cost);
	void shortestPath(int src);
	int minDis();
	void printShortestPath(int dis[]);
};

int Graph::index(int x, int y) {
	return (x + vertex*y);
}

Graph::Graph(int v) {
	vertex = v;
	dis = new int[v];
	inspectV = new bool[v];
//	cout << "setting data" << endl;
//	for(int i = 0; i < v; v++) {
//		dis[i] = INT_MAX;
//		inspectV[i] = false;
////		cout << "setting up" << endl;
//	}
}
void Graph::addEdge(int V1, int V2, int cost) {
//	matrix[index(V1,V2)] = cost;
//	matrix[index(V2,V1)] = cost;
//	if(V1 > V2)
//		addEdge(V2, V1, cost);
//	else
	graph_t[V1][V2] = cost;
	graph_t[V2][V1] = cost;
	edge++;
}
int Graph::minDis() {
	int min = INT_MAX;
	int minIndex;

	for(int v = 0; v < vertex; v++) {
//		cout << v <<endl;
		if(inspectV[v] == false && dis[v] <= min) {
			min = dis[v];
			minIndex = v;
		}
	}
	return minIndex;
}

int index1(int a, int b) {
	int c;
	if(a>b)
		c = b;
	else
		c=a;
	return c;
}
int index2(int a, int b) {
	int c;
	if(a<b)
		c = b;
	else
		c = a;
	return c;
}
//void Graph::printShortestPath(int dis[]){
//	cout <<"Vertex Distance from Source" << endl;
//	int shortestPath = INT_MAX;
//	int shortestV;
//	for (int i = 0; i<vertex; i++) {
//		if(shortestPath < dis[i]) {
//			shortestPath = dis[i];
//			shortestV = i;
//		}
//	}
//	cout << shortestV << "\t" << shortestPath << endl;
//}

void Graph::shortestPath(int src) {
//	dijkstra algo
	for(int i = 0; i < vertex; i++) {
		dis[i] = INT_MAX;
		inspectV[i] = false;
//		cout << "setting up" << endl;
	}
//	cout << "stage 1" << endl;
	dis[src] = 0;

	for(int count = 0; count < vertex - 1;count++){
		int u = minDis();
		inspectV[u] = true;
		for (int v = 0; v < vertex; v++) {
			//
			if (!inspectV[v] && graph_t[u].count(v) &&
			dis[u] != INT_MAX && dis[u]+graph_t[u][v] < dis[v]) {
			//
				dis[v] = dis[u] + graph_t[u][v];
//				cout << "crap" << endl;
			}
		}
//		cout << "crap" << endl;
	}
//	cout << "stage 2" << endl;
//	printShortestPath(dis);
}

void NearestDriver(){
    int n, m;

    cin >> n >> m;

    Graph g(n); // implement Graph class by yourself

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        g.addEdge(a, b, w);
//        cout << a << " " << b << " " << g.matrix[g.index(a,b)] << endl;
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
    		bestv = pos;
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


