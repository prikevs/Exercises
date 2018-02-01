#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *p = head;
        if (k == 0) {
            return head; 
        }
        ListNode *next, *now;
        while(k-- && p) {
            now = p;
            p = p->next; 
        }
        if (p == NULL) {
            return head; 
        }
        now->next = NULL;
        while(p) {
            next = p->next;
            p->next = head;
            head = p; 
            p = next;
        }
        return head;
    }
};

int main()
{
    return 0;
}
