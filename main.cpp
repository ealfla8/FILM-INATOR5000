#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include "graph.cpp"
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
        cout << "File Not Opened" << endl;
    }

    string inputInit;

    getline(f0Stream, inputInit);
    unsigned long count0 = 0;
    while (getline(f0Stream, inputInit)) {
        if (count0 == 10000) {  
            break;
        }
        stringstream lineData(inputInit);
        string token;
        node *temp = new node;

        getline(lineData, token, '\t');
        temp -> id = stoi(token.substr(2));
        getline(lineData, token, '\t');
        getline(lineData, token, '\t');
        temp -> name = token;
        getline(lineData, token, '\t');
        getline(lineData, token, '\t');
        if (token == "en" && (adjList -> getGraph().find(temp -> id) == adjList -> getGraph().end())) {
            temp -> genre = {};
            adjList -> insert(*temp);
            count0 += 1;
        }
        delete temp;
    }

    f0Stream.close();


    ifstream f1Stream;
    f1Stream.open(file1);
    if (!(f1Stream.is_open())) {
        cout << "File Not Opened" << endl;
    }

    string input;

    getline(f1Stream, input);
    unsigned long count1 = 0;
    while (getline(f1Stream, input)) {
        if (count1 == 10000) { 
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

            while (tempStr.find(',') != string::npos && temp -> genre.size() < 3) {
                temp -> genre.push_back(tempStr.substr(0, tempStr.find(',')));  //romance,comedy,somethingelse
                tempStr = tempStr.substr(tempStr.find(',') + 1);
            }
            temp -> genre.push_back(tempStr.substr(0, string::npos));
            for (auto &v : adjList -> getNodes()) {
                if (v.second.id == temp -> id) {
                    v.second.isExplicit = temp -> isExplicit;
                    for (auto &w : temp -> genre) {
                        v.second.genre.push_back(w);
                    }
                }
            }
            count1 += 1;
        }
        delete temp;
    }


    f1Stream.close();

    ifstream f2Stream;
    f2Stream.open(file2);
    if (!(f2Stream.is_open())) {
        cout << "File Not Opened" << endl;
    }

    string input2;


    getline(f2Stream, input);
    unsigned long count2 = 0;
    while (getline(f2Stream, input)) {
        if (count2 == 1000) { 
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

    for (auto i : adjList -> getNodes()) {
        for (auto j : adjList -> getNodes()) {
            adjList -> createEdge(i.second, j.second);
        }
    }

 
    int check = 0;
    for (auto i : adjList -> getGraph()) {
        for (auto j : i.second) {
            check += 1;
        }
    }

    string userInput = ""; 
    cout << "Behold! The Filminator 5000!" << endl; 
    cout << "Choose a movie you like: 1-20" << endl; 
    cout << "1: Blacksmith Scene" << endl; 
    cout << "2: The Arrival of the Train" << endl; 
    cout << "3: The Sea " << endl;  
    cout << "4: Fishing for Goldfish" << endl; 
    cout << "5: Jumping the Blanket" << endl; 
    cout << "6: The Devil's Castle" << endl; 
    cout << "7: A Terrible Night" << endl; 
    cout << "8: Card Party" << endl; 
    cout << "9: The Burglars" << endl; 
    cout << "10: At the Hypnotist's" << endl; 
    cout << "11: The Cabinet of Mephistopheles" << endl; 
    cout << "12: The Funeral of King Christian IX" << endl; 
    cout << "13: Clowns" << endl; 
    cout << "14: Hamlet" << endl; 
    cout << "15: The Cultivation of the Cacao Tree" << endl; 
    cout << "16: The Death of Ivan the Terrible" << endl; 
    cout << "17: Love Crazy" << endl; 
    cout << "18: Les Miserables" << endl; 
    cout << "19: The Moonshiners" << endl; 
    cout << "20: The Black Mask" << endl; 

    cin >> userInput; 
    node a; 

    if(userInput == "1"){
         a = adjList->getNodes()[5]; 
    }
    if(userInput == "2"){
         a = adjList->getNodes()[12]; 
    } 
    if (userInput == "3"){
         a = adjList->getNodes()[23]; 
    } 
    if(userInput == "4"){
         a = adjList->getNodes()[28]; 
    }
    if (userInput == "5"){
         a = adjList->getNodes()[31]; 
    }
    if(userInput == "6"){
        a  = adjList->getNodes()[91]; 
    }
    if(userInput == "7"){
        a  = adjList->getNodes()[131]; 
    }
    if(userInput == "8"){
        a  = adjList->getNodes()[132]; 
    }
    if(userInput == "9"){
        a  = adjList->getNodes()[143]; 
    }
    if(userInput == "10"){
        a  = adjList->getNodes()[144]; 
    }
    if(userInput == "11"){
        a = adjList->getNodes()[159]; 
    }
    if(userInput == "12"){
        a = adjList->getNodes()[543]; 
    }
    if(userInput == "13"){
        a = adjList->getNodes()[558]; 
    }
    if(userInput == "14"){
        a = adjList->getNodes()[631]; 
    }
    if(userInput == "15"){
        a = adjList->getNodes()[838]; 
    }
    if(userInput == "16"){
        a = adjList->getNodes()[844]; 
    }
    if(userInput == "17"){
        a = adjList->getNodes()[941]; 
    }
    if(userInput == "18"){
        a = adjList->getNodes()[969]; 
    }
    if(userInput == "19"){
        a = adjList->getNodes()[618]; 
    }
    if(userInput == "20"){
        a = adjList->getNodes()[573]; 
    }

    adjList->bfs(a); 
    cout << endl; 
    adjList->dfs(a); 


    return 0;
}

