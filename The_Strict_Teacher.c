#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
      long long  len,m,q,temp;
      long long p1,p2,david;
      scanf("%lld %lld %lld",&len,&m,&q);
      scanf("%lld %lld",&p1,&p2);
      scanf("%lld",&david);

      if(p1>p2){
        temp=p1;
        p1=p2;
        p2=temp;
      }
      if(david<p1){
        printf("%lld\n",p1-1);
      }
      else if(david>p1 && david <p2){
        temp = p2-p1;
        printf("%lld\n",temp/2);
      }
      else {
        printf("%lld\n",len-p2);
      }
    }
    return 0;
}