#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
void printGraph(vector<vector<pair<int,int> > > &g, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j].first<<" ";
        }
        cout<<endl;
    }
}
int min(int a, int b){
    return a<b?a:b;
}

int pick(int a[],bool b[],int n,int parentDist[]){
    int min = 99999;
    int ind = -1;
    for(int i=0;i<n;i++){
        if(b[i]==false && a[i]<min){
            min = a[i];
            ind = i;
        }
    }
    parentDist[ind] = min;
    return ind;
}
int Dijkstras(vector<vector<pair<int,int> > > &g, int a[], int n, int S,int D){
    bool mst[n];
    for(int i=0;i<n;i++){
        mst[i] = false;
    }
    mst[S-1] = true;
    int key[n];
    for(int i=0;i<n;i++){
        key[i] = 99999;
    }
    key[S-1] = 0;
    int parentDist[n];
    for(int i=0;i<n;i++){
        parentDist[i] = 0;
    }
    int piv = S-1;
    while(piv != -1){
        //vector<pair<int,int> v = g[piv];
        for(int i=0;i<g[piv].size();i++){
            if(key[g[piv][i].first-1] == 9999){
                key[g[piv][i].first-1] = g[piv][i].second;
            }else{
                key[g[piv][i].first-1] = min(key[g[piv][i].first-1],parentDist[g[piv][i].first-1]|g[piv][i].second );
            }
        }
        /*
        for(int i=0;i<n;i++){
            cout<<key[i]<<" ";
        }
        cout<<endl;
        */
        piv = pick(key,mst,n,parentDist);
        mst[piv] = true;
    }
    return key[D-1];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int> > > g(n);
    int u,v,c;
    for(int i=0;i<m;i++){
        cin>>u>>v>>c;
        g[u-1].push_back(make_pair(v,c));
    }
    int A,B;
    cin>>A>>B;
    //printGraph(g,n);
    int a[n];
    cout<<Dijkstras(g,a,n,A,B);
    
    
    
    return 0;
    
}