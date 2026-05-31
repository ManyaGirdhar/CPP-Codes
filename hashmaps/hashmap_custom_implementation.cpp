#include<iostream>
using namespace std;

template <typename V>
class mapnode{
public:                       //or private and then to access in mymap class make it the friend class
    string key;
    V value;
    mapnode* next;

    mapnode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapnode(){
        delete next;           //recursive so it will whole linkedlist
    }
};

template <typename V>
class mymap{
private:
    mapnode<V>** buckets;        //array
    int count;
    int numbucket;       //bucketsize

    int getindex(string key){
        int hashcode = 0;

        int base = 1;
        int p = 37;
        for(int i=key.size()-1; i>=0; i--){     //traversing the string
            hashcode += key[i] * base;
            base = base * p;

            hashcode = hashcode%numbucket;    //property of modulus operator
            base = base%numbucket;
        }

        return hashcode % numbucket;
    }

public:
    mymap(){
        count = 0;
        numbucket = 5;
        buckets = new mymap<V>* [numbucket];
        for(int i = 0; i<numbucket; i++){
            buckets[i] = NULL;
        }
    }
    ~mymap(){
        for(int i=0; i<numbucket; i++){
            delete buckets[i];          //deleting all the linkedlists first
        }
        delete []buckets;              //The [] after delete specifies that the pointer being deleted is an array pointer
    }
    int size(){
        return count;
    }
    V getvalue(string key){
        int bucketindex = getindex(key);               //reach to the index
        mapnode<V>* head = bucket[bucketindex];        //then get the head of linkedlist
        while(head != NULL){                           //traverse the linkedlist to get the value
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;                                      //key not present
    }
    void insert(string key, V value){
        int bucketindex = getindex(key);            //hash function
        mapnode<V>* head = bucket[bucketindex];
        while(head != NULL){                       //if key already present
            if(head -> key == key){
                head -> value = value;
                return;
            }
            head = head -> next;
        }

        //if key not present
        mapnode<V>* newhead = new mapnode<V>(key, value);
        newhead -> next = buckets[bucketindex];
        buckets[bucketindex] = newhead;

        count++;                                           //one node increased
    }
    V remove(string key){
        int bucketindex = getindex(key);
        mapnode<V>* prev = new mapnode<V>(key, value);
        mapnode<V>* head = new mapnode<V>(key, value);       //current node

        while(head!=NULL){
            if(head->key == key){
                if(prev == NULL){                       //head itself 
                    buckets[bucketindex] = head->next;
                }     
                else{
                    prev->next = head->next;
                } 

                V value = head->value;       
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
        }

        return 0;                             //if key not present then return 0;
    }
};

int main(){
    
}