#include <stdlib.h>
#include <stdio.h>

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void quicksort(int *arr, int left, int right)
{
    int pos;
    int i = left, j = right;
//    printf("left=%d, right=%d\n", left, right);
    if (left >= right-1)
        return;
    pos = left + rand()%(right-left);
    swap(arr+left, arr+pos);
    do{
        do i++; while(i < right && arr[i] < arr[left]);
        do j--; while(j >= left && arr[j] > arr[left]);
        if (i < j) swap(arr+i, arr+j);
    }while(i < j);
    swap(arr+j, arr+left); 
    quicksort(arr, left, j);
    quicksort(arr, j+1, right);
}

void Quicksort(int *arr, int n)
{
    srand(time(NULL)); 
    quicksort(arr, 0, n);
}
