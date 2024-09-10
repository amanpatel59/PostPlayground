#ifndef GLOBALFEED_HPP
#define GLOBALFEED_HPP

#include "Post.hpp"
#include <unordered_set>

using namespace std;

class GlobalFeed {
private:
    static unordered_set<Post*> generalGlobalFeed;
public:
    static void newGlobalPost(Post* post);
    static void showGlobalFeed();
    static Post* getPost(string postId);
};

#endif // GLOBALFEED_HPP
