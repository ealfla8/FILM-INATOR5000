#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
using namespace std;

// idea: read in data and make unordered map with vector<pair<int,double>>> w/ double (weight) initially = 0
//		 also at same time create nodes and push into map of map<int node> m
//		 for each node in map, check and see if there is a single genre in common with each other, if there is, create "edge"
//		 select "choice" and head to that specific index in graph
//		 look at the connected edges and calculate weight; choose the max/min (max similarity score or min 1/similarity score) and return that


struct node {
	int id;
	int startYear;

	string name;
	string director;
	vector<string> genre;

	double rating;

	bool isExplicit;

	node() {
		name = director = "";
		rating = 0.0;
		isExplicit = false;
		id = 0000000;
		startYear = 0;
	}

	node(int id, string n, string d, double r, bool e, vector<string> g, int sY) {
		name = n;
		director = d;
		rating = r;
		isExplicit = e;
		this->id = id;
		genre = g;
		startYear = sY;
	}
};

class adjacencyList {
	double vCount;
	unordered_map<int, vector<pair<int, double>>> graph;
	unordered_map<int, node> nodes;
	unordered_map<string, int> names;

public:
	adjacencyList() {
		vCount = 0.0;
	}

	void insert(node& n) {
		if (graph.find(n.id) == graph.end()) {
			//pair<int, double> a = make_pair(n.id, 0.0);
			vector<pair<int, double>> a = {};
			graph[n.id] = a;
			nodes[n.id] = n;
			//graph[n.id].pop_back();
			names[n.name] = n.id;
		}
		//if node shares genre with any movie, create an edge with it...
		auto iter = graph.begin();
		iter++;
		for (iter; iter != graph.end(); iter++) {
			int i = iter->first;
			//cout << i << endl;
			if (isAdjacent(n.id, i) != 0) { //this is the problem!! it doesn't get here!!! 
				cout << "it got inside the third if" << endl;
				pair<int, double> p1 = make_pair(n.id, 0.0); //the pair that represents the movie adjacent to i
				pair<int, double> p2 = make_pair(i, 0.0); //the pair that represents the movie adjecent to n
				graph[n.id].push_back(p2); //pushback p2 into vector of movies adjacent to n
				graph[i].push_back(p1); //pushback p1 into vector of movies adjacent to i
			}
		}
		//cout << endl;
		vCount++;
	}


	int isAdjacent(int a, int b) { //this works!! yay!!!
		node aA = nodes[a];
		node bB = nodes[b];
		int i = 0;

		//A: 0 1 2
		//B: 0 1 2
		//Possible combos: 0-0, 0-1, 0-2, 1-1, 1-2, 2-2

		if (aA.genre[0] == bB.genre[0])
			i++;
		if (aA.genre[0] == bB.genre[1])
			i++;
		if (aA.genre[0] == bB.genre[2])
			i++;
		if (aA.genre[1] == bB.genre[1])
			i++;
		if (aA.genre[1] == bB.genre[2])
			i++;
		if (aA.genre[2] == bB.genre[2])
			i++;
		return i;
	}

	double getWeight(node& from, node& to) {
		double score = 0.0;
		for (int i = 0; i < from.genre.size(); i++) {
			if (from.genre[i] == to.genre[i]) {
				score += 2.0;
			}
		}

		if (from.director == to.director) {
			score += 1.0;
		}

		if (from.isExplicit == to.isExplicit) {
			score += 0.5;
		}

		if (abs(from.startYear - to.startYear) <= 5.0) {
			score += 1.0;
		}

		double weight = (1.0 / score);
		return weight;
	}

	//given a name identify what node it is 
	node identifier(string str) {
		int i;
		if (names.count(str) != 0)
			i = names[str];
		return nodes[i];
	}

	unordered_map<int, node>& getNodes() {
		return nodes;
	}

