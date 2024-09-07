#include <bits/stdc++.h>

using namespace std;

class User{
private:

public:

    void follow(User* toFollow){}

    void makePost(string& postContent , string& privacySettings){}
};

int main(){
    // session manager

    unordered_map<string,User*>allUsers;

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
        switch(commandNumber){
            case 1 : {
                // Follow
                string follower , followee;
                cout<<"Enter follower Name"<<endl;
                cin>>follower;
                cout<<"Enter followee Name"<<endl;
                cin>>followee;

                // Checking if given users exists or not
                if(allUsers.find(follower) != allUsers.end() and allUsers.find(followee) != allUsers.end()){
                    allUsers[follower]->follow(allUsers[followee]);
                    cout<<follower<<" started following "<<followee<<endl;
                }
                else{
                    cout<<"User/Users not found"<<endl;
                }
            }
            case 2 : {
                string userName , postContent , privacySettings;
                cout<<"Enter user's name : ";
                cin>>userName;
                cout<<"Enter post content : ";
                cin.ignore();
                getline(cin,postContent);
                cout<<"Enter privacy setting (public/friends) : ";
                cin>>privacySettings;

                // Checking if given users exists or not
                if(allUsers.find(userName) != allUsers.end()){
                    allUsers[userName]->makePost(postContent, privacySettings);
                    cout<<userName<<" just posted"<<endl;
                }
                else{
                    cout<<"User/Users not found"<<endl;
                }
            }
        }
         
    }
    return 0;
}