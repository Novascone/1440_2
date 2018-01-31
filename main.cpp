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

class Analyzer {
	public:
		void analyze(Station* station);
};

void Analyzer::analyze(Station* station) {
	std::string lastDay = "";
	int count = 0;
	float totalGag = 0;
	float totalPcp = 0;

	std::cout << "Precipitation Analysis for " << station->getName() << std::endl;

	station->resetDayIteration();
	Day* day;
	while ((day=station->getDayNext()) != nullptr) {
		count++;

		day->resetStatIteration();
		Stat* stat;
		while ((stat = day->getStatNext()) != nullptr) {
			totalGag += stat->getPrecipitationQgag();
			totalPcp += stat->getPrecipitationQpcp();
		}
	}

	if (count==0) {
		std::cout << "No data points" << std::endl;
	}
	else {
		std::cout << "Total days: " << count << std::endl;
		std::cout << "Total GAG: " << totalGag << std::endl;
		std::cout << "Total PCP: " << totalPcp << std::endl;
		std::cout << "Daily Average GAG: " << totalGag/count << std::endl;
		std::cout << "Daily Average PCP: " << totalPcp/count << std::endl;

		std::cout << std::endl;
	}
}

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




