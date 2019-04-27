#include <iostream>
#include <vector>

using namespace std;

vector <vector <bool>>  tabla;
vector<vector <int>> lepes;
vector<int> innen;
vector<int> innen2;
int meret;

int egyLepes(int x, int y, int hanyadik);
int kx, ky, cy, cx;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> meret;
    tabla.resize(meret+1);
    lepes.resize(meret+1);
    string be;
    for (int i = 1; i <= meret; ++i) {
        cin >> be;
        tabla[i].push_back(false);
        lepes[i].push_back(99999);
        for (int j = 0; j < meret; ++j) {
            if (be[j]=='+')
                tabla[i].push_back(true);
            else
                tabla[i].push_back(false);
            lepes[i].push_back(9999);
        }
    }
    cin >> kx >> ky >> cx  >> cy;
    lepes[kx][ky] = 0;
    innen.push_back(kx);
    innen.push_back(ky);
    cout << egyLepes(kx, ky, 1) << endl;
    return 0;
}

bool jobbrafel (int x, int y, int hanyadik){
    x--;
    y++;
    bool volt = false;
    while (x > 0 && y <= meret && !tabla[x][y] && hanyadik < lepes[x][y]){
        lepes[x][y] = hanyadik;
        innen.push_back(x);
        innen.push_back(y);
        volt = true;
        x--;
        y++;
    }
    return volt;
}

bool balraFel (int x, int y, int hanyadik){
    x--;
    y--;
    bool volt = false;
    while (x > 0 && y >0 && !tabla[x][y] && hanyadik < lepes[x][y]){
        lepes[x][y] = hanyadik;
        innen.push_back(x);
        innen.push_back(y);
        volt = true;
        x--;
        y--;
    }
    return volt;
}

bool balraLe (int x, int y, int hanyadik){
    x++;
    y--;
    bool volt = false;
    while (x <= meret && y >0 && !tabla[x][y] && hanyadik < lepes[x][y]){
        lepes[x][y] = hanyadik;
        innen.push_back(x);
        innen.push_back(y);
        volt = true;
        x++;
        y--;
    }
    return volt;
}

bool jobbraLe (int x, int y, int hanyadik){
    x++;
    y++;
    bool volt = false;
    while (x <= meret && y <= meret && !tabla[x][y] && hanyadik < lepes[x][y]){
        lepes[x][y] = hanyadik;
        innen.push_back(x);
        innen.push_back(y);
        volt = true;
        x++;
        y++;
    }
    return volt;
}

int egyLepes(int x, int y, int hanyadik){
    while (true){
        innen2 = innen;
        innen.clear();
        for (int i = 0; i < innen2.size(); i += 2) {
            jobbrafel(innen2[i], innen2[i+1], hanyadik);
            balraFel(innen2[i], innen2[i+1], hanyadik);
            balraLe(innen2[i], innen2[i+1], hanyadik);
            jobbraLe(innen2[i], innen2[i+1], hanyadik);
        }
        if (lepes[cx][cy] != 9999){
            return lepes[cx][cy];
        }
        else if (innen.size() == 0)
            return -1;

        else hanyadik++;
    }

}