#include<iostream>
using namespace std;
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], total_profit = 0;
    int i,j, knap;
    knap = capacity;
    for(i = 0; i < n; i++)
    {
        if(weight[i] > knap)
        {
            break;
        }
        else
        {
            total_profit = total_profit + profit[i];
            knap = knap - weight[i];

        }
    }
    if(i < n)
    {
        x[i] = knap / weight[i];
        total_profit = total_profit + (x[i] * profit[i]);
    }
    cout<<"Maximum profit : "<<total_profit;

}

int main()
{

    float weight[20], profit[20], capacity;
    int num, i,j;
    float Ratio[20], temp;

    cout<<"Enter number of elements: ";
    cin>>num;
    cout<<"Enter weight and profit of objects : "<<endl;
    for(i =0; i< num; i++)
    {
        cin>>weight[i]>>profit[i];
    }
    cout<<endl<<"Enter capacity of knapsack: ";
    cin>>capacity;
    for(i =0; i<num; i++)
    {
        Ratio[i] = profit[i] / weight[i];
    }

    for(i =0; i<num; i++)
    {
        for(j = i+1; j<num; j++)
        {
            if(Ratio[i] < Ratio[j])
            {
                temp = Ratio[j];
                Ratio[j] = Ratio[i];
                Ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity);
    return 0;

}
