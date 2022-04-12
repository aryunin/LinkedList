#pragma once

template <typename T>
struct Elem {
    T data;
    Elem<T>* next;
};

template <typename T>
class List {
private:
    Elem<T>* head;
    Elem<T>* last;
public:
    List() : head{nullptr}, last{nullptr} { }

};