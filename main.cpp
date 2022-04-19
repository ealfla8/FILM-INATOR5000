#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include "graph.h"
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;

int main() {
    
    adjacencyList* adjList = new adjacencyList;

    string file1 = "title.basics.tsv"; //for title, isAdult, genre
    string file2 = "title.crew.tsv"; //for directors, writers

    ifstream f1Stream;
    f1Stream.open(file1);
    if (!(f1Stream.is_open())) {
        cout << "You twit." << endl;
    }

    string input;

    getline(f1Stream, input);
    int count = 0;
    while (getline(f1Stream, input)) {
        if (count == 10) {  //change for different range of test cases
            break;
        }
        stringstream lineData(input);
        string token;
        node* temp = new node;
        string tempStr;

        getline(lineData, token, '\t');
        temp -> id = stoi(token.substr(2));
        getline(lineData, token, '\t');
        getline(lineData, token, '\t');
        temp -> name = token;
        getline(lineData, token, '\t');
        getline(lineData, token, '\t');
        if (token == "1") {
            temp -> isExplicit = true;
        }
        else {
            temp -> isExplicit = false;
        }
        getline(lineData, token, '\t');
        getline(lineData, token, '\t');
        getline(lineData, token, '\t');
        getline(lineData, token, '\t');
        tempStr = token;
        while (tempStr.find(',') != string::npos) {
            temp -> genre.push_back(tempStr.substr(0, tempStr.find(',')));  //romance,comedy,somethingelse
            tempStr = tempStr.substr(tempStr.find(',') + 1);
        }
        temp -> genre.push_back(tempStr.substr(0, string::npos));
        adjList -> insert(*temp);
        count += 1;
        delete temp;
    }

    f1Stream.close();

    ifstream f2Stream;
    f2Stream.open(file2);
    if (!(f2Stream.is_open())) {
        cout << "You twit." << endl;
    }

    string input2;

    getline(f2Stream, input);
    int count2 = 0;
    while (getline(f2Stream, input)) {
        if (count2 == 10) { //change for different range of test cases
            break;
        }

        stringstream lineData(input);
        string token;
        node* temp = new node;
        string tempStr;

        getline(lineData, token, '\t');
        temp -> id = stoi(token.substr(2));
        getline(lineData, token, '\t');
        temp -> director = token.substr(0, ',');
        getline(lineData, token, '\t');

        for (auto v : adjList -> getNodes()) {
            if (v.second.id == temp -> id) {
                v.second.director = temp -> director;
            }
        }
        count2 += 1;

        delete temp;
    }

    f2Stream.close();

    adjList -> printGraph();
    //adjList.dfs(adjList.getNodes()[1]);

    return 0;
}
