#include<iostream>
#include<queue>
#include<list>
#include<string>
using namespace std;

/** The below code leetcode submission for carpool problem
 Here I have used pair of int, string. Which I can correct and use 
 pair of int and int. because a integer can have positive and negative association directly to it
 that way we save lot of convertion time :) **/
// class Solution {
// public:
    
//     bool carPooling(vector<vector<int>>& trips, int capacity) {

//        //this will perfectly work if you understnd that while dealing with numbers, we can have signs 
//        //associated with them too.. No need for so many convertions
//         auto compare = 
//         [](pair<int, string> left, pair<int, string> right){return left.first > right.first;};
//         int i=0;
//         list<pair<int, string > > list_of_events;
//         char plus = '+';
//         char minus = '-';
//         priority_queue< pair<int, string>, vector<pair <int, string> >, decltype(compare) > min_heap;

//         for(int i=0; i<trips[0].size(); i++)
//         {
//             string number_of_passengers = to_string(trips[i][0]);
//             string no_of_p_picked = number_of_passengers.append(0, plus);
//             string no_of_p_droped = number_of_passengers.append(0, minus);
//             pair<int, string> event1 = make_pair(trips[i][1], no_of_p_picked);
//             pair<int, string> event2 = make_pair(trips[i][2], no_of_p_droped);
//             min_heap.push(event1);
//             min_heap.push(event2);
//         }
//         int total_passengers = 0;
//         while(!min_heap.empty())
//         {
//             auto top_ele = min_heap.top();
//             char operation = top_ele.second.at(0);
//             if(operation == plus)
//                 total_passengers += static_cast<int>(top_ele.second.at(1));
//             else
//                 total_passengers -= static_cast<int>(top_ele.second.at(1));
//             if(total_passengers > capacity)
//             {
//                 return false;
//             }
//             min_heap.pop();
//         }
//         return true;        
//     }
// };

int main()
{
    //problem is this, trips[i] = number of passengers in the trip
    // to is kms from where all the passengers will be picked
    // from where all the passengers willl drop off
    // Input: trips = [[2,1,5],[3,3,7]], capacity = 4
    // Output: false
    int trips[2][3] = {{2, 1, 5}, {3, 3, 7}}; 
    int capacity = 4;

    list <pair<int, string> > event;

    int k = 1; //to track the event
    string s("");
    for(int i=0; i<2; i++)
    {
        for(int j=1; j<3; j++)
        {
            //trips[i][0] ==>> no of passengers 
            //trips[i][j] ==>> kms to pickup all the passengers
            if( j == 1)
                s = "+";
            else
                s = "-";

            s.append(to_string(trips[i][0]));

            pair<int,string> p = make_pair(k,s);

            event.push_back(p);
        }
    }

    //print the list

    for(auto x: event)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
    return 0;
}