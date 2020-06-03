#include "QueueArr.h"
#include <iostream>
using namespace std;

int main() {

    QueueArr queue;
    queue.enqueue(10);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(20);
    queue.enqueue(11);
    queue.enqueue(14);
    queue.enqueue(22);
    queue.enqueue(34);

    queue.dequeue();
    queue.dequeue();

    QueueArr queue2(queue);

    while (!queue2.isEmpty()) {
        int temp;
        queue2.dequeue(temp);
        cout << temp << endl;
    }

    return 0;
}