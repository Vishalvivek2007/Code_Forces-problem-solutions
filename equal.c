#include <stdio.h>
#include <stdlib.h>


int min(int a, int b) {
    return a < b ? a : b;
}


int compare(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    if (int_a == int_b) return 0;
    else if (int_a < int_b) return -1;
    else return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        long long k;
        scanf("%d %lld", &n, &k);

        int *s_ids = (int*)malloc(n * sizeof(int));
        int *t_ids = (int*)malloc(n * sizeof(int));

        
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            int remainder = val % k;
            s_ids[i] = min(remainder, k - remainder);
        }

        
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            int remainder = val % k;
            t_ids[i] = min(remainder, k - remainder);
        }

        
        qsort(s_ids, n, sizeof(int), compare);
        qsort(t_ids, n, sizeof(int), compare);

        
        int possible = 1; 
        for (int i = 0; i < n; i++) {
            if (s_ids[i] != t_ids[i]) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
        free(s_ids);
        free(t_ids);
    }
    return 0;
}