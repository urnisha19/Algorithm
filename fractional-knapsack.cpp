#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct
{
    double weight, price, ppw;
} item;

void showVec(string vecName, vector<item> items)
{
    cout << vecName << " : " << endl;
    for(int i=0; i< (int)items.size(); i++)
    {
        printf("%d -> %0.3lf %0.3lf %0.3lf\n", i, items[i].price, items[i].weight, items[i].ppw);
    }
    cout << endl;
}

bool cmp(item cA, item cB)
{
    if(cA.ppw == cB.ppw)
    {
        return cA.weight > cA.weight;
    }
    return cA.ppw > cB.ppw;
}

double fractionalKnapsack(vector<item> itemList, double remSpace)
{

    sort(itemList.begin(), itemList.end(), cmp);
    showVec("After sorting the vec", itemList);

    double totalPriceAchieved = 0.0;

    for(int i=0; i < (int) itemList.size(); i++)
    {
        if( itemList[i].weight <= remSpace )
        {
            //we can take the whole thing or total amount
            totalPriceAchieved += itemList[i].price;
            remSpace -= itemList[i].weight;
        }
        else
        {
            //you have less space available than your current item's amount
            totalPriceAchieved += (remSpace * itemList[i].ppw);
            remSpace = 0.0;
            break;
        }
    }

    return totalPriceAchieved;
}

int main()
{
    int totalItems;
    double totalSpace;
    item tempItem;
    while(scanf("%d %lf", &totalItems, &totalSpace) == 2)
    {
        vector<item> itemList;
        for(int i=0; i<totalItems; i++)
        {
            scanf("%lf %lf", &tempItem.price, &tempItem.weight);
            tempItem.ppw = tempItem.price / tempItem.weight;
            itemList.push_back(tempItem);
        }
        showVec("itemList after Input", itemList);

        printf("Total price achieved: %0.3lf\n", fractionalKnapsack(itemList, totalSpace));
    }
    return 0;
}


/**
3 50
120 30
60 10
100 20

6 15
40 5
10 4
24 3
36 6
20 2
35 7

*/
