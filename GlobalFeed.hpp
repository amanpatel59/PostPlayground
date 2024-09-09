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
};

#endif // GLOBALFEED_HPP
