#ifndef LOP_H
#define LOP_H
#include <string>
#include <iostream>
using namespace std;

class Buoihoc
{
public:
    Buoihoc(string type, string section, int day_, float startTime, float endTime, int startWeek, int endWeek, string room, string instructor) :
        type(type),
        section(section),
        day(day_),
        startTime(startTime),
        endTime(endTime),
        startWeek(startWeek),
        endWeek(endWeek),
        room(room),
        instructor(instructor)
    {
        cout << "1 Buoihoc created! \n";
    }

    const string type;
    const string section;

    const int day;
    const float startTime;
    const float endTime;
    const int startWeek;
    const int endWeek;
    const string room;
    const string instructor;
};

class Lop
{
public:
    Lop();
    string course;
    int id;

};

#endif // LOP_H
