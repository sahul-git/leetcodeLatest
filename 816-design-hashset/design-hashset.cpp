class MyHashSet {
    vector<int> hashSet;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        for(auto ele : hashSet){
            if(ele == key){
                return;
            }
        }
        
        hashSet.push_back(key);
            
    }
    
    void remove(int key) {
        int i=-1;
        for(int j=0; j<hashSet.size(); j++){
            if(hashSet[j] == key){
                i = j ;
                break;
            }

        }
        if( i!= -1){
            swap(hashSet[i], hashSet.back());
            hashSet.pop_back();
        }
        

    }
    
    bool contains(int key) {
        for(int j=0; j<hashSet.size(); j++){
            if(hashSet[j] == key){
               return true;
            }


        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */