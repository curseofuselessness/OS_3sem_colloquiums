#include "colloquium.h"
#include <gtest/gtest.h>

TEST(FactorialTest, BasicAssertions) {
    // Тест 1: Положительные числа
    vector<long long> result1 = generateFactorials(5);
    EXPECT_EQ(result1.size(), 5);
    EXPECT_EQ(result1[0], 1);   // 0! = 1
    EXPECT_EQ(result1[1], 1);   // 1! = 1
    EXPECT_EQ(result1[2], 2);   // 2! = 2
    EXPECT_EQ(result1[3], 6);   // 3! = 6
    EXPECT_EQ(result1[4], 24);  // 4! = 24

    // Тест 2: n = 0
    vector<long long> result2 = generateFactorials(0);
    EXPECT_TRUE(result2.empty());

    // Тест 3: n = 1
    vector<long long> result3 = generateFactorials(1);
    EXPECT_EQ(result3.size(), 1);
    EXPECT_EQ(result3[0], 1);
}

TEST(RemoveDuplicatesTest, BasicAssertions) {
    // Тест 1: Обычный случай с дубликатами
    vector<int> input1 = { 1, 2, 2, 3, 4, 4, 4, 5 };
    vector<int> result1 = removeDuplicates(input1);
    EXPECT_EQ(result1.size(), 5);
    EXPECT_EQ(result1[0], 1);
    EXPECT_EQ(result1[1], 2);
    EXPECT_EQ(result1[2], 3);
    EXPECT_EQ(result1[3], 4);
    EXPECT_EQ(result1[4], 5);

    // Тест 2: Все элементы уникальны
    vector<int> input2 = { 5, 3, 7, 1 };
    vector<int> result2 = removeDuplicates(input2);
    EXPECT_EQ(result2.size(), 4);
    EXPECT_EQ(result2, input2);  // порядок должен сохраниться

    // Тест 3: Пустой вектор
    vector<int> input3 = {};
    vector<int> result3 = removeDuplicates(input3);
    EXPECT_TRUE(result3.empty());

    // Тест 4: Все элементы одинаковые
    vector<int> input4 = { 2, 2, 2, 2 };
    vector<int> result4 = removeDuplicates(input4);
    EXPECT_EQ(result4.size(), 1);
    EXPECT_EQ(result4[0], 2);
}

TEST(ReverseListTest, BasicAssertions) {
    // Тест 1: Обычный список
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* reversed1 = reverse(head1);
    EXPECT_EQ(reversed1->value, 3);
    EXPECT_EQ(reversed1->next->value, 2);
    EXPECT_EQ(reversed1->next->next->value, 1);
    EXPECT_EQ(reversed1->next->next->next, nullptr);

    // Тест 2: Пустой список
    Node* head2 = nullptr;
    Node* reversed2 = reverse(head2);
    EXPECT_EQ(reversed2, nullptr);

    // Тест 3: Список из одного элемента
    Node* head3 = new Node(5);
    Node* reversed3 = reverse(head3);
    EXPECT_EQ(reversed3->value, 5);
    EXPECT_EQ(reversed3->next, nullptr);
}