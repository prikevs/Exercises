#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *start = new ListNode(-1);
        start->next = head;
        ListNode *p = start;
        ListNode *t = start;
        bool flag = false;
        while(p && p->next && p->next->next) {
            while(p->next && p->next->next && p->next->val == p->next->next->val) {
                flag = true;
                t = p->next->next; 
                p->next->next = p->next->next->next;
                delete t;
            } 
            if (flag) {
                t = p->next;
                p->next = p->next->next;
                delete t;
                flag = false;
            }
            else
                p = p->next;
        }
        head = start->next;
        delete start;
        return head;
    }
};

int main()
{
    return 0;
}
