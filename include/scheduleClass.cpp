#include "scheduleClass.hpp"

Task::Task(string n, string d, int m, int day, string p) {
    name = n;
    description = d;
    date = to_string(m) + "/" + to_string(day);
    priority = p;
    status = "Pending";
}
