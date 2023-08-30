#include "ListNode.h"
#include <iostream>

using namespace std;
//LeetCode 21. Merge Two Sorted Lists

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head = new ListNode(0);
        ListNode* curr = head;
 
        while(list1 != NULL && list2 != NULL) {
            if(list1->val<=list2->val) {
                curr->next=list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1 != NULL) curr->next = list1;
        if(list2 != NULL) curr->next = list2;
        return head->next;
    };
};

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(7);
    ListNode* node3 = new ListNode(44);

    node1->next = node2;
    node2->next = node3;

    ListNode* node4 = new ListNode(22);
    ListNode* node5 = new ListNode(63);
    ListNode* node6 = new ListNode(78);

    node4->next = node5;
    node5->next = node6;

    ListNode* head1 = node1;
    ListNode* head2 = node4;

    Solution sol;

    ListNode* res = sol.mergeTwoLists(head1, head2);

    ListNode* current = res;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    while (res != nullptr) {
        ListNode* temp = res;
        res = res->next;
        delete temp;
    }

    return 0;
}