#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL) {
            return head; 
        }
        int cnt = 0;
        ListNode *p = head;
        while(p) {
            ++cnt;
            p = p->next;
        }
        int target = cnt / k;
        ListNode *start = new ListNode(0);
        start->next = head;
        p = start->next;
        ListNode *last = start;
        ListNode *first = start->next;
        for(int i = 0; i < target; ++i) {
            int t = k; 
            first = p;
            while(p && t--) {
                ListNode *next = p->next;
                p->next = last->next;
                last->next = p;
                p = next;
            }
            last = first;
            first->next = p;
        }
        return start->next;
    }
};

int main()
{
    return 0;
}
