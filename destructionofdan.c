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
    int t;
    scanf("%d", &t);
    while (t--) {
        ll len;
        scanf("%lld",&len);
        ll* arr = (ll*)malloc(sizeof(ll)*len);
        ll ocount=0;
        ll sum=0;
        for(ll i=0;i<len;i++){
            scanf("%lld",arr+i);
            if(*(arr+i)%2==0){
                sum+= *(arr+i);
            }
            else{
                ocount++;
            }
        }
        
        ll* arr1=(ll*)malloc(sizeof(ll)*ocount);
        ocount=0;
        for(ll i=0;i<len;i++){
            if(*(arr+i)%2!=0){
                *(arr1+ocount)=*(arr+i);
                ocount++;
            }
        }
        
        if(ocount==0){
            printf("0\n");
        }
        else{
            mergesort(arr1,ocount);
            
            ll odds_to_add = (ocount / 2) + (ocount % 2);

            for(ll i = 0; i < odds_to_add; i++){
                sum += *(arr1 + (ocount - 1 - i));
            }
            
            printf("%lld\n",sum);
        }
        
        free(arr);
        if (ocount > 0) {
            free(arr1);
        }
    }
    return 0;
}