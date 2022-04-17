#include <stack>
#include <iostream>
#include <vector>

// adaptor container.
// stack - last in first out   LIFO
// queue - first in first out  FIFO


int main(){
    std::stack<int> s; // default - deque
    std::stack<int, std::vector<int>>  s1;

    s.push(1);
    s1.push(1);
    s1.pop();
    s.top();
    
    return 0;
}