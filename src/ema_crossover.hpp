#pragma once
#ifndef EMA_CROSSOVER_HPP
#define EMA_CROSSOVER_HPP

#include <vector>

class EMACrossover {
private:
  double cash = 1000.0;
  int position = 0;
  std::vector<double> emaFast;
  std::vector<double> emaSlow;

public:
  std::vector<double> calculateEMAVector(std::vector<double> &prices,
                                         int period);
  void printEMA();
};

#endif
