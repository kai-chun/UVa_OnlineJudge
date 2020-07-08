#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class species{
    public:
        string name;
        double num;
};

bool comp(species i, species j){
    return i.name < j.name;
}

int main(){
    int testCase_num;
    int treeNum;
    int isExist;
    vector<species> record;
    string tmpTree;

    cin >> testCase_num;
    for (int i = 0; i < testCase_num; i++){
        if (i != 0){
            record.clear();
            cout << endl;
        } else {
            cin.ignore();
            getline(cin, tmpTree); // ignore the line break after testCase_num
        }
        treeNum = 0;

        while (getline(cin, tmpTree)){
            if (tmpTree == ""){
                break;
            }
            // check if tmpTree exists in record[] and count its num
            isExist = 0;
            for (int j = 0; j < record.size(); j++){
                if (tmpTree == record[j].name){
                    isExist = 1;
                    record[j].num++;
                    break;
                }
            }

            // if tmpTree not exist in record[]
            if (!isExist){ 
                species tmpSpecies;
                tmpSpecies.name = tmpTree;
                tmpSpecies.num = 1;
                record.push_back(tmpSpecies);
            }
            treeNum++;
        }

        // in alphabetical order
        sort(record.begin(), record.end(), comp);    

        // count the percentage of the each trees' population
        for (int j = 0; j < record.size(); j++){
            double num = record[j].num / treeNum * 100;
            cout.precision(4);
            cout << record[j].name << " " << fixed << num << endl;
        }
    }
    return 0;
}