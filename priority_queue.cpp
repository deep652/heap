#include<iostream>
#include<queue>
#include<functional>

using namespace std;


void print(priority_queue<int> pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<"\t";
        pq.pop();
    }
    cout<<endl;
}

void printminheap(priority_queue<int, vector<int>, greater<int> > pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<"\t";
        pq.pop();
    }
    cout<<endl;
}

int main()
{
    //creation
    priority_queue<int> maxheap;
    //insert
    maxheap.push(23);
    maxheap.push(14);
    maxheap.push(11);
    maxheap.push(50);
    //print
    // for()
    // {
    //     cout<<val<<"\t";
    // }
    // range based selection is not allowed here, we will have to pop all the element
    // to print it, so creating a copy of main queue and using it for print is one way to print the heap
    print(maxheap);

    //deleting from heap

    maxheap.pop(); //deletes the top elemnt, we have to store it, than before poping use top to collect it

    print(maxheap);

    priority_queue<int> maxheap_copy = maxheap;

    priority_queue<int> maxheap_emplace;
    
    // std::priority_queue<Point> pq;

    // // Use emplace to construct elements in place
    // pq.emplace(3, 4);
    // pq.emplace(1, 2);
    // pq.emplace(5, 6);

    cout<< "maxheap size is" << maxheap.size() <<endl;

    //important
    //underlying heap declartion and declaring min heap
    // 
    // we can write comparator for greater too or lamda method, lets try all with the exmaple below
    // point to understand here is that, greate<int> will return true if left > right, this
    // only is there to decide the priorty i.e. the reorder will happen if a < b or the number we are inserting is
    // less than the vslue preseny
    priority_queue< int, vector<int>, greater<int> > minheap;

    minheap.push(23);
    minheap.push(14);
    minheap.push(11);
    minheap.push(50);

    printminheap(minheap);

    //using lamda function directly in the declaration 

    priority_queue<int, vector<int> , [](int left, int right){return left>right;}

    return 0;
}