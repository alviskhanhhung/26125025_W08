#include "function.h"
using namespace std;
int main() {
    ifstream inFile;
    inFile.open("input.txt");
    Node* pHead = nullptr;
    readDataFromFile(pHead, inFile);
    Node* pCurr = pHead;
    while (pCurr -> next != nullptr) {
        deleteElementWithValueK(pCurr->next, pCurr->data);
        pCurr = pCurr -> next;
    }
    ofstream outFile;
    outFile.open("output.txt");
    displayList(pHead, outFile);
    pCurr = pHead;
    deleteAll(pHead);
    return 0;
}