#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "Post.hpp"
#include "Observer.hpp"

using namespace std;

class User {
private:
    string name;
    unordered_set<User*> followers;
    vector<Post*> posts;
    unordered_set<string> notifications;
    unordered_set<Post*> userFeed;
    unordered_map<User*,vector<string>>messageStorage;
public:
    User(string name);

    void follow(User* toFollow);
    void makePost(string& postContent, string& privacySettings);
    void pushPostToFollowerFeed(Post* newPost);
    void showFeed();
    void notifyFollowersRegardingPost();
    void showNotifications();
    void showProfile();
    void likePost(string currentPostId, string postType);
    void commentPost(string currentPostId, string postType, string commentToPost);
    int getNumberOfPosts();
    string getProfile();
    unordered_set<User*> getFollowers();
    unordered_set<string> getNotifications();
    void setNotifications(unordered_set<string> updatedNotifications);
    bool isFollower(User* toCheck);
    void sendMessage(User* receiver,string message);
    void showMessageHistory(User* sender, User* receiver);
    void setMessageHistory(User* sender, User* receiver, vector<string>&messages);
    vector<string> getMessageHistory(User* sender, User* receiver);
};

#endif // USER_HPP
