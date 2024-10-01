#include "PmergeMe.hpp"

// Fonction pour vérifier si la chaîne d'entrée est un unsigned int valide
bool isValidUnsignedInt(const std::string& str) {
    if (str.empty() || (!isdigit(str[0]) && str[0] != '+')) return false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}


unsigned int    getInputArgs(char *arg)
{
    if (!isValidUnsignedInt(arg)) {
        // std::cerr << "Error: Invalid input '" << arg << std::endl;
        throw (std::exception());
    }
    unsigned long ulValue = std::strtoul(arg, NULL, 10);
    if (ulValue > UINT_MAX) {
        // std::cerr << "Error: Input '" << arg << "' is out of range for unsigned int." << std::endl;
        throw (std::exception());
    }
    return (static_cast<unsigned int>(ulValue));
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide at least one number as argument." << std::endl;
        return 1;
    }
    std::cout << std::fixed << std::setprecision(6);


    // WRITE BEFORE AND AFTER WITHOUT TAKING TIME IN ACCOUNT (BECAUSE WRITING CHANGE THE TIME)
    {
        std::vector<unsigned int> vContainer;
        unsigned int value;
        for (int i = 1; i < argc; ++i) {
            try{
                value = getInputArgs(argv[i]);
            }catch(std::exception & e){ 
                std::cerr << "Error" << std::endl;
                return (1);
            }
            vContainer.push_back(static_cast<unsigned int>(value));
        }
        std::cout << "Before: ";
        printVector(vContainer);

        fordJohnsonSort(vContainer);

        std::cout << "After:  ";
        printVector(vContainer);
    }


    //TIME VECTOR
    /*
        Faster because the acces to intern values is optimised in std::vector (this is important in our sorting algorithm)
        By the way, we can use the operator [] to acces those intern values
    */
    {
        clock_t vStart = clock();
        std::vector<unsigned int> vContainer;
        unsigned int value;
        for (int i = 1; i < argc; ++i) {
            value = std::strtoul(argv[i], NULL, 10);
            vContainer.push_back(static_cast<unsigned int>(value));
        }
        fordJohnsonSort(vContainer);
        clock_t vEnd = clock();
        double vDuration = (static_cast<double>(vEnd) - static_cast<double>(vStart)) / static_cast<double>(CLOCKS_PER_SEC) * 1000.0;
        std::cout << "Time to process a range of " << vContainer.size() << " elements with std::vector : " << vDuration << " ms" << std::endl;
    }
    

    //UTILISATION DE LA LISTE
    /* 
        Longer because the acces to intern values is not planned in std::list (important for our sorting algorithm)
        By the way, we can't use the operator [] to acces those intern values we must use iterators to browse std::list
    */
    {
        clock_t lStart = clock();
        std::list<unsigned int> lContainer;
        unsigned int value;
        for (int i = 1; i < argc; ++i) {
            value = std::strtoul(argv[i], NULL, 10);
            lContainer.push_back(static_cast<unsigned int>(value));
        }
        fordJohnsonSort(lContainer);
        clock_t lEnd = clock();
        double lDuration = (static_cast<double>(lEnd) - static_cast<double>(lStart)) / static_cast<double>(CLOCKS_PER_SEC) * 1000.0;
        std::cout << "Time to process a range of " << lContainer.size() << " elements with std::list :   " << lDuration << " ms" << std::endl;
        std::cout << "Test :  ";
        printList(lContainer);//test
    }

    return 0;
}
