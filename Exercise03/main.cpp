#include "function.h"
using namespace std;
#include "function.h"
using namespace std;
int main() {
    ifstream inFile;
    inFile.open("input.txt");
    Node* pHead = nullptr;
    readDataFromFile(pHead, inFile);
    Node *pCurr1 = pHead, *pCurr2 = pHead;

    ofstream outFile;
    outFile.open("output.txt");
    displayList(pHead, outFile);
    deleteAll(pHead);
    return 0;
}