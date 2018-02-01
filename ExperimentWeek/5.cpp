#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int LEN = 20;
const int STRLEN = 100;
const int xs = 3;
const int ys = 1;

bool graph[LEN][LEN];
char str[STRLEN];

int main()
{
    int n, x, y;
    char type;
    while(~scanf("%d, ", &n)) {
        memset(graph, false, sizeof(graph));
        for(int i = 0; i < n; ++i) {
            if (i != n-1) {
                scanf("%c,%d,%d, ", &type, &x, &y); 
            }
            else {
                scanf("%c,%d,%d", &type, &x, &y); 
            }
            int tx = x+xs-1;
            int ty = y+ys-1;
            if (type == 'A') {
                graph[ty][tx] = true;
                graph[ty-1][tx] = true;
                graph[ty-2][tx] = true;
                graph[ty-2][tx+1] = true;
                graph[ty-2][tx+2] = true;
            }
            else if (type == 'B') {
                graph[ty][tx] = true;
                graph[ty][tx+1] = true;
                graph[ty-1][tx] = true;
                graph[ty-1][tx+1] = true;
                graph[ty-2][tx] = true;
            }
            else if (type == 'C') {
                graph[ty][tx] = true;
                graph[ty+1][tx] = true;
                graph[ty][tx-1] = true;
                graph[ty][tx-2] = true;
                graph[ty][tx-3] = true;
            }
        }
        int ans = 0;
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                int tx = i+xs;
                int ty = j+ys;
                if (graph[ty][tx] == true) {
                    ++ans; 
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0; 
}
