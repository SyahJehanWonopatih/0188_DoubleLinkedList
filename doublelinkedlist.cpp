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
    
    void hapus() {  //membuat fungsi untuk menghapus Node
        if(START == NULL) { //jika list kosong maka tidak bisa dihapus
            cout << "\nList is empty!" << endl;
            return;
        }
        cout << "\nEnter the roll number of the student whose record to be deleted: "; //meminta nim yang akan dihapus
        int rollno;
        cin >> rollno;

        Node *current = START;

        while(current != NULL && current->noMhs != rollno) //membuat pointer untuk mencari Node yang akan dihapus
            current = current->next;

        if (current == NULL) {  //jika tidak ditemukan maka akan menampillkan pesan record not found!
            cout << "Record not found!" << endl;
            return;
        }
        if(current == START) {      //jika node yang akan dihapus adalah node pertama maka node pertama akan menunjuk ke node kedua 
            START = current->next;
            if(START != NULL) 
                START->prev = NULL;
        }
        else {  //jika node yang akan dihapus bukan node pertama maka node sebelumnya akan menunjuk ke node selanjutnya
            current->prev->next = current->next;

            if(current->next != NULL)
                current->next->prev = current->prev;
        }
        delete current; //menghapus node yang sudah tidak digunakan lagi
        cout << "\nRecord with roll number " << rollno << " deleted!" << endl;
    }

    void traverse() {
        if(START == NULL) {
            cout << "\nList is empty!" << endl;
            return;
        }
        Node *currentNode = START;

        cout << "\nRecords in ascending order of roll number are:\n ";
        int i = 0;
        while(currentNode != NULL) {    //membuat fungsi agar data dari awal sampai akhir ditampilkan
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;
            currentNode = currentNode->next;
            i++; 
        }
    }

    void revtraverse() {    //membuat fungsi revtraverse 
        if(START == NULL) { 
            cout << "\nList is empty!" << endl;
            return;
        }
        Node *currentNode = START;
        int i = 0;
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
            i++;
        }
        cout << "\nRecords in decending order of roll number are:\n";
        while(currentNode != NULL) {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            currentNode = currentNode->prev;
            i++;
        }
    }

    void rearchData() { //membuat fungsi untuk mencari data
        if(START == NULL) { 
            cout << "\nList is empty!" << endl;
            return;
        }

        int rollno;
        cout << "\nEnter roll number to search: ";
        cin >> rollno;
        Node *current = START;

        while(current != NULL && current->noMhs != rollno) {    
            current = current->next;
        }

        if(current == NULL) {   //jika tidak ditemukan maka akan menampillkan pesan record not found!
            cout << "\nRecord not found!" << endl;
            return;
        }
        else {
            cout << "Record found!\n";
            cout << "Roll number: " << current->noMhs << endl;
        }
    }
};




int main() {    //membuat fungsi main agar program dapat berjalan
    DoubleLinkedList list;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add record\n";
        cout << "2. Delete record\n";
        cout << "3. view adcending\n";
        cout << "4. view decending\n";
        cout << "5. Search record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                list.addnote();
                break;
            case '2':
                list.hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':  
                list.revtraverse();
                break;
            case '5':
                list.rearchData();
                break;
            case '6':
                return 0;
            default:
                cout << "\nInvalid option!\n";
        }
        cout << "\nPress any key to continue...\n";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    } while (choice != '6');
}