#include <iostream>
#include <vector>

using namespace std;

int mezoszam;
int k;
struct mezo{
    int ertek;
    vector<int> szomszed;
};

vector<mezo> tabla;
vector<vector <int>> dp;

int main() {
    cin >> mezoszam >> k;
    tabla.resize(mezoszam);
    for (int i = 0; i <mezoszam; ++i) {
        cin >> tabla[i].ertek;
    }
    int x;
    for (int j = 0; j < mezoszam; ++j) {
        cin >> x;
        while (x != 0) {
            tabla[j].szomszed.push_back(x);
            cin >> x;
        }
    }

    return 0;
}