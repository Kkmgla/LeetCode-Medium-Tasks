/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include <iostream>
#include <string>

using namespace std;

//Definition for singly-linked list.
struct ListNode{ 
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    string str1;
    string str2;
    string reversedStr1;
    string reversedStr2;
    bool perepolnenye = 0;

    struct MyStruct
    {
    public:
        ListNode* head;
        ListNode* prev;
        MyStruct() {
            head = nullptr;
            prev = nullptr;
        }
    };



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        Solution s;
        MyStruct myStruct;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        toStr1(l1);
        toStr2(l2);

        if (str1.size() >= str2.size())
        {
            for (int i = 0; i < str1.size(); i++) {

                int value1 = str1[i] - '0'; // Преобразуем символ в цифру
                int value2 = (i < str2.size()) ? str2[i] - '0' : 0; // Преобразуем символ в цифру, или используем 0, если str2 меньше
                int tmp = value1 + value2;

                if (tmp >= 10 && perepolnenye)
                {
                    tmp = tmp - 10;
                    tmp = tmp + 1;
                }
                else if (tmp >= 10 && !perepolnenye)
                {
                    tmp = tmp - 10;
                    perepolnenye = 1;
                }
                else if (tmp <= 10 && perepolnenye)
                {
                    tmp = tmp + 1;
                    perepolnenye = 0;

                    if (tmp == 10)
                    {
                        tmp = tmp - 10;
                        perepolnenye = 1;
                    }
                }
                else if (tmp <= 10 && !perepolnenye)
                {
                    // то все заебись
                }

                myStruct = s.createLinkedListFromDigit(tmp, myStruct);

            }
            if (perepolnenye)
            {
                myStruct = s.createLinkedListFromDigit(1, myStruct);
            }
        }
        else
        {
            for (int i = 0; i < str2.size(); i++) {

                int value1 = (i < str1.size()) ? str1[i] - '0' : 0; // Преобразуем символ в цифру
                int value2 = str2[i] - '0'; // Преобразуем символ в цифру, или используем 0, если str2 меньше
                int tmp = value1 + value2;

                if (tmp >= 10 && perepolnenye)
                {
                    tmp = tmp - 10;
                    tmp = tmp + 1;
                }
                else if (tmp >= 10 && !perepolnenye)
                {
                    tmp = tmp - 10;
                    perepolnenye = 1;
                }
                else if (tmp <= 10 && perepolnenye)
                {
                    tmp = tmp + 1;
                    perepolnenye = 0;

                    if (tmp == 10)
                    {
                        tmp = tmp - 10;
                        perepolnenye = 1;
                    }
                }
                else if (tmp <= 10 && !perepolnenye)
                {
                    // то все заебись
                }

                myStruct = s.createLinkedListFromDigit(tmp, myStruct);

            }
            if (perepolnenye)
            {
                myStruct = s.createLinkedListFromDigit(1, myStruct);
            }
        }

        return myStruct.head;



    }

    MyStruct createLinkedListFromDigit(int value, MyStruct myStruct) {
        
        ListNode* newNode = new ListNode(value); // Создаем новый узел

        // Если это первая цифра, она становится головой списка
        if (myStruct.head == nullptr) {
            myStruct.head = newNode;
        }
        else {
            myStruct.prev->next = newNode; // Связываем предыдущий узел с текущим
        }

        myStruct.prev = newNode; // Обновляем предыдущий узел

        return  myStruct;
    }

    // не используется
    ListNode* createLinkedListFromString(const string& digits) {
        ListNode* head = nullptr;
        ListNode* prev = nullptr;

        // Проходим по каждой цифре в строке
        for (char digit : digits) {
            int value = digit - '0'; // Преобразуем символ в цифру
            ListNode* newNode = new ListNode(value); // Создаем новый узел

            // Если это первая цифра, она становится головой списка
            if (head == nullptr) {
                head = newNode;
            }
            else {
                prev->next = newNode; // Связываем предыдущий узел с текущим
            }

            prev = newNode; // Обновляем предыдущий узел
        }

        return head;
    }

    int toStr1(ListNode* l) {
        string str = to_string(l->val);
        str1.append(str);
        if (l->next != nullptr) toStr1(l->next);
        return 0;
    }
    int toStr2(ListNode* l) {
        string str = to_string(l->val);
        str2.append(str);
        if (l->next != nullptr) toStr2(l->next);
        return 0;
    }

    void printLinkedList(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->val;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};


int main()
{
    ListNode* node1 = new ListNode(9);
    ListNode* node2 = new ListNode(9);
    ListNode* node3 = new ListNode(9);
    ListNode* node4 = new ListNode(9);
    ListNode* node5 = new ListNode(9);
    ListNode* node6 = new ListNode(9);
    ListNode* node7 = new ListNode(9);

    // Связываем узлы
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    ListNode* node8 = new ListNode(9);
    ListNode* node9 = new ListNode(9);
    ListNode* node10 = new ListNode(9);
    ListNode* node11 = new ListNode(9);

    // Связываем узлы
    node8->next = node9;
    node9->next = node10;
    node10->next = node11;

   /*
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(6);
    ListNode* node6 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node4->next = node5;
    node5->next = node6;
   */

    Solution s;
    ListNode* l;
    l = s.addTwoNumbers(node1, node8);

    // Выводим содержимое связанного списка
    cout << "Linked list: ";
    s.printLinkedList(l);

}