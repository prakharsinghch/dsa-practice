class Solution {
public:

    struct Node{
        Node* arr[2];

        bool contains(int i){
            return arr[i];
        }

        Node* get(int i){
            return arr[i];
        }

        void put(int i, Node* n){
            arr[i] = n;
        }

    };

    Node* root;

    void insert(int x){
        Node* n = root;

        for(int i = 31; i>=0;i--){
            int b = (x>>i) & 1;
            if(!n->contains(b)) n->put(b,new Node());

            n = n->get(b);
        }
    }

    int maxXOR(int x){
        Node* n = root;
        int res = 0;
        for(int i = 31; i>=0;i--){
            int b = (x>>i) & 1;
            if(n->contains(1-b)) {
                res = res | (1<<i);
                n = n->get(1-b);
            }
            else n = n->get(b);
        }

        return res;
    }

    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        root =  new Node();
        // for(int i = 0;i<nums.size();i++){
        //     for(int j=0;j<nums.size();j++){
        //         if(i == j) continue;
        //         else{
        //             ans = max(ans, nums[i]^nums[j]);
        //         }
        //     }
        // }

        for(auto x: nums) insert(x);
        
        for(auto x: nums){
            ans =  max(ans, maxXOR(x));
        }       
        
        return ans;
    }
};