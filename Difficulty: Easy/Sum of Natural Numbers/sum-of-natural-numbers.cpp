#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    // code here
    if(n==0){
        cout<<0;
        return 0;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    cout<<sum;
    return 0;
}