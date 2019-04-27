#include <iostream>
#include <vector>

using namespace std;

vector<int> arnap;
vector<int> oda (101, 0);
vector<int> vissza(101, 0);
vector<vector<int>> mego;


int main() {
    int n, x;
    cin >> n;
    arnap.resize(n+1);
    mego.resize(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        arnap[i+1 ] = x;
    }
    vector<int>atm = {0,0};
    for (int j = 1; j <= n; ++j) {
        mego[j] = atm;
        mego[j][0] = oda[arnap[j]-1];
        for (int k = arnap[j]; k <= 100 ; ++k) {
            oda[k]++;
        }
    }
    for (int j = n; j > 0; --j) {
        mego[j][1] = vissza[arnap[j]+1];
        for (int k = arnap[j]; k >= 0; --k) {
            vissza[k]++;
        }
    }


    for (int l = 1; l < n+1; ++l) {
        cout << mego[l][0]<<" " << mego[l][1] <<endl;
    }

    return 0;
}