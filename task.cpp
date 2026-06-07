#include "task.hpp"

// DEFAULT TASK
Task::Task() {
    name = "";
    description = "";
    date = "";
    priority = "";
    status = "";
}

// PARAMETER TASK
Task::Task(string n, string d, int m, int day, string p) {
    name = n;
    description = d;
    date = to_string(m) + "/" + to_string(day);
    priority = p;
    status = "Pending";
}

// MANAGER INIT
TaskManager::TaskManager() {
    count = 0;
}

// ADD TASK
void TaskManager::addTask() {
    if (count >= MAX_TASKS) {
        cout << "Task limit reached!\n";
        return;
    }

    string name, desc, priority;
    int m, d;

    cin.ignore();

    cout << "Task name: ";
    getline(cin, name);

    cout << "Description: ";
    getline(cin, desc);

    cout << "Month: ";
    cin >> m;

    cout << "Day: ";
    cin >> d;

    cout << "Priority (Low/Medium/High): ";
    cin >> priority;

    tasks[count] = Task(name, desc, m, d, priority);
    count++;

    cout << "Task added!\n";
}

// VIEW TASKS
void TaskManager::viewTasks() {
    if (count == 0) {
        cout << "No tasks yet.\n";
        return;
    }

    cout << "\n===== TASK LIST =====\n";

    for (int i = 0; i < count; i++) {
        cout << i << " | "
             << tasks[i].name << " | "
             << tasks[i].description << " | "
             << tasks[i].date << " | "
             << tasks[i].priority << " | "
             << tasks[i].status << "\n";
    }
}

// DELETE TASK
void TaskManager::deleteTask() {
    int i;
    cout << "Enter index: ";
    cin >> i;

    if (i < 0 || i >= count) {
        cout << "Invalid index!\n";
        return;
    }

    for (int j = i; j < count - 1; j++) {
        tasks[j] = tasks[j + 1];
    }

    count--;
    cout << "Task deleted!\n";
}

// MARK COMPLETE
void TaskManager::markComplete() {
    int i;
    cout << "Enter index: ";
    cin >> i;

    if (i < 0 || i >= count) {
        cout << "Invalid index!\n";
        return;
    }

    tasks[i].status = "Completed";
    cout << "Task marked complete!\n";
}
