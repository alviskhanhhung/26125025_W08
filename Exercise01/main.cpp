#include "function.h"
using namespace std;
/*
    INPUT                      | OUTPUT
#TEST CASE 1: Base case to see if the function works properly
input.txt: 1 2 2 4 2 6 0       | output.txt: 1 4 6 0
cin: 2                         |

#TEST CASE 2: Delete multiple elements at the beginning of the list
input.txt: 5 5 10 15 0         | output.txt: 10 15 0
cin: 5                         |

#TEST CASE 3: What if we need to delete the entire list
input.txt: 7 7 7 0             | output.txt: 0
cin: 7                         |
*/

int main() {
    ifstream inFile;
    inFile.open("input.txt");
    Node* pHead = nullptr;
    readDataFromFile(pHead, inFile);
    int x; cin >> x;
    deleteElementWithValueK(pHead, x);
    ofstream outFile;
    outFile.open("output.txt");
    displayList(pHead, outFile);
    deleteAll(pHead);
    return 0;
}