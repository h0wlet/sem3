#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedList.h"

TEST_CASE("Common test") {
    LinkedList list = LinkedList();
    list.push_front(1);
    list.push_back(2);
    int var[2] = {1, 2};
    int count = 0;
    for (LinkedList::iterator i = list.begin(); i != list.end(); i++) {
        REQUIRE(*i == var[count]);
        count++;
    }
}

TEST_CASE("Size and empty") {
    LinkedList list = LinkedList();
    REQUIRE(list.empty() == true);
    list.push_front(1);
    REQUIRE(list.size() == 1);
    REQUIRE(list.empty() == false);
    list.push_back(2);
    REQUIRE(list.size() == 2);
    LinkedList list1 = LinkedList();
    for (int i = 0; i < 5; i++){
        list1.push_back(i);
    }
    REQUIRE(list1.size() == 5);
}

TEST_CASE("Operator !=/==/+") {
    LinkedList list = LinkedList();
    for (int i = 1; i < 3; i++){
        list.push_back(i);
    }
    LinkedList list1 = LinkedList();
    for (int i = 0; i < 5; i++){
        list1.push_back(i);
    }
    REQUIRE((list == list1) == false);
    REQUIRE((list != list1) == true);
    list += list1;
    REQUIRE(list.size() == 7);
}

TEST_CASE("Operator ++/--(int) for iterator and insert"){
    LinkedList list = LinkedList();
    for (int i = 0; i < 3; i++) {
        list.push_back(i);
    }
    LinkedList::iterator it = list.begin();
    REQUIRE(*(it) == 0);
    REQUIRE(*(++it) == 1);
    REQUIRE(*(--it) == 0);
    it = list.insert(++it, 5);
    REQUIRE(*(it) == 5);
}

TEST_CASE("Erase"){
    LinkedList list = LinkedList();
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    REQUIRE(list.size() == 5);
    LinkedList::iterator it = list.begin();
    it = list.erase(++it);
    REQUIRE(list.size() == 4);
    REQUIRE(*(it) == 2);
    REQUIRE(*(--it) == 0);
    LinkedList::iterator it1 = list.begin();
    for (; *it1 != 4; it1++) {}
    REQUIRE(*(it1) == 4);
    it = list.erase(++it,it1);
    REQUIRE(list.size() == 2);
    REQUIRE(*(it) == 4);
    REQUIRE(*(--it) == 0);
}
