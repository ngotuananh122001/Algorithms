#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int _x) {
        val = _x;
    }
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        if (!list1 && !list2)
            return NULL;

        if (!list1)
            return list2;

        if (!list2)
            return list1;

        // Now, both pointer != NULL
        if (list1->val <= list2->val) {
            head = tail = list1;
            list1 = list1->next;
        } else {
            head = tail = list2;
            list2 = list2->next;
        }

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }

        if (list1) {
            tail->next = list1;
        }

        if (list2) {
            tail->next = list2;
        }

        return head;

    }

void PrintList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}
int main() {
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* a3 = new ListNode(4);
    ListNode* list1 = a1;
    a1->next = a2;
    a2->next = a3;
    a3->next = NULL;


    ListNode* b1 = new ListNode(1);
    ListNode* b2 = new ListNode(3);
    ListNode* b3 = new ListNode(4);
    ListNode* list2 = b1;
    b1->next = b2;
    b2->next = b3;
    b3->next = NULL;


    ListNode* head = mergeTwoLists(list1, list2);
    PrintList(head);

    return 0;
}

