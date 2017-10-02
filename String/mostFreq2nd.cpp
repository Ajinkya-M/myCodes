#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>



using namespace std;

class comp{
	public:
	bool operator()(pair<char,int> const &p1, pair<char,int> const &p2){
		return p1.second < p2.second;
	}
};

int main(){
	string s;
	int a[256] = {0};
	priority_queue< pair<char,int>, vector< pair<char,int> > ,comp> q;
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		a[s[i]]++;
		q.push(make_pair(s[i],a[s[i]]));
	}
	char f = q.top().first;
	q.pop();
	while(f == q.top().first){
		q.pop();
	}
	cout<<q.top().first<<endl;
	return 0;
}
