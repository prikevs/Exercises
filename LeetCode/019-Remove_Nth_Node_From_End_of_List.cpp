#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1, *p2, *last;
        last = p1 = p2 = head;
        int t = n;
        while(t--) {
            p2 = p2->next; 
        }
        while(p2) {
            last = p1;
            p1 = p1->next;
            p2 = p2->next; 
        }
        last->next = p1->next;
        if (p1 == head) {
            head = p1->next;
        }
        delete p1;
        return head;
    }
};

int main()
{
    return 0;
}
