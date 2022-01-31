#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <string>
using namespace std;

class Instance
{
public:


    Instance(string instanceFile);

private:
    void read_input (const string &inputFile);
    void read_domain (const string domainfile);

    template <class Container>
    void split(const std :: string& str, Container &cont, char delim);
};

#endif // INSTANCE_H
