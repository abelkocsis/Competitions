#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ke;
vector<int> veg;
int napszam;
int hatarorszam;

int main() {
    cin >> hatarorszam >> napszam;
    int x, y;
    for (int i = 0; i < hatarorszam; ++i) {
        cin >> x >> y;
        ke.push_back(x);
        veg.push_back(y);
    }
    sort(ke.begin(), ke.end());
    sort(veg.begin(), veg.end());

    int max = 0, maxmego = 0, maxhol, kezdmost= -2, vegemost=-2, leghosszabb = -1, epp = 0;

    int i=0, j=0;
    bool kezdesen;

    while (i < hatarorszam || j < hatarorszam){
        if ((i < hatarorszam && j < hatarorszam && ke[i] <= veg[j]) || j >= hatarorszam ){
            if (epp == 0 && vegemost != ke[i] - 1) {
                kezdmost = ke[i];
                max = 0;
            }
            epp++;
            if (epp > max){
                max = epp;
                maxhol = ke[i];
            }
            i++;
        }
        else {
            epp--;
            if (epp == 0) {
                vegemost = veg[j];
            }
            j++;
        }
        if (vegemost - kezdmost > leghosszabb){
            leghosszabb = vegemost - kezdmost;
            maxmego = maxhol;
        }

    }
    cout << leghosszabb+1 << endl << maxmego << endl;


    return 0;
}