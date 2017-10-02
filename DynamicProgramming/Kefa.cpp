#include <iostream>

using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n]
  int dp[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    dp[i] = 1;
  }


  for(int i=0;i<n;i++){
    int t = a[i];
    for(int j=i-1;j>=0;j--){
      if(a[j]+1 == t){
        dp[i]++;
        t = a[j];
      }else{
        break;
      }
    }
    cout<<dp[i]<<" ";
  }


  return 0;
}
