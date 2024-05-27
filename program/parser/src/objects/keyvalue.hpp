#pragma once

#include "syntaxobject.hpp"

namespace __ {
    class KeyValue : public SyntaxObject {
        public:
            KeyValue(void) noexcept {

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
            std::string __name = "key:value";
            std::string __description = "used to store an actual information segment, a prominent example would be username:password";
            std::string __additional = "";     
    };
}