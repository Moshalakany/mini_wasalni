#include "Graph.h"
#include<iostream>
#include<unordered_map>
#include<iterator>
using namespace std;
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<fstream>
#include<utility>
#include <sstream>
Graph::Graph() {

}
void Graph::AddEdge()
{
	if (adjlist.size() < 2) {
		cout << "Cities is less than 2 ! \n";
		return;
	}
	string city1;
	string city2;
	int weight;
	int count = 0;
	while (true)
	{
		cout << "Enter source:" << endl;
		cin >> city1;
		cout << "Enter distination: " << endl;
		cin >> city2;

		if (city1 != city2)
			break;
		cout << "You can not enter the same source and destination!!\n\n";
	}
	if (adjlist.find(city1) != adjlist.end() && adjlist.find(city2) != adjlist.end()) {
		while (true)
		{

			cout << "Enter distance between cities" << endl;
			cin >> weight;
			cout << "\n";
			if (weight > 0)
				break;
			cout << "You must enter postive value!\n\n";
		}
		bool check = true;
		if (!isDirected) {
			for (auto it : adjlist) {


				for (auto iti : it.second) {

					if ((it.first == city1 && iti.first == city2 && iti.second == weight) ||
						(it.first == city2 && iti.first == city1 && iti.second == weight)) {
						check = false;
						break;
					}
				}
			}
			if (check) {
				adjlist[city1].push_back(make_pair(city2, weight));
				adjlist[city2].push_back(make_pair(city1, weight));
				cout << " Added \n\n";

			}
			else
				cout << "This data is already added !! \n\n";
		}
		else
		{
			for (auto it : adjlist) {


				for (auto iti : it.second) {

					if ((it.first == city1 && iti.first == city2 && iti.second == weight)) {
						check = false;
						break;
					}
				}
			}
			if (check) {
				adjlist[city1].push_back(make_pair(city2, weight));
				cout << " Added \n\n";

			}
			else
				cout << "This data is already added !! \n\n";
		}
	}
	else
		cout << "One or the two cities you enterd are not exist please add them !\n\n";
}