	vector<int> bfs(node& src) {
		set<int> visited;
		queue<int> q;
		vector<int> m;

		visited.insert(src.id);
		q.push(src.id);

		while (!q.empty()) {
			int u = q.front();
			m.push_back(u);
			q.pop();
			vector<pair<int, double>> neighbors = graph[u];
			//sort(neighbors.begin(), neighbors.begin() + neighbors.size());
			for (int v = 0; v < neighbors.size(); v++) {
				//if (visited.count(neighbors.at(v).first) != 0) {
					/*
					if (graph[u].at(v).second >= 0.0 && graph[u].at(v).second <= 0.5) {
						visited.insert(graph[u].at(v).first);
						q.push(graph[u].at(v).first);
					}
					*/
					//make sure that all the genres are equalllll
					//unordered_map<int, vector<pair<int, double>>> graph;
					//unordered_map<int, node> nodes;
					//unordered_map<string, int> names;
				int id = graph[u].at(v).first;
				int idv = neighbors.at(v).first;
				if (nodes[id].genre == nodes[idv].genre) {
					visited.insert(graph[u].at(v).first);
					q.push(graph[u].at(v).first);
				}
				//}
			}
		}
		return m;
	}

	vector<int> dfs(node& src) {
		set<int> visited;
		stack<int> s;
		vector<int> vec;

		visited.insert(src.id);
		s.push(src.id);

		while (!s.empty()) {
			int u = s.top();
			vec.push_back(u);
			s.pop();
			vector<pair<int, double>> neighbors = graph[u];
			/*
			for (visited.count(neighbors.at(v).first) == 0) {
				if (graph[u].at(v).second > 0.0 && graph[u].at(v).second > 0.5 && graph[u].at(v).second <= 1) {
					visited.insert(graph[u].at(v).first);
					s.push(graph[u].at(v).first);
				}
			}
			*/
			/*
			for (int v : neighbors.size()) {
				if (visited.count(neighbors.at(v).first) == 0) {
					if (graph[u].at(v).second >= 0.0 && graph[u].at(v).second <= 0.5) {
						visited.insert(graph[u].at(v).first);
						s.push(graph[u].at(v).first);
					}
				}
			}
			*/
			//make sure at least one is equal
			// 0 1 2 --> 0 0 - 0 1 - 0 2 - 1 1 - 1 2 - 2 2
			// 0 1 2
			for (int v = 0; v < neighbors.size(); v++) {
				int id = graph[u].at(v).first;
				int idv = neighbors.at(v).first;
				if (nodes[id].genre.at(0) == nodes[idv].genre.at(0) || nodes[id].genre.at(0) == nodes[idv].genre.at(1) || nodes[id].genre.at(0) == nodes[idv].genre.at(2) || nodes[id].genre.at(1) == nodes[idv].genre.at(1) || nodes[id].genre.at(1) == nodes[idv].genre.at(2) || nodes[id].genre.at(2) == nodes[idv].genre.at(2)) {
					visited.insert(graph[u].at(v).first);
					s.push(graph[u].at(v).first);
				}
			}
		}
		return vec;
	}

	//hard coding to 2 works
	//accurate version is on github
	void printGraph() {
		/*
		auto iter = graph.begin();
		auto i = nodes.begin();
		for (iter; iter != graph.end(); iter++) {
			cout << iter->first << ": " << i->second.name << endl;
			cout << "Adjacent Movies: " << endl;
			for (int i = 0; i < iter->second.size(); i++)
				cout << iter->second.at(i).first << ": " << nodes[iter->second.at(i).first].name << " - " << iter->second.at(i).second << endl;
			cout << endl;
		}
		*/
		auto iter = graph.begin();
		//auto i = nodes.begin();
		for (iter; iter != graph.end(); iter++) {
			cout << iter->first << ": " << nodes[iter->first].name << endl;
			cout << "Adjacent Movies: " << endl;
			for (int i = 0; i < iter->second.size(); i++)
				cout << iter->second.at(i).first << ": " << nodes[iter->second.at(i).first].name << " - " << iter->second.at(i).second << endl;
			cout << endl;
		}
	}

};

