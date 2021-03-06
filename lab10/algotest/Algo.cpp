//
// Created by agnieszka on 16.05.17.
//

#include "Algo.h"
#include <string>
namespace algo
{

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> set;
        std::transform(m.begin(), m.end(), inserter(set, set.begin()), [](std::pair<std::string, int> arg){return arg.first;});
        return set;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> vec;
        std::transform(m.begin(), m.end(), back_inserter(vec), [](std::pair<std::string, int> arg){return arg.second;});
        return vec;
    }

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor) {
        std::map<std::string, int> map;
        std::transform(m.begin(), m.end(), inserter(map, map.begin()), [divisor](std::pair<std::string, int> arg){if(arg.second%divisor==0)return arg;});
        return map;
    }

    void SortInPlace(std::vector<int> *v) {

    }

    std::vector<int> Sort(const std::vector<int> &v) {
        return std::vector<int>();
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {

    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> vec;
        std::transform(v.begin(), v.end(), std::back_inserter(vec), [](double arg){return std::to_string(arg);});
        return vec;
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
        return std::__cxx11::string();
    }

    int Sum(const std::vector<int> &v) {
        return 0;
    }

    int Product(const std::vector<int> &v) {
        return 0;
    }

    bool Contains(const std::vector<int> &v, int element) {

        if(std::find(v.begin(), v.end(), element)==v.end()) return false;
        else return true;

    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        if(v.find(key)==v.end()) return false;
        else return true;
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
      if(std::find_if(v.begin(), v.end(), [value](std::pair<std::string, int> arg) {if(arg.second==value) return true; else return false;} )==v.end() ) return false;
        else return true;

    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        return std::vector<std::string>();
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {

    }

    void InitializeWith(int initial_value, std::vector<int> *v) {

       std::fill(v->begin(), v->end(), initial_value);

    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> vec;
        vec.resize(length);
        std::fill(vec.begin(), vec.end(), initial_value);
        return  vec;
    }

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {

        std::copy(v.begin(), v.begin()+n_elements, std::back_inserter(*out));
    }

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        return 0;
    }
}