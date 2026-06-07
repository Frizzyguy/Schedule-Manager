#include "task.hpp"

int main() {
    TaskManager tm;
    int choice;

    do {
        cout << "\n===== TASK MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Mark Complete\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tm.addTask();
                break;
            case 2:
                tm.viewTasks();
                break;
            case 3:
                tm.deleteTask();
                break;
            case 4:
                tm.markComplete();
                break;
        }

    } while (choice != 0);

    return 0;
}
