#ifndef region_hpp
#define region_hpp
#include <string>
#define MAX_STATS         100
#define MAX_STATION_COUNT 20
#include <fstream>
#include <iostream>
#include "station.hpp"
#include "day.hpp"
#include "split.hpp"
#include <sstream>






class Region {
	private:
		Station*        _stations[MAX_STATION_COUNT];
		int             _stationCount=0;
		int             _currentStation;

	public:
		Region();
		void load(std::ifstream &input);
		void resetStationIteration();
		Station* getNextStation();
		Station* findStation(std::string& id);

	private:
		Station* addStation(std::string& id, std::string& name);
};
#endif