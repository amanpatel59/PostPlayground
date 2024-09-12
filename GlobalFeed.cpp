#include "GlobalFeed.hpp"
#include "PostFacade.hpp"

using namespace std;

unordered_set<Post*> GlobalFeed::generalGlobalFeed;

void GlobalFeed::newGlobalPost(Post* post) {
    generalGlobalFeed.insert(post);
}

void GlobalFeed::showGlobalFeed() {
    cout<<"============= Global feed ============="<<endl;
    for (const auto& post : generalGlobalFeed){
        PostFacade* postFacade = new PostFacade(post);
        postFacade->showPostDetails();
    }
    cout<<"======================================="<<endl;
}


Post* GlobalFeed::getPost(string postId){
    for(auto post : generalGlobalFeed){
        if(post->getPostId() == postId)return post;
    }
    return nullptr;
}
