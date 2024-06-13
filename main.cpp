//#include "StacksAndQueues/Stack&Queues.h"
//#include "MapAndSet/Maps&Sets.h"


#include <iostream>
#include <iomanip>
#include <map>
#include <string_view>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using std::map;
using std::unordered_map;
using std::set;
using std::pair;
using std::vector;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;


void citiesByContinentAndCountry() {

    map<string, map<string, vector<string> > > citiesByContinentAndCountry;

    int  lines;
    cin >> lines;

    for (int i = 0; i < lines; ++i) {
        string continent, country, city;
        cin >> continent >> country >> city;
        citiesByContinentAndCountry[continent][country].push_back(city);
    }

    for (auto &continent : citiesByContinentAndCountry) {
        cout << continent.first << ":" << endl;
        for (auto &country : continent.second) {
            cout << "  " << country.first << " -> ";
            for (auto &city : country.second) {
                sort(country.second.begin(), country.second.end());

                if(city != country.second.back()) {
                    cout << city << ", ";
                }
                else
                    cout << city;
            }
            cout << endl;
        }

    }

}


int main() {
    citiesByContinentAndCountry();
    return 0;
}
