#include "Comment.hpp"

using namespace std;

Comment::Comment(string content, User* creator)
    : Post(content, creator) {}

void Comment::addReply(Post* reply) {
    replies.push_back(reply);
}

void Comment::show() {
    Post::showPostDetails();
    for (const auto& reply : replies) reply->showPostDetails();
}
