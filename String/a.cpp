#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	//cout<<s;
	int a[256] = {0};
	for(int i=0;i<s.length();i++){
		if(a[s[i]] == 0){
			cout<<s[i];
			a[s[i]] = 1;
		}else{
			continue;
		}
	}
	return 0;
}
