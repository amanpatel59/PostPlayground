#include "PostFacade.hpp"
#include <iostream>
using namespace std;

PostFacade::PostFacade(Post* currentPost) : PostDecorator(currentPost),LikeDecorator(currentPost),CommentDecorator(currentPost) {}

void PostFacade::showPostDetails(){
    PostDecorator::showPostDetails();
    LikeDecorator::showPostDetails();
    CommentDecorator::showPostDetails();
}