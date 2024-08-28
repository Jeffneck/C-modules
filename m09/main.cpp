#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <climits>
#include <cstring> // Pour memset
#include <cstdio>  // Pour sscanf

// Fonction pour vérifier le nombre d'arguments
void checkNbArgs(int ac) {
    if(ac != 2)
        throw(std::runtime_error("Error: ./btc needs 1 argument. Usage: ./btc <input_file>"));
}

// Fonction pour ouvrir un fichier
std::ifstream& extractFile(std::ifstream& filestream, const char *filename) {
    filestream.open(filename);
    if (!filestream)
        throw(std::runtime_error(std::string("Error: ") + filename + " can't be opened"));
    return filestream;
}

// Fonction pour parser une date au format "YYYY-MM-DD" en std::tm
std::tm parseDate(const std::string& date) {
    std::tm tm;
    ::memset(&tm, 0, sizeof(std::tm));

    if (sscanf(date.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday) != 3) {
        throw std::runtime_error(std::string("Error: bad input => ") + date);
    }

    tm.tm_year -= 1900; // Année depuis 1900
    tm.tm_mon -= 1;     // Mois entre 0 et 11

    return tm;
}

// Comparateur pour std::tm
struct tmCompare {
    bool operator()(const std::tm& lhs, const std::tm& rhs) const {
        if (lhs.tm_year != rhs.tm_year)
            return lhs.tm_year < rhs.tm_year;
        if (lhs.tm_mon != rhs.tm_mon)
            return lhs.tm_mon < rhs.tm_mon;
        return lhs.tm_mday < rhs.tm_mday;
    }
};

// Fonction pour lire et mapper les taux de change depuis le fichier CSV
std::map<std::tm, float, tmCompare> mapExchangeRate(std::ifstream &dataFile) {
    std::map<std::tm, float, tmCompare> exchangeRates;
    std::string line;
    while (std::getline(dataFile, line)) {
        std::istringstream ss(line);
        std::string date;
        float rate;
        if (std::getline(ss, date, ',') && ss >> rate) {
            std::tm tm = parseDate(date);
            exchangeRates[tm] = rate;
        }
    }
    return exchangeRates;
}

// Fonction pour vérifier si la valeur est valide
// bool isValidValue(const std::string& valueStr, float& value) {
//     std::istringstream ss(valueStr);
//     ss >> value;
//     if (ss.fail() || value < 0 || value > static_cast<float>(INT_MAX)) {
//         if (value < 0)
//             std::cerr << "Error: not a positive number." << std::endl;
//         else if (value > static_cast<float>(INT_MAX))
//             std::cerr << "Error: too large a number." << std::endl;
//         return false;
//     }
//     return true;
// }

// bool isValidValue(const std::string& valueStr, float& value) {
//     std::size_t value_st;
// 	std::istringstream ss(valueStr);

//     // Vérifier si la valeur dépasse INT_MAX
//     ss >> value_st;
//     // Vérifier si la conversion a échoué ou si la valeur est négative
//     if (ss.fail() || (value_st > static_cast<std::size_t>(INT_MAX) && value_st < static_cast<std::size_t>(UINT_MAX))) {
//         if (value_st < 0)
//             std::cerr << "Error: not a positive number." << std::endl;
//         return false;
//     }
//     if (value_st > static_cast<std::size_t>(INT_MAX)) {
//         std::cerr << "Error: too large a number." << std::endl;
//         return false;
//     }

//     ss >> value;

//     return true;
// }

bool isValidValue(const std::string& valueStr, float& value) {
    std::istringstream ss(valueStr);

    // Lire la valeur en tant que float
    ss >> value;
	double valueTest = 	static_cast<double>(value);
	char minus;
	ss >> minus;

    // Vérifier si la conversion a échoué ou si la valeur est négative
    if (ss.fail() || valueTest < 0 || minus = '-') {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    // Vérifier si la valeur dépasse INT_MAX
    if (valueTest > static_cast<double>(INT_MAX)) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

// Fonction pour afficher les résultats
void displayExchangeRate(const std::map<std::tm, float, tmCompare>& exchangeRates, std::ifstream &inputFile) {
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string dateStr, valueStr;
        if (std::getline(ss, dateStr, '|') && std::getline(ss >> std::ws, valueStr)) {
            try {
                std::tm tm = parseDate(dateStr);
                float value;
                if (isValidValue(valueStr, value)) {
                    std::map<std::tm, float, tmCompare>::const_iterator it = exchangeRates.lower_bound(tm);
                    if (it == exchangeRates.end() || it->first.tm_year != tm.tm_year || 
                        it->first.tm_mon != tm.tm_mon || it->first.tm_mday != tm.tm_mday) {
                        if (it != exchangeRates.begin()) {
                            --it;
                        } else {
                            throw std::runtime_error("Error: date out of range.");
                        }
                    }
                    float result = value * it->second;
                    std::cout << dateStr << " => " << value << " = " << result << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}


int main(int ac, char **av) {
    try {
        checkNbArgs(ac);
        std::ifstream inputFile;
        std::ifstream dataFile;
        extractFile(inputFile, av[1]);
        extractFile(dataFile, "data.csv");
        std::map<std::tm, float, tmCompare> exchangeRates = mapExchangeRate(dataFile);
        displayExchangeRate(exchangeRates, inputFile);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
