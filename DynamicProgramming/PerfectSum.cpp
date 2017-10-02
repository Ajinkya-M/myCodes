#include <iostream>
#include <vector>

using namespace std;

void foo(int sum,int a[],int n,std::vector<int> &v){
  if(sum == 0){
    cout<<endl;
    for(int i=0;i<v.size();i++){
      cout<<v[i]<<" ";
    }
    return;
  }
  if(n<0){
    return;
  }else{
    if(a[n-1] > sum){
      return foo(sum,a,n-1,v);
    }
    else{
      v.push_back(a[n-1]);
      foo(sum-a[n-1],a,n,v);
      v.pop_back();
      foo(sum,a,n-1,v);
      return;
    }
  }
}

int main(int argc, char const *argv[]) {
  int a[] = {2, 3, 5, 6, 8, 10};
  int sum = 10;
  int n = sizeof(a) / sizeof(a[0]);
  std::vector<int> v;
  foo(sum,a,n,v);
  return 0;
}
