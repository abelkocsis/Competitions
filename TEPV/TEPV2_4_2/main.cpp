#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> eredmeny;
vector<int> kezd;
vector<vector<int>> kozott;
vector<vector<int>> mego;

int main() {
    std::ios::sync_with_stdio(false);
    int n,m,k,x, y;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        eredmeny.push_back(x);
    }

    kozott.resize(m+1);
    mego.resize(m+1);

    for (int l = 0; l < m+1; ++l) {
        kozott[l].resize(m+1, 0);
        mego[l].resize(m+1, -1);
    }

    int i = 0, epp;
    while (i <= n){
        epp = eredmeny[i];
        for (int j = 0; j < kezd.size(); ++j) {
            if (epp != kezd[j])
                ++kozott[kezd[j]][epp];
        }



        if (find(kezd.begin(), kezd.end(), epp) == kezd.end()){
            kezd.push_back(epp);
        } else{
            if (kozott[epp][0] > mego[epp][0]) {
                mego[epp][0] = kozott[epp][0];
                kozott[epp][0] = mego[epp][0];
            }
            if (m > 1){
                if (kozott[epp][1] + kozott[epp][0] > mego[epp][1]){
                    mego[epp][1] = kozott[epp][1] + kozott[epp][0];
                    kozott[epp][1] = mego[epp][1];
                }
            }




            for (int l = 2; l < m+1; ++l) {
                kozott[epp][l-2] = 0;
                if (kozott[epp][l] + kozott[epp][l-1] > mego[epp][l]){
                    mego[epp][l] = kozott[epp][l] + kozott[epp][l-1];

                }
                kozott[epp][l] = kozott[epp][l] + kozott[epp][l-1];

            }
            kozott[epp][m-2] = 0;
            kozott[epp][m-1] = 0;
            kozott[epp][m] = 0;

        }

        ++i;
    }

    vector<int> mmm;

    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        mmm.push_back(mego[x][y]);
    }
    for (int i1 = 0; i1 < mmm.size(); ++i1) {
        cout << mmm[i1] << endl;
    }


    return 0;
}