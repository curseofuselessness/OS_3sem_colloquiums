#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<long long> generateFactorials(int n);                   // 1. Первые n факториалов
vector<int> removeDuplicates(const vector<int>& input);        // 2. Удаление дубликатов в контейнере, без изменения порядка

struct Node {
    int value;
    Node* next;
    Node(int x) : value(x), next(nullptr) {}
};

Node* reverse(Node* head);                                     // 3. Переворот сявзного списка
void printList(Node* head);
Node* readList(int n);

vector<int> readVectorWithLengthOf(int n);