#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
 
int min(int x,int y){
	return x<y?x:y;
}
int minDstXY(int a[],int n,int x,int y){
	int prev = -1;
	int i=0;
	for(i=0;i<n;i++){
		if(a[i] == x || a[i] == y){
			prev = i;
			break;
		}
	}
	i++;
	int dist = 999;
	for(;i<n;i++){
		if((a[i] == x || a[i] == y) && a[i] != a[prev]){
			dist = min(dist,abs(prev-i));
			prev = i;
		}
		else if((a[i] == x || a[i] == y)){
			prev = i;
		}
	}
	return dist;
} 


int main()
{
	int a[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
	int n = sizeof(a) / sizeof(a[0]);
	int x = 2;
	int y = 4;
	cout<<minDstXY(a,n,x,y);
	
	return 0;
}