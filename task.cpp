#include "task.hpp"
#include <fstream>
#include <limits>
#include <algorithm>

// DEFAULT
Task::Task() {
    name = "";
    description = "";
    date = "";
    priority = "";
    status = "";
}

// PARAMETER
Task::Task(string n, string d, int m, int day, string p) {
    name = n;
    description = d;
    date = to_string(m) + "/" + to_string(day);
    priority = p;
    status = "Pending";
}

// INIT
TaskManager::TaskManager() {
    count = 0;
}

// ADD
void TaskManager::addTask() {
    if (count >= MAX_TASKS) {
        cout << "Task limit reached!\n";
        return;
    }

    string name, desc, priority;
    int m, d;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

// VIEW
void TaskManager::viewTasks() {
    if (count == 0) {
        cout << "No tasks yet.\n";
        return;
    }

    cout << "\n===== TASK LIST =====\n";

    for (int i = 0; i < count; i++) {
        cout << i+1 << " | "
             << tasks[i].name << " | "
             << tasks[i].description << " | "
             << tasks[i].date << " | "
             << tasks[i].priority << " | "
             << tasks[i].status << "\n";
    }
}

// DELETE
void TaskManager::deleteTask() {
    int i;
    cout << "Enter task number: ";
    cin >> i;
    i--;

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

// COMPLETE
void TaskManager::markComplete() {
    int i;
    cout << "Enter task number: ";
    cin >> i;
    i--;

    if (i < 0 || i >= count) {
        cout << "Invalid index!\n";
        return;
    }

    tasks[i].status = "Completed";
    cout << "Task marked complete!\n";
}

// 🔍 SEARCH
void TaskManager::searchTask() {
    string keyword;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter keyword: ";
    getline(cin, keyword);

    bool found = false;

    for (int i = 0; i < count; i++) {
        if (tasks[i].name.find(keyword) != string::npos) {
            cout << i+1 << " | " << tasks[i].name << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No matching tasks found.\n";
    }
}

// 📊 PRIORITY VALUE HELPER
int getPriorityValue(string p) {
    if (p == "High") return 3;
    if (p == "Medium") return 2;
    return 1;
}

// 📊 SORT BY PRIORITY
void TaskManager::sortByPriority() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (getPriorityValue(tasks[j].priority) < getPriorityValue(tasks[j+1].priority)) {
                swap(tasks[j], tasks[j+1]);
            }
        }
    }
    cout << "Sorted by priority!\n";
}

// 📊 SORT BY DATE
void TaskManager::sortByDate() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (tasks[j].date > tasks[j+1].date) {
                swap(tasks[j], tasks[j+1]);
            }
        }
    }
    cout << "Sorted by date!\n";
}

// 💾 SAVE
void TaskManager::saveToFile() {
    ofstream file("tasks.txt");

    for (int i = 0; i < count; i++) {
        file << tasks[i].name << "|"
             << tasks[i].description << "|"
             << tasks[i].date << "|"
             << tasks[i].priority << "|"
             << tasks[i].status << "\n";
    }

    file.close();
    cout << "Saved to file!\n";
}

// 📂 LOAD
void TaskManager::loadFromFile() {
    ifstream file("tasks.txt");

    if (!file) {
        return; // no file yet
    }

    count = 0;

    while (count < MAX_TASKS) {
        getline(file, tasks[count].name, '|');
        if (file.eof()) break;

        getline(file, tasks[count].description, '|');
        getline(file, tasks[count].date, '|');
        getline(file, tasks[count].priority, '|');
        getline(file, tasks[count].status);

        count++;
    }

    file.close();
    cout << "Loaded from file!\n";
}
