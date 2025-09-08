#include<stdio.h>

void merge(long long *arr1,long long*arr2,long long *arr,long long len){
  long long middle=len/2;
  long long i=0,l=0,r=0;
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

void mergsort(long long *arr,long long len){
  if(len<=1){
    return;
  }
  long long middle=len/2;
  long long left[middle];
  long long right[len-middle];
  long long i=0,j=0;
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
    long long len, k,esum=-1,check=0,count=0;
    scanf("%lld %lld",&len,&k);
    long long arr1[len];
    long long arr2[len];
    for(long long i=0;i<len;i++){
      scanf("%lld",&arr1[i]);
    }
    for(long long i=0;i<len;i++){
      scanf("%lld",&arr2[i]);
      if(arr2[i]!=-1){
        if(esum==-1){
          esum=arr2[i]+arr1[i];
        }
        else if(esum!=arr2[i]+arr1[i]){
          check=-1;
        }
      }
      else{
        count++;
      }
    }
    mergsort(arr1,len);
    if(count==len){
      printf("%lld\n",k-arr1[len-1]+arr1[0]+1);
    }
    else{
      if(check==-1){
        printf("0\n");
      }
      else{
        if(arr1[len-1]>esum || arr1[0]+k<esum){
          printf("0\n");
        }
        else{
          printf("1\n");
        }
      }
    }
  }
}