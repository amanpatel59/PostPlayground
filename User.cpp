#include "User.hpp"
#include "Post.hpp"
#include "PostFactory.hpp"
#include "GlobalFeed.hpp"
#include "PostFacade.hpp"
#include <bits/stdc++.h>

using namespace std;

User::User(string name) : name(name) {}

void User::follow(User* toFollow) {
    toFollow->followers.insert(this);
    toFollow->notifications.insert(name + " started following");
}

void User::makePost(string& postContent, string& privacySettings) {
    string postId = this->name+to_string(posts.size()+1);
    Post* newPost = PostFactory::createPost("simple", postContent,privacySettings, this, postId);
    newPost->setPostId();
    newPost->showPostDetails();
    posts.push_back(newPost);
    Observer::notifyFollowers(this);
    pushPostToFollowerFeed(newPost);
    if (privacySettings == "public") GlobalFeed::newGlobalPost(newPost);
}

void User::pushPostToFollowerFeed(Post* newPost) {
    for (const auto& follower : followers) {
        follower->userFeed.insert(newPost);
    }
}

void User::showFeed() {
    if(userFeed.size() == 0){
        cout<<endl<<"========= nothing here ========="<<endl;
        return;
    }
    cout<<endl<<"========= user feed ========="<<endl;
    for (const auto& post : userFeed) {
        PostFacade* postFacade = new PostFacade(post);
        postFacade->showPostDetails();
    }
    cout<<endl<<"============================="<<endl;
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
        if(currentPost == nullptr){
            cout<<"No such Post Exists"<<endl;
            return;
        }
        LikeDecorator* decorateCurrentPost = new LikeDecorator(currentPost);
        decorateCurrentPost->like(this);
        Observer::notifyCreator(this,currentPost,"liked");
    }
    else{
        for(auto post : userFeed){
            if(currentPostId == post->getPostId()){
                LikeDecorator* decorateCurrentPost = new LikeDecorator(post);
                decorateCurrentPost->like(this);
                Observer::notifyCreator(this,post,"liked");
                return;
            }
        }
        cout<<"No such Post Exists"<<endl;
        return;
    }
}

void User::commentPost(string currentPostId, string postType , string commentToPost){
    // transform(postType.begin(), postType.end(), postType.begin(), toLower);
    if(postType == "public"){
        Post* currentPost = GlobalFeed::getPost(currentPostId);
        if(currentPost == nullptr){
            cout<<"No such Post Exists"<<endl;
            return;
        }
        CommentDecorator* decorateCurrentPost = new CommentDecorator(currentPost);
        decorateCurrentPost->addComment(commentToPost);
        Observer::notifyCreator(this,currentPost,"commented "+commentToPost);
    }
    else{
        for(auto post : userFeed){
            if(currentPostId == post->getPostId()){
                CommentDecorator* decorateCurrentPost = new CommentDecorator(post);
                decorateCurrentPost->addComment(commentToPost);
                Observer::notifyCreator(this,post,"commented "+commentToPost);
            }
        }
        cout<<"No such Post Exists"<<endl;
        return;
    }
}

int User::getNumberOfPosts(){
    return this->posts.size();
}

string User::getProfile() {
    return name;
}

unordered_set<User*> User::getFollowers(){
    return this->followers;
}

unordered_set<string> User::getNotifications(){
    return this->notifications;
}

void User::setNotifications(unordered_set<string> updatedNotifications){
    this->notifications = updatedNotifications;
}