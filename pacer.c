#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int len;
        long long num;
        scanf("%d %lld", &len, &num);
        
        long long arr1[len];
        int arr2[len];
        for (int i = 0; i < len; i++) {
            scanf("%lld %d", &arr1[i], &arr2[i]);
        }

        long long points = 0;
        long long prev_time = 0;
        int prev_pos = 0;

        for (int i = 0; i < len; i++) {
            long long curr_time = arr1[i];
            int curr_pos = arr2[i];

            long long diff = curr_time - prev_time;
            int delta_p = abs(curr_pos - prev_pos);
          
            if (diff < delta_p) {
                prev_time = curr_time;
                prev_pos = curr_pos;
                continue;
            }

            if ((diff % 2) == (delta_p % 2)) {
                points += diff;
            } else {
                points += diff - 1;
            }
            
            prev_time = curr_time;
            prev_pos = curr_pos;
        }

        points += (num - prev_time);
        
        printf("%lld\n", points);
    }
    return 0;
}
