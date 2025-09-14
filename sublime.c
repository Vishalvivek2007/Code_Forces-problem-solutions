#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
      int len,num;
      scanf("%d %d",&num,&len);
      if(len%2==0){
        printf("0\n");
      }
      else{
        printf("%d\n",num); 
      }
    }
    return 0;
}