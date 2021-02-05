#ifndef DATACOLLECTOR_H
#define DATACOLLECTOR_H

#include <chrono>
#include <fstream>

class DataCollector
{
public:
	DataCollector(int arrayN, int currValue, int count, bool traversalType, std::chrono::duration<double, std::milli> elapsed) : N_{ arrayN }, curr_ { currValue }, count_{ count }, traversalType_{ traversalType }, elapsed_{ elapsed } { print(); }

private:
	void print()
	{
		std::ofstream output("C:\\Users\\Admin\\Documents\\GitHub\\cst407srs02-Froenn\\CST407SRS02\\results.txt", std::ios::app);

		if (!output.is_open()) { throw std::runtime_error("Unable to open output file!"); }

		output << "\t\tN = " << N_ << std::endl;
		output << "Traversing "; if (!traversalType_) { output << "Columns\n";  } else { output << "Rows\n"; }
		output << count_  << " values < " << curr_ << std::endl;
		output << "Time Elapsed: " << elapsed_.count() << "ms\n\n";

		output.close();
	}


private:
	int const N_; //Width/length of array
	int const curr_;
	int const count_;
	bool const traversalType_;
	std::chrono::duration<double, std::milli> elapsed_;

};
#endif
