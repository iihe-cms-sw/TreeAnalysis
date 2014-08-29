#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>
#include "stdlib.h"
#include "TObject.h"
#include <sstream>
#include "ConfigVJets.h"

ConfigVJets::ConfigVJets(const char* filename){
    readConfigVJets(filename);
}

void ConfigVJets::print(std::ostream& o){
    o << "#### vjets config file automatically generated on the ";
    o << __DATE__ << " at " << __TIME__ << std::endl;
    for(std::map<std::string, std::string>::const_iterator it = table_.begin();
            it != table_.end();
            ++it){
        o << it->first << " = " << it->second << std::endl;
    }
}

bool ConfigVJets::readConfigVJets(const char* filename){
    if(filename == 0) filename = getenv("VJETS_CONFIG");
    if(filename == 0) filename = "vjets.cfg";

    std::ifstream f(filename);
    if(!f.good()){
        std::cerr << "Failed to read file " << filename << "!\n";
        return false;
    }

    std::cout << "Reading configuration from file " << filename << "\n";

    std::string line;
    while(getline(f, line).good()){
        trim(line);
        if(line.size() == 0 || line[0] == '#') continue;
        int pos=0;
        std::string key = tokenize(line, " \t", pos);
        std::string value = tokenize(line, "\n", pos);
        pos = 0;
        value = tokenize(value, "#", pos); //drop comments at end of the line.
        value = trim(value, " \t=");
        std::cerr << key << ": " << value << std::endl;
        table_[key] = value;
    }
    return true;
}

bool ConfigVJets::writeConfigVJets(const char* filename){
    std::ofstream f(filename);
    if(!f.good()){
        std::cerr << "Failed to read file " << filename << "!\n";
        return false;
    }
    print(f);
    return true;
}

bool ConfigVJets::get(const char* key, bool& value){
    return get<bool>(key, value);
}

bool ConfigVJets::get(const char* key, int& value){
    return get<int>(key, value);
}

bool ConfigVJets::get(const char* key, float& value){
    return get<float>(key, value);
}

bool ConfigVJets::get(const char* key, double& value){
    return get<double>(key, value);
}

bool ConfigVJets::get(const char* key, std::string& value){
    return get<std::string>(key, value);
}

bool ConfigVJets::get(const char* key, std::vector<int>& value){
    return get<std::vector<int> >(key, value);
}

bool ConfigVJets::get(const char* key, std::vector<float>& value){
    return get<std::vector<float> >(key, value);
}

bool ConfigVJets::get(const char* key, std::vector<double>& value){
    return get<std::vector<double> >(key, value);
}

bool ConfigVJets::get(const char* key, std::vector<std::string>& value){
    return get<std::vector<std::string> >(key, value);
}

bool ConfigVJets::getB(const char* key, bool defaultValue){
    return get2<bool>(key, defaultValue);
}

int ConfigVJets::getI(const char* key, int defaultValue){
    return get2<int>(key, defaultValue);
}

float ConfigVJets::getF(const char* key, float defaultValue){
    return get2<float>(key, defaultValue);
}

double ConfigVJets::getD(const char* key, double defaultValue){
    return get2<double>(key, defaultValue);
}

std::string ConfigVJets::getS(const char* key, std::string defaultValue){
    return get2<std::string>(key, defaultValue);
}

std::vector<bool> ConfigVJets::getVB(const char* key, std::vector<bool> defaultValue){
    return get2<std::vector<bool> >(key, defaultValue);
}

std::vector<int> ConfigVJets::getVI(const char* key, std::vector<int> defaultValue){
    return get2<std::vector<int> >(key, defaultValue);
}

std::vector<float> ConfigVJets::getVF(const char* key, std::vector<float> defaultValue){
    return get2<std::vector<float> >(key, defaultValue);
}

std::vector<double> ConfigVJets::getVD(const char* key, std::vector<double> defaultValue){
    return get2<std::vector<double> >(key, defaultValue);
}

std::vector<std::string> ConfigVJets::getVS(const char* key, std::vector<std::string> defaultValue){
    return get2<std::vector<std::string> >(key, defaultValue);
}


template<typename T>
void ConfigVJets::convert(const T& x, std::string& s) const{
    std::stringstream ss;
    ss << x;
    s = ss.str();
}

template<typename T>
void ConfigVJets::convert(const std::vector<T>& x, std::string& s) const{
    s = "";
    for(size_t i = 0; i < x.size(); ++i){
        if(i) s += ", ";
        std::string e;
        convert(x[i], e);
        s += e;
    }
}

void ConfigVJets::convert(const std::string& str, float& x) const{
    x = strtod(str.c_str(), 0);
}

void ConfigVJets::convert(const std::string& str, double& x) const{
    x = strtod(str.c_str(), 0);
}

void ConfigVJets::convert(const std::string& str, bool& x) const{
    x = strtol(str.c_str(), 0, 0);
}

void ConfigVJets::convert(const std::string& str, int& x) const{
    x = strtol(str.c_str(), 0, 0);
}

void ConfigVJets::convert(const std::string& str, std::string&  x) const{  
    x = str;
}

template<typename T>
void ConfigVJets::convert(const std::string& str, std::vector<T>& x) const{
    x.clear();
    int pos = 0;
    std::string s = str;
    trim(s, "{}");
    while(pos >= 0){
        std::string val = tokenize(s, ", ", pos);
        if(pos == 0) break;
        trim(val);
        T val_;
        convert(val, val_);
        std::cout << "Adding " << val_ << ", pos = " << pos << std::endl;
        x.push_back(val_);
    }
}

std::string ConfigVJets::trim(std::string s, const char* chars) const{
    std::string::size_type pos0 = s.find_first_not_of(chars);
    if(pos0==std::string::npos){
        pos0=0;
    }
    std::string::size_type pos1 = s.find_last_not_of(chars) + 1;
    if(pos1==std::string::npos){
        pos1 = pos0;
    }
    return s.substr(pos0, pos1-pos0);
}

std::string ConfigVJets::tokenize(const std::string& s, const std::string& delim,
        int& pos) const{
    if(pos<0) return "";
    int pos0 = pos;
    int len = s.size();
    //eats delimeters at beginning of the string
    while(pos0<len && find(delim.begin(), delim.end(), s[pos0])!=delim.end()){
        ++pos0;
    }
    if(pos0==len) return "";
    pos = s.find_first_of(delim, pos0);
    return s.substr(pos0, (pos>0?pos:len)-pos0);
}


template<typename T>
bool ConfigVJets::get(const char* key, T& value){
    std::map<std::string, std::string>::const_iterator it = table_.find(key);
    if(it!=table_.end()){
        convert(it->second, value);
        return true;
    } else{
        std::cerr << "Warning: parameter " << key << " was not found in configuration file!\n";
        std::string value_;
        convert(value, value_);
        std::string key_(key);
        table_[key_] = value_;
        return false;
    }
}

template<typename T>
T ConfigVJets::get2(const char* key, const T& defaultValue){
    T value = defaultValue;
    get(key, value);
    return value;
}
