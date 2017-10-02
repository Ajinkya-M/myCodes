#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>

using namespace std;
typedef struct node{
  int data;
  struct node *left,*right;
}Node;

typedef struct tree{
  Node *root;
}Tree;

Node* getNode(int data){
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = data;
  p->left = p->right = NULL;
  return p;
}

void inordTrav(Node *root){
  if(root == NULL){
    return;
  }else{
    inordTrav(root->left);
    cout<<root->data<<" ";
    inordTrav(root->right);
    return;
  }
}

void preordTrav(Node *root){
  if(root == NULL){
    return;
  }else{
    cout<<root->data<<" ";
    preordTrav(root->left);
    preordTrav(root->right);
    return;
  }
}

void postordTrav(Node *root){
  if(root == NULL){
    return;
  }else{
    postordTrav(root->left);
    postordTrav(root->right);
    cout<<root->data<<" ";
    return;
  }
}

int findHeight(node *root){
  if(root == NULL){
    return 0;
  }else{
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    if(lh > rh){
      return (lh + 1);
    }else{
      return (rh + 1);
    }
  }
}

static int flag_left_view = 0;

void printLevel(node *root,int d){
  if(root == NULL){
    return;
  }
  if(flag_left_view == 0){
    if(d == 1){
      //flag_left_view = 1;
      cout<<root->data<<" ";
    }else{
      printLevel(root->left,d-1);
      printLevel(root->right,d-1);
    }
  }
  return;

}

void printLevelOrd(node *root){
  int h = findHeight(root);
  for(int i=1;i<=h;i++){
    //flag_left_view = 0;//left view
    cout<<endl;
    printLevel(root,i);
  }
}

//static int size = 0;
int sizeofTree(node *root){
  if(root == NULL){
    return 0;
  }else{
    int l = sizeofTree(root->left);
    //cout<<root->data<<" ";

    int r = sizeofTree(root->right);
    return l+r+1;
  }
}


void printLevelOrdQueue(node *root){
  queue<node *> Q;
  if(root == NULL){
    return;
  }else{
    Q.push(root);
    node *curr;
    while(!Q.empty()){
      curr = Q.front();
      cout<<curr->data<<" ";
      if(curr->left){
        Q.push(curr->left);
      }
      if(curr->right){
        Q.push(curr->right);
      }
      Q.pop();
    }
  }
}
int iterativeHeight(node *root){
	if(root == NULL){
		return 0;
	}
	queue<node *> Q;
	Q.push(root);
	node *curr;
	int height = 0;
	while(!Q.empty()){
		height++;
		int cnt = Q.size();
		while(cnt){
			curr = Q.front();
			cout<<curr->data<<" ";
			if(curr->left){
				Q.push(curr->left);
			}
			if(curr->right){
				Q.push(curr->right);
			}
			Q.pop();
			cnt--;
		}
		cout<<endl;//after each level
	}
	return height;
}

void printStack(stack<node *> &s){
	if(!s.empty()){
	node* p = s.top();
	s.pop();
	cout<<p->data<< " ";
	printStack(s);
	s.push(p);
	}
}


void InorderStack(node *root){
	if(root == NULL){
		return;
	}
	node *curr;
	stack<node *> s;
	s.push(root);
	curr = s.top();
	while(!s.empty()){
		cout<<endl;
		printStack(s);
		while(curr->left){
			s.push(curr->left);
			curr=curr->left;
		}
		curr = s.top();
		s.pop();
		//cout<<curr->data<< " ";
		if(curr->right){
			curr=curr->right;
			s.push(curr);
		} 
	}
}

int main() {
  Tree t;
  Node *root;
  root = getNode(12);
  root->left = getNode(10);
  root->left->left = getNode(11);
  //root->left->right = getNode(13);
  root->right = getNode(30);
  root->right->left = getNode(25);
  root->right->right = getNode(40);
  
  //cout<<iterativeHeight(root);
  InorderStack(root);

  return 0;
}
