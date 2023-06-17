class Trie {
public:

    struct Node{
        Node *arr[26];
        bool f = false;

        bool contains(char c){
            return arr[c-'a'] != NULL;
        }

        void put(char c,Node* node){
            arr[c-'a'] = node;
        }

        Node* get(char c){
            return arr[c-'a'];
        }

        void setEnd(){
            f = true;
        }

        bool checkEnd(){
            return f;
        }


    };

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* n = root;
        for(int i=0;i<word.size();i++){
            if(!n->contains(word[i])) n->put(word[i],new Node());
            n = n->get(word[i]);
        }
        n->setEnd();
    }
    
    bool search(string word) {
        Node* n = root;
        for(int i=0;i<word.size();i++){
            if(!n->contains(word[i])) return false;
            n =n->get(word[i]);
        }
        return n->checkEnd();
    }
    
    bool startsWith(string word) {
         Node* n = root;
        for(int i=0;i<word.size();i++){
            if(!n->contains(word[i])) return false;
            n =n->get(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */