#include <iostream>
using namespace std;

int main(){
    int s; // size of the group
    long int n; // the group staying in the hotel on D-th day
    long int peopleNum, day;

    while (cin >> s >> n){
        peopleNum = s;
        day = 1;

        while (n >= day){
            day = day + peopleNum;
            peopleNum++;
        }
        peopleNum--;
        cout << peopleNum << endl;
    }

    return 0;
}