#include<stdio.h>

void addfront(char *arr , int *len, char item){
  for(int i=*len;i>0;i--){
    arr[i]=arr[i-1];
  }
  arr[0]=item;
  *len=*len+1;
  arr[*len]='\0';
  return;
}

void addrear(char *arr,int *len,char item){
  arr[*len]=item;
  *len=*len+1;
  arr[*len]='\0';
  return;
}

int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    int len1,len2;
    scanf("%d", &len1);
    char mainstr[100];
    scanf("%s",mainstr);
    scanf("%d",&len2);
    char words[50];
    char order[50];
    scanf("%s\n%s",words,order);
    for(int i=0;i<len2;i++){
      if(order[i]=='D'){
        addrear(mainstr,&len1,words[i]);
      }
      else{
        addfront(mainstr,&len1,words[i]);
      }
    }
    printf("%s\n",mainstr);
  }
}