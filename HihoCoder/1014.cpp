#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
const double pi = 4*atan(1);
int gcd(int a, int b)   {return b == 0? a:gcd(b,a%b);}
int lcm(int a, int b)   {return a/gcd(a,b)*b;}

const int LEN = 26;

struct Node {
    Node *letters[LEN];
    bool isend;
    int num;
    Node() {memset(this, 0, sizeof(Node));}
};


void insert_word(Node *node, char *word)
{
    while(*word != '\0') {
        int id = *word - 'a';
        if (node->letters[id] == NULL) {
            node->letters[id] = new Node;
        }
        word++; 
        node = node->letters[id]; 
        node->num++;
    }
    if (*word == '\0') {
        node->isend = true; 
    }
}

int query(Node *node, char *prefix)
{
    while(*prefix != '\0') {
       int id = *prefix - 'a';
       if (node->letters[id] == NULL) {
           return 0;
       }
       prefix++;
       node = node->letters[id];
    }
    if (*prefix == '\0') {
        return node->num;
    }
}

int main()
{
    int n;
    char word[20];
    Node *head = new Node;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", word); 
        insert_word(head, word);
    }
    scanf("%d", &n);
    while(n--) {
        scanf("%s", word); 
        printf("%d\n", query(head, word));
    }
    return 0;
}
