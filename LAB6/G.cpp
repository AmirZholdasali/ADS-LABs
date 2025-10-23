#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

void adder(std::map<std::string, std::string>::iterator& it, 
           std::vector<std::vector<std::string>>& res, 
           std::map<std::string, std::string>& map, 
           int& cnt, 
           std::string target){
    auto itr = map.lower_bound(target);
    if (itr != map.end()){
        cnt++;
        res[cnt].push_back(it->first);
        res[cnt].push_back(it->second);
        map.erase(it->first);
        target = itr->second;
        res[cnt].push_back(it->first);
        res[cnt].push_back(it->second);
        map.erase(itr->first);    
        adder(itr, res, map, cnt, target);
    }
    else if(it == map.end()){
        cnt++;
        res[cnt].push_back(it->first);
        res[cnt].push_back(it->second);
        map.erase(it->first);
    }
}

int main(){
    int q;
    std::string s1, s2;
    std::cin >> q;
    std::vector<std::vector<std::string>> res(1000);
    std::map<std::string, std::string> map;
    for(int i = 0; i < q ; i++){
        std::cin >> s1;
        std::cin >> s2;
        map.insert({s1, s2});
    }

    int cnt = -1;
    
    for (auto it = map.begin(); it != map.end(); ++it) {
        adder(it, res, map, cnt, it->second);
    }

    std::cout << cnt << std::endl;
    for(const auto &v : res){
        std::cout << v.front() << ' ' << v.back() << std::endl;
    }
    
}