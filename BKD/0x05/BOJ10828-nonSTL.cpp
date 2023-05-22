#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;
int dat[MX];
int pos = 0;

void push(int n){
    dat[pos++] = n;
}

int pop(){
    if(pos > 0){
        int num = dat[pos-1]; 
        pos--;
        return num;
    }
    else{
        return -1;
    }
}

int top(){
    if(pos > 0){
        return dat[pos-1];
    }
    else{
        return -1;
    }
}

int size(){
    return pos;
}

int empty(){
    if(pos == 0)
        return 1;
    else{
        return 1;
    }
}

int main(void){
    int n, x;

    string s;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "push"){
            cin >> x;;
            push(x);
        }
        else if(s == "pop"){
            cout << pop() << '\n';
        }
        else if(s == "top"){
            cout << top() << '\n';
        }
        else if(s == "size"){
            cout << size() << '\n';
        }
        else if(s == "empty"){
            cout << empty() << '\n';
        }
    }
}