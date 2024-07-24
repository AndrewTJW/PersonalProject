#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
//variable declared here so functions have access to it
string user_input;

//function to check if input is a character

//function to check if input is number
bool validateInput(string error_checking) { 
    for (char c : error_checking) {
        if (isalpha(c) || (int(c) >= 33 && int(c) <= 47) || (int(c) >= 58 && int(c) <= 64) || (int(c) >= 91 && int(c) <= 96) || (int(c) >= 123 && int(c) <= 126)) {
            return false;
        }
    }
    return true;
}

int main () {
    int total_cases, average_case, maximum_cases = 0, minimum_cases = 0, population, year, number_of_cases;
    float infection_rate = 0;
    string max_month, min_month, filename;
    char option;

// creating new datatype using struct
    struct dataset{
        string month [12]= {"JANUARY", "FEBUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", 
                            "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
        int cases [12];
        float arrInfection_rate [12];
    } arrMonthlyData;
// creating new datatype using struct

// interface beautification
    cout << "=============================================================" << endl << endl;
    cout << "            " << "COVID-19 CASES CALCULATING PROGRAM" << endl << endl;
    cout << "=============================================================" << endl << endl;
// interface beautification

        while (true) {
            cout << "Enter the preferred year for calculation: ";
            cin >> user_input;
            if (validateInput(user_input) == true) {
                year = stoi(user_input);
                if (year > 0) {
                    break;
                }
                else {
                    cout << "Invalid input!\n";
                }
            }
            else {
                cout << "Invalid value!\n";
            }            
        }

        for (int i = 0; i < 12; i++) {
            while (true) {
                cout << "Enter the number of cases for " << arrMonthlyData.month[i] << ": ";
                cin >> user_input;
                if (validateInput(user_input) == true) {
                    number_of_cases = stoi(user_input);
                    if (number_of_cases >= 0) {
                        break;
                    }
                    else {
                        cout << "Invalid input!\n";
                    }
                }
                else {
                    cout << "Invalid input!\n";
                }
            }
            arrMonthlyData.cases[i] = number_of_cases;
            total_cases = arrMonthlyData.cases[i] + total_cases;        
    }

    //calculate average case
    average_case = total_cases / 12;

    cout << "\n\nTo calculate infection rate, data for population is needed!" << endl;
    cout << "============================================================\n\n";
    while (true) {
        cout << "Enter number of population of your desired location: ";
        cin >> user_input;
        if (validateInput(user_input) == true) {
            population = stoi(user_input);
            if (population > 0 && population >= total_cases) {
                break;
            }
            else {
                cout << "Invalid input!\n";
            }
        }
        else {
            cout << "Invalid input!\n";
        }
    }

    //calculate infection rate [static_cast<float> is used to prevent integer division 
    //that will cause output to truncate and become 0]
    for (int j = 0; j < 12; j++) {
        infection_rate = 100 * ((float)arrMonthlyData.cases[j] / population);
        arrMonthlyData.arrInfection_rate[j] = infection_rate;
    }


    //to find minimum and maximum number of cases of the year
    minimum_cases = arrMonthlyData.cases[0];
    for (int y = 0; y < 12; y++) {
        if (arrMonthlyData.cases[y] >= maximum_cases) {
            maximum_cases = arrMonthlyData.cases[y];
        }
        if (arrMonthlyData.cases[y] <= minimum_cases) {
            minimum_cases = arrMonthlyData.cases[y];
        }
    }
    //get month of the maximum
    for (int i = 0; i < 12; i++) {
        if (maximum_cases == arrMonthlyData.cases[i]) {
            max_month = arrMonthlyData.month[i];
            break;
        }
    }
//get month of the minimum
    for (int i = 0; i < 12; i++) {
        if (minimum_cases == arrMonthlyData.cases[i]) {
            min_month = arrMonthlyData.month[i];
            break;
        }       
    }
//printing output 
    cout << "\n\nANALYZED DATA" << endl;
    cout << "================================================================\n";
    cout << "The total number of COVID-19 cases in year " << year << " is: " << total_cases << endl;
    cout << "The average number of COVID-19 cases in year " << year << " is: " << average_case << endl;
    cout << "The most number of cases recorded in year " << year << " is: " << maximum_cases 
    << " which is in " << max_month << endl;
    cout << "The least number of cases recorded in year " << year << " is: " << minimum_cases 
    << " which is in " << min_month << endl;

    cout << "\nINFECTION RATE TABLE" << endl;
    cout << "===============================================" << endl;
    cout << setw(25) << left << "MONTH" << setw(25) << left << "INFECTION RATE" << endl; 
    cout << setw(25) << left << "******" << setw(25) << left << "***************" <<endl;
    for (int i = 0; i < 12; i++) {
        cout << setw(25) << left << arrMonthlyData.month[i] << fixed << setprecision(2) << 
        arrMonthlyData.arrInfection_rate[i] << "%" << endl;
    }
    cout << endl << endl;


    //save data feature

    //error checking check if option is = Y or N
    while (true) {
        cout << "Do you want to save your data? (Y/N): ";
        cin >> user_input;
        if (user_input.length() != 1) {
            cout << "Invalid input!\n";
        }
        else {
            if (user_input == "Y" || user_input == "y") {
                option = 'Y';
            }
            else if (user_input == "N" || user_input == "n") {
                option = 'N';
            }
            if (option == 'Y') {
                cout << "Data saved successfully!";
                ofstream MyFile("C19_saved_data.txt");

                MyFile << "COVID-19 PROGRAM SAVED DATA" << endl;
                MyFile << "----------------------------" << endl << endl;
                MyFile << "Data for monthly cases: " << endl << endl;
                // writing number of cases per month into file 
                MyFile << setw(17) << left << "MONTH" << setw(25) << left << "NUMBER OF COVID-19 CASES" << endl;
                MyFile << setw(17) << left << "***********" << setw(25) << left << "*************************" << endl;
                for (int i = 0; i < 12; i++) {
                    MyFile << setw(17) << left << arrMonthlyData.month[i] 
                    << setw(25) << left << arrMonthlyData.cases[i] << endl;
                }
                MyFile << endl << endl;
                MyFile << "Data for infection rate: " << endl << endl;
                //writing infection rate for every month into file
                MyFile << setw(17) << left << "MONTH" << setw(20) << left << "INFECTION RATE" << endl;
                MyFile << setw(17) << left << "***********" << setw(20) << left << "***************" << endl;
                for (int i = 0; i < 12; i++) {
                    MyFile << setw(17) << left << arrMonthlyData.month[i] 
                    << fixed << setprecision(2) << arrMonthlyData.arrInfection_rate[i] << "%" << endl;
                }
                MyFile << endl << endl;
                MyFile << "DATA OVERVIEW: " << endl;
                MyFile << "=============================" << endl << endl;
                //writing overview of the data into file
                MyFile << "Total case in year " << year << ": " << total_cases << endl;
                MyFile << "Average case per month year "<< year << ": " << average_case << endl;
                MyFile << "Most cases recorded: " << max_month << endl;
                MyFile << "Least cases recorded: " << min_month << endl;

                MyFile.close();
                break;
            }
            else if (option == 'N') {
                cout << "Thank you for using me!";
                return 0;
            }
            else {
                cout << "Invalid Input!\n";
            }
        }
    }
    return 0;
}