#include <iostream>
#include "functions.hpp"
using namespace std;



void printCentered(string text, int width){
    int padding = (width - text.length())/2;

    if (padding > 0){
        string paddingText = "";
        while (padding)
        {
            padding--;
            paddingText += " ";
        }
        
        cout<< paddingText << text << "\n";
    }
    else {
        cout<< text << "\n";
    }
}

void printLine(int width){
    string line = "";
    for (int i = 0; i < width; i++){
        line += "-";
    }
    line += "\n";
    cout<< line;
}