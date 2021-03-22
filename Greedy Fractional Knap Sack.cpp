#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define a 50

using namespace std;
typedef struct
{
    char name[a];
    double weight, price, ppw;
} item;

bool cmp(item cA, item cB)
{
    if(cA.ppw == cB.ppw)
    {
        return cA.weight > cA.weight;
    }
    return cA.ppw > cB.ppw;
}

void showVec(string vecName, double totalSpace, vector<item>items)
{
    cout<<vecName;
    sort(items.begin(), items.end(), cmp);
    double takenWeight=0.0;
    for(int i=0; i<(int)items.size(); i++)
    {
        if(takenWeight+items[i].weight<=totalSpace)
        {
            takenWeight += items[i].weight;
            printf("%s taken with a fraction of 1\n",items[i].name); //the whole item is taken
        }
        else if(takenWeight==totalSpace)
        {
            printf("%s taken with a fraction of 0\n",items[i].name); //the item is not taken
        }

        else
        {
            double remainSpace,d;
            remainSpace = totalSpace - takenWeight;
            d = remainSpace/items[i].weight;
            printf("%s taken with a fraction of %lf\n",items[i].name, d);//the item is taken at some other amount rather than the total amount of the item
        }
    }
}

double fractionalKnapsack(vector<item> itemLt, double remSpace)
{
    double totPriceAchieved = 0.0;
    sort(itemLt.begin(), itemLt.end(), cmp);
    for(int i=0; i<(int)itemLt.size(); i++)
    {
        if( itemLt[i].weight <= remSpace )
        {
            totPriceAchieved += itemLt[i].price;
            remSpace -= itemLt[i].weight;
        }
        else
        {
            totPriceAchieved += (remSpace*itemLt[i].ppw);
            remSpace = 0.0;
            break;
        }
    }
    return totPriceAchieved;
}

int main()
{
    int N; //the total number of items
    double M; //the size of the knapsack
    item tpItem; //temporary item with the description(name, price in BDT, weights in kg)
    while(scanf("%d %lf", &N, &M) == 2)
    {
        vector<item> itemList;
        for(int i=0; i<N; i++)
        {
            scanf("%s %lf %lf", &tpItem.name, &tpItem.price, &tpItem.weight);
            tpItem.ppw = tpItem.price/tpItem.weight;
            itemList.push_back(tpItem);
        }

        printf("Total price achieved: %0.3lf\n", fractionalKnapsack(itemList,M));
        showVec("List of selected items\n", M,itemList);
    }
    return 0;
}


