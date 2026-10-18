#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class node{
    public:
    string key;
    int value;
    node* next;

    node(string key, int value){
        this->key = key;
        this->value = value;
        next = NULL;

    }

     ~node(){
        if(next!=NULL){
            delete next;
        }
     }
};

class  hashtable{
    node** table;
    int total_size;
    int current_size;

    int hashfunction(string key){
        //simple hash function
        int idx=0;
        for(int i=0;i<key.size();i++){        
            idx+=(key[i]*key[i])%total_size;
        }
        return idx%total_size;
    }

    void rehash(){  // tc=O(n)
        node** oldtable = table;
        int oldsize = total_size;

        total_size = 2*total_size;
        current_size = 0;
        table = new node*[total_size];

        for(int i=0;i<total_size;i++){
            table[i] = NULL;
        }

        // we  can copy the old va;ues from old table into new table
        for(int i=0;i<oldsize;i++){
            node* temp = oldtable[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp = temp->next;
            }

            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
        delete[] oldtable;
    }

    public:

    hashtable(int size){
        total_size = size;
        current_size = 0;

        table = new node*[total_size];

        for(int i=0;i<total_size;i++){
            table[i] = NULL;
        }  
    }

    void insert(string key, int value){  // O(1) in avg case
        int idx = hashfunction(key);

        node* newnode = new node(key,value);
        node* head = table[idx];
        newnode->next = table[idx];
        table[idx] = newnode;

        current_size++;

        double lambda = current_size/(double)total_size;

        if(lambda>1){
            rehash();//O(n) in worst case
        }
    }

    bool exits(string key){
        int idx = hashfunction(key);

        node* temp = table[idx];
        while(temp!=NULL){
            if(temp->key == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    int search(string key){
        int idx = hashfunction(key);

        node* temp = table[idx];
        while(temp!=NULL){
            if(temp->key == key){
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }

    void remove(string key){
        int idx = hashfunction(key);

        node*temp = table[idx];
        node* prev = temp;

        while(temp!=NULL){
            if(temp->key == key){ // now erase the node
                if(prev == temp){  // now delete head it is the head node in this case
                    table[idx] = temp->next;
                }else{
                    prev->next = temp->next;
                }
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    } 

    void print(){
        for(int i=0;i<total_size;i++){
            cout<<" idx "<<i<<" -> ";
            node* temp = table[i];
            while(temp!=NULL){
                cout<<temp->key<<" -> "<<temp->value<<" , ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    hashtable ht(7);

    ht.insert("india",150);
    ht.insert("china",150);
    ht.insert("us",50);
    ht.insert("nepal",10);

    ht.print();

    ht.remove("india");

    ht.print();

    if(ht.exits("india")){
        cout<<"India is present and its population is: "<<ht.search("india")<<endl;
    }
    else{
        cout<<"India is not present"<<endl;
    }



    return 0;
}