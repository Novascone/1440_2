#ifndef day_hpp
#define day_hpp
#include <iostream>
#include <string>
#define MAX_STATS         100
#include "stat.hpp"

class Day {
	private:
		std::string         _date;
		Stat*               _stats[MAX_STATS];
		int                 _statCount = 0;
		int                 _currentStat = -1;

	public:
		Day(std::string date);
		void addStat(Stat *stat);
		void resetStatIteration();
		Stat* getStatNext();
		std::string getDate() { return _date; }
};
#endif