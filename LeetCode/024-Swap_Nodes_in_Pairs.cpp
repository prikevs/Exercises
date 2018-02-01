#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        ListNode *p = head; 
        ListNode *last = head; 
        if (p == NULL) {
            return head; 
        }
        if (p->next != NULL) {
            head = head->next;
            p->next = head->next;
            head->next = p;
            last = p;
            p = p->next;
        }
        while(p && p->next != NULL) {
            ListNode *t = p; 
            last->next = p->next;
            t = p->next->next;
            p->next->next = p;
            last = p;
            p->next = t;
            p = t;
        }
        if (p == NULL)
            last->next = NULL;
        return head;
    }
};



int main()
{
    return 0;
}
