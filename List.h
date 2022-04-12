#pragma once

template <typename T>
struct Elem {
    T data;
    Elem<T>* next;
    Elem(const T& _data) : data{_data}, next{nullptr} { }
};

template <typename T>
class List {
private:
    Elem<T>* head;
    Elem<T>* last;
public:
    List() : head{nullptr}, last{nullptr} { }
    void add(const T&);
    void del(const size_t);
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
void List<T>::del(const size_t idx) {
    T* current{head};
    for(size_t i {0}; i < idx - 1; i++) {
        if(!current->next) throw std::out_of_range{"invalid index"};
        current = current->next;
    }
    if(!current->next) throw std::out_of_range{"invalid index"};
    T* tmp {current->next->next};
    delete current->next;
    current->next = tmp;
}