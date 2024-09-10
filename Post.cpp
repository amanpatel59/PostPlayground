#include "Post.hpp"
#include "User.hpp"
#include <iostream>

using namespace std;

Post::Post(string content, User* creator, string currentPostId) : content(content),privacy("public"),creator(creator),postId(currentPostId),likes(0){}

string Post::getContent(){
    return this->content;
}

void Post::setPrivacy(string newPrivacySettings) {
    privacy = newPrivacySettings;
}

string Post::getPrivacy() {
    return privacy;
}

void Post::addTag(string taggedUser) {
    tags.insert(taggedUser);
}

void Post::addMention(string mentionedUser) {
    mentions.insert(mentionedUser);
}

void Post::showPostDetails() {
    cout<<endl;
    cout << "Post : " << content << " (Privacy : " << privacy << ")" << endl;
    cout<<"Posted By : "<<creator->getProfile()<<endl;
    if (!tags.empty()) {
        cout << "Tagged people : ";
        for (const auto& person : tags) cout << person << " ";
        cout << endl;
    }
    if (!mentions.empty()) {
        cout << "Mentions : ";
        for (const auto& person : mentions) cout << person << " ";
        cout << endl;
    }
    cout<<"Post Id : "<<getPostId()<<endl<<"shou"<<endl;
}

User* Post::getCreator() {
    return creator;
}

string Post::getPostId(){
    return this->postId;
}

void Post::setPostId(){
    this->postId = creator->getProfile()+to_string(creator->getNumberOfPosts()+1);
}

void Post::setLikes(int newCountOfLikes){
    this->likes = newCountOfLikes;
}

int Post::getLikes(){
    return this->likes; 
}