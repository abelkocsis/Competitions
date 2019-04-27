#include <iostream>
#include <vector>

using namespace std;

vector <int> napok;
vector<int> szerencsesnapok;

int main() {
    int napszam, x;
    cin >> napszam;
    szerencsesnapok.resize(napszam, 0);

    cin >> x;
    napok.push_back(x);
    cin >> x ;
    napok.push_back(x);

    szerencsesnapok[0] = 0;


    for (int i = 2; i < napszam; ++i) {
        cin >> x ;
        napok.push_back(x);
        if (napok[i-2]> napok[i-1] &&  napok[i] > napok[i-1]){
            szerencsesnapok[i-1] = -1;
        }
        else if (napok[i-2]< napok[i-1] && napok[i] < napok[i-1])
            szerencsesnapok[i-1] = 1;

    }
    szerencsesnapok[napszam-1] = 0;

    int akt = 0;
    int ered = 0;
    int i = 0;
    int j;
    while (i < napszam){
        while(i < napszam && szerencsesnapok[i] != 1)
            i++;
        if (i < napszam && szerencsesnapok[i] == 1){
            j = i;
            akt = 0;
            while (j >= 0){
                akt += szerencsesnapok[j];
                if (akt > 0 && szerencsesnapok[j] == 1)
                    ered++;
                j--;
            }
            i++;
        }
    }
    cout << ered << endl;





    return 0;
}
