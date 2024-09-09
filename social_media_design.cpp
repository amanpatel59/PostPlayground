#include <bits/stdc++.h>

using namespace std;


// Forward declaration
class User;
class Post;

class Post {
private:
    string content;
    string privacy;
    unordered_set<string> tags;
    unordered_set<string> mentions;
    User* creator;  // Pointer to the User who created the post
public:
    Post(string content, User* creator) : content(content), privacy("public"), creator(creator) {}

    void setPrivacy(string newPrivacySettings) {
        privacy = newPrivacySettings;
    }

    string getPrivacy() {
        return this->privacy;
    }

    void addTag(string taggedUser) {
        tags.insert(taggedUser);
    }

    void addMention(string mentionedUser) {
        mentions.insert(mentionedUser);
    }

    void showPostDetails() {
        cout << "Post : " << content << " (Privacy : " << privacy << ")" << endl;
        
        if (!tags.empty()) {
            cout << "Tagged people : ";
            for (auto person : tags) cout << person << " ";
            cout << endl;
        }
        if (!mentions.empty()) {
            cout << "Mentions : ";
            for (auto person : mentions) cout << person << " ";
            cout << endl;
        }
    }

    User* getCreator() const {
        return creator;
    }
};

class GlobalFeed {
private:
    static unordered_set<Post*> generalGlobalFeed;
public:
    static void newGlobalPost(Post* post) {
        generalGlobalFeed.insert(post);
    }

    static void showGlobalFeed() {
        for (auto post : generalGlobalFeed) post->showPostDetails();
    }
};

// Define the static member
unordered_set<Post*> GlobalFeed::generalGlobalFeed;

class SimplePost : public Post {
public:
    SimplePost(string& content, User* creator) : Post(content, creator) {}
};

class Comment : public Post {
private:
    vector<Post*> replies;
public:
    Comment(string content, User* creator) : Post(content, creator) {}

    void addReply(Post* reply) {
        replies.push_back(reply);
    }

    void show() {
        Post::showPostDetails();
        for (auto reply : replies) reply->showPostDetails();
    }
};

class PostFactory {
public:
    static Post* createPost(string type, string content, User* creator) {
        if (type == "simple") {
            return new SimplePost(content, creator);
        } else if (type == "comment") {
            return new Comment(content, creator);
        }
        return nullptr;
    }
};

class User {
private:
    string name;
    vector<User*> followers;
    vector<Post*> posts;
    unordered_set<string> notifications;
    unordered_set<Post*> userFeed;
public:
    User(string name) : name(name) {}

    void follow(User* toFollow) {
        toFollow->followers.push_back(this);
        toFollow->notifications.insert(this->name + " started following");
    }

    void makePost(string& postContent, string& privacySettings) {
        Post* newPost = PostFactory::createPost("simple", postContent, this);
        newPost->showPostDetails();
        this->posts.push_back(newPost);
        notifyFollowersRegardingPost();
        pushPostToFollowerFeed(newPost);
        if (privacySettings == "public") GlobalFeed::newGlobalPost(newPost);
    }

    void pushPostToFollowerFeed(Post* newPost) {
        for (auto follower : followers) {
            follower->userFeed.insert(newPost);
        }
    }

    void showFeed() {
        for (auto post : userFeed) {
            post->showPostDetails();
        }
    }

    void notifyFollowersRegardingPost() {
        for (auto follower : followers) {
            follower->notifications.insert(this->name + " just posted an update");
        }
    }

    void showNotifications() {
        if (this->notifications.size() == 0) cout << "No New Notifications" << endl;
        for (auto notification : notifications) {
            cout << notification << endl;
        }
        notifications.clear();
    }

    void showProfile() {
        cout << "Your userName : " << name << endl;
    }

    string getProfile() {
        return this->name;
    }
};

int main() {
    unordered_map<string, User*> allUsers;
    User* user1 = new User("alice");
    User* user2 = new User("bob");
    allUsers["alice"] = user1;
    allUsers["bob"] = user2;
    string command;
    while (true) {
        cout << endl << endl;
        cout << "Available Commands" << endl;
        cout << "1. Follow" << endl;
        cout << "2. Post Update" << endl;
        cout << "3. Show Notification" << endl;
        cout << "4. Show Profile" << endl;
        cout << "5. Access Global Feed" << endl;
        cout << "6. Access Specific User Feed" << endl;
        cout << "7. Send Message" << endl;
        cout << "8. Exit" << endl;
        cout << endl << endl;
        cin >> command;
        int commandNumber = stoi(command);
        switch (commandNumber) {
            case 1: {
                string follower, followee;
                cout << "Enter follower Name: ";
                cin >> follower;
                cout << "Enter followee Name: ";
                cin >> followee;
                cout << endl;
                if (allUsers.find(follower) != allUsers.end() && allUsers.find(followee) != allUsers.end()) {
                    allUsers[follower]->follow(allUsers[followee]);
                    cout << follower << " started following " << followee << endl;
                } else {
                    cout << "User/Users not found" << endl;
                }
                break;
            }
            case 2: {
                string userName, postContent, privacySettings;
                cout << "Enter user's name: ";
                cin >> userName;
                cout << "Enter post content: ";
                cin.ignore();
                getline(cin, postContent);
                cout << "Enter privacy setting (public/friends): ";
                cin >> privacySettings;
                cout << endl;

                if (allUsers.find(userName) != allUsers.end()) {
                    allUsers[userName]->makePost(postContent, privacySettings);
                    cout << userName << " just posted" << endl;
                } else {
                    cout << "User not found" << endl;
                }
                break;
            }
            case 3: {
                string userName;
                cout << "Enter user's name: ";
                cin >> userName;
                cout << endl;

                if (allUsers.find(userName) != allUsers.end()) {
                    allUsers[userName]->showNotifications();
                } else {
                    cout << "User not found" << endl;
                }
                break;
            }
            case 4: {
                string userName;
                cout << "Enter user's name: ";
                cin >> userName;
                cout << endl;

                if (allUsers.find(userName) != allUsers.end()) {
                    allUsers[userName]->showProfile();
                } else {
                    cout << "User not found" << endl;
                }
                break;
            }
            case 5: {
                cout << endl;
                GlobalFeed::showGlobalFeed();
                break;
            }
            case 6: {
                cout << "Enter user name : ";
                string userName;
                cin >> userName;

                if (allUsers.find(userName) != allUsers.end()) {
                    allUsers[userName]->showFeed();
                } else {
                    cout << "User not found" << endl;
                }
                break;
            }
            default: {
                cout << "Invalid command" << endl;
                break;
            }
        }
    }
    return 0;
}
