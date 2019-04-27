#include <iostream>
#include <vector>

using namespace std;

vector<vector <bool>> data;
vector<bool> megov;
int emberszam, napszam;
bool different(int a, int b);

int main() {
    cin >> emberszam >> napszam;
    data.resize(emberszam);
    megov.resize(emberszam);
    for (int i = 0; i < emberszam; ++i) {
        data[i].resize(napszam+1, false);
    }

    int x, y;
    for (int j = 0; j < emberszam; ++j) {
        cin >> x;
        for (int i = 0; i < x; ++i) {
            cin >> y;
            data[j][y] = true;
        }
    }

    int mego = 0;
    bool jo;

    for (int k = 0; k < emberszam; ++k) {
        jo = true;
        for (int i = 0; i < emberszam && jo; ++i) {
            if (!different(k, i) && k != i){
                jo = false;
                continue;
            }

        }
        if (jo){
            mego++;
        }

    }

    cout << mego;

    return 0;
}

bool different(int a, int b){
    for (int i = 0; i <= napszam; ++i) {
        if (data[a][i] && !data[b][i])
            return true;
    }
    return false;
}