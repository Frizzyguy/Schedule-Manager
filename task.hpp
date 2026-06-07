#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
using namespace std;

const int MAX_TASKS = 100;

class Task {
public:
    string name;
    string description;
    string date;
    string priority;
    string status;

    Task();
    Task(string n, string d, int m, int day, string p);
};

class TaskManager {
private:
    Task tasks[MAX_TASKS];
    int count;

public:
    TaskManager();

    void addTask();
    void viewTasks();
    void deleteTask();
    void markComplete();
};

#endif
