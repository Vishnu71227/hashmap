#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    cout<<s.size()<<endl;

    cout<<" to remove 4 from the set: "<< s.erase(4)<<"4 is removed"<<endl;

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