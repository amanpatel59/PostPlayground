#include "Comment.hpp"

using namespace std;

Comment::Comment(string content,string privacy, User* creator,string postId) : Post(content,privacy,creator,postId) {}

void Comment::addReply(Post* reply) {
    replies.push_back(reply);
}

void Comment::show() {
    Post::showPostDetails();
    for (const auto& reply : replies) reply->showPostDetails();
}
