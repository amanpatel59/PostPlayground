#include "GlobalFeed.hpp"
#include "PostFacade.hpp"

using namespace std;

unordered_set<Post*> GlobalFeed::generalGlobalFeed;

void GlobalFeed::newGlobalPost(Post* post) {
    generalGlobalFeed.insert(post);
}

void GlobalFeed::showGlobalFeed() {
    for (const auto& post : generalGlobalFeed){
        PostFacade* postFacade = new PostFacade(post);
        postFacade->showPostDetails();
    }
}


Post* GlobalFeed::getPost(string postId){
    for(auto post : generalGlobalFeed){
        if(post->getPostId() == postId)return post;
    }
    return nullptr;
}
