#include <vector>
#include <iostream>
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode* secondHead = new ListNode();
        ListNode* secondHeadCurrNode = secondHead;
        ListNode* previousNode = nullptr;

        while (curr != nullptr)
        {
            if (curr->val >= x)
            {
                ListNode* nextNode = curr->next;

                secondHeadCurrNode->next = curr;
                secondHeadCurrNode = secondHeadCurrNode->next;
                curr->next = nullptr;

                if (previousNode != nullptr)
                {
                    previousNode->next = nextNode;
                }
                else
                {
                    head = nextNode;
                }

                curr = nextNode;
            }
            else
            {
                previousNode = curr;
                curr = curr->next;
            }
        }

        if (previousNode != nullptr)
        {
            previousNode->next = secondHead->next;
            return head;
        }
        else
        {
            return secondHead->next;
        }
    }
};

/*
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
*/
int main()
{
    vector<int>values = { 1,4,3,2,5,2 };
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;

    for (int i = 1; i < values.size(); ++i)
    {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }

    curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }

    cout << endl;

    Solution s;
    int x = 3;
    ListNode* sol = s.partition(head, x);
    curr = sol;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}