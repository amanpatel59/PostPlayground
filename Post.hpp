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
    unordered_set<string> tags;
    unordered_set<string> mentions;
    User* creator;  // Pointer to the User who created the post
public:
    Post(string content, User* creator);

    void setPrivacy(string newPrivacySettings);
    string getPrivacy();
    void addTag(string taggedUser);
    void addMention(string mentionedUser);
    void showPostDetails();
    User* getCreator() const;
};

#endif // POST_HPP
