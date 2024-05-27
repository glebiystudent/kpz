#pragma once 

// core.hpp (Singleton)
// singleton class to operate the whole program and act as a core/engine

#include <functional>

namespace __ {
    class core {
        public:
            static core& get(void) noexcept {
                return instance;
            } 
            
            template<typename F>
            inline auto run(F&& func) noexcept {
                for(;;) {
                    func();
                }
            }
        private:
            core() {

            }

            static core instance;
    };
}