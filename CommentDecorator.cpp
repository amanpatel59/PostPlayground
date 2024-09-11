#include "CommentDecorator.hpp"
#include "PostDecorator.hpp"
#include <iostream>
#include <unordered_set>

using namespace std;

CommentDecorator::CommentDecorator(Post* currentPost) : PostDecorator(currentPost) , currentPost(currentPost) {}

void CommentDecorator::addComment(string comment){
    unordered_set<string> currentComments = currentPost->getComments();
    currentComments.insert(comment);
    currentPost->setComments(currentComments);
    cout<<endl<<"You just added a Comment"<<endl;
}

void CommentDecorator::showPostDetails(){
    // Call the base class's showPostDetails method to include the base post's details
    // PostDecorator::showPostDetails();
    unordered_set<string> currentComments = currentPost->getComments();
    if(currentComments.size() == 0)return;
    cout<<"comments : "<<endl;
    for(auto comment : currentComments){
        cout<<"     "<<comment<<endl;
    }
}