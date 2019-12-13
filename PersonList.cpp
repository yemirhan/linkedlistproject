//************************  PersonList.cpp  **************************

#include <iostream>
#include <fstream>
#include "PersonList.h"

using namespace std;

PersonList::~PersonList() {
    for (PersonNode *p; !isEmpty(); ) {
        p = headname->nextname;
        delete headname;
        headname = p;
        p = headage->nextage;
        delete headage;
        headage = p;
    }
}

void PersonList::add(string el, int el2)
{
    PersonNode * temp = new PersonNode(el,el2);
    temp->nextname = 0;
    temp->nextage = 0;
    if (headage && headname == 0)
    {
        headage = tailage = temp;
        headname = tailname = temp;
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
            tailage = temp;
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
            tailname = temp;
        }
        else
        {
            previous->nextname = temp;
            temp->nextname = theadname;
        }
    }

}

void PersonList::remove(string el) {
    PersonNode * theadname = headname;
    PersonNode * theadage = headage;
    PersonNode * previous = 0;
    PersonNode * tempnext = 0;
    int el2;
    while (theadname->name != el && theadname != 0)
    {
        previous = theadname;
        theadname = theadname->nextname;
        el2 = theadname->age;
    }
    if (previous == 0)
    {
        headname = headname ->nextname;
    }
    else
    {
        tempnext = theadname->nextname;
        previous->nextname = tempnext;
    }
    previous=0;
    while (theadage->age != el2 && theadage != 0)
    {
        previous = theadage;
        theadage = theadage->nextage;
    }
    PersonNode * tempnext2 = 0;
    if (previous == 0)
    {
        headage = headage->nextage;
    }
    else
    {
        tempnext2 = theadage->nextage;
        previous->nextage = tempnext2;
    }
}
void PersonList::update(string el, int el2) {
    remove(el);
    add(el,el2);
}

bool PersonList::isInList(string el) const {
    PersonNode *tmp;
    for (tmp = headname; tmp != 0 && !(tmp->name == el); tmp = tmp->nextname);
    return tmp != 0;
}

void PersonList::printByAge() const {
    for (PersonNode *tmp = headage; tmp != 0; tmp = tmp->nextage)
        cout << tmp->name << " " << tmp->age << endl;
    cout << endl;
}
void PersonList::printByName() const {
    for (PersonNode *tmp = headname; tmp != 0; tmp = tmp->nextname)
        cout << tmp->name << " " << tmp->age << endl;
    cout << endl;
}
void PersonList::saveToFileByName(string filename) const{
    ofstream MyFile(filename);
    for (PersonNode *tmp = headname; tmp != 0; tmp = tmp->nextname)
        MyFile << tmp->name << " " << tmp->age << endl;
    MyFile.close();
}

void PersonList::saveToFileByAge(string filename) const {
    ofstream MyFile(filename);
    for (PersonNode *tmp = headage; tmp != 0; tmp = tmp->nextage)
        MyFile << tmp->name << " " << tmp->age << endl;
    MyFile.close();
}
void PersonList::loadFile(string filename) {
    string line;
    string name;
    int age,i;
    ifstream ReadFile(filename);
    while (getline(ReadFile, line)){
        if(line != ""){
            i = line.find(" ");
            name = line.substr(0, i);
            age = stoi(line.substr(i+1, line.size()-i));
            add(name,age);
        }
    }
}