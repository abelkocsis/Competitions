#include <iostream>
#include <vector>

using namespace std;

vector<int> tav;

int n, k;
int getDistance(int i, int j, bool balrol);
void keres(int i);
int plusz(int a);
int minusz(int a);


int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    int x;
    tav.resize(n+1);
    tav.resize(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        tav[i+1] = x;
    }
    /*for (int i = 2; i < n+1; ++i) {
        tav.resize(n+1);
        for (int j = i+1; j < n+1; ++j) {
            tav[i][j] = tav[1][j]-tav[1][i];
        }
    }*/

    for (int i = 0; i < n; ++i) {
        keres(i+1);
    }


    return 0;
}

int getDistance(int i, int j, bool balrol){
    bool voltcsere = false;
    if (j < i){
        int x = j;
        j = i;
        i = x;
        voltcsere = true;
    }
    if (i > 1) {
        int tt = tav[j] - tav[i];
        if (balrol ^ voltcsere)
            return tav[1] - tt;
        else
            return tt;
    } else
    {
        int tt = tav[j];
        if (balrol ^ voltcsere)
            return tav[1] - tt;
        else
            return tt;
    }
}

void keres (int i){
    int b = minusz(i);
    int j = plusz(i);
    for (int l = 0; l < k; ++l) {
        int z = getDistance(i, b, true);
        int u = getDistance(i, j, false);

        if ((getDistance(i, b, true) > getDistance(i, j, false) && j != i) || b == i){
            j = plusz(j);
        }
        else{
            b = minusz(b);
        }
    }
    if (plusz(b) == i){
        cout << plusz(i) << " ";
    }
    else
        cout << plusz(b) << " ";
    if (minusz(j) == i )
        cout << minusz(i) << endl;
    else
        cout << minusz(j) << endl;


}

int plusz(int a){
    ++a;
    if (a > n)
        a = 1;
    return a;
}

int minusz(int a){
    a--;
    if (a == 0)
        a = n;
    return a;
}


