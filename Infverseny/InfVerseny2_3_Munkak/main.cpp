#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Munka{
    int haszon;
    int hanyadik;
    int hatarido;
    bool done = false;
};

bool kisebb (Munka* a, Munka* b);
vector<vector<Munka*>> napok;
vector<Munka> munkak;

int main() {
    int munkanapszam, megrendelesszam;
    cin >> munkanapszam >> megrendelesszam;
    napok.resize(munkanapszam+1);
    int h, p;
    munkak.resize(megrendelesszam+1);
    for (int i = 0; i < megrendelesszam; ++i) {
        cin >> h >> p;
        munkak[i].haszon = p;
        munkak[i].hanyadik = i + 1;
        munkak[i].hatarido = h;
        for (int j = h; j > 0 ; --j) {
            napok[j].push_back(&munkak[i]);
        }
    }
    for (int k = 0; k < munkanapszam; ++k) {
        sort(napok[k].begin(), napok[k].end(), kisebb);
    }
    vector<vector<int>> mego;
    int maxbevetel = 0;
    for (int i = munkanapszam; i > 0 ; --i) {
        int k = 0;
        while (k < napok[i].size() && napok[i][k]->done)
            ++k;
        if (k < napok[i].size()){
            maxbevetel += napok[i][k]->haszon;
            napok[i][k]->done = true;
            vector<int> atm = {napok[i][k] ->hanyadik, i};
            mego.push_back(atm);
        }

    }
    cout << maxbevetel << " " << mego.size() << endl;
    for (int l = 0; l < mego.size(); ++l) {
        cout << mego[l][0] << " " << mego[l][1] << endl;
    }
    return 0;
}

bool kisebb (Munka* a, Munka* b){
    if ( a->haszon > b->haszon)
        return true;
    else
        return false;
}