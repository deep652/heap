#include<iostream>
#include<vector>
using namespace std;

//Max heap
class Heap
{
private:
    vector<int> heap;
    
    void heapifydown(int i)
    {
        if(i > heap.size())
            return;

        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int largest = i;
        if(l < heap.size() && heap[largest] < heap[l])
        {
            largest = l;
        }
        else if(r < heap.size() && heap[largest] < heap[r])
        {
            largest = r;
        }
        if(largest != i)
        {
            swap(heap[largest], heap[i]);
            heapifydown(largest);
        }
 
    }
    void move_up(int index)
    {
        //Algo is, add the element at the end of the vectoe/array and adjust/compare it to 
        //all its ancestors, it must follow the max rule

        if(index == 0)
        {
            return;
        }
        int parentindex = (index - 1)/2;
        if(heap[parentindex] < heap[index])
        {
            swap(heap[parentindex], heap[index]);
            move_up(parentindex);
        }
        
    }
public:
    void insert(int a)
    {
        heap.push_back(a);
        move_up(heap.size() - 1);
    }

    void printHeap()
    {
        for( auto val: heap )
        {
            cout<<val<<"\t";
        }
        cout<<endl;
    }

    //delete from heap    
    void delete_top()
    {
        int size = heap.size();
        int top = heap.front();
        heap[0] = heap.back();
        heap.pop_back();

        heapifydown(0);

        return;
    }
    
};
int main()
{
    Heap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(15);
    cout<<"Heap is ==>> ";
    maxHeap.printHeap();
    cout<<"After one delete Heap ==>> ";
    maxHeap.delete_top();
    maxHeap.printHeap();

    return 0;
}