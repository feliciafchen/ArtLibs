//
// Created by Felicia Chen on 11/14/23.
//

#include <sstream>
#include "API.h"

using json = nlohmann::json;

size_t API::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

std::string API::getImage(const std::string &prompt) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Authorization: Bearer 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");

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/images/generations");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // Set the request body
        std::string requestBody = R"({
            "model": "dall-e-2",
            "prompt": ")" + prompt + R"(",
            "n": 1,
            "size": "1024x1024"
        })";

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestBody.c_str());

        // Set the callback function to handle the response
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
        curl_global_cleanup();

        // Process the response as needed
        try {
            json jsonResponse = json::parse(response);

            // Check if 'data' array is present and not empty
            if (jsonResponse.contains("data") && jsonResponse["data"].is_array() && !jsonResponse["data"].empty()) {
                // Extract the URL from the first element in the 'data' array
                std::string imageUrl = jsonResponse["data"][0]["url"];
                return imageUrl;
            } else {
                std::cerr << "Error: 'data' array not found or empty in the JSON response." << std::endl;
            }

        } catch (json::parse_error& e) {
            std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        }
    }
}

std::string API::getSong(const std::string &prompt) {
    std::string song;
    CURL* curl;
    CURLcode res;

    // Initialize cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Set the API endpoint
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/chat/completions");

        // Set the authorization header with your API key
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Authorization: Bearer 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");
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        json messages = {
                { "role", "user" },
                { "content", prompt }
        };

        const std::string data = R"({"messages": [)" + messages.dump() + R"(], "model": "gpt-4"})";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        // Set the callback function to handle the response
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the HTTP request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Parse the JSON response
            json jsonResponse = json::parse(response);
            song = jsonResponse["choices"][0]["message"]["content"];
        }

        // Cleanup
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    // Cleanup cURL
    curl_global_cleanup();
    return song;
}
