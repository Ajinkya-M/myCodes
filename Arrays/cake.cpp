#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;



static int max_val = 0;
static int cnt = 0;
void foo(int n){
    if(n == 0){
        return;
    }
    int x;
    cin>>x;
    foo(n-1);
    if(max_val <= x){
        max_val = x;
        cnt++;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    foo(n);
    cout<<cnt<<endl;
    return 0;
}



/*
int main() {
    
    
    long int n;
    cin>>n;
    long int a;
    long int max = INT_MIN;
    long int cnt = 0;
    for(long int i=0;i<n;i++){
        cin>>a;
        if(max <= a){
            max = a;
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}
*/
