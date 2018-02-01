#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *oddhead, *evenhead;
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return head; 
        }

        ListNode *p = head;
        ListNode *odd, *even;
        int cnt = 0;
        while(++cnt && p != NULL) {
            if (cnt == 1) {
                oddhead = p; 
                odd = oddhead;
            }
            else if (cnt == 2) {
                evenhead = p; 
                even = evenhead;
            }
            else {
                if (cnt & 1) {
                    odd->next = p;
                    odd = p;
                } 
                else {
                    even->next = p; 
                    even = p;
                }
            }
            p = p->next;
        }
        if (odd != NULL) {
            odd->next = evenhead;
        }
        if (even != NULL) {
            even->next = NULL;
        }
        return oddhead;
    }
};

ListNode* construct(int n) {
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for(int i = 2; i <= n; ++i) {
        p->next = new ListNode(i); 
        p = p->next;
    }
    return head;
}

void Show(ListNode *head) {
    ListNode *p = head;
    while(p != NULL) {
        cout << p->val << endl; 
        p = p->next;
    }
}

int main()
{
    ListNode *head = construct(8);
    Show(head);
    Solution sol;
    sol.oddEvenList(head);
    Show(head);
    return 0;
}
