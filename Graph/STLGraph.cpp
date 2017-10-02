#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
void addEdge(std::vector<int> adj[],int src,int dest){
  adj[src].push_back(dest);
  adj[dest].push_back(src);
  return;
}

void printGraph(std::vector<int> adj[],int v){
  for(int i=0;i<v;i++){
    cout<<"adj to "<<i<<endl;
    for(int j=0;j<adj[i].size();j++){
      cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }
}
//******************************BFS********************************************
void BFS(std::vector<int> adj[],int v){
  int st = v;
  queue<int> Q;
  vector<bool> visited(5,false);
  visited[st] = true;
  Q.push(st);
  int s;
  while(!Q.empty()){
    s = Q.size();
    cout<<endl;
    while(s){
      st = Q.front();
      Q.pop();
      cout<<st<<" ";
      std::vector<int> ::iterator it = adj[st].begin();
      while(it != adj[st].end()){
        if(visited[*it] != true){
          visited[*it] = true;
          Q.push(*it);
        }
        it++;
      }
      s--;
    }
  }
}
//**************************************************************************
//**************************** DFS **********************************************
void DFSUtil(int v,std::vector<bool> &visited,std::vector<int> adj[]){
  visited[v] = true;
  cout<<v<<" ";
  std::vector<int> ::iterator it;
  for(it=adj[v].begin();it!=adj[v].end();it++){

    if(!visited[*it]){
      DFSUtil(*it,visited,adj);
    }
  }

}

void DFS(vector<int> adj[],int v){
  int st = v;
  vector<bool> visited(5,false);
  DFSUtil(st,visited,adj);

}
//**************************************************************************

void DFSitr(std::vector<int> adj[],int v){
  std::vector<bool> visited(5,false);
  std::vector<int> ::iterator it;
  stack<int> st;
  st.push(v);
  cout<<v<<" ";
  visited[v] = true;
  int curr;
  while(!st.empty()){
    curr = st.top();
    st.pop();
    it = adj[curr].begin();
    for(;it!=adj[curr].end();it++){
      if(visited[*it] != true){
        st.push(*it);
        cout<<*it<<" ";
        visited[*it] = true;
        break;
      }
    }

  }
}



int main(){
  int v = 5;
  std::vector<int> adj[v];
  addEdge(adj,0,1);
  addEdge(adj,0,4);
  addEdge(adj,1,4);
  addEdge(adj,1,3);
  addEdge(adj,1,2);
  addEdge(adj,2,3);
  addEdge(adj,3,4);

  //printGraph(adj,v);
  //BFS(adj,4);
  //DFS(adj,1);
  return 0;

}
