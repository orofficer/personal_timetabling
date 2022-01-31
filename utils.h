#ifndef UTILS_H
#define UTILS_H
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>
#include <vector>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <map>

class Utils
{
//    static std::mt19937 mt;
    static inline std::mt19937 mt = std::mt19937(0);


public:
    static void initRand(int seed){
        Utils::mt = std::mt19937(seed);
    }

    static int integer_random_generator(const int &a , const int &b ){
        return std::uniform_int_distribution<int>{a, b-1}(Utils::mt);
    }

    static double real_random_generator(const double& a, const double& b){
        return std::uniform_real_distribution<double>{a, b}(Utils::mt);
    }

    static double random_choice(const std::vector<double> &vec)
    {
        int rnd = integer_random_generator(0, vec.size());
        return vec[rnd];
    }

    static int biased_selection(const std::vector<double> &vec){
        std::discrete_distribution<> d(vec.begin(), vec.end());

        return d(mt);
    }

        static void shuffle(std::vector<int> &vec){
            std::shuffle(vec.begin(), vec.end(), Utils::mt);
        }

        template <typename T>
        static void remove(std::vector<T> &c, T &element){
            for (auto it = c.begin(); it != c.end(); /* "it" updated inside loop body */ ){
                if (*it == element){
                    it = c.erase(it);
                    break;
                }
                else {
                    ++it;
                }
            }
        }

        template <typename T>
        static void print_vec(std::vector<T> &c){
            for (auto i : c)
                std::cout << i << " ";

            std::cout << "\n";
        }

        static double round(double val){
            return roundf(val * 100000) / 100000;
        }

        static int sumVec_int(std::vector<int>& vec){
            int sum = 0;
            for (int& i : vec)
                sum += i;
            return sum;
        }

        static int position(std::vector<int>& vec, int element){
            auto it = std::find(vec.begin(), vec.end(), element);
            if (it == vec.end())
            {
                // element not in vector
                assert(false);
                return -1;
            } else
            {
              return std::distance(vec.begin(), it);
            }
        }

        static std::vector<int> gen_vector(int a, int b){
            std::vector<int> vec;
            for (int i = a; i < b; ++i){
                vec.push_back(i);
            }
            return vec;
        }

        static bool contain_pair(std::multimap<int,int>& container, int &i, int &j){
            auto it = container.find(i);
            while (it != container.end()) {
                if (it->first != i)
                    return false;
                if (it->second == j)
                    return true;
                ++it;
            }
            return false;
        }

    private:

};

// dynamic seed


// fixed seed
//std::mt19937 Utils::mt = std::mt19937(0);

#endif // UTILS_H
