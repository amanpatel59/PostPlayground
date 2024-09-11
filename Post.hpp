#ifndef POST_HPP
#define POST_HPP

#include <string>
#include <unordered_set>
using namespace std;

class User;

class Post {
private:
    string content;
    string privacy;
    string postId;
    unordered_set<string> tags;
    unordered_set<string> mentions;
    User* creator;  // Pointer to the User who created the post
    unordered_set<string> likes;
    unordered_set<string>comments;
public:
    Post(string content,string privacy, User* creator , string currentPostId); // constructor (not initialized just declared)
    
    string getContent();
    void setPrivacy(string newPrivacySettings);
    string getPrivacy();
    void addTag(string taggedUser);
    void addMention(string mentionedUser);
    virtual void showPostDetails();
    User* getCreator();
    string getPostId();
    void setPostId();
    void setLikes(unordered_set<string> newLikeList);
    unordered_set<string> getLikes();
    void setComments(unordered_set<string> newCommentList);
    unordered_set<string> getComments();
};

#endif // POST_HPP
