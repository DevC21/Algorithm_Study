#include<bits/stdc++.h>
using namespace std;

vector<int> numbers = {1,2,3,4,6,7,8,0};

map<int, bool> number;

int solution(vector<int> numbers) {
    int answer = 0;

    for(int x : numbers){
        number[x] = true;
    }

    for(int i = 0; i <= 9; i++){
        if(number[i] == false)
            answer += i;
    }

    if(answer > 0)
        return answer;
    else
        return -1;
}

int main(){
    int ans = solution(numbers);

    return 0;
}