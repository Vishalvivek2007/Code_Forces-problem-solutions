#include <stdio.h>

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
      int n,m,check=0,count=0;
      scanf("%d %d",&n,&m);
      int arr[n+1][m+1];
      for(int i=0;i<n;i++){
        check=0,count=0;
        for(int j=0;j<m;j++){
          scanf("%1d",&arr[i][j]);
          if(arr[i][j]==1 && check==0){
            count++;
          }
          else{
            check=1;
          }
        }
        arr[i][m]=count;
      }
      for(int i=0;i<m;i++){
        check=0,count=0;
        for(int j=0;j<n;j++){
          if(arr[j][i]==1 && check==0){
            count++;
          }
          else{
            check=1;
          }
        }
        arr[n][i]=count;
      }
      check=1;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(arr[i][j]==0){
            continue;
          }
          else{
            if(j<=arr[i][m]||i<=arr[n][j]){
              continue;
            }
            else{
              check=0;
            }
          }
        }
      }
      if(check==0){
        printf("NO\n");
      }
      else{
        printf("Yes\n");
      }

  }
  return 0;
}