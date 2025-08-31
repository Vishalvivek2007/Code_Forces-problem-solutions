#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        char s[n + 1];
        scanf("%s", s);
        int count_0 = 0;
        int count_1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                count_0++;
            } else {
                count_1++;
            }
        }
        int nm = max(count_0, count_1) - n / 2;
        if (k >= nm  && (k - nm) % 2 == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}