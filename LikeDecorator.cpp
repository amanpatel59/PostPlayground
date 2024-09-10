#include "LikeDecorator.hpp"
#include <iostream>

using namespace std;

LikeDecorator::LikeDecorator(Post* currentPost) : PostDecorator(currentPost) {}

void LikeDecorator::like(){
    this->likes++;
}

void LikeDecorator::showPostDetails(){
    // PostDecorator::showPostDetails();
    cout<<"Likes : "<<this->likes<<endl;
}