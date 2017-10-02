#include<iostream>
#include <stdlib.h>
using namespace std;

int main(){
  int a[]={1,2,3,2,3,7,2,1};
  int n = sizeof(a) / sizeof(a[0]);
  int dp[n];

  for(int i=0;i<n;i++){
    dp[i] = 1;
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(abs(a[j]-a[i]) == 1 && dp[j]+1 > dp[i]){
        dp[i] = dp[j] + 1;
      }
    }
  }

  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    cout<<dp[i]<<" ";
  }
}
