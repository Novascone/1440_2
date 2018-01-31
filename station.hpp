#ifndef station_hpp
#define station_hpp
#include <iostream>
#define MAX_DAYS          365
#define MAX_STATS         100
#define MAX_STATION_COUNT 20
#include "day.hpp"
#include "stat.hpp"


class Station {
	private:
		std::string         _id;
		std::string         _name;
		Day*               _days[MAX_DAYS];
		int                 _dayCount = 0;
		int                 _currentDay = -1;

	public:
		Station(std::string& id, std::string& name);
		void load(std::string& datetime, std::string& qgag, std::string& qpcp);
		void resetDayIteration();
		Day* getDayNext();

		std::string getId() { return _id; }
		std::string getName() { return _name; }

	private:
		Day* findDay(std::string& date);
		Day* addDay(std::string& date);
};

#endif