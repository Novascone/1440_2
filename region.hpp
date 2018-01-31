#ifndef region_hpp
#define region_hpp
#include <string>
#define MAX_STATS         100
#include <fstream>
#include <iostream>
#include "station.hpp"
#include "split.hpp"
#include <sstream>
#include <string>
#include "analyzer.hpp"




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