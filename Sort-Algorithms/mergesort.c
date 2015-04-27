#include <stdlib.h>
#include <string.h>

void merge(int *arr, int left, int right)
{
    int mid = (left + right) >> 1;
    int num = right - left;
    int *lt, *rt;
    int lp, rp, i;

    if (left >= right - 1)
        return;

    merge(arr, left, mid);
    merge(arr, mid, right);
    lt = (int *)malloc(sizeof(int)*(mid-left+1));
    rt = (int *)malloc(sizeof(int)*(right-mid+1));
    lt[mid-left] = rt[right-mid] = 0x7fffffff;
    memcpy(lt, arr+left, (mid-left)*sizeof(int));
    memcpy(rt, arr+mid, (right-mid)*sizeof(int));
    lp = rp = 0;
    for(i = left; i < right; i++){
        if (lt[lp] < rt[rp])
            arr[i] = lt[lp++];
        else
            arr[i] = rt[rp++];
    }
    free(lt);
    free(rt);

}

void Mergesort(int *arr, int n)
{
    merge(arr, 0, n); 
}
