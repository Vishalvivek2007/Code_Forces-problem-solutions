#include<stdio.h>
#include<stdlib.h>


int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    int len,x;
    scanf("%d %d",&len,&x);
    int *arr = (int*)calloc(len , sizeof(int));
    for(int i=0;i<len;i++){
        *(arr+i)=i;
        if(x==len){
            printf("%d ",*(arr+i));
            continue;
        }
        if(*(arr+i)!=x){
            printf("%d ",*(arr+i));
        }
        if(i==len-1){
            printf("%d ",x);
        }
    }
    printf("\n");
  }
}