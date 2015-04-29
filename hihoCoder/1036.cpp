#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;
const double pi = 4*atan(1);
int gcd(int a, int b)   {return b == 0? a:gcd(b,a%b);}
int lcm(int a, int b)   {return a/gcd(a,b)*b;}

const int ALPH = 26;

struct Node {
    Node *next[ALPH];
    Node *father;
    Node *fail;
    bool isw;
    int deep;
    Node() {
        memset(next, 0, sizeof(next));
        fail = NULL;
        deep = 0;
        isw = 0;
    } 
};

void insert_word(Node *root, char *s)
{
    Node *node = root;
    while(*s != '\0') {
        int ch = *s - 'a';
        if (node->next[ch] == NULL) {
            node->next[ch] = new Node;
        } 
        node->next[ch]->father = node;
        node->next[ch]->deep = node->deep + 1;
        node = node->next[ch];
        s++;
    }
    node->isw = true;
}

void ac_automan(Node *root)
{
    Node *node = root;
    root->fail = NULL;
    Node *temp = NULL;
    queue <Node *> q;
    q.push(node);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        for(int i = 0; i < ALPH; i++) {
            if (temp->next[i] == NULL) {
                continue; 
            } 
            if (temp == root) {
                temp->next[i]->fail = root; 
            }
            else {
                node = temp->fail;
                while(node != NULL) {
                    if (node->next[i] != NULL) {
                        temp->next[i]->fail = node->next[i];
                        break;
                    } 
                    node = node->fail;
                } 
                if (node == NULL) {
                    temp->next[i]->fail = root; 
                }
            }
            q.push(temp->next[i]);
        } 
    }
}

bool query(Node *root, char *s)
{
    Node *node = root;
    Node *temp = NULL;
    while(*s != '\0') {
        int ch = *s - 'a';
     //   printf("uch=%d\n", ch);
      //  printf("deep=%d\n", node->deep);
        while(node->next[ch] == NULL && node != root) {
            node = node->fail;
       //     printf("   deep=%d\n", node->deep);
            
        }
        if (node->next[ch]) {
            node = node->next[ch];
        //    printf("ch=%d\n", ch);
        }
        if (node->isw)
            return true;
        s++;
    }
    return false;
}

int main()
{
    int n;
    char word[1000000];
    char str[1000010];
    Node root;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", word); 
        insert_word(&root, word);
    }
    ac_automan(&root);
    scanf("%s", str);
    if (query(&root, str)) {
        printf("YES\n"); 
    }
    else {
        printf("NO\n");
    }

    return 0;
}
