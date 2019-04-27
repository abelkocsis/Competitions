#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> kezd;
vector<int> veg;

int main() {
    int n, t, k, x, y;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> x >> y;
            kezd.push_back(x);
            veg.push_back(y);

        }
    }
    veg.push_back(0);
    sort(kezd.begin(), kezd.end());
    sort(veg.begin(), veg.end());
    kezd.push_back(t+1);
    int max = 0;
    int i = 0;
    while (i < kezd.size()){
        if (kezd[i] > veg[i] && kezd[i] - veg[i] > max){
            max = kezd[i] - veg[i];
        }
        ++i;
    }
    if (max > 0)
        cout << max-1;
    else
        cout << 0;
    return 0;
}