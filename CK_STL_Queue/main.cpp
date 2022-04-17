#include <queue>
#include <iostream>
#include <vector>

// adaptor container.
// stack - last in first out   LIFO
// queue - first in first out  FIFO


int main(){
    std::queue<int> q; // default - deque
    std::queue<int, std::queue<int>>  q1;

    q.push(1);
    q1.push(1);
    q1.pop();
    q.front();
    q.back();
    
    return 0;
}