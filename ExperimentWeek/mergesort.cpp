#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MIN = 0;
const int MOD = 100001;
const int MAXINT = 0x7FFFFFFF;

void genSeq(int *arr, int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; ++i) {
        arr[i] = MIN + rand() % MOD;
    }
}

void mergeSort(int *arr, int l, int r)
{
    int mid = (l + r) >> 1;
    if (l == r) {
        return; 
    }
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    int len1 = mid - l + 1;
    int len2 = r - mid;
    printf("l=%d,r=%d,mid=%d,len1=%d,len2=%d\n", l, r, mid, len1, len2);
    int *larr = new int[len1+1]; 
    int *rarr = new int[len2+1]; 
    printf("larr: ");
    for(int i = 0; i < len1; ++i) {
        larr[i] = arr[l+i];
        printf("%d ", larr[i]);
    }
    printf("\n");
    larr[len1] = MAXINT;
    printf("rarr: ");
    for(int i = 0; i < len2; ++i) {
        rarr[i] = arr[mid+i+1];
        printf("%d ", rarr[i]);
    }
    printf("\n");
    rarr[len2] = MAXINT;
    int i, j;
    i = j = 0;
    for(int c = l; c <= r; ++c) {
        if (larr[i] < rarr[j]) {
            arr[c] = larr[i++]; 
        }
        else {
            arr[c] = rarr[j++]; 
        }
    }
    delete []larr;
    delete []rarr;
}

int main()
{
    int n = 10;    
    int *arr = new int[n];
    genSeq(arr, n);
    for(int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
