#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> erkezes;
vector<int> tavozas;

int main() {
    int n, p;
    cin >> n >> p;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        erkezes.push_back(x);
        tavozas.push_back(y);
    }
    sort(erkezes.begin(), erkezes.end());
    sort(tavozas.begin(), tavozas.end());

    int i0=0,j0=-1,i,j;
    int mettol=1;
    int meddig;
    int peoplehere = 0;
    int atm = 0;
    int megopeople = 100001;
    int megomettol;

    peoplehere++;
    int k = erkezes[i0];

    while (i0+1<n && erkezes[i0+1] == k){
        i0++;
        peoplehere++;
    }

    while (mettol+p - 1 <= tavozas[tavozas.size()-1]){
        atm = peoplehere;
        i = i0+1;
        j = j0+1;
        meddig = mettol + p - 1;

        while (i < n && erkezes[i] <= meddig){
            atm++;
            i++;
        }

        if (atm < megopeople){
            megopeople = atm;
            megomettol = mettol;
        }

        if (i0+1<n && erkezes[i0+1] < tavozas[j0+1]){
            i0++;
            mettol = erkezes[i0];
            int k = erkezes[i0];
            peoplehere++;
            while (i0+1<n && erkezes[i0+1] == k){
                i0++;
                peoplehere++;
            }
        }
        else{
            j0++;
            mettol = tavozas[j0]+1;
            int k = tavozas[j0];
            peoplehere--;
            while (j0+1 < n && tavozas[j0+1] == k){
                j0++;
                peoplehere--;
            }
            while (i0+1<n && erkezes[i0+1] == k){
                i0++;
                peoplehere++;
            }
        }


    }
    cout << megomettol << endl << megopeople << endl;


    return 0;
}