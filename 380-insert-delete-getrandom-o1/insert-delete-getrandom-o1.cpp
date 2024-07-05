#include <vector>
#include <unordered_map>
#include <cstdlib>

class RandomizedSet {
public:
    vector<int> vec1;
    unordered_map<int, int> mp;

    RandomizedSet() {
    }

    bool insert(int val) {
        if (mp.find(val) != mp.end())
            return false;
        vec1.push_back(val);
        mp[val] = vec1.size() - 1;
        return true;    
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;
        int index = mp[val];
        int lastElement = vec1.back();

        
        vec1[index] = lastElement;
        mp[lastElement] = index;

        // last element ko remove karay ga
        vec1.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        int n = vec1.size();
        int random = rand() % n; //let n=5 pher ye 0 say 4 tak value dy ga;
        return vec1[random];
    }
};



/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */