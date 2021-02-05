#ifndef DATA_TO_EXCEL_THREADED_H
#define DATA_TO_EXCEL_THREADED_H

#include <chrono>
#include <fstream>

class DataToExcelThreaded
{
public:
	DataToExcelThreaded(int N, std::chrono::duration<double, std::milli> time) : N_{ N }, time_{ time } { fill(); }

public:
	void fill()
	{
		std::ofstream output("C:\\Users\\Admin\\Documents\\GitHub\\cst407srs02-Froenn\\CST407SRS02\\DataToGraphThreaded.csv", std::ios::app);

		if (!output.is_open()) { throw std::runtime_error("Unable to open output file!"); }

		output << N_ << ',' << time_.count() <<  std::endl;
	}

private:
	int N_{ 0 };
	std::chrono::duration<double, std::milli> time_;
};
#endif