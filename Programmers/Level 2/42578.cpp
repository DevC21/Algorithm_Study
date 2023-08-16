#include<bits/stdc++.h>
using namespace std;

map<string, int> m;
vector<int> nCr;

// nCr = n-1Cr-1 + n-1Cr ������ ����Ͽ� ��������� ����
int combination(int n, int r){
    // n���߿� n���� ���ų� 0���� ���� ����� ���� 1��
    if(n == r || r == 0) 
        return 1; 
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    for(auto x : clothes)
        m[x[1]]++;
    
    // �� �ǻ� �������� 1���� �԰ų� ������ �� �ִ�.
    // nC1 + nC0�� ���ؼ� ������
    for(auto x : m){
        int sum = 0;
        for(int i = 0; i <= 1; i++)
            sum += combination(x.second, i);
        nCr.push_back(sum);
    }

    // ���Ǻ� Ȯ�� : �� Ȯ���� ���ÿ� �Ͼ Ȯ���� �� Ȯ���� ���� ����.
    for(auto x : nCr)
        answer *= x;
    // �ǻ��� �ּ� 1���� �Դ´� 
    // ��� �ǻ� ������ �ϳ��� ���Դ� ������ 1�� ���������� ����.
    answer--;

    // �Ϲ�ȭ
    // hash_table = {����1: n, ����2: m, ����3: k, ����4: p} �̷��� �־����ٸ�
    // (nC1 + nC0) x (mC1 + mC0) x (kC1 + kC0) x (pC1 + pC0) - 1

    return answer;
}