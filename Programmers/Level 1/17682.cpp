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

        // char�� �Ź� �� ������ �ʱ�ȭ������ ������ 
        // ���� ���� �״�� �������� ������ �߻���
        // ���� 9, 12��
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
        // dartResult�� ������ �Ѿ�� �ε����� �������� �ʰ� �ϴ� �ڵ�
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