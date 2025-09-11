#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
      int len;
      scanf("%d",&len);
      int arr[len];
      for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
      }
      int *ptr1=&arr[0];
      int *ptr2=&arr[0];
      int index1=0,index2=0,count=0;
      while(index1<len){
        if(index2==len-1){
          if(index1==0){
            count++;
            break;
          }
          else if(*(ptr1+index1-1)>*(ptr1+index1)){
            count++;
            break;
          }
          else{
            break;
          }
        }
        if(*(ptr2+index2+1)==*(ptr2+index2)){
          index2++;
          continue;
        }
        if(*(ptr2+index2+1)>*(ptr2+index2)){
          if(index1==0){
            count++;
            index2++;
            index1=index2;
          }
          else if(*(ptr1+index1-1)>*(ptr1+index1)){
            count++;
            index2++;
            index1=index2;
          }
          else{
            index2++;
            index1=index2;
          }
        }
        else{
          index2++;
          index1=index2;
        }
      }
      if(count==1){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
    return 0;
}