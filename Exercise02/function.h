#pragma once
#include <iostream>
#include <fstream>
#include <string>
struct Node {
    int data;
    Node* next;
};
void readDataFromFile(Node*& pHead, std::ifstream& inFile);
void displayList(Node* pHead, std::ofstream& outFile);
void deleteElementWithValueK(Node*& pHead, int k);
void deleteAll(Node*& pCurr);