#include <iostream>
#include <fstream>
using namespace std;
/*
    INPUT                      | OUTPUT
#TEST CASE 1: Base case to see if the function works properly
input.txt: 10 20 30 20 40 0    | output.txt: 10 30 40 0
cin: 20                        |

#TEST CASE 2: Delete multiple elements at the beginning of the list
input.txt: 5 5 10 15 0         | output.txt: 10 15 0
cin: 5                         |

#TEST CASE 3: What if we need to delete the entire list
input.txt: 7 7 7 0             | output.txt: 0
cin: 7                         |
*/
struct Node {
    int data;
    Node* next;
};
void deleteElementWithValueK(Node*& pHead, int k) {
    while (pHead != nullptr && pHead -> data == k) {
        Node* temp{pHead};
        pHead = pHead -> next;
        delete temp;
    }
    Node* pCurr = pHead;
    while (pCurr -> next != nullptr) {
        if (pCurr -> next -> data == k) {
            Node* temp = pCurr -> next;
            pCurr -> next = temp -> next;
            delete temp;
        }
        else {
            pCurr = pCurr -> next;
        } 
    }
}
int main() {
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        cerr << "Unable to open file input.txt";
        return 1;
    }
    int data{1};
    Node* pHead = nullptr;
    Node* pCurr = pHead;
    while (inFile >> data && data != 0) {
        if (pHead == nullptr) {
            pHead = new Node{data, nullptr};
            pCurr = pHead;
        }
        else {
            pCurr -> next = new Node{data, nullptr};
            pCurr = pCurr -> next;
        }
    }
    inFile.close();
    int x; cin >> x;
    deleteElementWithValueK(pHead, x);
    pCurr = pHead;
    ofstream outFile;
    outFile.open("output.txt");
    while (pCurr != nullptr) {
        outFile << pCurr -> data << ' ';
        pCurr = pCurr -> next;
    }
    outFile << 0;
    outFile.close();
    pCurr = pHead;
    while (pCurr != nullptr) {
        Node* temp = pCurr;
        pCurr = pCurr -> next;
        delete temp;
    }
    return 0;
}