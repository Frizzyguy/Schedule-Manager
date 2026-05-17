#pragma once
#include <vector>
#include <iostream>
using namespace std;

class schedule {
    public:
        schedule(string n, string desc, int month, int day);

        string name;
        string description;
        string date;
};

class manager {
    public:
        manager();
        void addTask(string n, string desc, int month, int day);
        void showTaskTable(int width, int margin);
    private:
        vector<schedule> tasks;
};