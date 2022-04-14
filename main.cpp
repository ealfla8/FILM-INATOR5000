#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;

int main() {
    //string file1 = "title.akas.tsv"; //for language
    string file1 = "title.basics.tsv"; //for title, isAdult, genre
    string file2 = "title.crew.tsv"; //for directors, writers

    ifstream f1Stream;
    f1Stream.open(file1);
    if (!(f1Stream.is_open())) {
        cout << "You twit." << endl;
    }

    string input;

    getline(f1Stream, input);
    while (getline(f1Stream, input)) {

        stringstream fileData(input);
        string token;
        //Node temp;
        //**string tempStr;

        getline(fileData, token, '\t');
        //temp.id = token;
        getline(fileData, token, '\t');
        getline(fileData, token, '\t');
        //temp.title = token;
        getline(fileData, token, '\t');
        getline(fileData, token, '\t');
        //temp.isAdult = token;
        //or
        //if (token == 0)
            //temp.isAdult = true;
        //else
            //temp.isAdult = false;
        getline(fileData, token, '\t');
        getline(fileData, token, '\t');
        getline(fileData, token, '\t');
        getline(fileData, token, '\t');
        //temp.genres = token
        //or
        //**tempStr = token;
        //while (tempStr.size() > 0)
            //temp.genres.push_back(tempStr.substr(0, ','));
            //tempStr = tempStr.substr(',');
    }

    f1Stream.close();

    ifstream f2Stream;
    f2Stream.open(file2);
    if (!(f2Stream.is_open())) {
        cout << "You twit." << endl;
    }

    string input2; //can probably use the same one but it makes me feel better

    getline(f2Stream, input);
    while (getline(f2Stream, input)) {

        stringstream lineData(input);
        string token;
        //Node temp;
        //**string tempStr;
        //string tempId;

        getline(lineData, token, '\t');
        //tempId = token;
        getline(lineData, token, '\t');
        //temp.directors = token
        //or
        //**tempStr = token;
        //while (tempStr.size() > 0)
        //temp.directors.push_back(tempStr.substr(0, ','));
        //tempStr = tempStr.substr(',');
        getline(lineData, token, '\t');
        //temp.directors = token
        //or
        //**tempStr = token;
        //while (tempStr.size() > 0)
        //temp.directors.push_back(tempStr.substr(0, ','));
        //tempStr = tempStr.substr(',');
    }

    f2Stream.close();

    return 0;
}
