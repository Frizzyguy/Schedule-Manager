#include "scheduleClass.hpp"

// constructor
schedule::schedule(string n, string desc, int month, int day, string p){
    name = n;
    description = desc;
    date = to_string(month) + "/" + to_string(day);
    priority = p;
    status = "Pending";
}

// manager constructor
manager::manager(){}

// add task
void manager::addTask(string n, string desc, int month, int day, string priority){
    tasks.push_back(schedule(n, desc, month, day, priority));
}

// display tasks
void manager::showTaskTable(int width, int margin){
    cout << "\n===== TASK LIST =====\n";
    cout << "Index | Name | Description | Deadline | Priority | Status\n";

    for (int i = 0; i < tasks.size(); i++){
        cout << i << " | "
             << tasks[i].name << " | "
             << tasks[i].description << " | "
             << tasks[i].date << " | "
             << tasks[i].priority << " | "
             << tasks[i].status << "\n";
    }
}

// delete
void manager::deleteTask(int index){
    if (index >= 0 && index < tasks.size()){
        tasks.erase(tasks.begin() + index);
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

// edit
void manager::editTask(int index){
    if (index >= 0 && index < tasks.size()){
        cin.ignore();

        cout << "New name: ";
        getline(cin, tasks[index].name);

        cout << "New description: ";
        getline(cin, tasks[index].description);

        int m, d;
        cout << "New month & day: ";
        cin >> m >> d;
        tasks[index].date = to_string(m) + "/" + to_string(d);

        cout << "New priority (Low/Medium/High): ";
        cin >> tasks[index].priority;

        cout << "Task updated!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

// mark complete
void manager::markComplete(int index){
    if (index >= 0 && index < tasks.size()){
        tasks[index].status = "Completed";
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

// filter priority
void manager::filterByPriority(string p){
    cout << "\nFiltered by Priority: " << p << "\n";

    for (int i = 0; i < tasks.size(); i++){
        if (tasks[i].priority == p){
            cout << i << " | "
                 << tasks[i].name << " | "
                 << tasks[i].description << " | "
                 << tasks[i].date << " | "
                 << tasks[i].priority << " | "
                 << tasks[i].status << "\n";
        }
    }
}

// filter status
void manager::filterByStatus(string s){
    cout << "\nFiltered by Status: " << s << "\n";

    for (int i = 0; i < tasks.size(); i++){
        if (tasks[i].status == s){
            cout << i << " | "
                 << tasks[i].name << " | "
                 << tasks[i].description << " | "
                 << tasks[i].date << " | "
                 << tasks[i].priority << " | "
                 << tasks[i].status << "\n";
        }
    }
}
