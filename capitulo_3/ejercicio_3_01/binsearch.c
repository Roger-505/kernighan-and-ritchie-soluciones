#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void){
    int v[] = {40, 41, 42, 43, 44, 45, 46};
    int x = 44;
    int n = 7;
    
    printf("Array: {");
    for (int i = 0; i < n; i++){
        if (i == n - 1)
            printf("%d", v[i]);
        else 
            printf("%d, ", v[i]);
    }
    printf("}\nIdx of %d: %d\n", x, binsearch(x, v, n));
}

int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;

    while(low <= high){
        mid = (low + high)/2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (v[mid] == x)
        return mid;
    else
        return -1;
}
