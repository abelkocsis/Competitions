#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    std::ios::sync_with_stdio(false);

    vector<int> egyvektor(750, 0);
    //vector<vector<int>> evmennyi(12);
    //vector<vector<int>> legkisebb(12);
    /*
    for (int j = 0; j < 12; ++j) {
        evmennyi[j].resize(31,0);
        legkisebb[j].resize(31,0);
    }*/



    int x, y;
    int darabszam;

    cin >> darabszam;


    for (int i = 0; i < darabszam; ++i) {
        cin >> x >> y;
        egyvektor[(x-1)*31*2+(y-1)*2]++;
        //++evmennyi[x-1][y-1];
        if (egyvektor[(x-1)*31*2+(y-1)*2] == 1)
            egyvektor[(x-1)*31*2+(y-1)*2+1] = i+1;

    }

    int eddig = 0;

    for (int h = 0; h < 12; ++h) {
        for (int n = 0; n < 31; ++n) {
            //eddig += evmennyi[h][n];
            eddig += egyvektor[h*31*2+(n)*2];
            if (eddig >= (darabszam/2)+1){
                cout << h+1 << " " << n+1 << endl << egyvektor[h*31*2+(n)*2+1]  << endl;
                return 0;
            }

        }
    }

    return 0;
}
