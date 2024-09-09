#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <unordered_set>
#include "Post.hpp"

using namespace std;

class User {
private:
    string name;
    vector<User*> followers;
    vector<Post*> posts;
    unordered_set<string> notifications;
    unordered_set<Post*> userFeed;
public:
    User(string name);

    void follow(User* toFollow);
    void makePost(string& postContent, string& privacySettings);
    void pushPostToFollowerFeed(Post* newPost);
    void showFeed();
    void notifyFollowersRegardingPost();
    void showNotifications();
    void showProfile();
    string getProfile();
};

#endif // USER_HPP
