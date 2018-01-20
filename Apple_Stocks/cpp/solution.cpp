#include <vector>
#include <iostream>

using namespace std;


int getMaxProfit(const vector<int>& stockPricesYesterday)
{
    int maxProfit = 0;

    // go through every time
    for (size_t outerTime = 0; outerTime < stockPricesYesterday.size();
        ++outerTime) {

        // for every time, go through every OTHER time
        for (size_t innerTime = 0; innerTime < stockPricesYesterday.size();
            ++innerTime) {

            // for each pair, find the earlier and later times
            size_t earlierTime = std::min(outerTime, innerTime);
            size_t laterTime   = std::max(outerTime, innerTime);

            // and use those to find the earlier and later prices
            int earlierPrice = stockPricesYesterday[earlierTime];
            int laterPrice   = stockPricesYesterday[laterTime];

            // see what our profit would be if we bought at the
            // min price and sold at the current price
            int potentialProfit = laterPrice - earlierPrice;

            // update maxProfit if we can do better
            maxProfit = std::max(maxProfit, potentialProfit);
        }
    }

    return maxProfit;
}

int main (void)
{
    vector<int> stockPricesYesterday = {10, 7, 5, 8, 11, 9};
    int maxProfit = getMaxProfit(stockPricesYesterday);
    cout << maxProfit << endl;
}
    
