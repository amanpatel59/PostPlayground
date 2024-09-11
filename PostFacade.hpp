#ifndef POSTFACADE_HPP
#define POATFACADE_HPP
#include <iostream>
using namespace std;

#include "PostDecorator.hpp"
#include "LikeDecorator.hpp"
#include "CommentDecorator.hpp"

class PostFacade : public LikeDecorator , CommentDecorator{
private:
    string userWhoInitiated;
public:
    PostFacade(Post* currentPost);

    void showPostDetails();
};

#endif