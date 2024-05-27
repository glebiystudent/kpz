#pragma once

#include "syntaxobject.hpp"

namespace __ {
    class Comment : public SyntaxObject {
        public:
            Comment(void) noexcept {

            }

            inline std::string name(void) noexcept override {
                return __name;
            }

            inline std::string description(void) noexcept override {
                return __description;
            }

            inline std::string additional(void) noexcept override { 
                return __additional;
            }

            inline std::string compose(void) noexcept override {  
                return __name + "\n" + __description + "\n";
            }
        private:
            std::string __name = "//comment";
            std::string __description = "used to have a user information stored in the parsed file and ignored by a parser";
            std::string __additional = "";     
    };
}