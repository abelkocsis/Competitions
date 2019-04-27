#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int meret;
vector<int>  szam;
vector<int>  bin2;
vector<int>  bin;

void Kovetkezo();
bool isValid ();
void BinKi();
void Elozo();

int main() {
    cin >> meret;

    szam.resize(meret+1);
    bin.resize(meret+1);
    for (int i = 0; i < meret; ++i) {
        cin >> szam[i+1];
    }
    for (int j = 1; j <= meret ; ++j) {
        if (szam[j] > j)
            bin[j] = 1;
        else
            bin[j] = 0;
    }
    bin2 = bin;
    Elozo();
    BinKi();
    cout << endl;
    bin = bin2;
    Kovetkezo();
    BinKi();


    

}

void Kovetkezo(){
    int i = meret-1;
    int lastegy = 99;
    bool megy = true;
    while(true) {


        while (!(bin[i - 1] == 0 && bin[i + 1] == 0) && bin[i] != 1) {
            i--;
        }
        if (bin[i] == 1) {
            bin[i] = 0;
            i--;
        } else {
            bin[i] = 1;
            return;
        }
    }


   // x += 1;
   // int mask = 3,                /* Use the mask to look for 11.     */
   //         pos = 2;                 /* Track our location in the bits.  */
   // while (mask <= x) {
   //     if ((mask & x) == mask) {  /* If we find 11, shift right to    */
   //         x >>= pos;               /*  zero it out.                    */
   //         x += 1;                  /* Add 1, shift back to the left,   */
   //         x <<= pos;               /*  and continue the search.        */
   //     }
   //     mask <<= 1;                /* Advance the mask (could advance  */
   //     pos += 1;                  /*  another bit in the above case). */
   // }
}

void Elozo(){
    int i = meret;
    while (bin[i] != 1)
        i--;
    bin[i] = 0;
    i++;
    for (; i < meret; i += 2) {
        bin[i] = 1;
    }
}

void BinKi(){
    for (int i = 1; i <= meret ; ++i) {
        if (bin[i] == 0)
            cout << i << " ";
        else{
            cout << i+1 << " " << i << " ";
            i++;
        }
    }
}

bool isValid (){
    for (int i = 0; i < meret; ++i) {
        if (abs(szam[i] - (i+1)) > 1)
            return false;
    }
    return true;
}

