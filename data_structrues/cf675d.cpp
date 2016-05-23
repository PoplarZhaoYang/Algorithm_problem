#include <iostream>
#include <set>
#include <map>
using namespace std;
map<int, int> le, ri;
int n, x;
set<int> st;
set<int>::iterator r, l;

int main() {
    cin >> n;
    cin >> x;
    st.insert(x);
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        r = st.upper_bound(x);
        if (r != st.begin()) l = --r, ++r;
        else l = st.end();
        if (r == st.end()) {
            cout << *l << " ";
            ri[*l]++;
        } else if (l == st.end()) {
            cout << *r << " ";
            le[*r]++;
        } else {
            if (ri.count(*l)) {
                cout << *r << " ";
                le[*r]++;
            } else {
                cout << *l << " ";
                ri[*l]++;
            }
        }
        st.insert(x);
    }
    cout << endl;
    return 0;
}
