#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node{
  int data;
  struct node *left,*right;
}node;

typedef struct tree{
  struct node *root;
}tree;

int max(int a,int b){
  return a>b?a:b;
}

node* getNode(int data){
  node *p = (node*)malloc(sizeof(node));
  p->data = data;
  p->left = NULL;
  p->right = NULL;
  return p;
}
int findHeight(node *root){
  if(root == NULL){
    return 0;
  }
  int lh = findHeight(root->left);
  int rh = findHeight(root->right);
  return max(lh,rh) +1;
}
void printLevel(node *root,int l){
  if(root == NULL){
    return;
  }
  if( l == 1){
    cout<<root->data<<" ";
    return;
  }else{
    printLevel(root->left,l-1);
    printLevel(root->right,l-1);
    return;
  }

}

void BFS(tree t){
  int h = findHeight(t.root);
  for(int i=1;i<=h;i++){
    printLevel(t.root,i);
  }
}
void Inord(node *root){
  if(root == NULL){
    return;
  }else{
    Inord(root->left);
    cout<<root->data<<" ";
    Inord(root->right);
    return;
  }
}
void Preord(node *root){
  if(root == NULL){
    return;
  }else{
    cout<<root->data<<" ";
    Preord(root->left);
    Preord(root->right);
    return;
  }
}

void Postord(node *root){
  if(root == NULL){
    return;
  }else{
    Postord(root->left);
    Postord(root->right);
    cout<<root->data<<" ";
    return;
  }
}

int size(node *root){
  if(root == NULL){
    return 0;
  }else{
    int ls = size(root->left);
    int rs = size(root->right);
    return ls + rs + 1;
  }
}

bool pathsum(node *root,int sum){
  if(root == NULL){
    return (sum==0);
  }else{
    int subsum = sum - root->data;
    return pathsum(root->left,subsum) || pathsum(root->right,subsum);
  }
}
void printLeftViewbyLevel(node *root,int l,int *flag){
  if(root == NULL){
    return;
  }
  if(*flag == 0){
    if(l == 1){
      *flag = 1;
      cout<<root->data<<" ";
      return;
    }else{
      printLeftViewbyLevel(root->left,l-1,flag);
      printLeftViewbyLevel(root->right,l-1,flag);
      return;
    }
  }

}

void printLeftView(node *root){
  int h = findHeight(root);
  int flag = 0;
  for(int i=1;i<=h;i++){
    flag = 0;
    printLeftViewbyLevel(root,i,&flag);
  }
}

bool isBalanced(node *root){
  if(root == NULL){
    return true;
  }
  else{
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    if(abs(lh-rh)<=1){
      return isBalanced(root->left) && isBalanced(root->right);
    }else{
      return false;
    }
  }
}

int diameterofTree(node *root){
  if(root == NULL){
    return 0;
  }else{
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    return max(max(diameterofTree(root->left),diameterofTree(root->right)),lh+rh+1);
  }
}
int Search(int a[],int x,int n){
    for(int i=0;i<n;i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}



void printPost(int in[],int pre[],int n){
    int root = Search(in,pre[0],n);

    if(root != 0){
        printPost(in,pre+1,root);
    }

    if(root != n-1){
        printPost(in+root+1,pre+root+1,n-root-1);
    }
    cout<<pre[0]<<" ";
}

void printPre(int in[],int post[],int n){
    int root =Search(in,post[n-1],n);
    if(root == -1){
        return;
    }
    cout<<post[n-1]<<" ";
    if(root != 0){
        printPre(in,post,root);
    }
    if(root != n-1){
        printPre(in+root+1,post+root,n-root-1);
    }
    return;
}

void printCurrPath(int a[],int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

void printpath(node *root,int path[],int pathlen){
    if(root != NULL){
        path[pathlen] = root->data;
        pathlen++;
    }
    if(root->left != NULL){
        printpath(root->left,path,pathlen);
    }
    if(root->right != NULL){
        printpath(root->right,path,pathlen);
    }
    if(root->left == NULL && root->right == NULL){
        printCurrPath(path,pathlen);
        return;
    }
    return;
}

void printAllpaths(node *root){
    int path[findHeight(root)];
    printpath(root,path,0);
}

node* createTree(int in[],int pre[],int inst,int inend){
    static int preInd = 0;

    if(inst>inend)
        return NULL;
    node *tnode = getNode(pre[preInd++]);

    if(inst == inend)
        return tnode;
    int inIndex = Search(in,tnode->data,inend+1);
    if(inIndex != 0){
        tnode->left = createTree(in,pre,inst,inIndex-1);
    }
    if(inIndex != inend){
        tnode->right = createTree(in,pre,inIndex+1,inend);
    }
    return tnode;
}

int main(){
    tree t;
    t.root = getNode(1);
    t.root->left = getNode(2);
    t.root->left->left = getNode(3);
    t.root->left->right = getNode(4);
    t.root->left->right->left = getNode(5);
    t.root->right = getNode(6);
    t.root->right->right = getNode(7);
    //cout<<findHeight(t.root);
    //BFS(t);
    //printLeftView(t.root);
    //Inord(t.root);
    //Preord(t.root);
    //Postord(t.root);
    //cout<<size(t.root);
    //printLeftView(t.root);
    /*
    if(isBalanced(t.root)){
      cout<<"balanced";
    }else{
      cout<<"Not Balanced";
    }
    */
    //cout<<diameterofTree(t.root);
    int in[] = {3,2,5,4,1,6,7};
    int pre[] = {1,2,3,4,5,6,7};
    int post[] = {3,5,4,2,7,6,1};
    //printPost(in,pre,size(t.root));
    //printPre(in,post,7);

    //printAllpaths(t.root);
    t.root = createTree(in,pre,0,6);
    Inord(t.root);
    Preord(t.root);
    Postord(t.root);
    BFS(t);

}
