#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, k, t, x;
    vector <int> versenyzok;
    vector<int> kulonbsegek;
    cin >> n >> m >> k >> t;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        versenyzok.push_back(x);
    }
    sort(versenyzok.begin(), versenyzok.end());

    for (int j = 0; j < versenyzok.size()-1; ++j) {
        kulonbsegek.push_back(versenyzok[j+1] - versenyzok[j]);
    }

    sort(kulonbsegek.begin(), kulonbsegek.end());

    if (kulonbsegek[kulonbsegek.size()-k+1] <= t)
        cout << "-1";
    else{
        for (int i = 0; i < k-1; ++i) {
            cout << kulonbsegek[kulonbsegek.size()-1-i] << " ";
        }
    }



    
    return 0;
}