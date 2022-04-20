#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
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
		id = 0;
		startYear = 0;
	}

	node(int id,string n, string d, double r, bool e, vector<string> g, int sY) {
		name = n;
    director = d;
		rating = r;
		isExplicit = e;
		this->id = id;
		genre = g;
		startYear = sY;
	}

  void to_string(node& n){
    cout << "Name: " << name << endl;
    cout << "Director: " << director << endl;
    cout << "Rating: " << rating << endl;
    cout << "Explicit: " << isExplicit << endl;
    cout << "Genre(s): ";
    for(int i = 0; i < genre.size(); i++)
      cout << genre.at(i) << " ";
    cout << endl << "Year Released: " << startYear << endl;
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
			vector<pair<int, double>> a = {};
			graph[n.id] = a;
			nodes[n.id] = n;
			names[n.name] = n.id;
		}
		vCount++;
	}

	int isAdjacent(int a, int b) { //this works!! yay!!!
		node aA = nodes[a];
		node bB = nodes[b];
		int c = 0;

		for(int i = 0; i < aA.genre.size(); ++i){
			for(int j = i; j < bB.genre.size(); ++j){
				if(aA.genre[i] == bB.genre[j]){
					++c;
				}
			}
		}
		//cout << c; 
		return c;
	}

  void createEdge(node& a, node& b){
    int i = isAdjacent(a.id, b.id);
    if(i >= 1){
      double weightAB = getWeight(a, b);
      double weightBA = getWeight(b, a);
      graph[a.id].push_back(make_pair(b.id, weightAB));
      graph[b.id].push_back(make_pair(a.id, weightBA));
    }
  }

	double getWeight(node& from, node& to) {
		double score = 0.0;
		for (int i = 0; i < from.genre.size(); i++) {
			if (from.genre[i] == to.genre[i]) {
				score += 2.5;
			}
		}

		if (from.director == to.director) {
			score += 1.5;
		}

		if (from.isExplicit == to.isExplicit) {
			score += 1.5;
		}

		if (abs(from.startYear - to.startYear) <= 5.0) {
			score += 1.5;
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

  unordered_map<int, vector<pair<int, double>>> getGraph(){
    return graph;
  }

  bool isEqualGenre(node& a, node&b){
	  int ii = 0; 
	  for(int i=0; i<a.genre.size(); i++){
		  if(find(b.genre.begin(), b.genre.end(), a.genre.at(i)) != b.genre.end())
		  		ii++; 
	  }
	  if( ii == a.genre.size())
	  		return true; 
	  return false; 
  }

	void bfs(node& src) {
		/*
		set<int> visited;
		queue<int> q;
		vector<int> m;
    cout << "created the set, queue, and vector" << endl;

		visited.insert(src.id);
		q.push(src.id);
    cout << "inserted and pushed" << endl;

		while (!q.empty()) {
      cout << "entered the while loop" << endl;
			int u = q.front();
			m.push_back(u);
			q.pop();
			vector<pair<int, double>> neighbors = graph[u];
			for (int v = 0; v < neighbors.size(); v++) {
        cout << "entered the for loop" << endl;
				//if (isEqualGenre(node& a, node&b)) {
					int id = graph[u].at(v).first;
					int idv = neighbors.at(v).first;
					if (isEqualGenre(nodes[id], nodes[idv])) {
            cout << "entered the if statement" << endl;
						visited.insert(graph[u].at(v).first);
						q.push(graph[u].at(v).first);
					}
				//}
			}
		}
    cout << "reached end of bfs" << endl;
		return m;
		*/
		set<int> visited;
		queue<int> q;

		visited.insert(src.id);
		q.push(src.id);
		cout << "Movies that have the same genre as " << src.name << endl;

		while(!q.empty()){
			int u = q.front();
			q.pop();
			vector<pair<int, double>> neighbors = graph[u];
			for(int v = 0; v < neighbors.size(); v++){
				if(visited.count(neighbors.at(v).first) == 0){
					visited.insert(neighbors.at(v).first);
					q.push(neighbors.at(v).first);
					cout << nodes[neighbors.at(v).first].name << endl;
				}
			}
		}
	}

	vector<int> dfs(node& src) {
		set<int> visited;
		stack<int> s;
		vector<int> vec;
    cout << "hello" << endl;
    
		visited.insert(src.id);
		s.push(src.id);
    cout << "hello part 1" << endl;

		while (!s.empty()) {
      cout << "hello in the while" << endl;
			int u = s.top();
			vec.push_back(u);
			s.pop();
			vector<pair<int, double>> neighbors = graph[u];
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
			for (int v = 0; v < neighbors.size(); v++) {
        cout << "hello in the for loop" << endl;
				int id = graph[u].at(v).first;
				int idv = neighbors.at(v).first;
				if (isAdjacent(id, idv) >= 1) {
          cout << "hello in the if statement" << endl;
					visited.insert(graph[u].at(v).first);
					s.push(graph[u].at(v).first);
				}
			}
		}
    cout << "hellow world" << endl;
		return vec;
	}
	
	//hard coding to 2 works
	//accurate version is on github
	void printGraph() {
		auto iter = graph.begin();
		for (iter; iter != graph.end(); iter++) {
			cout << iter->first << ": " << nodes[iter->first].name << endl;
			cout << "Adjacent Movies: " << endl;
			for (int i = 0; i < iter->second.size(); i++)
				cout << iter->second.at(i).first << ": " << nodes[iter->second.at(i).first].name << " - " << iter->second.at(i).second << endl;
			cout << endl;
		}
	}

};


    
