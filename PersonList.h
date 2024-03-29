//************************  PersonList.h  **************************
//           singly-linked list class to store name and ages

#ifndef LINKED_LIST
#define LINKED_LIST
using namespace std;
class PersonNode {
public:
    int age;
    string name;
    PersonNode *nextname; //name
    PersonNode *nextage; //age

    PersonNode() {
        nextage = nextname = 0;
    }
    PersonNode(string el, int el2, PersonNode *ptr = 0,PersonNode *ptr2 = 0) {
        name = el;
        age = el2;
        nextname = ptr;
        nextage = ptr2;
    }

};


class PersonList {
public:
    PersonList() {
        headage = tailage = 0;
        headname = tailname = 0;
    }
    ~PersonList();
    int isEmpty() {
        return headage == 0;
    }
    void add(string, int);
    void remove(string);
    void update(string, int);
    bool isInList(string) const;
    void printByAge() const;
    void printByName() const;
    void saveToFileByAge(string) const;
    void saveToFileByName(string) const;
    void loadFile(string);
private:
    PersonNode *headage, *tailage;
    PersonNode *headname, *tailname;
};

#endif
