#ifndef POSTDECORATOR_HPP
#define POSTDECORATOR_HPP

#include "Post.hpp"

class PostDecorator : public Post{
private:
    Post* basePost;
public:
    PostDecorator(Post* basePost) ; // constructor (not initialized just declared)

    virtual void showPostDetails() override;
};


#endif // POSTDECORATOR_HPP