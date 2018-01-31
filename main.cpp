#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "stat.hpp"
#include "day.hpp"
#include "station.hpp"
#include "region.hpp"
#include "split.hpp"
#include "analyzer.hpp"

#define MAX_DAYS          365
#define MAX_STATS         100
#define MAX_STATION_COUNT 20


int main(int argc, char* argv[]) {
	if (argc>1) {
		std::ifstream inputStream(argv[1], std::ios_base::in);

		Region region;
		region.load(inputStream);

		Analyzer analyzer;

		if (argc>2) {
			std::string stationId(argv[2]);
			Station* station = region.findStation(stationId);
			if (station!= nullptr)
				analyzer.analyze(station);
		}
		else {
			region.resetStationIteration();
			Station *station;
			while ((station = region.getNextStation()) != nullptr)
				analyzer.analyze(station);
		}
	}

	return 0;
}




