#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct adjListnode{
  int dest;
  struct adjListnode *next;
}adjListnode;

typedef struct adjList{
  adjListnode *head;
}adjList;

typedef struct graph{
  int v;
  adjList *arr;
}Graph;

adjListnode* getNode(int dest){
  adjListnode *n = (adjListnode*)malloc(sizeof(adjListnode));
  n->dest = dest;
  n->next = NULL;
  return n;
}

Graph* createGraph(int v){
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->v = v;
  g->arr = (adjList *)malloc(sizeof(adjList) * v);
  for(int i=0;i<v;i++){
    g->arr[i].head = NULL;
  }
  return g;
}

void addEdge(Graph *g,int src,int dest){
  //add dest to src
  adjListnode *n = getNode(dest);
  n->next = g->arr[src].head;
  g->arr[src].head = n;

  //add src to dest also
  n = getNode(src);
  n->next = g->arr[dest].head;
  g->arr[dest].head = n;

}

void printGraph(Graph *g){
  int v = g->v;
  adjListnode *p;
  for(int i=0;i<v;i++){
    p = g->arr[i].head;
    cout<<"adj nodes of "<<i<<endl;
    while(p){
      cout<<p->dest<<" ";
      p = p->next;
    }
    cout<<endl;
  }
}

int main(){
  int v = 5;
  Graph *g = createGraph(v);
  //cout<<g->v;
  addEdge(g,0,1);
  //addEdge(g,0,4);
  addEdge(g,1,2);
  //addEdge(g,1,4);
  addEdge(g,1,3);
  addEdge(g,2,3);
  //addEdge(g,3,4);

  printGraph(g);
  return 0;
}
