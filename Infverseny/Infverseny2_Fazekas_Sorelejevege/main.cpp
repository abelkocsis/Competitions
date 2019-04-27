#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pair{
    int i;
    int j;
};

vector<int> fazekak;
vector<vector<int>> opt;
vector<vector<int>> be;
vector<int> minuszegyek;
int optszamol(int i, int j);
void utkiir(int i, int j);
int n;

int main() {
    ios::sync_with_stdio(false);
    int x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        fazekak.push_back(x);
    }
    minuszegyek.resize(n, -1);
    opt.resize(n, minuszegyek);
    be = opt;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n-k; ++i) {
            optszamol(i, i+k);
        }
    }


    cout << opt[0][n-1] << endl;
    utkiir(0, n-1);
    return 0;
}

int optszamol(int i, int j){

    if (i == j){
        opt[i][j] = fazekak[i];
        return fazekak[i];
    }

    if (j - i == 1){
        opt[i][j] = max(fazekak[i], fazekak[j]);
        return opt[i][j];
    }


    int var[5];
    int ei = fazekak[i];
    int ei2 = fazekak[i+1];
    int ej = fazekak[j];
    int ej2 = fazekak[j-1];
    var[0] = opt[i+1][j-1] + max(ei, ej);
    var[1] = opt[i+2][j] + max (ei, ei2);
    var[2] = opt[i][j-2] + max (ej, ej2);
    var[3] = opt[i+1][j] + ei;
    var[4] = opt[i][j-1] + ej;
    int mini = 99999999 , minmelyik;
    for (int k = 0; k < 5; ++k) {
        if (var[k] < mini){
            mini = var[k];
            minmelyik = k;
        }
    }

    opt[i][j] = mini;
    be[i][j] = minmelyik;
    return mini;

}

void utkiir(int i, int j){
    if (i >= n)
        return;
    switch (be[i][j]){
        case -1:
            cout << i+1;
            if (i != j)
                cout << " " << j+1;
            cout << endl;
            break;
        case 0:
            cout << i+1 << " " << j+1 << endl;
            utkiir(i+1, j-1);
            break;
        case 1:
            cout << i+1 << " " << i+2 << endl;
            utkiir(i+2, j);
            break;
        case 2:
            cout << j+1 << " " << j << endl;
            utkiir(i, j-2);
            break;
        case 3:
            cout << i+1 << endl;
            utkiir(i+1, j);
            break;
        case 4:
            cout << j+1 << endl;
            utkiir(i, j-1);
            break;
    }
}