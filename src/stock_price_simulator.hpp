#ifndef STOCK_PRICE_SIMULATOR_HPP
#define STOCK_PRICE_SIMULATOR_HPP

#include <vector>

class StockPriceSimulator {
public:
  // Generate realistic stock prices using Geometric Brownian Motion
  std::vector<double> generateGBMPrices(
      int numDays = 252, // Trading days in a year
      double startPrice = 100.0,
      double annualReturn = 0.07,    // 7% expected annual return (mu)
      double annualVolatility = 0.20 // 20% annual volatility (sigma)
  );

  // Simpler version if you just want percentage-based random walk
  std::vector<double>
  generateSimplePercentageWalk(int numDays = 100, double startPrice = 100.0,
                               double dailyVolatility = 0.02 // 2% daily moves
  );
};
#endif
