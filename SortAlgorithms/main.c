#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include "test.h"

int cmp(const void *a, const void *b)
{
    return *(int *)a > *(int *)b? 1:-1;
}

int main()
{
    int n, max, min, i;
    int *arr;
    int *tmp;
    time_t start, end;
    scanf("%d %d %d", &n, &min, &max);
    generate_random_numbers(&arr, n, min, max);
    tmp = (int *)malloc(sizeof(int)*n);

//    for(i = 0; i < n; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//    fflush(stdout);
    memcpy(tmp, arr, sizeof(int)*n);
    start = clock();
    Mergesort(tmp, n);
    end = clock();
    printf("%ld\n", end-start);
    
    memcpy(tmp, arr, sizeof(int)*n);
    start = clock();
    qsort(tmp, n, sizeof(int), cmp);
    end = clock();
    printf("%ld\n", end-start);

    memcpy(tmp, arr, sizeof(int)*n);
    start = clock();
    Quicksort(tmp, n);
    end = clock();
    printf("%ld\n", end-start);
//    for(i = 0; i < n; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//    fflush(stdout);
    if (test(tmp, n))
        printf("YES\n");
    else
        printf("NO\n");
    destroy(&arr);
    destroy(&tmp);
    return 0;
}
