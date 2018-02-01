#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1, *p2;
        p1 = p2 = head;
        while(p1 && p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 == NULL) {
                return NULL; 
            }
            p2 = p2->next;
            if (p1 == p2) {
                while(true) {
                    if (head == p1) {
                        return head; 
                    }
                    head = head->next;
                    p1 = p1->next;
                }
            }
        }
        return NULL;
    }
};

int main()
{}

// n: steps
// a: straight length
// b: cycle length
// 
//    (n-a)%b == (2n-a)%b
// => n == b
