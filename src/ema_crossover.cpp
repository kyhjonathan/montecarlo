#include <iostream>
#include <random>
#include <vector>

class EMACrossover {
private:
  double cash = 1000.0;
  int position = 0;
  std::vector<double> emaFast;
  std::vector<double> emaSlow;

public:
  std::vector<double> calculateEMAVector(std::vector<double> &prices,
                                         int period) {
    std::vector<double> ema(prices.size(), 0.0);

    if (prices.size() < period) {
      return ema;
    }

    double multiplier = 2.0 / (period + 1);

    double sum = 0;
    for (int i = 0; i < period; i++) {
      sum += prices[i];
    }
    ema[period - 1] = sum / period;
    for (int i = period; i < prices.size(); i++) {
      ema[i] = (prices[i] - ema[i - 1]) * multiplier + ema[i - 1];
    }
    return ema;
  }

  std::vector<double> generateRandomWalkPrices(int numDays = 100,
                                               double startPrice = 100.0,
                                               double stepSize = 1.0) {
    std::vector<double> prices;
    prices.reserve(numDays);

    srand(time(NULL)); // Seed random
    double currentPrice = startPrice;
    prices.push_back(currentPrice);

    for (int i = 1; i < numDays; i++) {
      // Random step up or down
      double step = ((rand() % 100) / 100.0 - 0.5) * 2.0 * stepSize;
      currentPrice += step;

      // Ensure price stays positive
      if (currentPrice < 1.0)
        currentPrice = 1.0;

      prices.push_back(currentPrice);
    }

    return prices;
  }

  void printEMA(std::vector<double> &prices) { std::cout << "Stock Prices\n"; }
};
