#include "CommentDecorator.hpp"
#include "PostDecorator.hpp"
#include <iostream>
#include <unordered_set>

using namespace std;

CommentDecorator::CommentDecorator(Post* currentPost) : PostDecorator(currentPost) {}

void CommentDecorator::addComment(string comment){
    this->comments.insert(comment);
}

void CommentDecorator::showPostDetails(){
    // Call the base class's showPostDetails method to include the base post's details
    // PostDecorator::showPostDetails();
    if(comments.size() == 0)return;
    cout<<"comments : "<<endl;
    for(auto comment : comments){
        cout<<comment<<endl;
    }
}