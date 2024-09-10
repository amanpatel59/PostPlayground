#include "PostFactory.hpp"

using namespace std;

Post* PostFactory::createPost(string type, string content, User* creator,string postId) {
    if (type == "simple") {
        return new SimplePost(content, creator,postId);
    } else if (type == "comment") {
        return new Comment(content, creator,postId);
    }
    return nullptr;
}
