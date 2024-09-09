#include "PostFactory.hpp"

using namespace std;

Post* PostFactory::createPost(string type, string content, User* creator) {
    if (type == "simple") {
        return new SimplePost(content, creator);
    } else if (type == "comment") {
        return new Comment(content, creator);
    }
    return nullptr;
}
