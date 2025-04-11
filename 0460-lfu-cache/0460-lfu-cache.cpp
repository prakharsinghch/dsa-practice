class LFUCache {
public:
    unordered_map<int,int> mp;
    unordered_map<int,int> mfq;
    map<int,queue<int>> mq;
    int c;
    LFUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            mfq[key]++;
            mq[mfq[key]].push(key);
            return mp[key];
        }

        return -1;

    }
    
    void put(int key, int value) {
        if(mp.size() == c && mp.find(key) == mp.end()){
            int low = mq.begin()->first;
            while(true){
                while( !mq[low].empty() && mfq[mq[low].front()] != low ){
                    mq[low].pop();
                }
                if(!mq[low].empty()){
                    int key = mq[low].front();
                    mq[low].pop();
                    mp.erase(key);
                    mfq.erase(key);
                    break;
                }
                else{
                    mq.erase(low);
                    low++;
                }
            }
        }

        mp[key] = value;
        mfq[key]++;
        mq[mfq[key]].push(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */