#pragma once
#pragma once
#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
class Graph
{
public:
	bool isDirected=true;
	list<pair<string, bool>>graph;
	unordered_map<string, list<pair<string, int>>> adjlist;
	string gr;
	Graph();
	void AddEdge();
	void Addcity();
	void displaygraphdata();
	void Deletecity();
	void DeleteEdge();
	void mainmenu();
	void updategraph();
	void dijkstra(unordered_map<string, list<pair<string, int>>>, string s, string d);
	void DFS();
	void BFS();
	void save();
	void loadEdges(unordered_map<string, list<pair<string, int>>>&);
	void savecities();
	void loadCities(unordered_map<string, list<pair<string, int>>>& my_map);
	void AddGraph();
	void DeleteGraph();
	void LoadGraph();
	void SaveGraphes();
	void LoadGraphes(list<pair<string, bool>>& my_Graph);
	~Graph();
};
