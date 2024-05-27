#pragma once

// syntaxobject.hpp (Factory)
// class designed to be virtually inhereted from other classes(hence the factory method)
// used in a 'faq' part of a main parser in order to display information about certain parts of a syntax engine

#include <string>

namespace __ {
    class SyntaxObject {
        public:
            SyntaxObject() {

            }

            virtual std::string name(void) = 0;
            virtual std::string description(void) = 0;
            virtual std::string additional(void) = 0;
            virtual std::string compose(void) = 0;
    };
}