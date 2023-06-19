#include<bits/stdc++.h>
using namespace std;
#define ko get<0>
#define en get<1>
#define math get<2>
#define name get<3>

vector<tuple<int, int, int, string>> student;

bool func_sort(const tuple<int, int, int, string> &a,tuple<int, int, int, string> &b){
    // ���� ������ �����ϴ� ������ == ���� ������ ū ����
    if(ko(a) != ko(b)){
        return ko(a) > ko(b);
    }
    // ���� ������ �����ϴ� ������ == ���� ������ ���� ����
    else if(en(a) != en(b)){
        return en(a) < en(b);
    }
    // ���� ������ �����ϴ� ������ == ���� ������ ū ����
    else if(math(a) != math(b)){
        return math(a) > math(b);
    }
    // ���� ������ �����ϴ� ������ == �̸��� �� ���ĺ��� ���� ������ ����
    return name(a) < name(b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        int kor, eng, mat;
        cin >> s >> kor >> eng >> mat;
        student.push_back({kor, eng, mat, s});
    }

    sort(student.begin(), student.end(), func_sort);

    for(int i = 0; i < n; i++){
        cout << name(student[i]) << '\n';
    }

}