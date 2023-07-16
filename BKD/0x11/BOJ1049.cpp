#include<bits/stdc++.h>
using namespace std;

int n, m;
int Singlemin = 1001;
int Setmin = 1001;
int purchaseSet;
int purchaseSingle;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int setprice;
        int singleprice;
        cin >> setprice >> singleprice;
        Setmin = min(setprice, Setmin); 
        Singlemin = min(singleprice, Singlemin);
    }

    if(Singlemin * 6 >= Setmin){
        purchaseSet = n / 6 * Setmin;
        purchaseSingle = (n - n / 6 * 6) * Singlemin;
        cout << purchaseSet + min(Setmin, purchaseSingle);
    }
    else if(Singlemin * 6 < Setmin){
        purchaseSingle = n * Singlemin;
        cout << purchaseSingle;
    }
}