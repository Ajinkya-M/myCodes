#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;
int size = 0;
map<pair<int,int>,int> mp;
int foo(int k,int a[],int n,vector<int> &v){
  if(mp.find(make_pair(k,n))!=mp.end()){
    return mp[make_pair(k,n)];
  }
  if(k == 0){
    mp[make_pair(k,n)] = v.size();
    return v.size();
  }
  if(n == 0){
    return 0;
  }
  int l=0,m=0,p=0;
  if(a[n-1] > k){
    l = foo(k,a,n-1,v);
  }else{
    v.push_back(a[n-1]);
    m = foo(k-a[n-1],a,n,v);
    v.pop_back();
    p = foo(k,a,n-1,v);
  }
  mp[make_pair(k,n)] = max(max(l,m),p);
  return mp[make_pair(k,n)];
}

int main(){
  int k;
  cin>>k;
  int a[3];
  for(int i=0;i<3;i++){
    cin>>a[i];
  }
  std::vector<int> v;
  cout<<foo(k,a,3,v);
  //cout<<size;
}
