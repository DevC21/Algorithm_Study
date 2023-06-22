#include<bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string answer = "";

    for(int i = 0; i < new_id.size(); i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] += 'a' - 'A';
    }

    for(int i = 0; i < new_id.size(); i++){
        if(((new_id[i] >= 'a' && new_id[i] <= 'z') ||
            (new_id[i] >= '0' && new_id[i] <= '9') ||
            new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') != true){
            new_id.erase(i, 1);
            i = -1;
        }
    }

    new_id = regex_replace(new_id, regex("\\.{2,}"), ".");

    /* 위 두 과정은 다음 정규식 표현으로 가능
    // Step 2
    new_id = regex_replace(new_id, regex("[^a-z0-9._-]"), "");

    // Step 3
    new_id = regex_replace(new_id, regex("\\.+"), ".");
    */

    if(new_id[0] == '.')
        new_id.erase(0, 1);

    if(new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.size() - 1, 1);

    if(new_id == "")
        new_id = "a";

    if(new_id.size() >= 16){
        new_id = new_id.substr(0, 15);
        if(new_id[new_id.size() - 1] == '.')
            new_id.erase(new_id.size() - 1, 1);
    }

    if(new_id.size() <= 2){
        while(new_id.size() <= 2)
            new_id += new_id[new_id.size() - 1];
    }

    answer = new_id;
    return answer;
}