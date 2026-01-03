#include "stock_price_simulator.hpp"
#include <cmath>
#include <random>
#include <vector>

// Generate realistic stock prices using Geometric Brownian Motion
std::vector<double>
StockPriceSimulator::generateGBMPrices(int numDays, double startPrice,
                                       double annualReturn,
                                       double annualVolatility) {
  std::vector<double> prices;
  prices.reserve(numDays);
  prices.push_back(startPrice);

  // Use better random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<double> dist(0.0, 1.0); // Standard normal

  double dt = 1.0 / 252.0; // Daily time step (1 trading day)

  for (int i = 1; i < numDays; i++) {
    double randomShock = dist(gen); // Random value from normal distribution

    // GBM formula: S(t+1) = S(t) * exp((mu - 0.5*sigma^2)*dt +
    // sigma*sqrt(dt)*Z)
    double drift =
        (annualReturn - 0.5 * annualVolatility * annualVolatility) * dt;
    double diffusion = annualVolatility * std::sqrt(dt) * randomShock;

    double newPrice = prices[i - 1] * std::exp(drift + diffusion);
    prices.push_back(newPrice);
  }

  return prices;
}

std::vector<double> StockPriceSimulator::generateSimplePercentageWalk(
    int numDays, double startPrice, double dailyVolatility) {
  std::vector<double> prices;
  prices.reserve(numDays);
  prices.push_back(startPrice);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<double> dist(0.0, dailyVolatility);

  for (int i = 1; i < numDays; i++) {
    double percentChange = dist(gen); // e.g., -0.03 for -3%
    double newPrice = prices[i - 1] * (1.0 + percentChange);

    // Keep price positive
    if (newPrice < 0.01)
      newPrice = 0.01;

    prices.push_back(newPrice);
  }

  return prices;
};
