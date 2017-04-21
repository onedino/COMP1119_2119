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

#define MAT_MAX 99999
//asd

using namespace std;

class Graph {
public:
	int edge;
	int vertex;
	int *matrix;
	int *dis;
	int *allDis;
	bool *inspectV;


	int index(int x, int y);
	Graph(int e);
	~Graph();
	void addEdge(int V1, int V2, int cost);
	void shortestPath(int src);
	int minDis();
	void printShortestPath(int dis[]);
	void shortestPathAll();
};

int Graph::index(int x, int y) {
	return (x + vertex*y);
}

Graph::Graph(int v) {
	vertex = v;
	matrix = new int[v*v];
//	dis = new int[v];
//	inspectV = new bool[v];
//	cout << "setting data" << endl;
	for(int i = 0; i < v; i++) {
		for(int j = 0;j<v;j++) {
			matrix[index(i,j)] = MAT_MAX;
		}
//			inspectV[i] = false;
//		cout << "setting up" << endl;
	}
}
Graph::~Graph() {
//	delete[] matrix;
//	delete[] allDis;
//	delete[] dis;
//	delete[] inspectV;
}
void Graph::addEdge(int V1, int V2, int cost) {
	matrix[index(V1,V2)] = cost;
	matrix[index(V2,V1)] = cost;
	edge++;
}
int Graph::minDis() {
	int min = MAT_MAX;
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
//void Graph::printShortestPath(int dis[]){
//	cout <<"Vertex Distance from Source" << endl;
//	int shortestPath = MAT_MAX;
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
	dis = new int[vertex];
	inspectV = new bool[vertex];
	for(int i = 0; i < vertex; i++) {
		dis[i] = MAT_MAX;
		inspectV[i] = false;
//		cout << "setting up" << endl;
	}
//	cout << "stage 1" << endl;
	dis[src] = 0;

	for(int count = 0; count < vertex - 1;count++){
		int u = minDis();
		if(u==src){break;}
		inspectV[u] = true;
		if(dis[u]==MAT_MAX){continue;}
		for (int v = 0; v < vertex; v++) {
			if (!inspectV[v] && matrix[index(u,v)] > 0 &&
			dis[u] != MAT_MAX && dis[u]+matrix[index(u,v)] < dis[v]) {
				dis[v] = dis[u] + matrix[index(u,v)];
//				cout << "crap" << endl;
			}
		}
//		cout << "crap" << endl;
	}
//	cout << "stage 2" << endl;
//	printShortestPath(dis);
}

void Graph::shortestPathAll() {
	for(int i=0; i<vertex;i++) {
		for(int j = 0; j < vertex; j++) {
				allDis[index(i,j)] = matrix[index(i,j)];
				allDis[index(j,i)] = matrix[index(j,i)];
//			cout << allDis[index(j,i)] << endl;
		}
	}
	for(int k=0;k<vertex;k++){
		for(int i=0;i<vertex;i++){
			for(int j=0;j<vertex;j++){
				if(allDis[index(i,k)]+allDis[index(k,j)]<allDis[index(i,j)]){
					allDis[index(i,j)]=allDis[index(i,k)]+allDis[index(k,j)];
					allDis[index(j,i)] = allDis[index(i,j)];
//					cout << allDis[index(i,j)] << endl;
				}
			}
		}
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
//        cout << a << " " << b << " " << g.matrix[g.index(a,b)] << endl;
    }
    int u;
    cin >> u;
    // implement your own shortest path
    g.shortestPath(u);

    int bestv = -1;
    int l;
    cin >> l;
    int closestCar = MAT_MAX;
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
    int n, m;
    cin >> n >> m;
    Graph g(n);
    g.allDis = new int[g.vertex * g.vertex];
    for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;

		g.addEdge(a, b, w);
//        cout << a << " " << b << " " << g.matrix[g.index(a,b)] << endl;
	}

    g.shortestPathAll();
    int queues;
    cin >> queues;
//    cout << "ok" << endl;
//    cout << queues << endl;;
    for(int i = 0;i < queues; i++) {
    	int start, des;	//start and destination
    	cin >> start >> des;
//    	cout <<i << endl;
    	cout << g.allDis[g.index(start,des)] << endl;
    }
}

void Diameter(){
    //your code starts here
	int n, m;
	cin >> n >> m;
	Graph g(n);
	g.allDis = new int[g.vertex * g.vertex];
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		g.addEdge(a, b, w);
	}
	g.shortestPathAll();
	int worstDis = 0;
	for(int i = 0; i < g.vertex; i++) {
		for(int j = 0;j < g.vertex; j++) {
			int dis = g.allDis[g.index(i,j)];
			if(dis == MAT_MAX) {
				cout << "NOT_CONNECTED" << endl; return;
			}
			if(dis > worstDis)
				worstDis = dis;
		}
	}
	cout << worstDis << endl;
}

void DiameterApproximation(){
    //your code starts here
	int n, m;
	cin >> n >> m;
	Graph g(n);
//	g.allDis = new int[g.vertex * g.vertex];
	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		g.addEdge(a, b, w);
	}
	g.shortestPath(0);
	int worstNode = 0;
	int worstDis = 0;
	for(int i = 0; i<g.vertex; i++) {
		cout << g.dis[i] << endl;
		if(g.dis[i] > worstDis && g.dis[i] != MAT_MAX) {
			worstDis = g.dis[i];
			worstNode = i;
		}
	}
//	cout << worstDis;
	int interimNode = worstNode;
	g.shortestPath(interimNode);
	worstDis = 0;
	for(int i = 0;i < g.vertex ; i++) {
		if(g.dis[i] > worstDis) {
			worstDis = g.dis[i];
			worstNode = i;
		}
	}
	if(worstDis == MAT_MAX)
		cout << "Not connected" <<endl;
	else
		cout << worstDis << endl;
	return;
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
