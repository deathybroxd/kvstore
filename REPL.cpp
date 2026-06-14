#include "REPL.h"

REPL::REPL() {}

REPL::~REPL() {}

void REPL::Run() {
    int command;
    std::cout << "Welcome to the kvstore! " << std::endl;
    std::cout << "Here is a list of commands: " << std::endl;
    do {
        std::cout << "===== COMMANDS ===== " << std::endl;
        std::cout << "1. PUT " << std::endl;
        std::cout << "2. GET" << std::endl;
        std::cout << "3. REMOVE" << std::endl;
        std::cout << "4. RANGE " << std::endl;
        std::cout << "5. SIZE " << std::endl;
        std::cout << "6. CLEAR " << std::endl;
        std::cout << "7. HELP " << std::endl;
        std::cout << "8. QUIT" << std::endl;
        std::cin >> command;
        command--;
        Dispatch(command);
    } while (command != QUIT);
}

// ===== PRIVATE HELPERS ======

void REPL::Dispatch(int commandInt) {
    COMMAND command = static_cast<COMMAND>(commandInt);
    std::string key, value, low, high;
    switch(command) {
        case PUT:
            std::cout << "Enter <key> <value>: " << std::endl;
            getline(std::cin, key, ' ');
            std::cin >> value;
            m_store.Put(key, value);
            break;
        case GET:
            std::cout << "Enter <key>: " << std::endl;
            std::cin >> key;
            m_store.Get(key);
            break;
        case REMOVE:
            std::cout << "Remove <key>: " << std::endl;
            std::cin >> key;
            m_store.Remove(key);
            break;
        case RANGE:
            std::cout << "Range <low> <high>" << std::endl;
            getline(std::cin, low, ' ');
            std::cin >> high;
            break;
        case SIZE:
            std::cout << m_store.Size() << std::endl;
            break;
        case CLEAR:
            m_store.Clear();
            std::cout << "KVStore successfully cleared. " << std::endl;
            break;
        case HELP:
            PrintHelp();
            break;
        case QUIT:
            break;
        default:
            std::cout << "Invalid Command. " << std::endl;
            break;
    }
}

void REPL::PrintHelp() {
    std::cout << "===== COMMANDS ===== " << std::endl;
    std::cout << "PUT " << std::endl;
    std::cout << "GET" << std::endl;
    std::cout << "REMOVE" << std::endl;
    std::cout << "RANGE " << std::endl;
    std::cout << "SIZE " << std::endl;
    std::cout << "CLEAR " << std::endl;
    std::cout << "HELP " << std::endl;
    std::cout << "QUIT" << std::endl;
}
