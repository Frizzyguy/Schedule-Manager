#include "scheduleClass.hpp"
#include "functions.hpp"
#include <vector>
#include <iostream>
using namespace std;


#pragma region //schedule function definition
schedule::schedule(string n, string desc, int month, int day){
            name = n;
            description = desc;
            date = to_string(month) + "/" + to_string(day);
}
#pragma endregion


#pragma region //manager function definition
manager::manager(){}
void manager::addTask(string n, string desc, int month, int day){
    int textSize = tasks.size();
    tasks.resize(textSize + 1, schedule(n,desc,month,day));
}


void manager::showTaskTable(int width, int margin){
    int numberSection = 3;
    string sectionText[numberSection] = {"Task Name","Description","Deadline"};

    int sectionTextCharacterTotal = 0;
    for (int i = 0; i < numberSection; i++){
        sectionTextCharacterTotal += sectionText[i].size();
    }

    cout<<"\n";
    printLine(width);
    cout<<"\n";
    printCentered("TASK TABLE",width);
    cout<<"\n";
    printLine(width);
    
    
    int sectionWidth = (width % numberSection == 0) ? width/numberSection : (width/numberSection) + 1;
    for (int i = 0; i < numberSection; i++){
        int sectionPadding = ((sectionWidth - sectionText[i].size())/2);
        string offsetPadding = ((sectionWidth - sectionText[i].size()) % 2) ? " " : ""; 
        string padding = "";
        while (sectionPadding - 1 != 0)
        {
            sectionPadding--;
            padding += " ";
        }
        
        string sectionBreak = " ";
        if (i + 1 != numberSection){
            sectionBreak = "|";
        }
        cout<< padding << sectionText[i] << padding << offsetPadding << sectionBreak;
    }

    cout<<"\n";
    printLine(width);

    int numOfTask = tasks.size();
    for (int i = 0; i < numOfTask; i++){
        string taskText[numberSection] = {};
        taskText[0] = tasks[i].name;
        taskText[1] = tasks[i].description;
        taskText[2] = tasks[i].date;
        
        for (int j = 0; j < numberSection; j++){
            int sectionPadding = (sectionWidth - taskText[j].size())/2;
            string offsetPadding = ((sectionWidth - taskText[j].size()) % 2) ? " " : "";

            string padding = "";
            while (sectionPadding - 1 != 0){
                sectionPadding--;
                padding += " ";
            }

            string sectionBreak = " ";
            if (j + 1 != numberSection){
                sectionBreak = "|";
            }
            cout<< padding << taskText[j] << padding << offsetPadding << sectionBreak;
        }

        cout<<"\n";
    }
}

#pragma endregion
