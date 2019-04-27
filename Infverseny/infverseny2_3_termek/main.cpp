#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct esemeny{
    int mettol;
    int meddig;
    int hanyadik;
};


bool rend_rel(esemeny a, esemeny b){
    return a.mettol < b.mettol;
}

int main() {
    //std::ios::sync_with_stdio(false);
    vector<esemeny> esemenyek;

    int esemenyszam;
    cin >> esemenyszam;
    int x, y;
    esemeny e;
    for (int i = 0; i < esemenyszam; ++i) {
        cin >> e.mettol  >> e.meddig;
        e.hanyadik = i+1;
        esemenyek.push_back(e);
    }
    sort(esemenyek.begin(), esemenyek.end(), rend_rel);
    vector<vector<int>> mego;
    int i;
    for (int j = 0; j < esemenyszam; ++j) {
        i = 0;
        while (i < mego.size() && mego[i][0] >= esemenyek[j].mettol)
            ++i;
        if (i >= mego.size()){
            vector<int> atm = {esemenyek[j].meddig, esemenyek[j].hanyadik};
            mego.push_back(atm);
        }
        else{
            mego[i][0] = esemenyek[j].meddig;
            mego[i].push_back(esemenyek[j].hanyadik);
        }
    }

    cout << mego.size() << endl;
    for (int k = 0; k < mego.size(); ++k) {
        for (int j = 1; j < mego[k].size(); ++j) {
            cout << mego[k][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


