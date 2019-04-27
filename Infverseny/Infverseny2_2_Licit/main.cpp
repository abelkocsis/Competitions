#include <iostream>
#include <vector>

using namespace std;

vector<int> maxok;
vector<vector<int>> mik;

int main() {
    int meret, licitszam;
    cin >> licitszam >> meret;

    maxok.resize(meret+1);
    mik.resize(meret+1);
    maxok[0] = 0;
    maxok[1] = 0;
    int honnan, meddig, mennyiert;
    for (int i = 0; i < licitszam; ++i) {
        cin >> honnan >> meddig >> mennyiert;


        if (maxok[honnan-1] + mennyiert > maxok[meddig]){
            maxok[meddig] = maxok[honnan-1] + mennyiert;
            mik[meddig] = mik[honnan-1];
            mik[meddig].push_back(i+1);

            for (int j = meddig+1; j < maxok.size(); ++j) {
                maxok[j] = maxok[meddig];
                mik[j] = mik[meddig];
            }
            
        }
        
        
    }
    int me=0, mo;

    /*for (int l = 0; l < maxok.size(); ++l) {
        cout << maxok[l] << " ";
    }

    cout << endl;*/
    for (int j = 0; j < maxok.size(); ++j) {
        if (maxok[j]>me){
            me = maxok[j];
            mo = j;
        }
    }
    cout << me << endl;
    for (int k = 0; k < mik[mo].size(); ++k) {
        cout << mik[mo][k] << " ";
    }
    return 0;
}

