#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void merge(ll *arr1, ll *arr2, ll *arr, ll len) {
    ll middle = len / 2;
    ll i = 0, l = 0, r = 0;

    while (l < middle && r < len - middle) {
        if (arr1[l] < arr2[r]) {
            arr[i++] = arr1[l++];
        } else {
            arr[i++] = arr2[r++];
        }
    }
    while (l < middle) {
        arr[i++] = arr1[l++];
    }
    while (r < len - middle) {
        arr[i++] = arr2[r++];
    }
}

void mergesort(ll *arr, ll len) {
    if (len <= 1) {
        return;
    }
    ll middle = len / 2;

    ll *left = (ll *)malloc(middle * sizeof(ll));
    ll *right = (ll *)malloc((len - middle) * sizeof(ll));

    if (left == NULL || right == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (ll i = 0; i < middle; i++) {
        left[i] = arr[i];
    }
    for (ll i = middle; i < len; i++) {
        right[i - middle] = arr[i];
    }

    mergesort(left, middle);
    mergesort(right, len - middle);

    merge(left, right, arr, len);

    free(left);
    free(right);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
      ll len;
      scanf("%lld",&len);
      ll arr1[len],arr2[len],arr3[len];
      for(ll i=0;i<len;i++){
        scanf("%lld",&arr1[i]);
        arr3[i]=arr1[i];
      }
      for(ll i=0;i<len;i++){
        scanf("%lld",&arr2[i]);
        arr3[i]-=arr2[i];
      }
      mergesort(arr3,len);
      if(arr3[0]<0){
        if(arr3[1]>=-arr3[0]){
          printf("YES\n");
        }
        else{
          printf("NO\n");
        }
      }
      else{
        printf("YES\n");
      }
    }
    return 0;
}