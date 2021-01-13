#include <iostream>
using namespace std;
int gcd(int, int);

int main(){
    int n, g;

    while (cin >> n){
        if (n == 0){
            break;
        }

        g = 0;
        for (int i = 1; i < n; i++){
            for (int j = i+1; j <= n; j++){
                g += gcd(i, j);
            }
        }
        cout << g << endl;
    }
    return 0;
}

int gcd(int i, int j){
    int tmp;
    if (j > i){
        tmp = i;
        i = j;
        j = tmp;
    }

    while (j > 0){
        tmp = i % j;
        i = j;
        j = tmp;
    }
    return i;
}
