#pragma once

#include "colloquium.h"

vector<int> readVectorWithLengthOf(int n) {
	vector<int> result;
	result.reserve(n);

	cout << "Enter array members: ";

	int a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		result.push_back(a);
	}

	return result;
}

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->value;

        if (current->next != nullptr) {
            cout << " -> ";
        }

        current = current->next;

    }

    cout << endl;
}

Node* readList(int n) {
    int a;
    Node* temp;
    Node* head;

    cout << "Enter members of list: ";

    cin >> a;

    temp = new Node(a);
    head = temp;

    for (int i = 1; i < n; i++) {
        cin >> a;

        temp->next = new Node(a);
        temp = temp->next;

    }

    return head;
}