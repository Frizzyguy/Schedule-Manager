#include "functions.hpp"
#include <iostream>
using namespace std;

// Add Task
void Manager::addTask() {
    string name, desc, priority;
    int m, d;

    cin.ignore();
    cout << "Task Name: ";
    getline(cin, name);

    cout << "Description: ";
    getline(cin, desc);

    cout << "Month and Day: ";
    cin >> m >> d;

    cout << "Priority (Low/Medium/High): ";
    cin >> priority;

    tasks.push_back(Task(name, desc, m, d, priority));
    cout << "Task added!\n";
}

// View Tasks
void Manager::viewTasks() {
    cout << "\n===== TASK LIST =====\n";
    cout << "Index | Name | Description | Date | Priority | Status\n";

    for (int i = 0; i < tasks.size(); i++) {
        cout << i << " | "
             << tasks[i].name << " | "
             << tasks[i].description << " | "
             << tasks[i].date << " | "
             << tasks[i].priority << " | "
             << tasks[i].status << "\n";
    }
}

// Delete Task
void Manager::deleteTask() {
    int i;
    cout << "Enter index: ";
    cin >> i;

    if (i >= 0 && i < tasks.size()) {
        tasks.erase(tasks.begin() + i);
        cout << "Deleted!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

// Edit Task
void Manager::editTask() {
    int i;
    cout << "Enter index: ";
    cin >> i;

    if (i >= 0 && i < tasks.size()) {
        cin.ignore();

        cout << "New name: ";
        getline(cin, tasks[i].name);

        cout << "New description: ";
        getline(cin, tasks[i].description);

        int m, d;
        cout << "New date: ";
        cin >> m >> d;
        tasks[i].date = to_string(m) + "/" + to_string(d);

        cout << "New priority: ";
        cin >> tasks[i].priority;

        cout << "Updated!\n";
    }
}

// Mark Complete
void Manager::markComplete() {
    int i;
    cout << "Enter index: ";
    cin >> i;

    if (i >= 0 && i < tasks.size()) {
        tasks[i].status = "Completed";
        cout << "Done!\n";
    }
}

// Filter Priority
void Manager::filterPriority() {
    string p;
    cout << "Enter priority: ";
    cin >> p;

    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].priority == p) {
            cout << i << " | " << tasks[i].name << "\n";
        }
    }
}

// Filter Status
void Manager::filterStatus() {
    string s;
    cout << "Enter status: ";
    cin >> s;

    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].status == s) {
            cout << i << " | " << tasks[i].name << "\n";
        }
    }
}
