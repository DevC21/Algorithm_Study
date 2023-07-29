#include<bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0;

    int tmp = n;
    int NumberOfOne = 0;
    while(tmp != 0){
        if(tmp % 2 == 1)
            NumberOfOne++;
        tmp /= 2;
    }

    int tmpOne = 0;
    tmp = n;
    while(NumberOfOne != tmpOne){
        tmpOne = 0;
        tmp++;
        int binary = tmp;
        while(binary != 0){
            if(binary % 2)
                tmpOne++;
            binary /= 2;
        }
    }

    answer = tmp;
    return answer;
}