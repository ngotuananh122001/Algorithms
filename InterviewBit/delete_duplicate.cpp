/*
  @title: Remove Duplicates from Sorted List
  @desc
    Given a sorted linked list,
    delete all duplicates such that each element appear only once.
  @Note
    Given 1->1->2->3->3, return 1->2->3.
  @Link
    https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/
*/


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    // constructor
    ListNode(int v) {
        val = v;
        next = NULL;
    }
};


ListNode* deleteDuplicates(ListNode* A) {
    if (!A)
        return A;

    ListNode* current = A, *next;

    while (current) {
        next = current->next;
        if (!next)
            break;

        if (current->val == next->val) {
            current->next = next->next;
            delete next;
        } else
            current = next;
    }
    return A;
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(2);
    ListNode* n5 = new ListNode(2);
    ListNode* n6 = new ListNode(3);

    ListNode* head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    cout << "Before: ";
    while (n1) {
        cout << n1->val << " ";
        n1 = n1->next;
    }
    cout << endl;

    ListNode* ans = deleteDuplicates(head);

    cout << "After: ";
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}
