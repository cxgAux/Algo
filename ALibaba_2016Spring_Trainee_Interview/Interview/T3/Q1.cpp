#include <iostream>
#include <utility>

using namespace std;

typedef struct _slist {
    int _val;
    struct _slist * _next;
    _slist(int val) : _val(val), _next(nullptr) {}
} * sList;

sList findCollision(sList head) {
    if(head) {
        sList _fast = head, _slow = head;
        while(_fast->_next != nullptr && _slow->_next != nullptr) {
            _fast = _fast->_next->_next;
            _slow = _slow->_next;
            if(_fast == _slow) {
                return _fast;
            }
        }
        return nullptr;
    }
    return nullptr;
}

sList findEntrance(sList head, sList collision) {
    while(head != collision) {
        head = head->_next;
        collision = collision->_next;
    }
    return head;
}

pair<sList, sList> copyList(sList head, sList end) {
    if(head == nullptr) {
        return make_pair(head, head);
    }
    else {
        sList _cpHead = new _slist(head->_val), _t = _cpHead;
        while(head->_next != end) {
            head = head->_next;
            _t->_next = new _slist(head->_val);
            _t = _t->_next;
        }
        return make_pair(_cpHead, _t);
    }
}

sList copyLoop(sList head) {
    if(head == nullptr) {
        return head;
    }
    else {
        sList _cpHead = new _slist(head->_val), _t = _cpHead;
        while(head->_next) {
            head = head->_next;
            _t->_next = new _slist(head->_val);
            _t = _t->_next;
        }
        _t->_next = _cpHead;
        return _cpHead;
    }
}

sList copy(sList _lst) {
    sList _collision = findCollision(_lst);
    if(_collision == nullptr) {
        return copyList(_lst, nullptr).first;
    }
    else {
        sList _entrance = findEntrance(_lst, _collision),
            _h2 = copyLoop(_entrance);
        pair<sList, sList> _h1 = copyList(_lst, _entrance);
        _h1.second->_next = _h2;
        return _h1.first;
    }
}

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
