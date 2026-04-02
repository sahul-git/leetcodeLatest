class Twitter {
public:
    priority_queue<vector<int>> maxh;
    vector<vector<int>> followers;
    int time = 0;
    Twitter() {
        followers = vector<vector<int>>(500, vector<int>(500, 0));

    }
    
    void postTweet(int userId, int tweetId) {
        maxh.push({time++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        
        vector<int> tweets;
        vector<vector<int>> temp;
        
        int cnt = 0;  // limit scanning

        while(tweets.size() < 10 && !maxh.empty() && cnt < 100){
            auto topt = maxh.top();
            maxh.pop();
            
            int tweetId = topt[1];
            int user = topt[2];

            if(user == userId || followers[userId][user] == 1){
                tweets.push_back(tweetId);
            }

            temp.push_back(topt);
            cnt++;   // ✅ limit
        }

        for(auto &x : temp){
            maxh.push(x);
        }

        return tweets;
    

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followers[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followers[followerId][followeeId] = 0;
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