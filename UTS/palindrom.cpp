#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(NULL) {}

    bool isEmpty() { return top == NULL; }

    void push(char c) {
        Node* baru = new Node;
        baru->data = c;
        baru->next = top;
        top = baru;
    }

    char pop() {
        if (isEmpty()) return '\0';
        Node* hapus = top;
        char c = hapus->data;
        top = top->next;
        delete hapus;
        return c;
    }

    ~Stack() {
        while (!isEmpty()) pop();
    }
};

bool cekPalindrom(const string& kata) {
    Stack s;
    string bersih = "";

    // abaikan spasi/tanda baca dan huruf besar-kecil
    for (size_t i = 0; i < kata.length(); i++) {
        if (isalnum((unsigned char)kata[i])) {
            bersih += tolower((unsigned char)kata[i]);
        }
    }

    // push semua karakter ke stack
    for (size_t i = 0; i < bersih.length(); i++) {
        s.push(bersih[i]);
    }

    // Pop (urutan terbalik) lalu bandingkan dengan aslinya
    for (size_t i = 0; i < bersih.length(); i++) {
        if (s.pop() != bersih[i]) return false;
    }
    return true;
}

int main() {
    string kata;
    cout << "Masukkan kata/kalimat: ";
    getline(cin, kata);

    if (cekPalindrom(kata))
        cout << "\"" << kata << "\" adalah PALINDROM" << endl;
    else
        cout << "\"" << kata << "\" BUKAN palindrom" << endl;

    return 0;
}