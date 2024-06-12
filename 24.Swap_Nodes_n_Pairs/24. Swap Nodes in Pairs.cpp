// 24. Swap Nodes in Pairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize pointers
        ListNode* prev = dummy;
        ListNode* current = head;

        // Traverse the list and swap pairs
        while (current != nullptr && current->next != nullptr) {
            // Nodes to be swapped
            ListNode* first = current;
            ListNode* second = current->next;

            // Swapping the nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move the pointers for the next pair
            prev = first;
            current = first->next;
        }

        // The new head is the next node of the dummy node
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node memory
        return newHead;
    }
};


int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);

    // Устанавливаем связи между узлами
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Solution s;
    ListNode* hh = s.swapPairs(node1);

    // Выводим значения узлов
    while (hh != nullptr) {
        std::cout << hh->val << " ";
        hh = hh->next;
    }
}