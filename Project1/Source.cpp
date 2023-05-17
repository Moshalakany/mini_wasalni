#include<iostream>
#include<unordered_map>
#include<iterator>
#include<string>
#include<vector>
#include"Graph.h"
using namespace std;
Graph g;
int main() {
	int press;
	g.LoadGraphes(g.graph);
	g.loadCities(g.adjlist);
	g.loadEdges(g.adjlist);
	while (true) {
		cout << "press 1 to add new graph" << endl;
		cout << "press 2 to load graph" << endl;
		cout << "press 3 to delete graph" << endl;
		cout << "press 4 to exit" << endl;
		cin >> press;
		if (press == 1) {
			g.AddGraph();
		}
		else if (press == 2) {
			g.LoadGraph();
		}
		else if (press == 3)
			g.DeleteGraph();
		else if (press == 4) {
			g.SaveGraphes();
			break;
		}
	}
	
	return 0;
}