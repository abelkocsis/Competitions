#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct futo {
    int i;
    int e;
    int sorszam;
};

bool rend_rel(const futo a, const futo b);




int main() {
    int tav, futoszam;
    vector<futo> futok;
    cin >> tav >> futoszam;
    int x, y;
    futo f;
    for (int i = 0; i < futoszam; ++i) {
        cin >> x >> y;
        f.i = x;
        f.e = y;
        f.sorszam = i+1;
        futok.push_back(f);
    }
    sort(futok.begin(), futok.end(), rend_rel);

    int hatralevo = tav;
    int i = futoszam-1;
    vector<int> mego;
    int maxki, maxmeddig=99999;

    while (hatralevo > 0){
        while (futok[i].e >= hatralevo){
            if (futok[i].i < maxmeddig){
                maxmeddig = futok[i].i;
                maxki = futok[i].sorszam;
            }
            i--;
        }
        mego.push_back(maxki);
        hatralevo = maxmeddig;
    }
    reverse(mego.begin(), mego.end());
    cout << mego.size() << endl;
    for (int j = 0; j < mego.size(); ++j) {
        cout << mego[j] << " ";
    }

    return 0;
}

bool rend_rel(const futo a, const futo b){
    if (a.e < b.e || (a.e == b.e && a.i > b.i))
        return true;
    return false;
}