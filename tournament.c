#include<stdio.h>
#include<stdlib.h>

void merge(int *arr1,int*arr2,int *arr,int len){
  int middle=len/2;
  int i=0,l=0,r=0;
  while(l<middle && r<len-middle){
    if(arr1[l]<arr2[r]){
      arr[i]=arr1[l];
      i++;
      l++;
    }
    else{
      arr[i]=arr2[r];
      i++;
      r++;
    }
  }
  while(l<middle){
    arr[i]=arr1[l];
    i++;
    l++;
  }
  while(r<len-middle){
    arr[i]=arr2[r];
    i++;
    r++;
  }
}

void mergsort(int *arr,int len){
  if(len<=1){
    return;
  }
  int middle=len/2;
  int left[middle];
  int right[len-middle];
  int i=0,j=0;
  for(;i<len;i++){
    if(i<middle){
      left[i]=arr[i];
    }
    else{
      right[j]=arr[i];
      j++;
    }
  }
  mergsort(left,middle);
  mergsort(right,len-middle);
  merge(left,right,arr,len);
}

int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    int len, index, len2,temp=0;
    scanf("%d %d %d",&len,&index,&len2);
    int arr[len];
    for(int i=0;i<len;i++){
      scanf("%d",&arr[i]);
    }
    temp=arr[index-1];
    mergsort(arr,len);
    if(len2==1){
      if(arr[len-1]==temp){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
    else{
      printf("YES\n");
    }

  }
}