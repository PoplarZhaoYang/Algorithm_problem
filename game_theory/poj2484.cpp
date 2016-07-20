#include <iostream>

class solve
{
public:
    int n;
public:
    void run(void){
        while (std::cin >> n) {
            if (!n) return;
            std::cout << (n <= 2 ? "Alice" : "Bob") << std::endl;
        }
    }
}ac;

int main()
{
    ac.run();
    return 0;
}
