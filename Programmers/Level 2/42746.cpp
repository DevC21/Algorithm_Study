#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if (n == 1 || n == 0) return 0;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) 
            return 0;
    }
    return 1;
}

char arr[8];
bool isused[8];
set<int> prime;

void func(int n, int size, string s){
    if(n == size)
        return;

    for(int i = 0; i < size; i++){
        if(!isused[i]){
            s += arr[i];
            isused[i] = true;
            if(isprime(stoi(s)))
                prime.insert(stoi(s));
            func(n + 1, size, s);
            s.pop_back();
            isused[i] = false;
        }
    }
}


int solution(string numbers) {
    int answer = 0;

    for(int i = 0; i < numbers.size(); i++)
        arr[i] = numbers[i];
    
    func(0, numbers.size(), "");

    answer = prime.size();

    return answer;
}