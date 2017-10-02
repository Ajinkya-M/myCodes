#include <iostream>
#include <vector>
#include <string>
using namespace std;

int max(int a,int b){
  return a>b?a:b;
}

int foo(string s,int l,int r){
  if(r == l){
    return 1;
  }
  if(l+1 == r && s[l] == s[r]){
    return 2;
  }
  else{
    if(s[l] == s[r]){
      return (2+foo(s,l+1,r-1));
    }else{
      return max((foo(s,l+1,r)),(foo(s,l,r-1)));
    }
  }

}
int main(){

  string s;
  cin>>s;
  int n = s.length();
  cout<<foo(s,0,n-1);
}
