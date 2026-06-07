#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    string name;
    string description;
    string date;
    string priority;
    string status;

    Task(string n, string d, int month, int day, string p);
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask();
    void viewTasks();
    void deleteTask();
    void markComplete();
};

#endif
