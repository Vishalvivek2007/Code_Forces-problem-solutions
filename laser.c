#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        long long x, y, n,m;
        scanf("%lld %lld %lld %lld",&n,&m,&x,&y);
        long long arr1[n];
        long long arr2[m];
        for(long long i=0;i<n;i++){
          scanf("%lld",&arr1[i]);
        }
        for(long long i=0;i<m;i++){
          scanf("%lld",&arr2[i]);
        }
        printf("%lld\n",n+m);
    }
    return 0;
}