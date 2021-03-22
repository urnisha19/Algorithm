#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    queue<int> q; // Construct an empty queue
    for (int i = 0; i < 5; i++)
    {
        cout << i+2 << " ";
        q.push(i + 2); // Pushes i+2 to the end of the queue
    }
    getchar();
    // Q is now { 2, 3, 4, 5, 6 }
    cout << "Front/First element of the Queue: " << q.front()<<endl;
    cout << "Rear/Last element of the Queue: " << q.back()<<endl;

    int sz = q.size(); // Size of queue is 5
    cout << "Current size of the queue is: " <<sz<< endl;
    getchar();

    cout<<"While queue is not empty: " <<endl;
    while (!q.empty())              // Print until Q is empty
    {
        int Front = q.front(); // Retrieve the front of the queue
        cout <<"Current front: "<<Front<<endl; // Prints queue current front
        q.pop();                   // REMEMBER to remove the element!
        cout << "After poping the front current size of the queue is: " << q.size() << endl;
        getchar();
    }
    cout << endl;

    if (q.empty())
    {
        cout << "Currently queue is empty." << endl;
    }
    else
    {
        sz = q.size();
        cout << "Current size of the queue is: " << sz << endl;
    }
     q.push(-1);
    getchar();
    cout << "After pushing -1 to the empty queue, front: " << q.front() << endl;
    cout << "After pushing -1 to the empty queue, back: " << q.back() << endl;
    cout << "Current size of the queue is: " << q.size() << endl;
    return 0;
}
