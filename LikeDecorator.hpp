#ifndef LIKEDECORATOR_HPP
#define LIKEDECORATOR_HPP

#include "PostDecorator.hpp"
using namespace std;

class LikeDecorator : virtual public PostDecorator{
private:
    Post* currentPost;
public:
    LikeDecorator(Post* currentPost);
    void like();
    virtual void showPostDetails();
};

#endif