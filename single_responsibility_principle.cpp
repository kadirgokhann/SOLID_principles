#include <iostream>
#include <string>
#include <fstream>

class Report {
public:
    std::string generateReport()
	{
        return "This is the report data.";
    }

    void saveReportToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << generateReport();
            file.close();
        }
    }

    void printReport() {
        std::cout << generateReport() << std::endl;
    }
};
// Problems with This Code:
//   The Report class has multiple responsibilities:
//    - It generates report data.
//    - It handles saving the report to a file.
//    - It handles printing the report.
//   Violates SRP: Each class should only have one reason to change.
//   If the way reports are generated, saved, or printed changes, we have to modify the Report class
//   for multiple reasons.


// SOLUTION -------
// SOLUTION -------
// SOLUTION -------
// SOLUTION -------

// The responsibility of this class is to generate reports only.
class Report {
public:
    std::string generateReport() {
        return "This is the report data.";
    }
};

// This class handles saving the report to a file.
class ReportFileSaver {
public:
    void saveToFile(const std::string& reportData, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << reportData;
            file.close();
        }
    }
};

// This class handles printing the report.
class ReportPrinter {
public:
    void print(const std::string& reportData) {
        std::cout << reportData << std::endl;
    }
};

// Advantages:
// Single Responsibility:
//	   The Report class is only responsible for generating the report.
//	   The ReportFileSaver class is responsible for saving reports to a file.
//	   The ReportPrinter class is responsible for printing reports.
// Easy Maintenance:
//	   If the report format changes, only the Report class needs to be modified.
//	   If we need to save reports to a database instead of a file, we can modify or create
//		   a new class for that without affecting the rest of the system.
//	   Similarly, changing how reports are printed will only affect the ReportPrinter class.
