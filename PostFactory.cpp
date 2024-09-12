#include "PostFactory.hpp"

using namespace std;

Post* PostFactory::createPost(string type, string content,string privacy, User* creator,string postId) {
    if (type == "simple") {
        return new SimplePost(content,privacy,creator,postId);
    }
    return nullptr;
}
