#ifndef DATA_TO_EXCEL_H
#define DATA_TO_EXCEL_H

#include <chrono>
#include <fstream>

class DataToExcel
{
public:
	DataToExcel(int N, std::chrono::duration<double, std::milli> time, bool order) : N_{ N }, time_{ time }, order_{ order } { fill(); }

public:
	void fill()
	{
		std::ofstream output("C:\\Users\\Admin\\Documents\\GitHub\\cst407srs02-Froenn\\CST407SRS02\\DataToGraph.csv", std::ios::app);

		if (!output.is_open()) { throw std::runtime_error("Unable to open output file!"); }

		output << N_ << ',' << time_.count() << ','; if (!order_) { output << std::endl; }
	}

private:
	int N_{ 0 };
	std::chrono::duration<double, std::milli> time_;
	bool order_;
};
#endif