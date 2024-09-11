#include "PostDecorator.hpp"

using namespace std;

PostDecorator::PostDecorator(Post* basePost) : Post(basePost->getContent(),basePost->getPrivacy(),basePost->getCreator(),basePost->getPostId()) , basePost(basePost) {}

void PostDecorator::showPostDetails(){
    Post::showPostDetails();
}