#ifndef LIKEDECORATOR_HPP
#define LIKEDECORATOR_HPP

#include "PostDecorator.hpp"
#include "User.hpp"
using namespace std;

class LikeDecorator : virtual public PostDecorator{
private:
    Post* currentPost;
public:
    LikeDecorator(Post* currentPost);
    void like(User* userWhoInitialized);
    void unlike(unordered_set<string>&currentLikes , User* userWhoInitialized);
    virtual void showPostDetails();
};

#endif