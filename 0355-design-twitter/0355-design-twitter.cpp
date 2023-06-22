class Twitter {
public:
    map<int,map<int,int>> follower;
    Twitter() {
        
    }

    vector<pair<int,int>> post;
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int n = post.size()-1,count=10;
        while(n>= 0 && count>0){
            if(post[n].first == userId || follower[userId][post[n].first]){
                feed.push_back(post[n].second);
                count--;
            }
            n--;
        }   
        return feed;    
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId][followeeId] = 0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */