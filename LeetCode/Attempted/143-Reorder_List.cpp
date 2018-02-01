#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        int cnt = 1; 
        ListNode *p = head;
        ListNode *odd, *even, *p1, *p2, *t, *t1, *t2;
        odd = even = NULL;
        while(p) {
            t = p->next;
            if (cnt % 2 == 1) {
                if (odd == NULL) {
                    odd = p;
                    p1 = odd;
                }
                else
                    p1->next = p; 
            }
            else {
                if (even == NULL) {
                    even = p;
                    even->next = NULL;
                }
                else {
                    p->next = even;
                    even = p;
                }
            }
            ++cnt; 
            p = t;
        }
        p1 = odd;
        p2 = even;
        head = p1;
        while(p1 && p2) {
            t1 = p1->next;
            t2 = p2->next;
            p1->next = p2; 
            p2->next = t1;
            p1 = t1;
            p2 = t2;
        }
    }
};

int main()
{
    return 0;
}
