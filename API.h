//
// Created by Felicia Chen on 11/14/23.
//

#ifndef TEST_API_H
#define TEST_API_H
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

class API {
public:
    static const std::string getImage(const std::string &prompt);
    static size_t WriteCallbackURL(void *contents, size_t size, size_t nmemb, std::string *output);
    static bool DownloadImageToFile(const std::string &url, const std::string &filePath);
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, FILE *file);
};

#endif //TEST_API_H
