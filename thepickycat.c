#include<stdio.h>
#include<stdlib.h>

long long binarysearch(long long* arr, long long ele, long long len) {
    long long low = 0;
    long long high = len - 1;
    while (low <= high) {
        long long middle = low + (high - low) / 2;
        long long value = arr[middle];
        if (value < ele) {
            low = middle + 1;
        } else if (value > ele) {
            high = middle - 1;
        } else {
            return middle;
        }
    }
    printf("Not found\n");
    return -1;
}

void merge(long long* arr1, long long* arr2, long long* arr, long long len) {
    long long middle = len / 2;
    long long i = 0, l = 0, r = 0;
    while (l < middle && r < len - middle) {
        if (arr1[l] < arr2[r]) {
            arr[i] = arr1[l];
            i++;
            l++;
        } else {
            arr[i] = arr2[r];
            i++;
            r++;
        }
    }
    while (l < middle) {
        arr[i] = arr1[l];
        i++;
        l++;
    }
    while (r < len - middle) {
        arr[i] = arr2[r];
        i++;
        r++;
    }
}

void mergsort(long long* arr, long long len) {
    if (len <= 1) {
        return;
    }
    long long middle = len / 2;
    long long left[middle];
    long long right[len - middle];
    long long i = 0, j = 0;
    for (; i < len; i++) {
        if (i < middle) {
            left[i] = arr[i];
        } else {
            right[j] = arr[i];
            j++;
        }
    }
    mergsort(left, middle);
    mergsort(right, len - middle);
    merge(left, right, arr, len);
}

int main() {
    int  n;
    scanf("%lld", &n);
    while (n--) {
        long long len, diff, item;
        scanf("%lld", &len);
        long long arr[len];
        for (long long i = 0; i < len; i++) {
            scanf("%lld", &arr[i]);
            if(arr[i]<0){
              arr[i]*=-1;
            }
        }
        item = arr[0];
        mergsort(arr, len);
        if(len%2==0){
          diff = len/2-1;
        }
        else{
          diff = len/2;
        }
        long long check = binarysearch(arr, item, len);
        if (len-check-1>=diff) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}