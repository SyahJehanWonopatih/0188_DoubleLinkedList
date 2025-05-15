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

        if(START == NULL || nim <= START->noMhs) {  //memasukkan node baru di awal jika list kosong atau nim lebih kecil dari nim di node pertama
            if (START != NULL && nim == START->noMhs) {
                cout << "\nDuplicate number not allowed!" << endl;
                return;
            }
            newNode->next = START;  //node baru menunjuk ke node pertama

            if (START != NULL)  //jika list tidak kosong maka node pertama menunjuk ke node baru
                START->prev = newNode;  

            newNode->prev = NULL;  //node baru tidak memiliki node sebelumnya
            START = newNode; 
            return; 
        }
        Node *current = START;  
        while (current->next != NULL && nim == current->next->noMhs) {     
            cout << "\nDuplicate roll numbers not allowed!" << endl;
            return;
        }
        newNode->next = current->next;  
        newNode->prev = current;  

        if(current->next != NULL)   
            current->next->prev = newNode;  
        current->next = newNode;   
    }
    
    
};




int main() {

}