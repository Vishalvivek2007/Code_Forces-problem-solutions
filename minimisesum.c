#include<stdio.h>
#include<stdlib.h>

int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    int len;
    scanf("%d",&len);
    int arr[len];
    for(int i=0;i<len;i++){
      scanf("%d",&arr[i]);
    }
    if(arr[0]>arr[1] ){
      arr[0]=arr[1]+arr[0];
      arr[1]=0;
    }
    else if(len!=2){
      arr[1]=arr[1]+arr[2];
      arr[2]=0;
    }
    int min=arr[0],sum=arr[0];
    for(int i=1;i<len;i++){
      if (arr[i]<min){
        min=arr[i];
      }
      sum+=min;
    }
    printf("%d\n",sum);
  }
}