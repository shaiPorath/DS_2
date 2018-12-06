//
// Created by Hagar on 06/12/2018.
//

#ifndef LIST_TEMPLATE_TRY_H
#define LIST_TEMPLATE_TRY_H

template <class T>
class shit{
public:
    T s;
    shit(T& s):s(s){}
    shit (shit<T>& t){ s = t.s ;}
    T bla(shit<T> a);
};

class egg{
public:
    int a;
    egg(int a): a(a){}
};

template <class T>
T shit<T>::bla(shit<T> a){
    T* b = new T(a.s);
    return *b;
}
#endif //LIST_TEMPLATE_TRY_H
