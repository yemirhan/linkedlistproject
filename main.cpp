#include <iostream>
using namespace std;

#include "PersonList.h"
int main() {
    int selection;
    string filename;
    string name;
    int age;
    PersonList personList;
    while(true){
        cout << "1) Add a person" << endl;
        cout << "2) Remove a person" << endl;
        cout << "3) Update a person" << endl;
        cout << "4) Print people by age" << endl;
        cout << "5) Print people by name" << endl;
        cout << "6) Load people from file" << endl;
        cout << "7) Save people to a file by age" << endl;
        cout << "8) Save people to a file by name" << endl;
        cout << "9) Exit" << endl;
        cin >> selection;
        if (selection == 1){
            cout << "Enter a name and age:"<< endl;
            cin >> name >> age;
            personList.add(name,age);
        }
        else if (selection == 2){
            cout << "Enter a name to remove:"<< endl;
            cin >> name;
            if(personList.isInList(name) == 1){
                personList.remove(name);
                continue;
            }
            cout << "No one named " << name << " exists in the list"<<endl;
        }
        else if (selection == 3){
            cout << "Enter a name and age:"<< endl;
            cin >> name >> age;
            if(personList.isInList(name) == 1){
                personList.update(name, age);
                continue;
            }
            cout << "No one named " << name << " exists in the list"<<endl;
        }
        else if (selection == 4){
            personList.printByAge();
        }
        else if (selection == 5){
            personList.printByName();
        }
        else if (selection == 6){
            cout << "Enter a file name to load:" << endl;
            cin >> filename;
            personList.loadFile(filename);
        }
        else if (selection == 7){
            cout << "Enter a file name to save:" << endl;
            cin >> filename;
            personList.saveToFileByAge(filename);
        }
        else if (selection == 8) {
            cout << "Enter a file name to save:" << endl;
            cin >> filename;
            personList.saveToFileByName(filename);
        }
        else{
            break;
        }
    }

}