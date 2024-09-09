#include "Post.hpp"
#include "User.hpp"
#include <iostream>

using namespace std;

Post::Post(string content, User* creator)
    : content(content), privacy("public"), creator(creator) {}

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
    cout<<"Posted By : "<<creator->getProfile()<<endl<<endl;
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
}

User* Post::getCreator() const {
    return creator;
}
