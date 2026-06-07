#include "scheduleClass.hpp"
#include <iostream>
using namespace std;

int main(){
    manager m;
    int choice;

    do {
        cout << "\n===== TASK MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Edit Task\n";
        cout << "5. Mark as Completed\n";
        cout << "6. Filter by Priority\n";
        cout << "7. Filter by Status\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1){
            string name, desc, priority;
            int month, day;

            cin.ignore();
            cout << "Task name: ";
            getline(cin, name);

            cout << "Description: ";
            getline(cin, desc);

            cout << "Month and Day: ";
            cin >> month >> day;

            cout << "Priority (Low/Medium/High): ";
            cin >> priority;

            m.addTask(name, desc, month, day, priority);
        }

        else if (choice == 2){
            m.showTaskTable(80, 5);
        }

        else if (choice == 3){
            int i;
            cout << "Index to delete: ";
            cin >> i;
            m.deleteTask(i);
        }

        else if (choice == 4){
            int i;
            cout << "Index to edit: ";
            cin >> i;
            m.editTask(i);
        }

        else if (choice == 5){
            int i;
            cout << "Index to mark complete: ";
            cin >> i;
            m.markComplete(i);
        }

        else if (choice == 6){
            string p;
            cout << "Enter priority: ";
            cin >> p;
            m.filterByPriority(p);
        }

        else if (choice == 7){
            string s;
            cout << "Enter status: ";
            cin >> s;
            m.filterByStatus(s);
        }

    } while (choice != 0);

    return 0;
}
