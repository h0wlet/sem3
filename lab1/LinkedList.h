
#ifndef LAB_LINKEDLIST_H
#define LAB_LINKEDLIST_H

typedef int value_type;
class LinkedList {
private:
    struct _List {
        struct _List *next;
        struct _List *prev;
        value_type value;
    };

    int _size = 0;
    _List *endOfList;

public:
    class iterator {

        friend class LinkedList;
        _List *node;
        explicit iterator(_List *it);

    public:
        iterator();
        iterator & operator=(const iterator & other);
        bool operator!=(const iterator & other) const;
        bool operator==(const iterator & other) const;
        //Возвращает ссылку на текущий элемент коллекции.
        value_type & operator*();
        //Возвращает указатель на текущий элемент коллекции.
        value_type * operator->();

        iterator & operator++();
        iterator operator++(int);
        iterator & operator--();
        iterator operator--(int);
    };
    class const_iterator {

        friend class LinkedList;
        const _List *const_node;
        explicit const_iterator(_List *it);

    public:
        const_iterator();
        const_iterator & operator=(const const_iterator & other);
        bool operator!=(const const_iterator & other) const;
        bool operator==(const const_iterator & other) const;
        //Возвращает ссылку на текущий элемент коллекции.
        const value_type & operator*() const;
        //Возвращает указатель на текущий элемент коллекции.
        const value_type * operator->() const;

        const_iterator & operator++();
        const_iterator operator++(int);
        const_iterator & operator--();
        const_iterator operator--(int);
    };
    /* Конструкторы */
    LinkedList();
    LinkedList(const LinkedList & other);
    LinkedList(LinkedList && other);

    /* Деструктор */
    ~LinkedList();

    /* Оператор присваивания */
    LinkedList & operator=(const LinkedList & other);
    LinkedList & operator=(LinkedList && other);

    /* Доступ к итераторам */
    //Возвращает итератор, указывающий на первый элемент списка.
    iterator begin();
    const_iterator cbegin() const;
    //Возвращает итератор, указывающий на элемент списка, следующий за последним, т.е. отсутствующий в списке.
    iterator end();
    const_iterator cend() const;

    /* Размерность */
    int size() const;
    bool empty() const;

    /* Доступ к элементам */
    //Возвращает ссылку на первый элемент списка.
    value_type & front();
    const value_type & front() const;
    //Возвращает ссылку на последний элемент списка.
    value_type & back();
    const value_type & back() const;

    /* Модификаторы */
    iterator erase(iterator position);
    iterator erase(iterator begin, iterator end);
    int remove(const value_type & value);
    void clear();

    void pop_back();
    void pop_front();
    //Добавляет значение value в конец списка.
    void push_back(const value_type & value);
    //Добавляет значение value в начало списка.
    void push_front(const value_type & value);
    //Вставляет значение value перед элементом, на который указывает before
    iterator insert(iterator before, const value_type & value);

    /* Операторы внутренние */
    //Присоединяет other к списку.
    LinkedList & operator+=(const LinkedList & other);

    /* Операторы внешние */
    friend bool operator!=(const LinkedList & left, const LinkedList & right);
    friend bool operator==(const LinkedList & left, const LinkedList & right);

};

/* Операторы внешние */
//Сравнивает 2 листа
bool operator!=(const LinkedList & left, const LinkedList & right);
bool operator==(const LinkedList & left, const LinkedList & right);

//Возвращает лист объединяющий 2 листа.
LinkedList operator+(const LinkedList & left, const LinkedList & right);


#endif //LAB_LINKEDLIST_H
