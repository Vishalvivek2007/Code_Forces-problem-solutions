#include <stdio.h>
#include <string.h>



int main() {
    int q;
    scanf("%d", &q);  

    while (q--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        char s[n];
        scanf("%s", s);

        int ans = 0;  
        int cnt = 0;  

         
        for (int i = 0; i < n; ++i) {
            
             
            if (s[i] == '0') {
                cnt++;
            } else {
                 
                cnt = 0;
            }

             
             
            if (cnt >= m) {
                ans++;  

                 
                 
                 
                 
                for (int j = i; j < i + k && j < n; ++j) {
                    s[j] = '1';
                }

                 
                 
                cnt = 0;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}