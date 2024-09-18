#include <iostream>
#include <vector>
#include <algorithm>

// Génération de la séquence de Jacobsthal
std::vector<unsigned int> generateJacobsthalList(int n) {
    std::vector<unsigned int> jacobsthal;
    unsigned int a = 0, b = 1;
    while (jacobsthal.size() < static_cast<size_t>(n)) {
        jacobsthal.push_back(a);
        unsigned int next = b + 2 * a;
        a = b;
        b = next;
    }
    return jacobsthal;
}

// Fonction pour insérer un élément dans un vecteur trié sans duplications
void insertInOrder(std::vector<unsigned int>& vec, const unsigned int value) {
    std::vector<unsigned int>::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
    // Vérifiez si la valeur est déjà présente
    if (it == vec.end() || *it != value) {
        vec.insert(it, value);
    }
}

void fordJohnsonSort(std::vector<unsigned int>& vec) {
    if (vec.size() <= 1) return;

    bool isOdd = vec.size() % 2 != 0;
    unsigned int laggard = 0;

    if (isOdd) {
        laggard = vec.back();
        vec.pop_back();
    }

    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        unsigned int first = vec[i];
        unsigned int second = vec[i + 1];
        pairs.push_back(std::make_pair(std::min(first, second), std::max(first, second)));
    }

    std::vector<unsigned int> S;
    for (size_t i = 0; i < pairs.size(); ++i) {
        S.push_back(pairs[i].second);
    }
    std::sort(S.begin(), S.end());

    std::vector<unsigned int> pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        pend.push_back(pairs[i].first);
    }

    std::vector<unsigned int> jacobsthalSeq = generateJacobsthalList(pend.size());
    std::cout << "test " << S.size() << " | " << pend.size() << " | " << jacobsthalSeq.size() << std::endl;//
    std::cout  << "\ndata to sort :"<< std::endl;//
	for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }//
	std::cout  << "\nS content :"<< std::endl;//
	for (size_t i = 0; i < S.size(); ++i) {
        std::cout << S[i] << " ";
    }//
    std::cout  << "\npend content :"<< std::endl;//
	for (size_t i = 0; i < pend.size(); ++i) {
        std::cout << pend[i] << " ";
    }//
    std::cout  << "\njacob seq content :"<< std::endl;//
	for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
        std::cout << jacobsthalSeq[i] << " ";
    }//
    std::cout << std::endl;//

    for (std::vector<unsigned int>::reverse_iterator rit = jacobsthalSeq.rbegin(); rit != jacobsthalSeq.rend(); ++rit) {
        if (*rit < pend.size()) {
            unsigned int value = pend[*rit];
            insertInOrder(S, value);
            // std::cout << "insertion !" << std::endl;
        }
    }

    // std::cout << "test " << S.size() << " | " << pend.size() << " | " << jacobsthalSeq.size() << std::endl;

    if (isOdd) {
        insertInOrder(S, laggard);
    }

    vec = S;
}

int main() {
    std::vector<unsigned int> data = {9, 8, 7, 6, 5, 4, 3, 2, 1, 99, 88, 77, 66, 55, 44, 33, 22, 11};
    fordJohnsonSort(data);
	
	std::cout  << "\nAfter ford Johnson :"<< std::endl;//
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    return 0;
}
