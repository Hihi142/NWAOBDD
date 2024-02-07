#include<iostream>
#include<cstdio>
#include"inc/intpair.hpp"
#include"inc/inttriple.hpp"
#include"inc/canonical_table.cpp"
#include<unordered_map>
using namespace std;

signed main()
{
    CanonicalTable<int, hash<int> >CT;
    int a = 1, b = 2, c = 3;
    int *p1 = &a, *p2 = &b, *p3 = &c;
    CT.insert(p1);
    CT.insert(p2);
    printf("%p %p\n", CT.lookup(p3), p1);
}