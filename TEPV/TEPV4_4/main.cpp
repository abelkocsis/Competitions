#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n ;
    int current;
    cin >> n;
    stack<int> mvagany;
    vector<int> eredmeny;
    int i = 0;
    bool going = true;
    while(i < n && going) {
        cin >> current;
        if (eredmeny.size() > 0 && current < eredmeny[eredmeny.size()-1]){
            while (!mvagany.empty()){
                eredmeny.push_back(mvagany.top());
                mvagany.pop();
            }
            going = false;
        }
        else if ((mvagany.empty() || current < mvagany.top()) ){
            mvagany.push(current);
        }
        else{
            while (!mvagany.empty() && current >= mvagany.top()){
                eredmeny.push_back(mvagany.top());
                mvagany.pop();
            }
            mvagany.push(current);
        }
        i++;


    }

    while (!mvagany.empty() && going &&  (eredmeny.size() == 0 || mvagany.top() > eredmeny[eredmeny.size()-1])){
        eredmeny.push_back(mvagany.top());
        mvagany.pop();
    }
    /*int prev;
    int sorrendbe = 1;
    prev = eredmeny[0];
    for (int j = 0; j < eredmeny.size(); ++j) {
        cout << eredmeny[j] << " ";
    }
    cout << endl;
*/
    cout << eredmeny.size();
    return 0;
}