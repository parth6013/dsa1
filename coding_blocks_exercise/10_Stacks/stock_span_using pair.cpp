#include<iostream>
#include<stack>
using namespace std;


class StockSpanner 
{
public:
    // each element in the stack is pair whose first --> price and second --> day number
    stack<pair<int,int>>stk;
    int index=0;
    StockSpanner() 
    {
        while(!stk.empty())
        {
            stk.pop();
        }
        index=0;
    }
    
    int next(int price) 
    {
        int ans;
        if(stk.empty())
        {
            stk.push({price,index});
            ans=index+1;
        }
        else
        {
            while(!stk.empty() && stk.top().first<=price)
            {
                stk.pop();
            }
            ans=(stk.empty()?index+1:index-stk.top().second);
            stk.push({price,index});
        }
        index++;
        return ans;
    }
};