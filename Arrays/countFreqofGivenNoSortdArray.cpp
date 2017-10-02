#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
int first(int a[],int low,int high,int x){
	int mid;
	if(low < high){
		mid = (low + high) / 2;
		if((mid == 0 || a[mid-1] < x)&& a[mid] == x){
			return mid;
		}
		if(a[mid]>=x){
			return first(a,low,mid-1,x);
		}
		else return first(a,mid+1,high,x);
	}
	return high;
}

int last(int a[],int low,int high,int x,int n){
	int mid;
	//cout<<low<< " " << high;
	if(low<high){
		mid = (low+high) / 2;
		//cout<< " "<<mid<<" elem at a[mid+1] is "<<a[mid+1] <<" X is "<<x<<endl;
		if((mid == n-1 || a[mid+1] > x) && a[mid] == x){
			return mid;
		}
		if(a[mid]>x){
			return last(a,low,mid-1,x,n);
		}
		else return last(a,mid+1,high,x,n);
	}
	return high;
}


int mBS(int a[],int low,int high,int x,int n){
	int i,j;
	i = first(a,low,high,x);
	cout<<"first is "<<i<<endl;
	j = last(a,i,high,x,n);
	return j;
}

int main()
{
	int a[] = {1, 1, 2, 2, 2, 2, 3,};
	int n = sizeof(a) / sizeof(a[0]);
	int x = 1;
	cout<<mBS(a,0,n-1,x,n);
	
	return 0;
}