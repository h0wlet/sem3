#include "LinkedList.h"

LinkedList::iterator::iterator(){
    this->node = nullptr;
}

LinkedList::iterator::iterator(LinkedList::_List *it) {
    this->node = it;
}

LinkedList::iterator & LinkedList::iterator::operator=(const LinkedList::iterator & other){
    this->node = other.node;
    return (*this);
}

bool LinkedList::iterator::operator!=(const LinkedList::iterator & other) const{
    return (this->node != other.node);
}

bool LinkedList::iterator::operator==(const LinkedList::iterator & other) const{
    return (this->node == other.node);
}

//Возвращает ссылку на текущий элемент коллекции.
value_type & LinkedList::iterator::operator*(){
    return this->node->value;
}

//Возвращает указатель на текущий элемент коллекции.
value_type * LinkedList::iterator::operator->(){
    return &(this->node->value);
}

LinkedList::iterator & LinkedList::iterator::operator++(){
    this->node = node->next;
    return *this;
}

LinkedList::iterator LinkedList::iterator::operator++(int){
    LinkedList::iterator it;
    it.node = this->node;
    this->node = node->next;
    return it;
}

LinkedList::iterator &LinkedList::iterator::operator--() {
    this->node = node->prev;
    return *this;
}

LinkedList::iterator LinkedList::iterator::operator--(int){
    LinkedList::iterator it;
    it.node = this->node;
    this->node = node->prev;
    return it;
}

//Возвращает итератор, указывающий на первый элемент списка.
LinkedList::iterator LinkedList::begin() {
    return (LinkedList::iterator(endOfList->next));
}

//Возвращает итератор, указывающий на элемент списка, следующий за последним, т.е. отсутствующий в списке.
LinkedList::iterator LinkedList::end() {
    return (LinkedList::iterator(endOfList));
}

//Удаляет элемент, на который указывает итератор pos.
LinkedList::iterator LinkedList::erase(LinkedList::iterator position){
    LinkedList::iterator it = LinkedList::iterator(position.node->next);
    it.node->prev = it.node->prev->prev;
    it.node->prev->next = it.node;
    delete position.node;
    _size--;
    return it;
}

//Удаляет элементы в интервале [begin, end).
LinkedList::iterator LinkedList::erase(LinkedList::iterator begin, LinkedList::iterator end) {
    while (begin != end){
        begin = erase(begin);
    }
    return begin;
}

//Вставляет значение value перед элементом, на который указывает before
LinkedList::iterator LinkedList::insert(LinkedList::iterator before, const value_type & value){
    _List *newList = new _List;
    newList->value = value;
    newList->next = before.node;
    newList->prev = (--before).node;
    (++before).node->prev->next = newList;
    before.node->prev = newList;
    _size++;
    return (LinkedList::iterator(newList));
}
