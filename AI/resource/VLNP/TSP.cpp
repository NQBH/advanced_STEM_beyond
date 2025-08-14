#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<limits>
#include<random>
using namespace std;

struct City {
    double x, y;
    City(double x, double y): x(x), y(y) {}
};

class TSPSolver {
private:
    vector<City> cities;
    int population_size;
    int elite_size;
    double mutation_rate;
    int generations;

    double distance(const City& a, const City& b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }
    vector<int>createRandomRoute() {
        vector<int> route(cities.size());
        for (int i = 0; i < cities.size(); ++i) {
            route[i] = i;
        }
        random_shuffle(route.begin(), route.end());
        return route;
    }
    double calculateTotalDistance(const vector<int>& route) {
        double total = 0.0;
        for (int i = 0; i < route.size(); ++i) {
            int from = route[i];
            int to = route[(i + 1) % route.size()];
            total += distance(cities[from], cities[to]);
        }
        return total;
    }
    vector<vector<int>>initialPopulation() {
        vector<vector<int>>population;
        for (int i = 0; i < population_size; ++i) {
            population.push_back(createRandomRoute());

        }
        return population;
    }

    vector<pair<int, double>>rankRoutes(const vector<vector<int>>& population) {
        vector<pair<int, double>>fitnessResults;
        for (int i = 0; i < population.size(); ++i) {
            fitnessResults.emplace_back(i, 1.0 / calculateTotalDistance(population[i]));
        }
        sort(fitnessResults.begin(), fitnessResults.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.second > b.second;
        });
        return fitnessResults;
    }
    vector<int> selection(const vector<pair<int, double>>& popRanked) {
        vector<int> selectionResults;

        for (int i = 0; i < elite_size; ++i) {
            selectionResults.push_back(popRanked[i].first);
        }
        double totalFitness = 0.0;
        for (const auto& item : popRanked) {
            totalFitness += item.second;
        }
        vector<double> cumProbs;
        double cumSum = 0.0;
        for (const auto& item : popRanked) {
            cumSum += item.second;
            cumProbs.push_back(cumSum / totalFitness);
        }
        for (int i = 0; i < popRanked.size() - elite_size; ++i) {
            double pick = (double)rand() / RAND_MAX;
            for (int j = 0; j < cumProbs.size(); ++j) {
                if (pick <= cumProbs[j]) {
                    selectionResults.push_back(popRanked[j].first);
                    break;
                }
            }
        }
        return selectionResults;
    }
    vector<int> breed(const vector<int>& parent1, const vector<int>& parent2) {
        vector<int> child;
        int startPos = rand() % parent1.size();
        int endPos = rand() % parent1.size();

        if (startPos > endPos) {
            swap(startPos, endPos);
        }
        for (int i = startPos; i <= endPos; ++i) {
            child.push_back(parent1[i]);
        }
        for (int city : parent2) {
            if (find(child.begin(), child.end(), city) == child.end()) {
                child.push_back(city);
            }
        }
        return child;
    }
    vector<vector<int>>breedPopulation(const vector<vector<int>>& matingPool) {
        vector<vector<int>> children;

        for (int i = 0; i < elite_size; ++i) {
            children.push_back(matingPool[i]);
        }
        int poolSize = matingPool.size();
        for (int i = elite_size; i < poolSize; ++i) {
            int parent1Idx = i % poolSize;
            int parent2Idx = (i + 1) % poolSize;
            children.push_back(breed(matingPool[parent1Idx], matingPool[parent2Idx]));
        }
        return children;
    }
    vector<int> mutate(const vector<int>& route) {
        vector<int>mutatedRoute = route;
        for (int i = 0; i < mutatedRoute.size(); ++i) {
            if ((double)rand() / RAND_MAX < mutation_rate) {
                int swapWith = rand() % mutatedRoute.size();
                swap(mutatedRoute[i], mutatedRoute[swapWith]);
            }
        }
        return mutatedRoute;
    }
    vector<vector<int>> mutatePopulation(const vector<vector<int>>& population) {
        vector<vector<int>> mutatedPop;
        for (const auto& route : population) {
            mutatedPop.push_back(mutate(route));
        }
        return mutatedPop;
    }
    vector<vector<int>> nextGeneration(const vector<vector<int>>& currentGen) {
        auto popRanked = rankRoutes(currentGen);
        auto selectionResults = selection(popRanked);

        vector<vector<int>> matingPool;
        for (int idx : selectionResults) {
            matingPool.push_back(currentGen[idx]);
        }
        auto children = breedPopulation(matingPool);
        auto nextGen = mutatePopulation(children);
        return nextGen;

    }
public:
    TSPSolver(const vector<City>& cities, int popSize = 100, int eliteSize = 20, double mutRate = 0.01, int gens = 500): cities(cities), population_size(popSize), elite_size(eliteSize), mutation_rate(mutRate), generations(gens) {
        srand(time(nullptr));
    }
    pair<vector<int>, double>geneticAlgorithm() {
        auto population = initialPopulation();
        double bestDistance = numeric_limits<double>::max();
        vector<int>bestRoute;

        cout << "Initial best distance: " << calculateTotalDistance(population[0]) << endl;
        for (int i = 0; i < generations; ++i) {
            population = nextGeneration(population);

            auto currentBestRoute = population[0];
            auto currentBestDist = calculateTotalDistance(currentBestRoute);

            if (currentBestDist < bestDistance) {
                bestDistance = currentBestDist;
                bestRoute = currentBestRoute;
            }
            if (i % 50 == 0) {
                cout << "Generation " << i << ": " << bestDistance << endl;
            }
        }
        cout << "Final best distance: " << bestDistance << endl;
        return{bestRoute, bestDistance};

    }
};
int main() {
    vector<City> cities;
    int numCities = 20;

    for (int i = 0; i < numCities; ++i) {
        double x = static_cast<double>(rand()) / RAND_MAX * 100;
        double y = static_cast<double>(rand()) / RAND_MAX * 100;
        cities.emplace_back(x, y);
    }
    TSPSolver solver(cities, 100, 20, 0.01, 500);
    auto result = solver.geneticAlgorithm();

    cout << "\nBest route found: ";
    for (int city : result.first) {
        cout << city << " ";

    }
    cout << "\nTotal distance: " << result.second << endl;
    return 0;
}