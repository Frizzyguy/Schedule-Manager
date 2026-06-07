#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include "scheduleClass.hpp"

class Manager {
public:
    void addTask();
    void viewTasks();
    void deleteTask();
    void editTask();
    void markComplete();
    void filterPriority();
    void filterStatus();

private:
    vector<Task> tasks;
};

#endif
