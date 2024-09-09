
#include "User.hpp"
#include "Post.hpp"
#include "PostFactory.hpp"
#include "GlobalFeed.hpp"
#include <iostream>

using namespace std;

User::User(string name) : name(name) {}

void User::follow(User* toFollow) {
    toFollow->followers.push_back(this);
    toFollow->notifications.insert(name + " started following");
}

void User::makePost(string& postContent, string& privacySettings) {
    Post* newPost = PostFactory::createPost("simple", postContent, this);
    newPost->showPostDetails();
    posts.push_back(newPost);
    notifyFollowersRegardingPost();
    pushPostToFollowerFeed(newPost);
    if (privacySettings == "public") GlobalFeed::newGlobalPost(newPost);
}

void User::pushPostToFollowerFeed(Post* newPost) {
    for (const auto& follower : followers) {
        follower->userFeed.insert(newPost);
    }
}

void User::showFeed() {
    for (const auto& post : userFeed) {
        post->showPostDetails();
    }
}

void User::notifyFollowersRegardingPost() {
    for (const auto& follower : followers) {
        follower->notifications.insert(name + " just posted an update");
    }
}

void User::showNotifications() {
    if (notifications.size() == 0) cout << "No New Notifications" << endl;
    for (const auto& notification : notifications) {
        cout << notification << endl;
    }
    notifications.clear();
}

void User::showProfile() {
    cout << "Your userName : " << name << endl;
}

string User::getProfile() {
    return name;
}
