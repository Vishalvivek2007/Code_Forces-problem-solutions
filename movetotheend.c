#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        long long len;
        scanf("%lld", &len);
        long long arr[len];
        for (long long i = 0; i < len; i++) {
            scanf("%lld", &arr[i]);
        }
        long long prefix_max[len];
        long long suffix_sum[len + 1];
        prefix_max[0] = arr[0];
        for (long long i = 1; i < len; i++) {
            if (prefix_max[i - 1] > arr[i]) {
                prefix_max[i] = prefix_max[i - 1];
            } else {
                prefix_max[i] = arr[i];
            }
        }
        suffix_sum[len] = 0;
        for (long long i = len - 1; i >= 0; i--) {
            suffix_sum[i] = suffix_sum[i + 1] + arr[i];
        }
        for (int k = 1; k <= len; k++) {
            long long ans = prefix_max[len - k] + suffix_sum[len - k + 1];
            printf("%lld ", ans);
        }
        printf("\n");
    }
    return 0;
}