#include <iostream>
#include <string>
#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listSize = counter(head, 0);
        size = listSize;

        if (listSize == 0) return nullptr;
        if (listSize == 1) return nullptr;

        fixHead = head;

        if (n == 1) remove(head, listSize - n, 1);
        else if (n == size) {
            ListNode* newHead = remove(head, listSize - n, 2);
            fixHead = newHead;
        }
        else if(n != size && n != 1) remove(head, listSize - n, 3);

        return fixHead; // Возвращаем fixHead вместо head
    }

private:
    ListNode* fixHead; // Добавляем fixHead как приватное поле
    int size = 0;

    int counter(ListNode* head, int cnt) {
        if (head == nullptr) {
            return cnt; // Базовый случай: если достигнут конец списка, возвращаем счетчик
        }
        // Рекурсивный случай: переходим к следующему узлу и увеличиваем счетчик
        return counter(head->next, cnt + 1);
    }

    ListNode* remove(ListNode* head, int target, int option) {
        if (target == 1 && option == 1) {
            head->next = nullptr;
            return head; // Возвращаем head, чтобы указать на новый конец списка
        }
        if (target == 0 && option == 2) {
            if (head == nullptr) // Проверяем, является ли head nullptr
                return nullptr; // Возвращаем nullptr, если head уже nullptr
            head = head->next;
            return head;
        }
        if (target == 1 && option == 3) {
            head->next = head->next->next;
            return head; // Возвращаем head, чтобы указать на измененный список
        }
        target--;
        return remove(head->next, target, option); // Используем возвращаемое значение рекурсивного вызова
    }

};


int main()
{
    // Создаем 5 узлов
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    // Устанавливаем связи между узлами
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution s;
    ListNode* hh = s.removeNthFromEnd(node1, 5);

    // Выводим значения узлов
    while (hh != nullptr) {
        std::cout << hh->val << " ";
        hh = hh->next;
    }
}