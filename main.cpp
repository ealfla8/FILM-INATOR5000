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

    adjacencyList* adjList = new adjacencyList();

    string file0 = "title.akas.tsv"; //for finding all English titles
    string file1 = "title.basics.tsv"; //for title, isAdult, genre
    string file2 = "title.crew.tsv"; //for directors, writers

    ifstream f0Stream;
    f0Stream.open(file0);
    if (!(f0Stream.is_open())) {
        cout << "You twit." << endl;
    }

    string inputInit;

    getline(f0Stream, inputInit);
    unsigned long count0 = 0;
    while (getline(f0Stream, inputInit)) {
        if (count0 == 4) {  //change for different range of test cases
            break;
        }
        stringstream lineData(inputInit);
        string token;
        node *temp = new node;

        getline(lineData, token, '\t');
        temp -> id = stoi(token.substr(2));
        getline(lineData, token, '\t');
        getline(lineData, token, '\t');
        //temp -> name = token;
        getline(lineData, token, '\t');
        getline(lineData, token, '\t');
        if (token == "en" && (adjList -> getGraph().find(temp -> id) == adjList -> getGraph().end())) {
            temp -> genre = {};
            adjList -> insert(*temp);
            count0 += 1;
            //cout << "just inserted node with ID: " << temp -> id << " and name: " << temp -> name << endl;
        }
        delete temp;
    }

    f0Stream.close();


    ifstream f1Stream;
    f1Stream.open(file1);
    if (!(f1Stream.is_open())) {
        cout << "You twit." << endl;
    }

    string input;

    //std::cout << "made it" << std::endl;
    getline(f1Stream, input);
    unsigned long count1 = 0;
    while (getline(f1Stream, input)) {
        if (count1 == 4) {  //change for different range of test cases
            break;
        }

        stringstream lineData(input);
        string token;
        node* temp = new node();
        string tempStr;

        getline(lineData, token, '\t');
        temp -> id = stoi(token.substr(2));
        if (adjList -> getGraph().find(temp -> id) == adjList -> getGraph().end()) {
            continue;
        }
        else {
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
            //std::cout << "made it 2" << std::endl;

            while (tempStr.find(',') != string::npos && temp -> genre.size() < 3) {
                temp -> genre.push_back(tempStr.substr(0, tempStr.find(',')));  //romance,comedy,somethingelse
                //cout << "ID: " << temp -> id << " genre: " << tempStr.substr(0, tempStr.find(',')) << endl;
                //cout << temp -> genre.size() << endl;
                tempStr = tempStr.substr(tempStr.find(',') + 1);
            }
            temp -> genre.push_back(tempStr.substr(0, string::npos));
            for (auto &v : adjList -> getNodes()) {
                if (v.second.id == temp -> id) {
                    v.second.isExplicit = temp -> isExplicit;
                    v.second.name = temp -> name;
                    for (auto &w : temp -> genre) {
                        //cout << "ID: " << temp -> id << " genre: " << w << endl;
                        v.second.genre.push_back(w);
                        //cout << "size of v's genres: " << v.second.genre.size() << endl;
                        //cout << "ID: " << temp -> id << " first g: " << v.second.genre[0] << endl;
                    }
                }
                //v.second.genre = temp -> genre;
            }
            count1 += 1;
        }
        delete temp;
    }

    //std::cout << "made it 1" << std::endl;

    f1Stream.close();

    ifstream f2Stream;
    f2Stream.open(file2);
    if (!(f2Stream.is_open())) {
        cout << "You twit." << endl;
    }

    string input2;

    //std::cout << "made it 2" << std::endl;

    getline(f2Stream, input);
    unsigned long count2 = 0;
    while (getline(f2Stream, input)) {
        if (count2 == 4) { //change for different range of test cases
            break;
        }

        stringstream lineData(input);
        string token;
        node* temp = new node();
        string tempStr;

        getline(lineData, token, '\t');
        temp -> id = stol(token.substr(2));
        getline(lineData, token, '\t');
        temp -> director = token.substr(0, ',');
        getline(lineData, token, '\t');

        for (auto &v : adjList -> getNodes()) {
            if (v.second.id == temp -> id) {
                v.second.director = temp -> director;
            }
        }
        count2 += 1;

        delete temp;
    }

    f2Stream.close();

    /*adjacencyList* adjList = new adjacencyList();
    node* node1 = new node();
    node1 -> id = 1;
    node1 -> name = "One!";
    node1 -> genre = {"action", "comedy"};

    node* node2 = new node();
    node2 -> id = 2;
    node2 -> name = "Two!";
    node2 -> genre = {"action", "romance"};

    node* node3 = new node();
    node3 -> id = 3;
    node3 -> name = "Three!";
    node3 -> genre = {"romance"};

    adjList -> insert(*node1);
    adjList -> insert(*node2);
    adjList -> insert(*node3);*/

    for (auto i : adjList -> getNodes()) {
        for (auto j : adjList -> getNodes()) {
            //cout << "made it" << endl;
            //cout << i.second.genre.size() << endl;
            adjList -> createEdge(i.second, j.second);
            //cout << adjList -> getNodes()[i].genre[0] << " " << adjList -> getNodes()[j].genre[0] << endl;
        }
    }

    //adjList -> printGraph();


    cout << "num nodes: " << (adjList -> getGraph()).size() << endl;
    int check = 0;
    for (auto i : adjList -> getGraph()) {
        for (auto j : i.second) {
            check += 1;
        }
    }
    cout << "num edges: " << check << endl;

    adjList -> printGraph();

    //cout << adjList -> dfs(adjList -> getNodes()[1]) << endl;

    //cout << "and upon closer inspection: " << adjList -> getGraph()[0][0].second << endl;
    //cout << "and upon closer inspection: " << adjList -> getGraph()[1][0].second << endl;
    //cout << "and upon closer inspection: " << adjList -> getGraph()[2][0].second << endl;
    return 0;
}


