
#include<iostream>
#include<vector>



#define EMPTY -1

using namespace std;


struct hash_node{
    int key;
    int value;
    hash_node(){
        key = 0;
        value = 0;
    }
    hash_node(int key_, int value_){
        key = key_;
        value = value_;
    }
};


class HashMap {
    private:
        int size;
        vector<int> key_slots;
        vector<int> value_slots;

    public:
        vector<hash_node> hash_array;

        HashMap(int size_){
            size = size_;
            hash_node new_hash_node;
            for (int i = 0; i < size; i++)
            {
                new_hash_node = hash_node(EMPTY, EMPTY);
                hash_array.push_back(new_hash_node);
            }

        }

        int insert_to_hash_map(int key_ , int value_){
            int place = add_hash_function(key_);
            if (place == -1)
                return -1;
            else{
                hash_array[place].key = key_;
                hash_array[place].value = value_;
                return 1;
            }
        }


        int find_element(int key_){
            int place = find_hash_function(key_);
            if (place == -1){
                // cout<<"Element not found";
                return -1;
            }
            else if (place == -2){
                // cout<<"Hash Full and Element not found";
                return -1;
            }
            else{
                return place;
            }
        }





        int add_hash_function(int key){
            int place = hash_function(key);
            // cout<<"place is "<<place<<endl;
            if (hash_array[place].key == EMPTY)
                return place;
            else
                return add_hash_function_probe(key, 1, place);

        }
        int add_hash_function_probe(int key, int probe, int base_place){
            int place = hash_function(key + probe);
            // cout<<"place is "<<place<<endl;
            if(hash_array[place].key == EMPTY)
                return place;
            else if (hash_array[place].key != EMPTY && place  != base_place)
                return add_hash_function_probe(key, probe+1, base_place);
            else
                return -1;
            
        }

        int hash_function(int key){
            return key % size;
        }

        int find_hash_function(int key){
            int place = hash_function(key);
            if(hash_array[place].key == key)
                return place;
            else if (hash_array[place].key == EMPTY)
                return -1;
            else{
                return find_hash_function_probe(key, 1);
            }
        }

        int find_hash_function_probe(int key, int probe){
            int place = hash_function(key+probe);
            if(hash_array[place].key == key)
                return place;
            else {
                if (place == EMPTY)
                    return -1;
                else if (place == key){
                    return -2;
                }
                else
                    return find_hash_function_probe(key, probe+1);
            }
        }


};


void display_hash(HashMap newHash, int hash_size){

    for( int i = 0; i < hash_size; i++ ){
        cout<<newHash.hash_array[i].key<<"\t"<<newHash.hash_array[i].value<<endl;
    }

}

int main(){


    // coding for hashing. created a empty array of structure called Hashmap. Multipple Hashmaps objects can be created.


    int hash_size = 10;
    HashMap newHash = HashMap(hash_size);


    display_hash(newHash, hash_size);
    
    for(int i = 0 ; i < hash_size/2; i++ )
        newHash.insert_to_hash_map(i,i);
    display_hash(newHash, hash_size);

    
    for(int i = 0 ; i < hash_size*2; i++ ){
        if (newHash.insert_to_hash_map(i+hash_size,i) == 1){
            cout<<"entering value "<<i+hash_size<<endl<<"Hash updated"<<endl;
            display_hash(newHash, hash_size);
        }
        else    
            cout<<"Hash FULL"<<"\tCan't insert "<<i+hash_size<<endl;
    }


    return 0;
}