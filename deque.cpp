/*
Finally, a deque has both the features of a stack and a queue. It has the member methods size() and
empty(), but instead of the push(), pop() combination, it now provides 4 different methods, all pretty
much selft-explanatory: push_front(), push_back(), pop_front(), pop_back()
*/

#include <iostream>
#include <deque>
#include <cstdio>

using namespace std;

int main()
{
    deque<int> dq; // Construct an empty deque (double-ended queue  )
    for (int i = 0; i < 5; i++)
    {
        cout << i+2 << " ";
        dq.push_back(i + 2); // Pushes i to the end of the deque
    }
    cout << endl;
    // dq is now { 2, 3, 4, 5, 6 }
    int sz=dq.size();
    cout << "Currently in the front of the deque: " << dq.front() << endl;
    cout << "Currently in the back of the deque: " << dq.back() << endl;
    cout << "Current size of the deque is: " << sz <<endl;

    for (int i = 1; i <= 5; i++)
    {
        dq.push_front(-i); // Pushes i to the front of the dqueue
    }
    // dq is now {-5, -4, -3, -2, -1, 2, 3, 4, 5, 6 }

    getchar();
    cout << "Current size of the deque is: " << dq.size() << endl;

    getchar();
    cout << "Currently in the front of the deque: " << dq.front() << endl;
    cout << "Currently in the back of the deque: " << dq.back() << endl;

    getchar();
    dq.pop_back();
    cout << "Currently in the back of the deque: " << dq.back() << endl;

    getchar();
    dq.pop_front();
    cout << "Currently in the front of the deque: " << dq.front() << endl;
    getchar();

    while (!dq.empty())
    {                               // Print until dq is empty
        int CurrentFront = dq.front(); // Retrieve the front of the dqueue
        dq.pop_front();             // REMEMBER to remove the element!
        cout << "Current Front to pop: "<<CurrentFront << endl;   // Prints dqueue line by line
    }
    cout << endl;

    getchar();
    sz = dq.size();
    cout << "Current size of the deque is: " << sz << endl;

    return 0;
}
