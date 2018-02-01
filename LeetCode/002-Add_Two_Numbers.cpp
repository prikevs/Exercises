#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *ret;
    ListNode *makeNode(int n) {
        return new ListNode(n); 
    }
    void destroy(ListNode *p) {
        if (p != NULL) {
            destroy(p->next); 
            delete p;
        }
    }
public:
    ~Solution() {
        //destroy(ret);         
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1, *p2, *p3, *last;
        p1 = l1;
        p2 = l2;
        ret = makeNode(0);
        p3 = ret;
        last = ret;

        while(p1 || p2) {
            int c1, c2;
            if (p1 == NULL) {
                c1 = 0; 
            }                
            else {
                c1 = p1->val; 
                p1 = p1->next;
            }
            if (p2 == NULL) {
                c2 = 0; 
            }
            else {
                c2 = p2->val; 
                p2 = p2->next;
            }
            p3->val += c1 + c2;
            p3->next = makeNode(p3->val/10);
            p3->val %= 10;
            last = p3;
            p3 = p3->next;
        } 
        if (p3->val == 0 && p3 != ret) {
            last->next = NULL;
            delete p3;
        }
        return ret;
    }
};

void show(ListNode *head) {
    ListNode *p = head;
    while(p != NULL) {
        cout << p->val << " "; 
        p = p->next;
    }
    cout << endl;
}

void construct(ListNode *head, vector<int> nums)
{
    ListNode *p = head;
    for(auto num: nums) {
        p->val = num;
        p = new ListNode(num);
        p = p->next;
    }    
}

int main()
{
    ListNode *l1 = new ListNode(0);    
    ListNode *l2 = new ListNode(0);    
    Solution sol;
    auto ret = sol.addTwoNumbers(l1, l2);
    show(ret);

    return 0;
}
