#include "task.hpp"

int main() {
    TaskManager tm;
    int choice;

    tm.loadFromFile();

    do {
        cout << "\n===== TASK MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Mark Complete\n";
        cout << "5. Search Task\n";
        cout << "6. Sort by Priority\n";
        cout << "7. Sort by Date\n";
        cout << "8. Save Tasks\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: tm.addTask(); break;
            case 2: tm.viewTasks(); break;
            case 3: tm.deleteTask(); break;
            case 4: tm.markComplete(); break;
            case 5: tm.searchTask(); break;
            case 6: tm.sortByPriority(); break;
            case 7: tm.sortByDate(); break;
            case 8: tm.saveToFile(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid!\n";
        }

    } while (choice != 0);

    return 0;
}
