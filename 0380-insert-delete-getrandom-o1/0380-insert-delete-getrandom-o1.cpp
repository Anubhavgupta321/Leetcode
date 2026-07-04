class RandomizedSet {
    unordered_map<int,int> mpp;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val){
        if(mpp.count(val)) return false;
        nums.push_back(val);
        mpp[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mpp.count(val)) return false;
        int idx=mpp[val];
        int last=nums.back();

        mpp[last]=idx;
        nums[idx]=last;

        mpp.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */