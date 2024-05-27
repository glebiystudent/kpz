#pragma once

// parser.hpp (SRP)
// class designed to parse a specific file class

#include <filesystem>
#include <fstream>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

#include "filemanager.hpp"

namespace __ {
    class parser {
        public:
            parser(bool autoinit = false) noexcept {
                if(autoinit)
                    init();
            }

            // deploys the file manager into our class
            inline auto load(const __::filemanager& manager) noexcept -> void {
                this->manager = manager;
            }

            // logs the files that are imported in the system
            inline auto log(void) noexcept -> void {
                for(const auto& e: manager.get())
                    std::cout << e << "\n";
            }

            // extracts all the lines from the files to our storage system
            auto extract(void) noexcept -> void {
                std::vector<std::string> data = this->manager.get();
                if(data.empty())
                    return; 

                for(std::string file : data) {
                    std::ifstream f;
                    f.open(file);
                    if(f.is_open()) {
                        std::vector<std::string> lines;
                        for(std::string line; std::getline(f, line); )
                            lines.emplace_back(line);
                        this->data[file] = lines;
                    }
                    f.close();
                }
            }

            // parses each line by line
            auto parse(void) noexcept -> void {
                this->extract();

                for(const auto& [key, value] : data) {
                    // each file
                    for(const auto& e : value) {
                        // each line
                        if(e.starts_with("//"))
                            continue;
                        std::size_t split = e.find(':');
                        if(split == std::string::npos)
                            continue;

                        std::string __key, __value;
                        __key = e.substr(0, split);
                        __value = e.substr(split + 1);
                        
                        variables[key][__key] = __value;
                    }
                }
            }

            inline auto get(void) noexcept -> std::unordered_map<std::string, std::vector<std::string>> {
                return this->data;
            }
            
            inline auto get_vars(void) noexcept -> std::unordered_map<std::string, std::unordered_map<std::string, std::string>> {
                return this->variables;
            }

        private:
            // initializes the bin folder if it doesnt exist in the current directory
            inline auto init(void) noexcept -> void {
                if(!fs::exists("./bin"))
                    fs::create_directory("./bin");
            }

            filemanager manager;
            
            // file_name : {lines...}
            std::unordered_map<std::string, std::vector<std::string>> data;
            // file_name : [key, value...]
            std::unordered_map<std::string, std::unordered_map<std::string, std::string>> variables;
    };
}