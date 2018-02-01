#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
using namespace std;

class Solution {
    unordered_map<string, bool> vis;
    unordered_map<string, vector<string>> dict;
    int size;

    bool isvisited(string& from, int to) {
        auto res = vis.find(from+to_string(to));
        if (res == vis.end()) {
            return false; 
        }
        return res->second;
    }

    void visit(string& from, int to) {
        auto res = vis.insert(pair<string, bool>(from+to_string(to), true)); 
        if (res.second == false) {
            res.first->second = true; 
        }
    }

    void unvisit(string& from, int to) {
        auto it = vis.find(from+to_string(to)); 
        it->second = false;
    }

    bool DFS(string& from, int i, vector<string> &ret) {
        if (i == size+1) {
            return true;
        }
        for (int to = 0; to < dict[from].size(); ++to) {
            if (isvisited(from, to)) {
                continue; 
            } 
            visit(from, to);
            ret[i] = dict[from][to];
            if (DFS(dict[from][to], i+1, ret) == true) {
                return true; 
            }
            unvisit(from, to);
        }
        return false;
    }
public:

    vector<string> findItinerary(vector<pair<string, string>>& tickets) {
        size = tickets.size();
        vector<string> ret(size+1);
        for (auto& ticket: tickets) {
            auto v = dict.find(ticket.first); 
            if (v == dict.end()) {
                dict.insert(pair<string, vector<string>>(ticket.first, vector<string>())); 
            } 
            v = dict.find(ticket.first); 
            v->second.push_back(ticket.second); 
        } 
        for (auto& item: dict) {
            sort(item.second.begin(), item.second.end());
        }

        string begin("JFK");
        ret[0] = begin;
        DFS(begin, 1, ret);
        return ret;
    }
};


int main()
{
    Solution sol;
    vector<pair<string, string>> tickets(18);
    tickets[0] = pair<string, string>("DRW", "HBA");
    tickets[1] = pair<string, string>("EZE", "DRW");
    tickets[2] = pair<string, string>("ANU", "EZE");
    tickets[3] = pair<string, string>("AXA", "EZE");
    tickets[4] = pair<string, string>("DRW", "HBA");
    tickets[5] = pair<string, string>("ANU", "SYD");
    tickets[6] = pair<string, string>("EZE", "ANU");
    tickets[7] = pair<string, string>("CNS", "DRW");
    tickets[8] = pair<string, string>("HBA", "BNE");
    tickets[9] = pair<string, string>("JFK", "CNS");
    tickets[10] = pair<string, string>("BNE", "EZE");
    tickets[11] = pair<string, string>("HBA", "EZE");
    tickets[12] = pair<string, string>("EZE", "AXA");
    tickets[13] = pair<string, string>("ANU", "TIA");
    tickets[14] = pair<string, string>("CNS", "ANU");
    tickets[15] = pair<string, string>("ADL", "CNS");
    tickets[16] = pair<string, string>("TIA", "ANU");
    tickets[17] = pair<string, string>("EZE", "ADL");
    auto ret = sol.findItinerary(tickets);
    for (auto r: ret) {
        cout << r << endl;  
    }
    return 0;
}
