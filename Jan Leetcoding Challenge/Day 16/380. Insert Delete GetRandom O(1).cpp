// create a vector and map to store the value and index of the element 
// for insert we check if the element is present in the map ornot , if not we pushback the element into vector , its index in map and return true

// for remove first search in map if the element is present in the map if not return false .
// store the index of the element which is to be removed , then send the element to the back of vector .
//  swap the last element to the curr index
// update the value in the map 
// pop back the last element
// erase from map
// return true;

// for random element use rand()%n to generate any random number where n is the size of vector

class RandomizedSet {
public:
    vector<int>vec;
    unordered_map<int,int> mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())    // search for element in map
        return false;

        vec.push_back(val);             // push the val into vector
        mp[val] = vec.size()-1;         // assign the index
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())      // check for element in map
        return false;

        int ind = mp[val];              // find idx of element which is to be removed
        int lastElement = vec.back();   // put that element at last of vector
        vec.back()=val;                  

        vec[ind]=lastElement;           // swap the elements
        mp[lastElement]=ind;            // idx of last element will become idx of curr idx

        vec.pop_back();                 // pop the last element
        mp.erase(val);                  // delete element from map
        return true;
    }
    
    int getRandom() {
        int n = vec.size();             
        int random = rand()%n;          // use rand() for generating random number
        return vec[random];             // return random number
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
