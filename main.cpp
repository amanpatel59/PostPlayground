#include <iostream>
#include <string>
#include <unordered_map>
#include "User.hpp"
#include "Post.hpp"
#include "SimplePost.hpp"
#include "Comment.hpp"
#include "PostFactory.hpp"
#include "GlobalFeed.hpp"
#include "Post.hpp"
#include "LikeDecorator.hpp"
#include "CommentDecorator.hpp"

using namespace std;

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
        cout << "7. Like a Post" << endl;
        cout << "8. Comment on a Post" << endl;
        cout << "9. Send Message" << endl;
        cout << "10. Exit" << endl;
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
            case 7: {
                string userName , postId , postType;
                cout<<"Enter user name who wants to like : ";
                cin>>userName;
                cout<<"Enter Post Id : ";
                cin>>postId;
                cout<<"Enter Post Type (public/friends) : ";
                cin>>postType;
                if (allUsers.find(userName) != allUsers.end()) {
                    allUsers[userName]->likePost(postId,postType);
                } else {
                    cout << "User not found" << endl;
                }
                break;
            }
            case 8: {
                string userName , postId , postType , comment;
                cout<<"Enter user name who wants to comment : ";
                cin>>userName;
                cout<<"Enter Post Id : ";
                cin>>postId;
                cout<<"Enter Post Type (public/friends) : ";
                cin>>postType;
                cout<<"Enter the comment : ";
                cin.ignore();
                getline(cin, comment);
                if (allUsers.find(userName) != allUsers.end()) {
                    allUsers[userName]->commentPost(postId,postType,comment);
                } else {
                    cout << "User not found" << endl;
                }
                break;
            }
            case 9: {
                // Send Message
                string sender , receiver , message;
                cout<<"Enter who wants to send the message : ";
                cin>>sender;
                cout<<"Enter to whom you want to send message : ";
                cin>>receiver;
                if(allUsers.find(sender) == allUsers.end() or allUsers.find(receiver) == allUsers.end()){
                    cout<<"User/Users not found"<<endl;
                }
                else if(allUsers[sender]->isFollower(allUsers[receiver]) == 0 or allUsers[receiver]->isFollower(allUsers[sender]) == 0){
                    cout<<"sender and receiver must follow each other for exchanging messages"<<endl;
                }
                else{
                    cout<<"Enter the message you want to send : ";
                    cin.ignore();
                    getline(cin,message);
                    // cout<<"message send !"<<endl;

                    cout<<endl<<"=================================="<<endl;
                    allUsers[sender]->sendMessage(allUsers[receiver],message);
                    allUsers[sender]->showMessageHistory(allUsers[sender],allUsers[receiver]);
                    cout<<endl<<"=================================="<<endl;
                }
                break;
            }
            case 10: {
                // Exit the program
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid command" << endl;
                break;
            }
        }
    }

    return 0;
}
