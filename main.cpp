#include "instance.h"
#include "config.h"
#include "utils.h"
using namespace std;

int main(int argc, char* argv[])
{
    try{
        Config config(argc, argv);
        Instance instance(config.input);
    }
    catch (const string& e) { std::cerr << "EXCEPTION | " << e << "\n"; }

    return 0;
}
