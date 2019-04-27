#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;


struct ism{
    bool volt = false;
    int hossz;
    int hanyadiktol;
};
ism rek(int i, int melyseg);

vector<ism>dp;

int main() {
    std::ios::sync_with_stdio(false);
    int n, x;
    cin >> n;
    v.resize(n+1);
    dp.resize(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v[i+1]=x;
    }

    for (int j = 1; j < n+1; ++j) {
        ism i = rek(j,0);
        cout << i.hossz << " " << i.hanyadiktol << endl;
    }

    return 0;
}

int f(int i ){
    return v[i];
}

vector<int> volt;

ism rek(int i, int melyseg){

    if (dp[i].volt){
        volt.clear();
        return dp[i];
    }

    if (find(volt.begin(), volt.end(), i) == volt.end()){
        volt.push_back(i);
        rek(f(i), 0);
        return dp[i];
    }
    else{
        int hanyadiktol = 0;
        while (volt[hanyadiktol] != i){
            hanyadiktol++;
        }
        hanyadiktol++;
        ism m;
        m.volt = true;
        m.hanyadiktol = hanyadiktol;
        m.hossz = (volt.size()-hanyadiktol+1);


        for (int j = hanyadiktol-1; j < volt.size(); ++j) {
            dp[volt[j]].volt=true;
            dp[volt[j]].hanyadiktol=1;
            dp[volt[j]].hossz= volt.size()-hanyadiktol+1;
        }

        int k = 2;
        for (int j = hanyadiktol-2; j >= 0; j--){
            dp[volt[j]].volt = true;
            dp[volt[j]].hanyadiktol = k;
            dp[volt[j]].hossz = volt.size()-hanyadiktol+1;
            k++;
        }

        volt.clear();
        return m;
    }


}