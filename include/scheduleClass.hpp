#ifndef SCHEDULECLASS_HPP
#define SCHEDULECLASS_HPP

#include <iostream>
using namespace std;

class Task {
public:
    string name;
    string description;
    string date;
    string priority;
    string status;

    Task(string n, string d, int m, int day, string p);
};

#endif
