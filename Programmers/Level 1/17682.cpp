#include<bits/stdc++.h>
using namespace std;

int solution(string dartResult) {
    int answer = 0;

    string curS = "";
    int pre = 0;
    int cur = 0;

    for(int i = 0; i < dartResult.size(); i++){
        if(isdigit(dartResult[i])){
            curS += dartResult[i];
            if(isdigit(dartResult[i + 1])){
                curS += dartResult[i + 1];
                i++;
            }
            continue;
        }

        // char를 매번 빈 값으로 초기화해주지 않으면 
        // 이전 값을 그대로 가져가서 오류가 발생함
        // 테케 9, 12번
        char bonus = ' ';
        char option = ' ';

        if(isdigit(dartResult[i + 1])){
            bonus = dartResult[i];
        }
        else if(!isdigit(dartResult[i + 1])){
            bonus = dartResult[i];
            option = dartResult[i + 1];
            i++;
        }
        // dartResult의 범위를 넘어가는 인덱스에 접근하지 않게 하는 코드
        // if(i + 1 < dartResult.size()){
        //     if(isdigit(dartResult[i + 1])){
        //         bonus = dartResult[i];
        //     }
        //     else if(!isdigit(dartResult[i + 1])){
        //         bonus = dartResult[i];
        //         option = dartResult[i + 1];
        //         i++;
        //     }
        // }
        // else if(i + 1 >= dartResult.size()){
        //     bonus = dartResult[i];
        // }


        if(bonus == 'S')
            cur += stoi(curS);
        else if(bonus == 'D')
            cur += pow(stoi(curS), 2);
        else if(bonus == 'T')
            cur += pow(stoi(curS), 3);

        if(option == '*'){
            pre *= 2;
            cur *= 2;
        }
        else if(option == '#'){
            cur *= -1;
        }

        curS = "";
        answer += pre;
        pre = cur;
        cur = 0;
    }
    answer += pre;

    return answer;
}