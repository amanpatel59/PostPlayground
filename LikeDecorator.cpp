#include "LikeDecorator.hpp"
#include <iostream>

using namespace std;

LikeDecorator::LikeDecorator(Post* currentPost) : PostDecorator(currentPost) , currentPost(currentPost) {}

void LikeDecorator::like(){
    currentPost->setLikes(currentPost->getLikes()+1);
}

void LikeDecorator::showPostDetails(){
    // PostDecorator::showPostDetails();
    cout<<"Likes : "<<currentPost->getLikes()<<endl;
}