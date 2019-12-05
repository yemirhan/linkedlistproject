//************************  intSLList.cpp  **************************

#include <iostream>
#include <fstream>
#include "IntSLList.h"

using namespace std;

IntSLList::~IntSLList() {
    for (PersonNode *p; !isEmpty(); ) {
        p = headname->nextname;
        delete headname;
        headname = p;
        p = headage->nextage;
        delete headage;
        headage = p;
    }
}
void IntSLList::add(string el, int el2)  {
    if (tailname || tailage != 0) {      // if list not empty;
        tailname->nextname = new PersonNode(el, el2);
        tailage->nextage = new PersonNode(el, el2);
        tailname = tailname->nextname;
        tailage = tailage -> nextage;
    }
    else {
        headage = tailage = new PersonNode(el,el2);
        headname = tailname = new PersonNode(el,el2);
    }
}

void IntSLList::remove(string el) {
    if (headage || headname != 0)                     // if non-empty list;
        if (headname == tailname && el == headname->name) { // if only one
            delete headname,headage;// node on the list;
            headage = tailage = 0;
            headname = tailname = 0;
        }
        else if (el == headname->name) {  // if more than one node on the list
            PersonNode *tmp = headname, *tmp2 = headage;
            headname = headname->nextname;
            headage = headage->nextage;
            delete tmp,tmp2;// and old head is deleted;
        }
        /*else {                        // if more than one node in the list
            PersonNode *pred, *tmp;
            for (pred = head, tmp = head->node; // and a non-head node
                 tmp != 0 && !(tmp->name == el);// is deleted;
                 pred = pred->node, tmp = tmp->node);
            if (tmp != 0) {
                pred->node = tmp->node;
                if (tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }*/
}

bool IntSLList::isInList(string el) const {
    PersonNode *tmp;
    for (tmp = headname; tmp != 0 && !(tmp->name == el); tmp = tmp->nextname);
    return tmp != 0;
}

void IntSLList::printByAge() const {
    for (PersonNode *tmp = headage; tmp != 0; tmp = tmp->nextage)
        cout << tmp->name << " " << tmp->age << endl;
    cout << endl;
}
void IntSLList::printByName() const {
    for (PersonNode *tmp = headname; tmp != 0; tmp = tmp->nextname)
        cout << tmp->name << " " << tmp->age << endl;
    cout << endl;
}
void IntSLList::saveToFileByName(string filename) const{
    ofstream MyFile(filename);
    for (PersonNode *tmp = headname; tmp != 0; tmp = tmp->nextname){
        MyFile << tmp->name << " " << tmp->age << endl;
        MyFile << endl;
    }
    MyFile.close();
}

void IntSLList::saveToFileByAge(string filename) const {
    ofstream MyFile(filename);
    for (PersonNode *tmp = headage; tmp != 0; tmp = tmp->nextage){
        MyFile << tmp->name << " " << tmp->age << endl;
        MyFile << endl;
    }
    MyFile.close();
}
void IntSLList::loadFile(string filename) const {
    string line;
    string name;
    int age,i;
    ifstream ReadFile(filename);
    while (getline(ReadFile, line)){
        if(line != ""){
            for (i = 0; i < line.size(); ++i);
            name = line.substr(0, i);
            age = stoi(line.substr(i, line.size()-i));
            cout << name << " " << age << endl;
        }
    }
}