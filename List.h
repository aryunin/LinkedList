#pragma once

template <typename T>
struct Elem {
    T data;
    Elem<T>* next;
};
