#include "parser/init.hpp"

#include <iostream>
#include <string>
#include <conio.h>

// global variable instead of local for the sole purpose of singletone
// used to operate the whole program thru a single lambda
__::core __::core::instance;

auto main() -> int {
    // main classes
    __::parser parser(true);
    __::filemanager manager(true);

    // storage systems
    std::vector<std::string> file_names;
    std::unordered_map<std::string, std::vector<std::string>> parsed_data;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> variables;

    // menu running via infinite anonymous lambda cycle
    __::core::get().run([&](){
        for(;;) {
            // clearing the terminal's buffer
            system("cls");

            // text menu part
            std::cout << "[main menu]: (load -> extract -> log/output)\n";
            std::cout << "[1] load\n";
            std::cout << "[2] extract(+parse)\n";
            std::cout << "[3] log\n";
            std::cout << "[4] output\n";
            std::cout << "[5] \n";
            std::cout << "[6] guide\n";
            std::cout << "[-1] exit\n";
            
            // outputting the currently loaded files section
            if(file_names.size() >= 1) {
                std::cout << "\n[loaded files]:\n";
                for(std::size_t i = 0; i < file_names.size(); ++i)
                    std::cout << "[" << i << "] " << file_names[i] << "\n";
                std::cout << "\n";
            }

            std::string input;
            std::getline(std::cin, input);

            if(input == "-1") { // exit
                break;
            } else if (input == "1") { // load
                parser.load(manager);
                file_names = manager.get();
            } else if (input == "2") { // extract(+parse)
                parser.parse();
                parsed_data = parser.get();
                variables = parser.get_vars();
            } else if (input.starts_with("3")) {  // log
                std::size_t space = input.find(' ');
                if(space == std::string::npos)
                    continue;
                int arg = std::stoi(input.substr(space + 1));
                if(!(arg >= 0 && arg < file_names.size()))
                    continue;

                system("cls");
                std::cout << "[" << file_names[arg] << "]:\n";
                for(const auto& e : parsed_data[file_names[arg]])
                    std::cout << e << "\n";

                getch();
            } else if (input.starts_with("4")) { // output(log parsed data)
                std::size_t space = input.find(' ');
                if(space == std::string::npos)
                    continue;
                int arg = std::stoi(input.substr(space + 1));
                if(!(arg >= 0 && arg < file_names.size()))
                    continue;

                system("cls");
                std::cout << file_names[arg] << " parsed: \n";
                for(const auto &[key, value] : variables[file_names[arg]])
                    std::cout << "[" << key << "]: [" << value << "]\n";
                std::cout << "\n\n";
                getch();
            } else if (input == "6") { // guide
                system("cls");
                __::Comment comment;
                __::KeyValue keyvalue;
                std::cout << "[quick guide]\n\n\n";
                std::cout << comment.compose() << "\n";
                std::cout << keyvalue.compose() << "\n";

                getch();
            }
        }
    });
}