#ifndef COMMENTDECORATOR_HPP
#define COMMENTDECORATOR_HPP

#include "PostDecorator.hpp"
#include <iostream>
#include <unordered_set>

using namespace std;

class CommentDecorator : virtual public PostDecorator{
private:
    Post* currentPost;
public:
    CommentDecorator(Post* currentPost);
    void addComment(string comment);
    virtual void showPostDetails();
};

#endif