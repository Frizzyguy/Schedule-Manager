#ifndef SCHEDULECLASS_HPP
#define SCHEDULECLASS_HPP

#include <iostream>
#include <vector>
using namespace std;

class schedule {
public:
    schedule(string n, string desc, int month, int day, string p);

    string name;
    string description;
    string date;
    string priority;
    string status;
};

class manager {
public:
    manager();

    void addTask(string n, string desc, int month, int day, string priority);
    void showTaskTable(int width, int margin);

    void deleteTask(int index);
    void editTask(int index);

    void markComplete(int index);
    void filterByPriority(string p);
    void filterByStatus(string s);

private:
    vector<schedule> tasks;
};

#endif