void Graph::Addcity() {
	cout << "Enter  name of the city" << endl;
	string nameofcity;
	cin >> nameofcity;
	if (adjlist.find(nameofcity) == adjlist.end()) {
		adjlist[nameofcity];
		cout << " Added \n\n";
	}
	else {
		cout << "This city is already exist!\n\n";
	}
	//add new city 
}
void Graph::displaygraphdata() {
	if (adjlist.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	if (!isDirected) {
		for (auto it : adjlist) {
			for (auto iti : it.second) {

				cout << it.first << "----- " << iti.first;
				cout << "  " << iti.second << "   \n";
			
			}

		}
	}
	else
	{
		for (auto it : adjlist) {
			for (auto iti : it.second) {
				cout << it.first << "----> " << iti.first;

				cout << "  " << iti.second << "   \n";
			}

		}
	}
	for (auto it : adjlist)
	{
		cout << " City  " << " :   " << it.first << endl;
	}
}
void Graph::Deletecity()
{
	if (adjlist.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	cout << "Enter name of the city" << endl;
	string nameofcity;
	cin >> nameofcity;
	bool found = false;


	if (adjlist.find(nameofcity) != adjlist.end()) {
		adjlist.erase(nameofcity);
		cout << "Deleted\n\n";
		for (auto it : adjlist) {

			for (auto iti : it.second) {
				if (iti.first == nameofcity) {
					adjlist[it.first].remove(make_pair(iti.first, iti.second));
					
				}
			}
		}
	}
	else
	{
		cout << "This city is not exist\n\n";
	}
}

void Graph::DeleteEdge()
{
	bool isExist=false;
	for (auto it : adjlist) {
		if (!adjlist[it.first].empty()) {
			isExist = true;
			break;
		}
	}
	if (!isExist) {
		cout << "There is no edge to delete ! \n";
		return;
	}
	string city1;
	string city2;
	int weight;
	int count = 0;
	while (true)
	{
		cout << "Enter source:" << endl;
		cin >> city1;
		cout << "Enter distination: " << endl;
		cin >> city2;
		if (city1 != city2)
			break;
		cout << "You can not enter the same source and destination!!\n\n";
	}
	if (adjlist.find(city1) != adjlist.end() && adjlist.find(city2) != adjlist.end()) {
		while (true)
		{

			cout << "Enter distance between cities" << endl;
			cin >> weight;
			cout << "\n";
			if (weight > 0)
				break;
			cout << "You must enter postive value!\n\n";
		}
		bool check = false;
		if (!isDirected) {
			for (auto it : adjlist) {
				for (auto iti : it.second) {

					if ((it.first == city1 && iti.first == city2 && iti.second == weight) ||
						(it.first == city2 && iti.first == city1 && iti.second == weight)) {
						check = true;
						break;
					}
				}


			}
			if (check) {
				adjlist[city1].remove(make_pair(city2, weight));
				adjlist[city2].remove(make_pair(city1, weight));
				cout << " Deleted \n\n";
			}
			else
			{
				cout << "This edge is not exist to remove ! \n\n";
			}
		}
		else
		{
			for (auto it : adjlist) {
				for (auto iti : it.second) {

					if ((it.first == city1 && iti.first == city2 && iti.second == weight)) {
						check = true;
						break;
					}
				}


			}
			if (check) {
				adjlist[city1].remove(make_pair(city2, weight));
				cout << " Deleted \n\n";
			}
			else
			{
				cout << "This edge is not exist to remove ! \n\n";
			}
		}
	}
	else
		cout << "One or the two cities you enterd are not exist please add them !\n\n";
}
void Graph::mainmenu() {
	int press;
	while (true) {
		cout << "Press 1 to add city" << endl;
		cout << "Press 2 to add edge" << endl;
		cout << "Press 3 to display data" << endl;
		cout << "Press 4 to update graph" << endl;
		cout << "Press 5 to apply dijkstra\n";
		cout << "Press 6 to apply BFS\n";
		cout << "Press 7 to applly DFS\n";
		cout << "Press 8 to exit" << endl;
		cin >> press;
		if (press == 1) {
			Addcity();
		}
		else if (press == 2) {

			AddEdge();
		}

		else if (press == 3) {
			displaygraphdata();
		}
		else if (press == 4) {
			updategraph();
		}
		else if (press == 5) {
			if (adjlist.size() < 1) {
				cout << "No city added ! \n";
				continue;
			}
			cout << "Enter source: ";
			string s, d;
			cin >> s;
			cout << "Enter destination: ";
			cin >> d;
			dijkstra(adjlist, s, d);
		}
		else if (press == 6) {
			BFS();
		}
		else if (press == 7) {
			DFS();
		}
		else if (press == 8) {
			savecities();
			save();
			SaveGraphes();
			stack<string> del;
			for (auto it : adjlist) {
				del.push(it.first);
			}
			while (!del.empty())
			{
				adjlist.erase(del.top());
				del.pop();
			}
			break;
		}
		else
			cout << "Invalid Input!!\n";
	}
}
void Graph::updategraph() {
	if (adjlist.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	int press;
	while (true) {
		cout << "Press 1 to add new city" << endl;
		cout << "Press 2 to add new edge" << endl;
		cout << "Press 3 to remove city" << endl;
		cout << "Press 4 to remove edge" << endl;
		cout << "Press 5 to exit" << endl;
		cin >> press;

		if (press == 1) {
			Addcity();

		}
		else if (press == 2) {
			AddEdge();
		}
		else if (press == 3) {
			Deletecity();
		}
		else if (press == 4) {
			DeleteEdge();
		}
		else if (press == 5) {
			break;
		}
	}
}

void Graph::dijkstra(unordered_map<string, list<pair<string, int>>>adjlist, string s, string d)
{
	
	unordered_map<string, int> dist;
	unordered_map<string, bool> visited;
	unordered_map<string, string> parent;
	for (auto& i : adjlist) {
		dist[i.first] = INT_MAX;//set costs of all intially to a large number(infinity).
		visited[i.first] = false;
	}
	dist[s] = 0;//set cost of start point intially to zero.
	for (int i = 0; i < adjlist.size() - 1; i++) {//for loops that loop on the graph(adjancency list).
		string current = "";
		int shortestDistance = INT_MAX;
		for (auto& j : adjlist) {
			if (!visited[j.first] && dist[j.first] <= shortestDistance) {
				current = j.first;
				shortestDistance = dist[j.first];
			}
		}
		visited[current] = true;
		for (auto& j : adjlist[current]) {
			int edgeWeight = j.second;
			string neighbor = j.first;

			if (!visited[neighbor]) {
				int totalDistance = edgeWeight + dist[current];

				if (totalDistance < dist[neighbor]) {
					dist[neighbor] = totalDistance;
					parent[neighbor] = current;
				}
			}
		}
	}
	if (dist[d] != INT_MAX) {
		cout << "Shortest distance between " << s << " and " << d << " is " << dist[d] << endl;

		cout << "Shortest path is: ";
		vector<string> path;

		string current = d;
		while (current != s) {
			path.push_back(current);
			current = parent[current];
		}

		path.push_back(s);

		reverse(path.begin(), path.end());

		for (auto& i : path) {
			cout << i << " ";
		}
		cout << endl;
	}
	else {
		cout << "There is no path between " << s << " and " << d << endl;
	}
}
void Graph::BFS()
{
	if (adjlist.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	string start;
	cout << " Enter the starting city to apply BFS" << endl;
	cin >> start;
	if (adjlist.find(start) == adjlist.end())
	{
		cout << "This city is not found!" << endl;
	}
	else
	{
		queue <string>queue;
		unordered_map<string, bool>visited;
		queue.push(start);
		visited[start] = true;
		cout << "Following is Breadth First Traversal (starting from  \" " << start << " \" ) " << endl;
		while (!queue.empty()) {
			string temp = queue.front();
			queue.pop();
			cout << temp << endl;
			for (auto it : adjlist[temp])
			{
				if (!visited[it.first])
				{
					queue.push(it.first);
					visited[it.first] = true;
				}
			}
		}
	}
}
void Graph::DFS()
{
	if (adjlist.size() < 1) {
		cout << "No city added ! \n";
		return;
	}
	string start;
	cout << " Enter the starting city to apply DFS" << endl;
	cin >> start;
	if (adjlist.find(start) == adjlist.end())
	{
		cout << "This city is not found" << endl;
	}
	else
	{
		unordered_map<string, bool>visited;
		stack<string> stack;
		stack.push(start);
		cout << "Following is Depth First Traversal (starting from  \" " << start << " \" ) " << endl;
		while (!stack.empty())
		{
			string temp = stack.top();
			stack.pop();

			if (!visited[temp])
			{
				cout << temp << endl;
				visited[temp] = true;
			}
			for (auto it : adjlist[temp])
			{
				if (!visited[it.first])
				{
					stack.push(it.first);
				}
			}
		}
	}
}
void Graph::save()
{
	ofstream file(gr + "Edge.txt", ios::trunc);
	if (file.is_open()) {

		for (auto& i : adjlist)
		{


			for (auto& j : i.second)
			{
				file << i.first << " ";
				file << j.first << " " << j.second << endl;
				
			}
		}
	
	}
	file.close();
}
void Graph::loadEdges(unordered_map<string, list<pair<string, int>>>& my_map)
{
	ifstream infile(gr + "Edge.txt");
	if (infile.is_open()) {
		string outer_key, inner_key;
		int value;
		while (infile >> outer_key >> inner_key >> value) {
			my_map[outer_key].push_back(make_pair(inner_key, value));
		}
	}
	infile.close();
}
void Graph::savecities()
{
	ofstream file(gr + "city.txt", ios::trunc);

	if (file.is_open()) {

		for (auto& i : adjlist)
		{
			file << i.first << "\n";
		}
	}
	file.close();
}
void Graph::loadCities(unordered_map<string, list<pair<string, int>>>& my_map)
{
	ifstream infile(gr+"city.txt");
	if (infile.is_open()) {
		string city;
		while (infile >> city) {
			my_map[city];
		}
	}
	infile.close();
}
void Graph::AddGraph()
{
	int press;
	cout << "Enter Graph name" << endl;
	cin >> gr;
	for (auto it :graph) {
		if (gr == it.first) {
			cout << "This graph is already exist ! load it\n\n";
			return;
		}
	}
	cout << "press 1 for directed Graph" << endl;
	cout << "press 2 for Undirected Graph" << endl;
	cin >> press;
	if (press == 1) {

		graph.push_back(make_pair(gr,true));
		isDirected = true;
	}
	else if (press == 2) {
		graph.push_back(make_pair(gr, false));
		isDirected = false;
	}
	mainmenu();
}
void Graph::LoadGraph()
{
	if (graph.empty()) {
		cout << "No Graph added ! \n";
		return;
	}
	cout << "Graphes exist is : \n";
		for (auto it : graph)
		{
			cout <<" ( " <<it.first << " , ";
			if (it.second)
				cout << "Directed Graph )\n";
			else
			{
				cout << "Undirected Graph )\n";
			}
		}
	cout << "Enter Graph name" << endl;
	cin >> gr;
	for (auto it : graph) {
		if (gr == it.first) {
			isDirected = it.second;
				loadCities(adjlist);
				loadEdges(adjlist);
			mainmenu();
			return;
			
		}
			
	}
	cout << "This graph is not exist ! add it \n\n";

}

void Graph::DeleteGraph()
{
	if (graph.empty()) {
		cout << "No Graph added ! \n";
		return;
	}
	cout << "Graphes exist is : \n";
	for (auto it : graph)
	{
		cout << " ( " <<it.first << " , ";
		if (it.second)
			cout << "Directed Graph )\n";
		else
		{
			cout << "Undirected Graph )\n";
		}


	}
	string GRA;
	cout << "Enter Graph yoy want to delete\n";
	cin >> GRA;
	for (auto it : graph)
	{
		if (GRA == it.first) {
			graph.remove(make_pair(GRA, it.second));
			return;
		}
			
	}
	cout << "This graph is not exist !\n";
}

void Graph::SaveGraphes()
{
	ofstream file("Graph.txt", ios::trunc);

	if (file.is_open()) {

		for (auto it : graph) {
			file << it.first << " " << it.second << "\n";
		}
	}
	file.close();
}

void Graph::LoadGraphes(list<pair<string, bool>>& my_Graph)
{
	ifstream infile("Graph.txt");
	if (infile.is_open()) {
		string gra;
		bool direct;
		while (infile >> gra>> direct) {
			my_Graph.push_back(make_pair(gra, direct));
		}
	}
	infile.close();
}
Graph::~Graph()
{

}