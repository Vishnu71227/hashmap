#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int arr[7] = {1,2,7,11,15,5,9};
    int n = 7;
    int target = 9;
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        int comp = target-arr[i];
        if(mp.count(comp)){
            cout<<"Pair is: "<<mp[comp]<<" , "<<i<<endl;
        }
        mp[arr[i]] = i;
    }
    return 0;}