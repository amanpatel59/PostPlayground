#include "Observer.hpp"


void Observer::notifyFollowers(User* currentUser){
    unordered_set<User*> followers = currentUser->getFollowers();
    string newNotification = currentUser->getProfile()+" just posted";
    for(auto follower : followers){
        unordered_set<string>notifications = follower->getNotifications();
        notifications.insert(newNotification);
        follower->setNotifications(notifications);
    }
}

void Observer::notifyCreator(User* userWhoInitialized , Post* targetPost , string actionDone){
    unordered_set<User*> followers = targetPost->getCreator()->getFollowers();
    unordered_set<string> notifications = targetPost->getCreator()->getNotifications();
    string newNotification = userWhoInitialized->getProfile()+" just "+actionDone+" on your post with postId = "+targetPost->getPostId();
    notifications.insert(newNotification);
    targetPost->getCreator()->setNotifications(notifications);
}

