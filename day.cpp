
#include "day.hpp"
#include <iostream>

Stat* Day::getStatNext() {
	Stat* stat = nullptr;
	if (_currentStat < _statCount)
		stat = _stats[_currentStat++];
	return stat;
}

Day::Day(std::string date) {
	_date = date;
}
void Day::resetStatIteration() {
	_currentStat = 0;
}
void Day::addStat(Stat *stat) {
	if (_statCount<MAX_STATS)
		_stats[_statCount++] = stat;
	else
		std::cerr << "Too many stats for " << getDate() << std::endl;
}
