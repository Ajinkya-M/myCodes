#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void copy(int a[],int b[],int n){
    //int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        b[i] = a[i];
    }
}

int count1s(int a[],int n){
    int c = 0;
    for(int i=0;i<n;i++){
        if(a[i] == 1){
            c+=1;
        }
    }
    return c;
}

void flip(int a[],int x,int y){
    for(int i=x;i<=y;i++){
        if(a[i]==1){
            a[i] = 0;
        }else{
            a[i] = 1;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        //cout<<a[i]<<" ";
    }

    int max = -999;
    int ir = -1,jr = -1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            copy(a,b,n);
            flip(b,i,j);
            int k = count1s(b,n);
            if(max < k){
                max = k;
                ir = i;
                jr = j;
            }

        }
    }

    cout<<max;
    return 0;
}
