#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    map<string,int> mp;

    mp["india"] = 100;
    mp["us"] = 50;
    mp["china"] = 150;
    mp["nepal"] = 10;

    cout<<mp["india"]<<endl;
    mp.erase("india");

    for(pair<string,int> country : mp){
        cout<<country.first<<" , "<<country.second<<endl;
    }

    if(mp.count("india")){
        cout<<"India is present and its population is: "<<mp["india"]<<endl;
    }
    else{
        cout<<"India is not present"<<endl;
    }
}