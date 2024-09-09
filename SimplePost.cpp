#include "SimplePost.hpp"

using namespace std;

SimplePost::SimplePost(string& content, User* creator)
    : Post(content, creator) {}
