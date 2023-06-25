#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

// Define the grading scale
std::map<int, std::string> gradingScale = {
    {85, "A+"},
    {80, "A"},
    {75, "B+"},
    {65, "B"},
    {58, "C+"},
    {55, "C-"},
    {50, "D"},
    {0, "F"}
};

// Function to convert marks to grade
std::string convertMarksToGrade(int marks)
{
    for (const auto& grade : gradingScale)
    {
        if (marks >= grade.first)
        {
            return grade.second;
        }
    }
    return "F";
}

// Function to run the Apriori Algorithm
void runAprioriAlgorithm(const std::vector<std::vector<std::string>>& data)
{
    // TODO: Implement the Apriori Algorithm logic here
    // ...
}

int main()
{
    std::ifstream file("data1.csv");
    std::string line;
    std::vector<std::vector<std::string>> data;

    if (file.is_open())
    {
        // Read the CSV file line by line
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string value;
            std::vector<std::string> row;

            // Split each line into values separated by commas
            while (std::getline(iss, value, ','))
            {
                row.push_back(value);
            }

            // Convert marks to grade for FOP column
            row[1] = convertMarksToGrade(std::stoi(row[1]));

            // Convert marks to grade for OOPS column
            row[2] = convertMarksToGrade(std::stoi(row[2]));

            // Add the pre-processed row to the data vector
            data.push_back(row);
        }

        file.close();

        // Run the Apriori Algorithm on the pre-processed data
        runAprioriAlgorithm(data);
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }

    return 0;
}
