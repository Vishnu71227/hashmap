#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;


int majorityElement(vector<int>& num) {
        int n =  num.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            if(mp.count(num[i])){ 
                mp[num[i]]++;
            }else{
                mp[num[i]]=1;
            }    
        }

        for(pair<int,int> i:mp){
            if(i.second>n/2){
                return i.first;
            }
        }
        return -1;
    }

int main(){
    vector<int> num = {3,2,3};
    cout<<"The majority element is: ";
    cout<<majorityElement(num)<<endl;
    return 0;
}    