#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

string makePostfix(string in){
    stack <char> s;
    string str = in;
    int n = str.length();
    int i=0;
    string op="";
    while(i<n){
        if(str[i] == '('){
            s.push(str[i]);
            i++;
            continue;
        }
        if(str[i] == '*' || str[i] == '/'){
            if(!s.empty() && (s.top() == '*' || s.top() == '/')){
              op += s.top();
              s.pop();
              continue;
            }else{
                s.push(str[i]);
                i++;
                continue;
            }
        }else if(str[i] == '+' ||  str[i] == '-'){
            if(!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')){
                op += s.top();
                s.pop();
                continue;
            }else{
                s.push(str[i]);
                i++;
            }
        }else if(str[i] == ')'){
            while( !s.empty() && (s.top() != '(')){
                op += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }else{
            op += str[i];
            i++;
        }
    }
    while(!s.empty()){
        op += s.top();
        s.pop();
    }
    return op;
}



float evalPostfix(string in){
    stack <float> s;
    string str = in;
    float op1,op2,result = 0;
    int n = str.length();
    char oprnd;
    int i=0;
    while(i<n){
        //cout<<"str[i] = "<<str[i]<<endl;
        if(str[i] >='0' && str[i] <= '9'){
            s.push(str[i]-'0');
            i++;
            continue;
        }
        else{
            if(!s.empty()){
                op2 = s.top();
                s.pop();
            }else{
                //cout<<"1"<<endl;
                return -9999;
            }
            if(!s.empty()){
                op1 = s.top();
                s.pop();
            }else{
                //cout<<"2"<<endl;
                return -9999;
            }
            oprnd = str[i];
            //cout<<op1<<str[i]<<op2<<" = ";
            switch(oprnd){
                    case '+':result = float(op1) + float(op2);
                    break;
                    case '-':result = float(op1) - float(op2);
                    break;
                    case '*':result = float(op1) * float(op2);
                    break;
                    case '/':if(op2 == 0) return -9999;
                             else result = float(op1) / float(op2);
                             break;
                    default : //cout<<"3"<<endl;
                              return -9999;
            }
            i++;
            //cout<<result<<endl;
            s.push(result);
        }
    }
    
    return s.top();
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    getline(cin,s);
    stringstream ss(s);
    string tok,in;
    while(ss>>tok){
        in += tok;
    }
    stack<char> st;
    int n = in.length();
     
    for(int i=1 ;i<n  ;i++ ){
        if(in[i] == '-' && in[i-1] == '('){
            in.insert(i,"0");
        }
    }
    string postfix = makePostfix(in);
    //cout<<postfix<<endl;
    
    float val = evalPostfix(postfix);
    if(val != -9999)
        cout<<val<<endl;
    else{
        cout<<"ERROR"<<endl;
    }
    return 0;
}
