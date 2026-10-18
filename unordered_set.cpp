#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    unordered_set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    cout<<s.size()<<endl;

    s.erase(4);

    if(s.find(4)!=s.end()){
        cout<<"India is present and its population is: "<<endl;
    }
    else{
        cout<<"India is not present"<<endl;
    }

    for(int country : s){
        cout<<country<<endl;
    }

    return 0;
}