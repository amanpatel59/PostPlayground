
#include "User.hpp"
#include "Post.hpp"
#include "PostFactory.hpp"
#include "GlobalFeed.hpp"
#include "PostFacade.hpp"
#include <bits/stdc++.h>

using namespace std;

User::User(string name) : name(name) {}

void User::follow(User* toFollow) {
    toFollow->followers.push_back(this);
    toFollow->notifications.insert(name + " started following");
}

void User::makePost(string& postContent, string& privacySettings) {
    string postId = this->name+to_string(posts.size()+1);
    Post* newPost = PostFactory::createPost("simple", postContent, this, postId);
    newPost->setPostId();
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
        PostFacade* postFacade = new PostFacade(post);
        postFacade->showPostDetails();
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

void User::likePost(string currentPostId, string postType){
    // transform(postType.begin(), postType.end(), postType.begin(), toLower);
    if(postType == "public"){
        Post* currentPost = GlobalFeed::getPost(currentPostId);
        LikeDecorator* decorateCurrentPost = new LikeDecorator(currentPost);
        decorateCurrentPost->like();
    }
    else{
        for(auto post : userFeed){
            if(currentPostId == post->getPostId()){
                LikeDecorator* decorateCurrentPost = new LikeDecorator(post);
                decorateCurrentPost->like();
            }
        }
    }
}

void User::commentPost(string currentPostId, string postType , string commentToPost){
    // transform(postType.begin(), postType.end(), postType.begin(), toLower);
    if(postType == "public"){
        Post* currentPost = GlobalFeed::getPost(currentPostId);
        CommentDecorator* decorateCurrentPost = new CommentDecorator(currentPost);
        decorateCurrentPost->addComment(commentToPost);
    }
    else{
        for(auto post : userFeed){
            if(currentPostId == post->getPostId()){
                CommentDecorator* decorateCurrentPost = new CommentDecorator(post);
                decorateCurrentPost->addComment(commentToPost);
            }
        }
    }
}

int User::getNumberOfPosts(){
    return this->posts.size();
}

string User::getProfile() {
    return name;
}
