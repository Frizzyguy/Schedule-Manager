#include "functions.hpp"
#include <iostream>
using namespace std;

int main() {
    Manager m;
    int choice;

    do {
        cout << "\n===== TASK MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Edit Task\n";
        cout << "5. Mark Completed\n";
        cout << "6. Filter by Priority\n";
        cout << "7. Filter by Status\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: m.addTask(); break;
            case 2: m.viewTasks(); break;
            case 3: m.deleteTask(); break;
            case 4: m.editTask(); break;
            case 5: m.markComplete(); break;
            case 6: m.filterPriority(); break;
            case 7: m.filterStatus(); break;
        }

    } while (choice != 0);

    return 0;
}
