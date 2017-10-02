#include <iostream>

using namespace std;
int a[10];
struct stack{
	int top;
	int lowHigh;
}st1,st2;

void push(stack *st,int x){
	if(st->lowHigh == 0){
		//low end
		if(a[st->top + 1] == -1){
			a[st->top + 1] = x;
			st->top++;
			cout<<"pushed "<<x<<" now top is "<<st->top<<endl;
		}else{
			cout<<"stack1 is full"<<" now top is "<<st->top<<endl;
		}
	}else{
		//high end;
		if(a[st->top - 1] == -1){
			a[st->top - 1] = x;
			st->top--;
			cout<<"pushed "<<x<<" now top is "<<st->top<<endl;
		}else{
			cout<<"stack2 is full"<<" now top is "<<st->top<<endl;
		}
	}
}

void pop(stack *st){
	if(st->top == -1 || st->top == 10){
		cout<<"stack is empty"<<endl;
	}else{
		cout<<a[(st->top)]<<endl;
		a[st->top] = -1;
		(st->top)--;
	}
}

int main() {
	// your code goes here
	
	int n = sizeof(a) / sizeof(a[0]);
	for(int i=0;i<n;i++){
		a[i] = -1;
	}
	st1.top = -1;
	st2.top = n;
	st1.lowHigh = 0;
	st2.lowHigh = 1;
	
	push(&st1,10);
	push(&st1,11);
	push(&st1,12);
	push(&st1,13);
	push(&st1,14);
	push(&st1,15);
	push(&st2,16);
	push(&st2,17);
	push(&st2,18);
	push(&st2,19);
	pop(&st1);
	pop(&st1);
	push(&st2,20);
	push(&st2,21);
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<" "<<a[i];
	}
	
	return 0;
}