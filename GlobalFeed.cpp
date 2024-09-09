#include "GlobalFeed.hpp"

using namespace std;

unordered_set<Post*> GlobalFeed::generalGlobalFeed;

void GlobalFeed::newGlobalPost(Post* post) {
    generalGlobalFeed.insert(post);
}

void GlobalFeed::showGlobalFeed() {
    for (const auto& post : generalGlobalFeed) post->showPostDetails();
}
