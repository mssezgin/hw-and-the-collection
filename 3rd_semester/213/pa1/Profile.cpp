#include "Profile.h"
#include <iomanip>

Profile::Profile() {

}

Profile::Profile(const std::string &firstname, const std::string &lastname, const std::string &email) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->email = email;
}

const std::string &Profile::getFirstname() const {
    return this->firstname;
}

const std::string &Profile::getLastname() const {
    return this->lastname;
}

const std::string &Profile::getEmail() const {
    return this->email;
}

LinkedList<Profile *> &Profile::getFriends() {
    return this->friends;
}

LinkedList<Post *> &Profile::getLikes() {
    return this->likes;
}

LinkedList<Post *> &Profile::getPosts() {
    return this->posts;
}

void Profile::setFirstname(const std::string &firstname) {
    this->firstname = firstname;
}

void Profile::setLastname(const std::string &lastname) {
    this->lastname = lastname;
}

void Profile::setEmail(const std::string &email) {
    this->email = email;
}

void Profile::addFriend(Profile *profile) {
    this->friends.insertAtTheTail(profile);
}

void Profile::addLike(Post *post) {
    this->likes.insertAtTheTail(post);
}

void Profile::addPost(Post *post) {
    this->posts.insertAtTheTail(post);
}

void Profile::dropFriend(Profile *profile) {
    this->friends.removeNode(profile);
}

void Profile::dropLike(Post *post) {
    this->likes.removeNode(post);
}

void Profile::dropPost(Post *post) {
    this->posts.removeNode(post);
}

std::ostream &operator<<(std::ostream &os, const Profile &profile) {
    os << "firstname: " << profile.firstname;

    os << std::setfill(' ') << std::setw(40) << "friends: [";
    Node<Profile *> *f = profile.friends.getFirstNode();
    while (f) {
        os << f->data->getEmail();
        if (f->next) os << ", ";
        f = f->next;
    }
    os << "]\n";
    
    os << "lastname: " << profile.lastname;

    os << std::setfill(' ') << std::setw(40) << "likes: [";
    Node<Post *> *l = profile.likes.getFirstNode();
    while (l) {
        os << l->data->getPostId();
        if (l->next) os << ", ";
        l = l->next;
    }
    os << "]\n";

    os << "email: " << profile.email;

    os << std::setfill(' ') << std::setw(40) << "posts: [";
    Node<Post *> *p = profile.posts.getFirstNode();
    while (p) {
        os << p->data->getPostId();
        if (p->next) os << ", ";
        p = p->next;
    }
    os << "]\n----------\n";

    return os;
}

bool Profile::operator==(const Profile &rhs) const {
    
    return this->email == rhs.email && this->lastname == rhs.lastname && this->firstname == rhs.firstname;
}

bool Profile::operator!=(const Profile &rhs) const {
    return !(rhs == *this);
}

bool Profile::operator<(const Profile &rhs) const {
    
    if (this->lastname < rhs.lastname) return true;
    else if (this->lastname == rhs.lastname && this->firstname < rhs.firstname) return true;
    else return false;
}

bool Profile::operator>(const Profile &rhs) const {
    return rhs < *this;
}

bool Profile::operator<=(const Profile &rhs) const {
    return !(rhs < *this);
}

bool Profile::operator>=(const Profile &rhs) const {
    return !(*this < rhs);
}
