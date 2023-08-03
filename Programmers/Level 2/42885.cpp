#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    // 오름차순 정렬
    sort(people.begin(), people.end());

    int start = 0;
    int end = people.size() - 1;

    while(start <= end){
        // start와 end가 같다는 것은 혼자 남았다는 뜻이다.
        // answer에 1을 더해주고 while 문을 빠져나간다.
        if(start == end){
            answer++;
            break;
        }
        // 남아있는 사람중에 제일 가벼운 사람과 제일 무거운 사람이 무게 제한에 걸리지 않으면
        // 두 사람이 타고 나갈 수 있다.
        else if(people[start] + people[end] <= limit){
            start++;
            end--;
            answer++;
        }
        // 남아있는 사람중에 제일 가벼운 사람과 제일 무거운 사람이 무게 제한을 넘으면
        // 제일 무거운 사람은 무조건 혼자서 타고 나가야 한다.
        else if(people[start] + people[end] > limit){
            end--;
            answer++;
        }
    }

    return answer;
}