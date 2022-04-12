#pragma once

template <typename T>
class List;
template <typename T>
class Iterator;

template <typename T>
class Elem {
    friend class List<T>;
    friend class Iterator<T>;
private:
    T data;
    Elem<T>* next;
public:
    explicit Elem(const T& _data) : data{_data}, next{nullptr} { }
    Elem(const T& _data, Elem<T>* _next) : data{_data}, next{_next} { }
};

template <typename T>
class Iterator {
private:
    Elem<T>* current;
public:
    explicit Iterator(Elem<T>* elem) : current{elem} {
        if(!current) throw std::out_of_range{"empty iterator"};
    }
    T get() const {
        return current->data;
    }
    void next() {
        if(!current->next) throw std::out_of_range{"next is null"};
        current = current->next;
    }
    bool hasNext() const {
        return current->next;
    }
};

template <typename T>
class List {
private:
    Elem<T>* head;
    Elem<T>* last;
public:
    List() : head{nullptr}, last{nullptr} { }
    void add(const T&);
    void insert(const T&, size_t);
    void del(size_t);
    T get(size_t) const;
    Iterator<T> firstIterator() const {
        return Iterator<T>{head};
    }
};

template <typename T>
void List<T>::add(const T &data) {
    if(!head) {
        head = new Elem<T>{data};
        last = head;
    }
    else {
        last->next = new Elem<T>{data};
        last = last->next;
    }
}

template <typename T>
void List<T>::insert(const T& val, const size_t idx) {
    Elem<T>* current{head};
    for(size_t i {0}; i < idx - 1; i++) {
        if(!current->next) throw std::out_of_range{"invalid index"};
        current = current->next;
    }
    current->next = new Elem<T>{val, current->next};
}

template <typename T>
void List<T>::del(const size_t idx) {
    Elem<T>* current{head};
    for(size_t i {0}; i < idx - 1; i++) {
        if(!current->next) throw std::out_of_range{"invalid index"};
        current = current->next;
    }
    if(!current->next) throw std::out_of_range{"invalid index"};
    Elem<T>* tmp {current->next->next};
    delete current->next;
    current->next = tmp;
}

template <typename T>
T List<T>::get(const size_t idx) const {
    Elem<T>* current{head};
    for(size_t i {0}; i < idx; i++) {
        if(!current->next) throw std::out_of_range{"invalid index"};
        current = current->next;
    }
    return current->data;
}