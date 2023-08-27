class Twitter {
private:
    vector<unordered_set<int>> followList;
    vector<vector<pair<int,int>>> tweets;
    int timeStamp;
public:
    Twitter() {
        this->followList = vector<unordered_set<int>>(501);
        this->tweets = vector<vector<pair<int,int>>>(501);
        this->timeStamp = 0;
        for(int i = 1; i <= 500; i++) {
            followList[i].insert(i);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<vector<int>> pq;
        for(auto& following : followList[userId]) {
            if(!tweets[following].empty()) {
                int lastIdx = tweets[following].size() - 1;
                pq.push({tweets[following][lastIdx].first, tweets[following][lastIdx].second, following, lastIdx});
            }
        }
        while(!pq.empty() && result.size() < 10) {
            vector<int> front = pq.top();
            pq.pop();
            int ts = front[0];
            int tweet = front[1];
            int following = front[2];
            int lastIdx = front[3];
            result.push_back(tweet);
            if(lastIdx > 0) {
                pq.push({tweets[following][lastIdx - 1].first, tweets[following][lastIdx - 1].second, following, lastIdx - 1});
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
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