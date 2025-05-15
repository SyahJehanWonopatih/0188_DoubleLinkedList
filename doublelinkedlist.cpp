#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList {
private:
    Node *START;

public:
    DoubleLinkedList() {
        START = NULL;
    }

    void addnote() {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        Node *newNode = new Node(); //membuat memori untuk node baru

        newNode->noMhs = nim;   //menyimpan nim ke dalam node baru

    
        
    }
};