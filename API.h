//
// Created by Felicia Chen on 11/14/23.
//

#ifndef TEST_API_H
#define TEST_API_H
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

class API {
private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
public:
    static std::string getImage(const std::string& prompt);
    static std::string getSong(const std::string& prompt);
};


#endif //TEST_API_H
