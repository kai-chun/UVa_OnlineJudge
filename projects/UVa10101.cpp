#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int kuti = 10000000;
const int lakh = 100000;
const int hajar = 1000;
const int shata = 100;
void transfer(int, int);

int main() {
    long long int num;
    int firstHalf, secondHalf;
    int count = 0;

    while (cin >> num) {
        count++;
        
        cout << setw(4) << setfill(' ') << count << ". ";

        if (num == 0){
            cout << "0";
        } else if (num >= kuti) {
            firstHalf = num / kuti;
            secondHalf = num % kuti;
            transfer(firstHalf, 0);
            cout << " kuti";
            transfer(secondHalf, 1);
        } else {
            transfer(num, 0);
        }
        cout << endl;
    }
    return 0;
}

void transfer(int n, int count){
    int k, l, h, s, x;

    l = n / lakh;
    if (l > 99){
        k = l / 100;
        cout << k << " kuti";
        l = l % 100;
        count++;
    }
    if (l != 0){
        if (count != 0){
            cout << " ";
        }
        cout << l << " lakh";
        count++;
    }
    n = n % lakh;
    h = n / hajar;
    if (h != 0) {
        if (count != 0){
            cout << " ";
        }
        cout << h << " hajar";
        count++;
    }
    n = n % hajar;
    s = n / shata;
    if (s != 0) {
        if (count != 0){
            cout << " ";
        }
        cout << s << " shata";
        count++;
    }
    x = n % shata;
    if (x != 0){
        if (count != 0){
            cout << " ";
        }
        cout << x;
    }
}