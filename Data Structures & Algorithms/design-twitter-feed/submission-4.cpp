class Twitter {
private:
    int globalTime = 0; 
    unordered_map<int,int> userTweets;
    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq; 
    unordered_map<int, unordered_set<int> > userFollowees;

    queue<pair<int,int>> q; 
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[tweetId] = userId;
        pq.push({globalTime++, tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 10; 
        vector<int> feed;
        auto pq2 = pq;
        while(!pq2.empty() && count > 0){
            int currTweet = pq2.top().second;
            int currUser = userTweets[currTweet]; 

            if(currUser == userId || userFollowees[userId].find(currUser) != userFollowees[userId].end()){
                feed.push_back(currTweet);
                count--;
            }
            pq2.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowees[followerId].erase(followeeId);
    }
};
