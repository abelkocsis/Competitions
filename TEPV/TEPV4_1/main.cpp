#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tabor{
    int etel;
    int kovtaborig;
};

vector<tabor> ut;
vector<int> mego;

int main() {
    int taborszam, kap, akt;
    int x,y;
    cin >> taborszam >> kap;
    mego.resize(taborszam,0);
    tabor t;
    for (int i = 0; i < taborszam-1; ++i) {
        cin >> x >> y;
        t.etel = x;
        t.kovtaborig = y;
        ut.push_back(t);
    }

    bool megy = true;


    mego[0] = min(kap, ut[0].etel);
    akt = min(kap, ut[0].etel);
    akt -= ut[0].kovtaborig;
    if (akt < 0)
        megy = false;
    int i;
    if (megy)
        i = 1;
    else
        i = 0;
    while(megy && i < taborszam){
        ut[i].etel -= ut[i-1].kovtaborig;
        mego[i] = min(kap, akt+ut[i].etel)-akt;
        akt = min(kap, akt+ut[i].etel);
        if (akt < ut[i].kovtaborig){
            i++;
            megy = false;
        }
        else if (i == taborszam-1 && akt < ut[i].kovtaborig*2){
            i++;
            megy = false;
        }
        else{
            akt -= ut[i].kovtaborig;
            i++;
        }
    }
    cout << i << endl;
    for (int j = 0; j < i-1; ++j) {
        if (mego[j] < 0)
            cout << 0 << " ";
        else
            cout << mego[j] << " ";
    }
    return 0;
}