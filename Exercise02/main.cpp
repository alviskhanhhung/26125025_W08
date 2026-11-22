#include <iostream>
#include <fstream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void readDataFromFile(Node*& pHead, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Unable to open file " << filename;
        return;
    }
    int data;
    Node* pCurr = nullptr;
    while (inFile >> data && data != 0) {
        if (pHead == nullptr) {
            pHead = new Node{data, nullptr};
            pCurr = pHead;
        } else {
            pCurr->next = new Node{data, nullptr};
            pCurr = pCurr->next;
        }
    }
    inFile.close();
}
void deleteElementWithValueK(Node*& pHead, int k) {
    while (pHead != nullptr && pHead->data == k) {
        Node* temp{pHead};
        pHead = pHead->next;
        delete temp;
    }
    Node* pCurr = pHead;
    while (pCurr != nullptr && pCurr->next != nullptr) {
        if (pCurr->next->data == k) {
            Node* temp = pCurr->next;
            pCurr->next = temp->next;
            delete temp;
        } else {
            pCurr = pCurr->next;
        }
    }
}
void displayList(Node* pHead, const string& filename) {
    Node* pCurr = pHead;
    ofstream outFile(filename);
    while (pCurr != nullptr) {
        outFile << pCurr -> data << ' ';
        pCurr = pCurr -> next;
    }
    outFile << 0 << endl;
    outFile.close();
}
int main() {
    int data{1};
    Node* pHead = nullptr;
    readDataFromFile(pHead, "input.txt");
    Node* pCurr = pHead;
    while (pCurr -> next != nullptr) {
        deleteElementWithValueK(pCurr->next, pCurr->data);
        pCurr = pCurr -> next;
    }
    displayList(pHead, "output.txt");
    pCurr = pHead;
    while (pCurr != nullptr) {
        Node* temp = pCurr;
        pCurr = pCurr -> next;
        delete temp;
    }
    return 0;
}