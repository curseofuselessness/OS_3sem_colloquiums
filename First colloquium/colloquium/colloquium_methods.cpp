#include "colloquium.h"


vector<long long> generateFactorials(int n) {
    vector<long long> result;
    if (n <= 0) return result;

    result.push_back(1); // 0! = 1

    for (int i = 1; i < n; i++) {
        result.push_back(result.back() * i);
    }

    return result;
}

vector<int> removeDuplicates(const vector<int>& input) {
    unordered_set<int> seen;
    vector<int> result;

    for (const int& num : input) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }

    return result;
}

Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* newHead = reverse(head->next);

    head->next->next = head; 
    head->next = nullptr;    

    return newHead;
}

