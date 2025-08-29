#include<stdio.h>
#include<stdlib.h>

int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    int len,time,start=0,check=0;
    scanf("%d %d",&len,&time);
    int *arr = malloc(len*sizeof(int));
    for(int i=0;i<len;i++){
      scanf("%d",&arr[i]);
    }
    for(int i=0;i<len;i++){
      if(arr[i]==0 && start==0){
        continue;
      }
      else{
        if(start<time){
          start++;
        }
        else{
          if(arr[i]==0){
            continue;
          }
          else{
            if(check!=1){
              printf("NO\n");
              check=1;
            }
          }
        }
      }
    }
    if(check==0){
      printf("YES\n");
    }
    free(arr);
  }
}
