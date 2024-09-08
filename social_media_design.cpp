#include <bits/stdc++.h>

using namespace std;



class Post{
private:
    string content;
    string privacy;
    unordered_set<string>tags;
    unordered_set<string>mentions;
public:
    Post(string content) : content(content) , privacy("public") {}

    void setPrivacy(string newPrivacySettings){
        privacy = newPrivacySettings;
    }

    string getPrivacy(){
        return this->privacy;
    }

    void addTag(string taggedUser){
        tags.insert(taggedUser);
    }

    void addMention(string mentionedUser){
        mentions.insert(mentionedUser);
    }

    void showPostDetails(){
        cout<<"Post : "<<content<<" (Privacy : "<<privacy<<")"<<endl;
        if(!tags.empty()){
            cout<<"Tagged people : ";
            for(auto person : tags)cout<<person<<" ";
            cout<<endl;
        }
        if(!mentions.empty()){
            cout<<"Mentions : ";
            for(auto person : mentions)cout<<person<<" ";
            cout<<endl;
        }
    }
};


class SimplePost : public Post{
public:
    SimplePost(string& content) : Post(content) {}
};


class Comment : public Post{
private:
    vector<Post*>replies;
public:
    Comment(string content) : Post(content) {}

    void addReply(Post* reply){
        replies.push_back(reply);
    }

    void show(){
        Post::showPostDetails();
        for(auto reply : replies)reply->showPostDetails();
    }
};


class PostFactory{
public:
    static Post* createPost(string type , string content){
        if(type == "simple"){
            SimplePost* posting = new SimplePost(content);
            return posting;
        }
        else if(type == "comment"){
            Comment* posting = new Comment(content);
            return posting;
        }
        return nullptr;
    }
};



class User{
private:
    string name;
    vector<User*>followers;
    vector<Post*>posts;
    unordered_set<string>notifications;
public:
    User(string name) : name(name) {}

    void follow(User* toFollow){
        // NEED TO CHECK THIS
        toFollow->followers.push_back(this);
        toFollow->notifications.insert(this->name+" started following");
    }

    // NEED TO COMPLETE
    void makePost(string& postContent , string& privacySettings){}

    void notifyFollowers(){
        for(auto follower : followers)notifications.insert("new noti");
    }

    void showNotifications() {
        if(this->notifications.size() == 0)cout<<"No New Notifications"<<endl;
        for(auto notification : notifications){
            cout<<notification<<endl;
        }
        notifications.clear();
    }

    void showProfile() {
        cout<<"Your userName : "<<name<<endl;
    }

    string getProfile(){
        return this->name;
    }
};

int main(){
    // session manager

    unordered_map<string,User*>allUsers;
    User* user1 = new User("alice");
    User* user2 = new User("bob");
    allUsers["alice"] = user1;
    allUsers["bob"] = user2;
    string command;
    while(true){
        cout<<"Available Commands"<<endl;
        cout<<"1. Follow"<<endl;
        cout<<"2. Post Update"<<endl;
        cout<<"3. Show Notifiacation"<<endl;
        cout<<"4. Show Profile"<<endl;
        cout<<"5. Send Message"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>command;
        int commandNumber = stoi(command);
        switch (commandNumber) {
            case 1: {
                // Follow
                string follower, followee;
                cout << "Enter follower Name: ";
                cin >> follower;
                cout << "Enter followee Name: ";
                cin >> followee;

                // Checking if given users exist or not
                if (allUsers.find(follower) != allUsers.end() && allUsers.find(followee) != allUsers.end()) {
                    allUsers[follower]->follow(allUsers[followee]);
                    cout << follower << " started following " << followee << endl;
                } else {
                    cout << "User/Users not found" << endl;
                }
                break;  // Important to end this case
            }
            case 2: {
                string userName, postContent, privacySettings;
                cout << "Enter user's name: ";
                cin >> userName;
                cout << "Enter post content: ";
                cin.ignore();  // To ignore the newline character left in the buffer
                getline(cin, postContent);
                cout << "Enter privacy setting (public/friends): ";
                cin >> privacySettings;

                // Checking if the given user exists
                if (allUsers.find(userName) != allUsers.end()) {
                    allUsers[userName]->makePost(postContent, privacySettings);
                    cout << userName << " just posted" << endl;
                } else {
                    cout << "User not found" << endl;
                }
                break;  // Important to end this case
            }
            case 3: {
                // Show Notifications
                string userName;
                cout << "Enter user's name: ";
                cin >> userName;

                // Checking if the given user exists
                if (allUsers.find(userName) != allUsers.end()) {
                    allUsers[userName]->showNotifications();
                } else {
                    cout << "User not found" << endl;
                }
                break;  // Important to end this case
            }
            case 4: {
                // Show Profile
                string userName;
                cout << "Enter user's name: ";
                cin >> userName;

                // Checking if the given user exists
                if (allUsers.find(userName) != allUsers.end()) {
                    allUsers[userName]->showProfile();
                } else {
                    cout << "User not found" << endl;
                }
                break;  // Important to end this case
            }
            case 5: {
                // Send Message
                // Implementation needed
                break;  // Important to end this case
            }
            default: {
                cout << "Invalid command" << endl;
                break;  // Optional: Handle invalid commands
            }
        }
         
    }
    return 0;
}