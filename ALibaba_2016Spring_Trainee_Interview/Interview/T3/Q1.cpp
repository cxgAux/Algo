#include <iostream>

using namespace std;

struct _slist {
    int _val;
    struct _slist * _next;
};

int main(int argc, char const *argv[]) {
    //fast slow pointer to find the collision

    //if without loop, copy anyway

    //else
    //find the loop entrance with head and collision

    //direct copy [head, entrance) to p1
    //direct copy [entrance, entrance) to p2
    //link p1->p2->p2
    return 0;
}
