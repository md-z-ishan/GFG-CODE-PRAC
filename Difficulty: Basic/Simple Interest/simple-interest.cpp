#include <iostream>
using namespace std;

int main() {
    int p, r, t;
    cin >> p >> r >> t;

    // code here
    double si=(p*r*t)/100.0;
    cout<<fixed<<setprecision(2)<<si;

    return 0;
}