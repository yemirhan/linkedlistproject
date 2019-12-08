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

void IntSLList::add(string el, int el2)
{
    PersonNode * temp = new PersonNode(el,el2);
    temp->nextname = 0;
    temp->nextage = 0;
    if (headage && headname == 0)
    {
        headage = temp;
        headname = temp;
    }
    else
    {
        PersonNode * theadname = headname;
        PersonNode * theadage = headage;
        PersonNode * previous = 0;
        //Append for age
        while (theadage != 0 && el2 > theadage->age)
        {
            previous = theadage;
            theadage = theadage->nextage;
        }
        if (previous == 0)
        {
            headage = temp;
            temp->nextage = theadage;
        }
        else if (theadage == 0)
        {
            previous->nextage = temp;
        }
        else
        {
            previous->nextage = temp;
            temp->nextage = theadage;
        }
        //Append for name
        previous= 0;
        while (theadname != 0 && el > theadname->name)
        {
            previous = theadname;
            theadname = theadname->nextname;
        }
        if (previous == 0)
        {
            headname = temp;
            temp->nextname = theadname;
        }
        else if (theadname == 0)
        {
            previous->nextname = temp;
        }
        else
        {
            previous->nextname = temp;
            temp->nextname = theadname;
        }
    }

}

void IntSLList::remove(string el) {
    /*if (headage || headname != 0)                     // if non-empty list;
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
        else {                        // if more than one node in the list
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
    PersonNode temp;
    int age,i;
    ifstream ReadFile(filename);
    while (getline(ReadFile, line)){
        if(line != ""){
            i = line.find(" ");
            name = line.substr(0, i);
            age = stoi(line.substr(i, line.size()-i));
            //personList.add(name,age);
        }
    }
}