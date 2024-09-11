#ifndef LIKEDECORATOR_HPP
#define LIKEDECORATOR_HPP

#include "PostDecorator.hpp"
using namespace std;

class LikeDecorator : virtual public PostDecorator{
private:
    Post* currentPost;
public:
    LikeDecorator(Post* currentPost);
    void like(string userWhoInitialized);
    void unlike(unordered_set<string>&currentLikes , string userWhoInitialized);
    virtual void showPostDetails();
};

#endif