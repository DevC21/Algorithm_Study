#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> slice_1;
    map<int, int> slice_2;
    for(auto x : topping)
        slice_2[x]++;

    // 처음에는 map의 원소들을 모두 돌면서 0 보다 크면 토핑의 개수를 카운트하는 풀이를 했으나 시간초과
    for (int i = 0; i < topping.size() - 1; i++) {
        // slice_1은 원소를 삭제할 일이 없으므로 set으로 해도 무방하다
        slice_1[topping[i]]++;
        slice_2[topping[i]]--;
        // slice_2에서 0이 되는 원소를 삭제한다.
        if(slice_2[topping[i]] == 0)
            slice_2.erase(topping[i]);
        // slice_1와 slice_2의 크기만 비교하면 토핑의 개수를 카운트할 수 있다.
        if(slice_1.size() == slice_2.size()) 
            answer++;
    }

    return answer;
}