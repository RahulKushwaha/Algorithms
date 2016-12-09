class compare
{
public:
    bool operator() (pair<int, int>x, pair<int, int>y)
    {
        return x.first < y.first;
    }
};

class Twitter {
public:
    unordered_map<int, unordered_set<int>> userLookup;
    unordered_map<int, list<pair<int, int>>> tweets;
    int timestamp;
    
    /** Initialize your data structure here. */
    Twitter(): timestamp(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_front(make_pair(timestamp++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        unordered_set<int>& friends = userLookup[userId];
        
        for(unordered_set<int>::iterator friendsItr = friends.begin(); friendsItr != friends.end(); friendsItr ++)
        {
            list<pair<int, int>>& userTweets = tweets[*friendsItr];
            for(list<pair<int, int>>::iterator tweetItr = userTweets.begin(); tweetItr != userTweets.end(); tweetItr ++)
            {
                pq.push(*tweetItr);
            }
        }
        
        list<pair<int, int>>& userTweets = tweets[userId];
        for(list<pair<int, int>>::iterator tweetItr = userTweets.begin(); tweetItr != userTweets.end(); tweetItr ++)
        {
            pq.push(*tweetItr);
        }
        
        vector<int> tweets;
        
        for(int i = 0; i < 10 && pq.empty() == false; i ++)
        {
            pair<int, int> top = pq.top();
            tweets.push_back(top.second);
            pq.pop();
        }
        
        return tweets;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
        {
            return;
        }
        
        userLookup[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        userLookup[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */