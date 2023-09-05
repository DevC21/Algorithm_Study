#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> slice_1;
    map<int, int> slice_2;
    for(auto x : topping)
        slice_2[x]++;

    // ó������ map�� ���ҵ��� ��� ���鼭 0 ���� ũ�� ������ ������ ī��Ʈ�ϴ� Ǯ�̸� ������ �ð��ʰ�
    for (int i = 0; i < topping.size() - 1; i++) {
        // slice_1�� ���Ҹ� ������ ���� �����Ƿ� set���� �ص� �����ϴ�
        slice_1[topping[i]]++;
        slice_2[topping[i]]--;
        // slice_2���� 0�� �Ǵ� ���Ҹ� �����Ѵ�.
        if(slice_2[topping[i]] == 0)
            slice_2.erase(topping[i]);
        // slice_1�� slice_2�� ũ�⸸ ���ϸ� ������ ������ ī��Ʈ�� �� �ִ�.
        if(slice_1.size() == slice_2.size()) 
            answer++;
    }

    return answer;
}