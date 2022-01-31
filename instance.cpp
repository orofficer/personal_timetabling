#include "instance.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include "utils.h"
#include "lop.h"
//#include <boost/filesystem.hpp>

Instance :: Instance(string instanceFile){
    read_input(instanceFile);
}

void Instance :: read_input(const string &inputFile){
    ifstream myFile(inputFile);
    if(!myFile.is_open()){
        cout << "Unable to open file \n";
        exit(0);
    }
    string line;
    vector <string> elements;
    getline(myFile, line);

    while(getline(myFile, line)){
        split(line, elements, ',');
        for (string e : elements){
            cout << e << " - ";
        }
        cout << "\n";

    }
    myFile.close();
}

void Instance::read_domain(const string domainfile)
{
    ifstream myFile(domainfile);
    if(!myFile.is_open()){
        cerr << "Unable to open domain file \n";
        exit(0);
    }
    string line;
    vector <string> elements;
    getline(myFile, line);

    while(getline(myFile, line)){
        split(line, elements, ',');

        for (string e : elements){
            cout << e << " - ";
        }
        cout << "\n";

    }
    myFile.close();
}

template <class Container>
void Instance :: split (const std::string &str, Container &cont, char delim){
    cont.clear();
    std::stringstream ss (str);
    std::string token;
    while(std::getline(ss,token,delim))
        if(token != "")
            cont.push_back(token);
}
