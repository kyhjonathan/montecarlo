#include "ema_crossover.hpp"
#include <iostream>
#include <vector>

std::vector<double>
EMACrossover::calculateEMAVector(std::vector<double> &prices, int period) {
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

void EMACrossover::printEMA() { std::cout << "Stock Prices\n"; }
