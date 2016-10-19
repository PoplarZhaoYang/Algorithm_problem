#include <iostream>
using namespace std;
#define pr(x) cout << #x << ": " << x << " " 
#define pl(x) cout << #x << ": " << x << endl;

int main() {
	int x, y;
	while (~scanf("%d%d", &x, &y)) {
		int step = 0;
		int a = 1; double b = 1;
		while (b + 1e-8 < y) {
			int t = (double(a * y) - x * b) / x;
			if (t > 0) b += t, step += t;
			else b += b / a, ++a, ++step;
			pr(a), pr(b), pl(step);
		}
		printf("%d\n", step);
	}
	return 0;
}
