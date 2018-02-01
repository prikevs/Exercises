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

const int LEN = 200020;

bool judge(char *str1, char *str2, int length)
{
    char *s1, *s2, *s3, *s4;
    int mid = length/2;
    if (length == 0) {
        return false;
    }
    if (strncmp(str1, str2, length) == 0)
        return true;
    if (length%2 == 1) {
        return false;
    }
    s1 = str1;
    s2 = str1 + mid;
    s3 = str2;
    s4 = str2 + mid;
    if (strncmp(s1, s3, mid) == 0 && strncmp(s2, s4, mid) == 0)
        return true;
    return judge(s1, s4, mid) && judge(s2, s3, mid) || judge(s1, s3, mid) && judge(s2, s4, mid);

}

int main()
{
    char str1[LEN], str2[LEN];
    scanf("%s %s", str1, str2); 
    int length = strlen(str1);
    if (strcmp(str1, str2) == 0) {
        printf("YES\n"); 
        return 0;
    } 
    if (length % 2 == 1) {
        printf("NO\n"); 
        return 0;
    }
    if (judge(str1, str2, length)) {
        printf("YES\n"); 
    }
    else {
        printf("NO\n");
    }
    return 0;
}
