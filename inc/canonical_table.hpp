#pragma once
#include<assert.h>
#include<unordered_map>

template<typename T, typename THash>
class CanonicalTable {
private:
    std::unordered_map<T, T*, THash>um;
public:
    unsigned size();
    void insert(T* item);
    void erase(T* item);
    T* lookup(T* item);
};

template<typename T, typename THash>
unsigned CanonicalTable<T, THash>::size()
{
    return um.size();
}

template<typename T, typename THash>
void CanonicalTable<T, THash>::erase(T* item)
{
    assert(um.find(*item) != um.end());
    um.erase(*item);
}


template<typename T, typename THash>
void CanonicalTable<T, THash>::insert(T* item)
{
    assert(um.find(*item) == um.end());
    um[*item] = item;
}

template<typename T, typename THash>
T* CanonicalTable<T, THash>::lookup(T* item)
{
    auto it = um.find(*item);
    if(it == um.end()) 
        return NULL;
    else 
        return it->second;
}