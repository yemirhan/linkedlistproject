#include <iostream>
using namespace std;

#include "IntSLList.h"
/*void loadfile(string filename){
    personList.add()
}*/
int main() {
    int selection;
    string filename;
    string name;
    int age;
    IntSLList personList;
    //cout << "Enter file name to load from" << endl;
    //cin >> filename;
    //loadfile(filename);
    while(true){
        cout << "1) Add a person" << endl;
        cout << "2) Remove a person" << endl;
        cout << "3) Print people by age" << endl;
        cout << "4) Print people by name" << endl;
        cout << "7) Load people from file" << endl;
        cout << "5) Save people to a file by age" << endl;
        cout << "6) Save people to a file by name" << endl;
        cout << "7) Exit" << endl;
        cin >> selection;
        if (selection == 1){
            cout << "Enter a name and age:"<< endl;
            cin >> name >> age;
            personList.add(name,age);
        }
        else if (selection == 2){
            cout << "Enter a name to remove:"<< endl;
            cin >> name;
            personList.remove(name);
        }
        else if (selection == 3){
            personList.printByAge();
        }
        else if (selection == 4){
            personList.printByName();
        }
        else if (selection == 5){
            cout << "Enter a file name to save:" << endl;
            cin >> filename;
            personList.saveToFileByAge(filename);
        }
        else if (selection == 6){
            cout << "Enter a file name to save:" << endl;
            cin >> filename;
            personList.saveToFileByName(filename);
        }
        else if (selection == 7){
            cout << "Enter a file name to load:" << endl;
            cin >> filename;
            personList.loadFile(filename);
        }
        else{
            break;
        }
    }

}