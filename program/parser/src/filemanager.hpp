#pragma once

// filemanager.hpp (SRP)
// class designed to open all the files from /bin folder and store the data about the opened files
// also being used in other classes as a data bridge

#include <filesystem>
#include <vector>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

namespace __ {
    class filemanager {
        public:
            filemanager(bool autoload = false) noexcept {
                if(autoload)
                    this->load();
            }


            inline auto load(void) noexcept -> void {
                if(!fs::exists("./bin"))
                    return;

                for(const auto& e : fs::directory_iterator("./bin"))
                    data.emplace_back(e.path().string());

            }

            inline auto get(void) noexcept -> std::vector<std::string> {
                return this->data;
            }
        private:
            std::vector<std::string> data;
    };
}