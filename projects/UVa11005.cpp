#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int cal_cost_of_base(int[], long long int, int);

int main(){
    int test_case_num, query_num;
    int cost[36];

    cin >> test_case_num;
    for (int i = 0; i < test_case_num; i++){
        if (i != 0){
            cout << endl;
        }
        cout << "Case " << (i+1) << ":" << endl;
        
        // access the cost of the 36 characters
        for (int j = 0; j < 36; j++){
            cin >> cost[j];
        }

        cin >> query_num;
        long long int queries[query_num];

        for (int j = 0; j < query_num; j++){
            cin >> queries[j];

            long long int min_cost = 0;
            vector<int> all_cost;

            // calculate all possible cost and find the minimum
            for (int k = 2; k <= 36; k++){
                long long int tmp = cal_cost_of_base(cost, queries[j], k);
                all_cost.push_back(tmp);
                if (min_cost >= tmp || min_cost == 0){
                    min_cost = tmp;
                }
            }

            // print the base of the min_cost
            cout << "Cheapest base(s) for number " << queries[j] << ":";
            for (int k = 0; k < all_cost.size(); k++){
                if (all_cost[k] == min_cost){
                    cout << " " << (k+2);
                }
            }
            cout << endl;
        }
    }
    return 0;
}

// calculate the cost of num being expressed in base
long long int cal_cost_of_base(int cost[], long long int num, int base){
    vector<int> expressed_in_base;
    long long int totalCost = 0;

    // convert num into expressed_in_base
    while (num > 0){
        expressed_in_base.push_back(num % base);
        num /= base;
    }
    reverse(expressed_in_base.begin(), expressed_in_base.end());
    
    // calculate the cost of expressed_in_base
    for (int i = 0; i < expressed_in_base.size(); i++){
        totalCost += cost[expressed_in_base[i]];
    }

    return totalCost;
}