#include "function.h"

void readDataFromFile(Node*& pHead, std::ifstream& inFile) {
    if (!inFile) {
        std::cerr << "Unable to open file ";
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
void displayList(Node* pHead, std::ofstream& outFile) {
    Node* pCurr = pHead;
    while (pCurr != nullptr) {
        outFile << pCurr -> data << ' ';
        pCurr = pCurr -> next;
    }
    outFile << 0 << '\n';
    outFile.close();
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
void deleteAll(Node*& pCurr) {
    while (pCurr != nullptr) {
        Node* temp = pCurr;
        pCurr = pCurr -> next;
        delete temp;
    }
}