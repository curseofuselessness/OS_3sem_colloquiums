#include "colloquium.h"

using namespace std;

int main() {
	int n;

	cout << "1. Enter amount of Factorials: ";
	cin >> n;

	vector<long long> factorials = generateFactorials(n);

	cout << "Factorials: ";

	for (const auto& item : factorials) {
		cout << item << " ";
	}

	cout << endl;

	cout << "2. Enter amount of numbers of array, to delete duplicates: ";
	cin >> n;

	vector<int> inputVector2 = readVectorWithLengthOf(n);
	vector<int> outputVector2 = removeDuplicates(inputVector2);

	cout << "Array after removing duplicates: ";

	for (const auto& item : outputVector2) {
		cout << item << " ";
	}

	cout << endl;

	cout << "3. Enter amount of numbers of list, to reverse it: ";
	cin >> n;
	Node* temp = readList(n);
	printList(reverse(temp));


}