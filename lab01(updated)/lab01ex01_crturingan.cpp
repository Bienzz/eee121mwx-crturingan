#include <iostream>
using namespace std;


int GCD(int x, int y){
    int gcd;
    if (x < y){
    int temp;
    temp = x;
    x = y;
    y = temp;   
}
    while (y != 0){
    gcd = y;
    y = x % y;
    x = gcd;
    }
    return x;
}

int LCM(int x, int y){
    int lcm = (x*y) / GCD(x, y);
    return lcm;
}

int main(){

    int x, y;

    cin >> x;
    cin >> y;
    cout << GCD(x,y) << endl;
    cout << LCM(x,y) << endl;
    
    return 0;
}