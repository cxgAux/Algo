#include <iostream>
#include <utility>
#include <queue>
#include <memory.h>

using namespace std;

#define set(container, idx) (container[idx >> 5] |= (0x1 << (idx & 0x1F)))
#define cls(container, idx) (container[idx >> 5] & ~(0x1 << (idx & 0x1F)))
#define tst(container, idx) (container[idx >> 5] & (0x1 << (idx & 0x1F)))

void _unique(int * p, int & sz) {
    if(sz == 0) {
        return;
    }
    else {
        int _sz = 0;
        for(int i = 1; i < sz; ++ i) {
            if(p[_sz] != p[i]) {
                p[++ _sz] = p[i];
            }
        }
        sz = _sz + 1;
    }
}

int main(int argc, char const *argv[]) {
    //input
    int szA, szB, k;
    while(cin >> szA >> szB >> k) {
        int * A = new int [szA], * B = new int [szB];
        for(int i = 0; i < szA; ++ i) {
            cin >> A[i];
        }
        for(int i = 0; i < szB; ++ i) {
            cin >> B[i];
        }
        if(k == 0) {
            continue;
        }
        //step 1: unique arrays
        _unique(A, szA);
        _unique(B, szB);
        if(szA == 0 || szB == 0) {
            continue;
        }
        //step 2: bfs with heap and bitmap
        int _sz = ((szA * szB) >> 5) + 1, * visited = new int [_sz];
        memset(visited, 0, sizeof(int) * _sz);
        struct Comp {
            bool operator()(const pair<int, int> & _pre, const pair<int, int> & _post) {
                return _pre.first > _post.first;
            }
        };
        priority_queue< pair<int, int>, vector< pair<int, int> >, Comp> pq;
        pq.push(make_pair(A[0] + B[0], 0));
        set(visited, 0);
        int _prev = 0;
        while(k != 0 && !pq.empty()) {
            int _f = pq.top().first, _s = pq.top().second;
            pq.pop();
            if(_s == 0) {
                _prev = _f;
                k --;
                cout << _prev;
            }
            else {
                if(_f > _prev) {
                    _prev = _f;
                    cout << " " << _prev;
                    k --;
                }
            }
            int _x = _s / szB, _y = _s % szB, _nidx = _s + szB;
            if((_x < szA - 1) && (tst(visited, _nidx) == false)) {
                set(visited, _nidx);
                pq.push(make_pair(A[_x + 1] + B[_y], _nidx));
            }
            _nidx = _s + 1;
            if((_y < szB - 1) && (tst(visited, _nidx) == false)) {
                set(visited, _nidx);
                pq.push(make_pair(A[_x] + B[_y + 1], _nidx));
            }
        }
        cout << endl;
        cout << "new case\n";
    }
    return 0;
}
