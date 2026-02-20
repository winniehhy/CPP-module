#include "PmergeMe.hpp"

void PmergeMe::runDequeSort() {
    clock_t startTime = clock();

    fordJohnsonSortDeque(_deque);

    clock_t endTime = clock();
    _dequeTime = static_cast<double>(endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
}

void PmergeMe::createPairs(std::vector<std::pair<int, int> >& pairs, std::deque<int>& data) {
    size_t idx = 0;
    while (idx < data.size() - 1) {
        int lo = data[idx];
        int hi = data[idx + 1];
        if (lo > hi)
            std::swap(lo, hi);
        pairs.push_back(std::make_pair(lo, hi));
        idx += 2;
    }
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& data) {
    if (data.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairList;
    std::deque<int> mainChain;
    std::deque<int> pendChain;

    createPairs(pairList, data);
    //displayPairs("Pairs created (deque)", pairList);

    // Populate main and pend chains from pairs
    for (std::vector<std::pair<int, int> >::iterator it = pairList.begin(); it != pairList.end(); ++it) {
        mainChain.push_back(it->second);
        pendChain.push_back(it->first);
    }
    // printStep("Main chain before recursion (deque)", mainChain);
    // printStep("Pend chain before recursion (deque)", pendChain);

    std::deque<int> savedMain = mainChain;

    fordJohnsonSortDeque(mainChain);
    //printStep("Main chain after recursion (deque)", mainChain);

    // Re-align pend chain to match sorted main order
    std::deque<int> alignedPend;
    for (size_t i = 0; i < mainChain.size(); i++) {
        for (size_t j = 0; j < savedMain.size(); j++) {
            if (mainChain[i] == savedMain[j]) {
                alignedPend.push_back(pendChain[j]);
                savedMain[j] = -1;
                break;
            }
        }
    }
    pendChain = alignedPend;
    // printStep("Pend chain reordered (deque)", pendChain);

    // Append straggler if input had odd count
    if (data.size() % 2 != 0)
        pendChain.push_back(data.back());
    // printStep("Pend chain after odd check (deque)", pendChain);

    JacobInsert(mainChain, pendChain);
    // printStep("After JacobInsert (deque)", mainChain);
    data = mainChain;
}

void PmergeMe::JacobInsert(std::deque<int>& mainChain, std::deque<int>& pendChain) {
    int pendSize = static_cast<int>(pendChain.size());

    // Generate Jacobsthal sequence up to pendSize
    std::vector<int> jacobSeq;
    jacobSeq.push_back(0);
    jacobSeq.push_back(1);

    int nextJ = jacobSeq.back() + 2 * jacobSeq[jacobSeq.size() - 2];
    while (nextJ < pendSize) {
        jacobSeq.push_back(nextJ);
        nextJ = jacobSeq.back() + 2 * jacobSeq[jacobSeq.size() - 2];
    }

    // Track each pend element's paired position in mainChain
    std::deque<size_t> pairedPos;
    for (int i = 0; i < pendSize; ++i)
        pairedPos.push_back(static_cast<size_t>(i));

    int prevJ = -1;

    for (size_t k = 0; k < jacobSeq.size(); k++) {
        int currJ = jacobSeq[k];

        for (int i = currJ; i > prevJ; --i) {
            if (static_cast<int>(pendChain.size()) < i + 1)
                continue;

            int val = pendChain[i];
            size_t upperBound = pairedPos[i];

            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + upperBound, val);
            size_t insertAt = pos - mainChain.begin();
            mainChain.insert(pos, val);

            // Shift paired positions after insertion point
            for (size_t j = 0; j < pairedPos.size(); j++) {
                if (pairedPos[j] >= insertAt)
                    ++pairedPos[j];
            }
        }
        prevJ = currJ;
    }

    // Insert any remaining pend elements not covered by Jacobsthal indices
    for (int i = pendSize - 1; i > prevJ; --i) {
        int val = pendChain[i];
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }
}
