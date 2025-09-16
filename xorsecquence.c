#include<stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    long long a ,b;
    scanf("%lld %lld",&a,&b);
    for(long long i=0;i<50;i++){
      if((a&(1ll << i)) != (b&(1ll << i))){
        
        printf("%lld\n",1ll <<i);
        break;

      }
    }
  }
}