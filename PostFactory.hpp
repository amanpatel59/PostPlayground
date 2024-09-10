#ifndef POSTFACTORY_HPP
#define POSTFACTORY_HPP

#include "Post.hpp"
#include "SimplePost.hpp"
#include "Comment.hpp"

using namespace std;

class PostFactory {
public:
    static Post* createPost(string type, string content, User* creator,string postId);
};

#endif // POSTFACTORY_HPP
