#include "SimplePost.hpp"

using namespace std;

SimplePost::SimplePost(string& content, User* creator , string postId) : Post(content, creator,postId) {}
