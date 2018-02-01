#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *ret = head;
        ListNode *p = head->next;
        while(p != NULL) {
            ListNode *t = p;
            p = p->next;
            t->next = ret;
            ret = t;
        } 
        head->next = NULL;
        return ret;
    }
};

int main()
{
    return 0;
}
