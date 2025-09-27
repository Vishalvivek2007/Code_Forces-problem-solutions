#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
      int arr[101][3],sum=0;
      int len;
      scanf("%d",&len);
      int arr2[101];
      for(int i=0;i<101;i++){
        arr[i][0]=0;
        arr[i][1]=0;
        arr[i][2]=0;
      }
      for(int i=0;i<len;i++){
        scanf("%d",&arr2[i]);
        arr[arr2[i]][0]+=1;
        if(arr[arr2[i]][0]==2){
          sum++;
        }
      }
      int check=0;
      for(int i=0;i<101;i++){
        if(arr[i][0]>1){
          arr[i][2]=check;
          if(check==0){
            check=1;
          }
          else{
            check=0;
          }
        }
      }
      if(sum<2){
        printf("-1\n");
        goto here;
      }
      for(int i=0;i<len;i++){
        if(arr[arr2[i]][0]==1){
          printf("1 ");
        }
        else{
          if(arr[arr2[i]][2]==0){
            if(arr[arr2[i]][1]%2==0){
              printf("1 ");
            }
            else{
              printf("2 ");
            }
            arr[arr2[i]][1]++;
          }
          else{
            if(arr[arr2[i]][1]%2==0){
              printf("1 ");
            }
            else{
              printf("3 ");
            }
            arr[arr2[i]][1]++;
          }
        }
      }
      printf("\n");
      here:
      continue;
    }
    return 0;
}