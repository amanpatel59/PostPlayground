#include "SimplePost.hpp"

using namespace std;

SimplePost::SimplePost(string& content,string privacy, User* creator , string postId) : Post(content,privacy,creator,postId) {}
