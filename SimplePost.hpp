#ifndef SIMPLEPOST_HPP
#define SIMPLEPOST_HPP

#include "Post.hpp"

using namespace std;

class SimplePost : public Post {
public:
    SimplePost(string& content, User* creator,string postId="");
};

#endif // SIMPLEPOST_HPP
