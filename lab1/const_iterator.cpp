#include "LinkedList.h"

LinkedList::const_iterator::const_iterator(){
    this->const_node = nullptr;
}

LinkedList::const_iterator::const_iterator(LinkedList::_List *it) {
    this->const_node = it;
}

LinkedList::const_iterator & LinkedList::const_iterator::operator=(const LinkedList::const_iterator & other){
    this->const_node = other.const_node;
    return (*this);
}

bool LinkedList::const_iterator::operator!=(const LinkedList::const_iterator & other) const{
    return (this->const_node != other.const_node);
}

bool LinkedList::const_iterator::operator==(const LinkedList::const_iterator & other) const{
    return (this->const_node == other.const_node);
}

//Возвращает ссылку на текущий элемент коллекции.
const value_type & LinkedList::const_iterator::operator*() const {
    return this->const_node->value;
}

//Возвращает указатель на текущий элемент коллекции.
const value_type * LinkedList::const_iterator::operator->() const {
    return &(this->const_node->value);
}

LinkedList::const_iterator & LinkedList::const_iterator::operator++(){
    this->const_node = const_node->next;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int){
    LinkedList::const_iterator it;
    it.const_node = this->const_node;
    this->const_node = const_node->next;
    return it;
}

LinkedList::const_iterator & LinkedList::const_iterator::operator--() {
    this->const_node = const_node->prev;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int){
    LinkedList::const_iterator it;
    it.const_node = this->const_node;
    this->const_node = const_node->prev;
    return it;
}

LinkedList::const_iterator LinkedList::cbegin() const {
    return (LinkedList::const_iterator(endOfList->next));
}

LinkedList::const_iterator LinkedList::cend() const {
    return (LinkedList::const_iterator(endOfList));
}
