#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        long long s;
        scanf("%d %lld", &n, &s);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int dx, dy;
            long long x, y;
            scanf("%d %d %lld %lld", &dx, &dy, &x, &y);

            long long eff_x = x;
            long long eff_y = y;

            if(x==y){
              if(x==s/2){
                ans++;
              }
              else if(dx==dy){
                ans++;
              }
            }
            else if(x+y==s){
              if(dx!=dy){
                ans++;
              }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}