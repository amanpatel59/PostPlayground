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
    int likes;
    unordered_set<string>comments;
public:
    Post(string content, User* creator , string currentPostId); // constructor (not initialized just declared)
    
    string getContent();
    void setPrivacy(string newPrivacySettings);
    string getPrivacy();
    void addTag(string taggedUser);
    void addMention(string mentionedUser);
    virtual void showPostDetails();
    User* getCreator();
    string getPostId();
    void setPostId();
    void setLikes(int newCountOfLikes);
    int getLikes();
};

#endif // POST_HPP
