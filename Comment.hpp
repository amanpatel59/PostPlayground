#ifndef COMMENT_HPP
#define COMMENT_HPP

#include "Post.hpp"
#include <vector>

using namespace std;

class Comment : public Post {
private:
    vector<Post*> replies;
public:
    Comment(string content, User* creator,string postId);
    void addReply(Post* reply);
    void show();
};

#endif // COMMENT_HPP
