#include <stdio.h>
int search(int a[], int size, int n){
    int i=0;
    for(i=0;i<size;i++)
   {
        if(a[i]==n)break;
    }
    return i<size? i : -1;
}

