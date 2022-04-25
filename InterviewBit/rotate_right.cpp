#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;

    ListNode(int v) {
        val = v;
        next = NULL;
    }
};

ListNode* rotateRight(ListNode* A, int B) {
    if (!A)
        return A;

    if (A->next == NULL)
        return A;

    ListNode* head = A;
    ListNode* tail = head;

    int cnt = 1;
    while (tail->next) {
        tail = tail->next;
        cnt++;
    }

    tail->next = head;


    int steps = cnt - (B % cnt) - 1;
    for (int i = 0; i < steps; i++)
        head = head->next;

    tail = head;
    head = head->next;
    tail->next = NULL;
    return head;
}

void PrintList(ListNode* head) {
    cout << "Lists: ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    PrintList(n1);
<<<<<<< HEAD
    ListNode* head = rotateRight(n1, 100);
=======
    ListNode* head = rotateRight(n1, 98);
>>>>>>> LinkedList
    PrintList(head);
}
