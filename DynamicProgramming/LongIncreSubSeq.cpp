#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	int a[] = {10, 9, 4, 5, 4, 8, 6};
	int len = sizeof(a) / sizeof(a[0]);
	int dp[len];
	//dp init
	for(int i=0;i<len;i++){
		dp[i] = 1;
	}
	
	for(int i=1;i<len;i++){
		for(int j=0;j<i;j++){
			if(abs(a[j]-a[i]) == 1 && dp[j]+1 > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
	}
	for(int i=0;i<len;i++){
		cout << dp[i]<<" ";
	}
	
	int max = 0;
	for(int i=0;i<len;i++){
		if(dp[i] > max){
			max = dp[i];
		}
	}
	cout<<endl<<max;
	
}