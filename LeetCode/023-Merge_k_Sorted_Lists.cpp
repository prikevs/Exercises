#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *merge(ListNode *p1, ListNode *p2) {
        ListNode *ret = NULL, *p;
        if (p1 == NULL && p2 == NULL) {
            return NULL; 
        }
        else {
            if (p1 == NULL) {
                ret = p2;
                p2 = p2->next;
            }
            else if (p2 == NULL) {
                ret = p1;
                p1 = p1->next;
            }
            else {
                if (p1->val < p2->val) {
                    ret = p1;
                    p1 = p1->next;
                }
                else {
                    ret = p2;
                    p2 = p2->next;
                }
            }
        }
        p = ret;
        while(p1 || p2) {
            if (p1 == NULL) {
                p->next = p2;
                p2 = p2->next;
            }
            else if (p2 == NULL) {
                p->next = p1;
                p1 = p1->next;
            }
            else {
                if (p1->val < p2->val) {
                    p->next = p1;
                    p1 = p1->next;
                }
                else {
                    p->next = p2;
                    p2 = p2->next;
                }
            }
            p= p->next;
        }
        //ret->next = NULL;
        return ret;
    }

    void merge_lists(int l, int r, vector<ListNode*>& lists) {

        if (l == r-1) {
            return;     
        }
        int mid = (l + r) >> 1;
        merge_lists(l, mid, lists);
        merge_lists(mid, r, lists);
        lists[l] = merge(lists[l], lists[mid]);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) {
            return NULL; 
        }
        merge_lists(0, size, lists);
        return lists[0];
    }
};

int main()
{
    return 0;
}
