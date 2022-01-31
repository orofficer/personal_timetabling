#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <string>
#include <chrono>
#include <random>
using namespace std;

class Config
{
public:

    string input;
    bool found_input = false;

    string output;
    bool found_output = false;

    double time_limit = 30.0;
    bool found_time_limit = false;

    Config(int argc, char* argv[]) {
        for (int i = 1; i < argc; ++i) {
            string key = argv[i];

            if (key == "-i") {
                string value = argv[++i];
                input = value;
                found_input = true;
            }

            else if (key == "-o") {
                string value = argv[++i];
                output = value;
                found_output = true;
            }

            else if (key == "-t") {
                string value = argv[++i];
                time_limit = stof(value);
                found_time_limit = true;
            }

            else {
                cerr << "Invalid argument !!!\n";
                exit(0);
            }
        }

        if (!found_input) {
            cerr << "ERROR: Input is required !!!\n";
            exit(0);
        }
        if (!found_output) {
    //	    cout << "Warning: Output is missing !!!!\n";
        }
        if (!found_time_limit) {
    //	    cout << "Warning: time_limit default = 30.0s\n";
        }
        cout << flush;
    }
};

#endif // CONFIG_H
