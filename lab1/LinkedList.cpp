#include "LinkedList.h"
#include <stdexcept>

LinkedList::LinkedList(){
    endOfList = new _List;
    endOfList->prev = endOfList->next = endOfList;
}

LinkedList::LinkedList(const LinkedList & other){
    endOfList = new _List;
    for (_List *i = other.endOfList->next; i != other.endOfList; i = i->next) {
        push_back(i->value);
    }
}

LinkedList::LinkedList(LinkedList &&other) {
    endOfList = other.endOfList;
    _size = other._size;
    other.endOfList = nullptr;
    other._size = 0;
}

LinkedList::~LinkedList() {
    this->clear();
    delete this->endOfList;
}

LinkedList & LinkedList::operator=(const LinkedList & other){
    if (this == &other)
        return *this;
    this->clear();
    for (auto i = other.endOfList->next; i != other.endOfList; i = i->next) {
        this->push_back(i->value);
    }
    return *this;
}

LinkedList & LinkedList::operator=(LinkedList && other){
    if (this == &other)
        return *this;
    clear();
    delete endOfList;
    endOfList = other.endOfList;
    _size = other._size;
    other.endOfList = nullptr;
    other._size = 0;
    return *this;
}

int LinkedList::size() const {
    return(_size);
}

bool LinkedList::empty() const{
    return (_size == 0);
}

//Возвращает ссылку на первый элемент списка.
value_type & LinkedList::front() {
    if (empty()) {
        throw std::logic_error("List is empty");
    }
    return *begin();
}

const value_type & LinkedList::front() const{
    if (empty()) {
        throw std::logic_error("List is empty");
    }
    return *cbegin();
}

//Возвращает ссылку на последний элемент списка.
value_type & LinkedList::back(){
    if (empty()) {
        throw std::logic_error("List is empty");
    }
    return *--end();
}

const value_type & LinkedList::back() const{
    if (empty()) {
        throw std::logic_error("List is empty");
    }
    return *--cend();
}

//Удаляет все вхождения value в список.
int LinkedList::remove(const value_type & value){
    int count = 0;
    for (auto it = begin(); it != end(); ) {
        if (*(it) == value){
            count++;
            it = erase(it);
        } else {
            ++it;
        }
    }
    return count;
}

void LinkedList::clear(){
    for (auto it = begin(); it != end(); it++) {
        erase(it);
    }
}

void LinkedList::pop_back(){
    if (empty()) {
        throw std::logic_error("List is empty");
    }
    iterator it = --end();
    erase(it);
}

void LinkedList::pop_front(){
    if (empty()) {
        throw std::logic_error("List is empty");
    }
    iterator it = begin();
    erase(it);
}

//Добавляет значение value в конец списка.
void LinkedList::push_back(const value_type & value){
    iterator it = end();
    insert(it, value);
}

//Добавляет значение value в начало списка.
void LinkedList::push_front(const value_type & value){
    iterator it = begin();
    insert(it, value);
}

//Присоединяет other к списку.
LinkedList & LinkedList::operator+=(const LinkedList & other){
    for (auto i = other.endOfList->next; i != other.endOfList; i = i->next) {
        push_back(i->value);
    }
    return *this;
}

bool operator!=(const LinkedList &left, const LinkedList &right) {
    if (left.size() != right.size())
        return true;
    auto varLeft = left.endOfList->next;
    auto varRight = right.endOfList->next;
    while (varLeft->value == varRight->value) {
        if ((varLeft == left.endOfList && varRight == right.endOfList)) return false;
        varLeft = varLeft->next;
        varRight = varRight->next;
    }
    return true;
}

bool operator==(const LinkedList & left, const LinkedList & right){
    return !(left != right);;
}

LinkedList operator+(const LinkedList & left, const LinkedList & right){
    return LinkedList(left)+=right;
}
