#include <iostream>
using namespace std;

// Struktur node tree
struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

// Membuat node baru
Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->kiri = NULL;
    baru->kanan = NULL;
    return baru;
}

// Menyisipkan node ke tree (rekursif)
Node* sisip(Node* root, int nilai) {
    if (root == NULL) {              // posisi kosong: jadikan node baru
        return buatNode(nilai);
    }
    if (nilai < root->data) {        // lebih kecil dari parent: ke kiri
        root->kiri = sisip(root->kiri, nilai);
    } else if (nilai > root->data) { // lebih besar dari parent: ke kanan
        root->kanan = sisip(root->kanan, nilai);
    } else {
        cout << "Angka " << nilai << " sudah ada, diabaikan." << endl;
    }
    return root;
}


// Post-order: kiri -> kanan -> root
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->kiri);
    postOrder(root->kanan);
    cout << root->data << " ";
}

void Terbesar(Node* root) {
    if (root == NULL) return;
    Terbesar(root->kiri);
    Terbesar(root->kanan);
    if(root->kiri >= root->kanan){
        cout << Terbesar;
    }
    else {
        cout << Terbesar;
    }
}

void akar(Node* root) {
    if (root == NULL) return;
    akar(root->kanan);
    cout << root->data << " ";
}

// Membebaskan memori tree
void hapusTree(Node* root) {
    if (root == NULL) return;
    hapusTree(root->kiri);
    hapusTree(root->kanan);
    delete root;
}

int main() {
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (0 untuk berhenti)" << endl;
    while (true) {
        cout << "Angka: ";
        cin >> angka;
        if (angka == 0) break;       // berhenti saat input 0
        root = sisip(root, angka);   // angka pertama otomatis jadi root
    }

    if (root == NULL) {
        cout << "Tree kosong." << endl;
        return 0;
    }
    cout << "\nPost-order : ";
    postOrder(root);
    cout << "\nNilai Terbesar : ";
    Terbesar(root);
    cout << "\nRoot : ";
    akar(root);        
    cout << endl;

    

    hapusTree(root);
    return 0;
}