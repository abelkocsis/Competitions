#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct csapat{
    int pontszam;
    vector<bool> jatszott;
};

vector<csapat> csapatok;


vector<int> mego;
vector<int> vmego;
int n, f, k, x;

struct ret{
    int mini;
    vector<int> eddigimego;
};

ret generate(int i);

int main() {
    cin >> n >> f;
    csapatok.resize(n);

    for (int i = 0; i < n; ++i) {
        csapatok[i].jatszott.resize(n, false);
    }

    for (int i = 0; i < n; ++i) {
        cin >> k;
        csapatok[i].pontszam = k;
        for (int j = 0; j < k; ++j) {
            cin >> x;
            --x;
            csapatok[i].jatszott[x] = true;
            csapatok[x].jatszott[i] = true;
        }
    }
    ret megoldas;
    megoldas =  generate(0);
    //cout << megoldas.mini << endl;

    for (int l = 0; l < megoldas.eddigimego.size(); l += 2) {
        cout << megoldas.eddigimego[l]+1 << " " << megoldas.eddigimego[l+1]+1 << endl;
    }
    return 0;
}

ret generate(int i){
    int mini = 9999;
    vector<int> megoloc;
    for (int j = 0; j < n; ++j) {
        if (i != j && !csapatok[i].jatszott[j] && find(mego.begin(), mego.end(), j) == mego.end()){

            if (mego.size() == n - 2){
                if (abs(csapatok[i].pontszam - csapatok[j].pontszam) < mini){
                    mini = abs(csapatok[i].pontszam - csapatok[j].pontszam);
                    megoloc.push_back(i);
                    megoloc.push_back(j);
                }
            }
            else{
                mego.push_back(i);
                mego.push_back(j);
                int y = 0;
                bool benne = true;
                while (benne){
                    benne = false;
                    for (int l = 0; l < mego.size(); ++l) {
                        if (y == mego[l]){
                            y++;
                            benne = true;
                            break;
                        }
                    }

                }
                ret a = generate(y);
                int er = a.mini + abs(csapatok[i].pontszam - csapatok[j].pontszam);
                mego.pop_back();
                mego.pop_back();

                if (er < 9999 && er < mini ){
                    mini = er;
                    megoloc = a.eddigimego;
                    megoloc.push_back(i);
                    megoloc.push_back(j);

                }
            }

        }
    }
    ret r;
    r.mini = mini;
    r.eddigimego = megoloc;
    return r;
};