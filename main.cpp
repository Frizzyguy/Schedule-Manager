#include <iostream>
#include "include/scheduleClass.hpp"
#include "include/functions.hpp"
using namespace std;

int consoleWidth = 160;
int main(){
    manager scheduleManager;
    
    printLine(consoleWidth);
    cout<<"\n";
    printCentered("SCHEDULE MANAGER", consoleWidth);

    scheduleManager.addTask("Dalumat","Pelikula",5,20);
    scheduleManager.addTask("Arts Apreciation","Pelikula",5,28);
    scheduleManager.addTask("Arts Apreciation","Pelikula",5,28);
    scheduleManager.addTask("Dalumat","Pelikula",5,20);

    scheduleManager.showTaskTable(consoleWidth, 2);
    while (true)
    {
        
    }
    
}