#include "REPL.h"

REPL::REPL() {}

REPL::~REPL() {}

void REPL::Run() {
    int command;
    std::cout << "Welcome to the kvstore! " << std::endl;
    std::cout << "Here is a list of commands: " << std::endl;
    do {
        std::cout << "===== KVStore COMMANDS ===== " << std::endl;
        std::cout << "1. PUT " << std::endl;
        std::cout << "2. GET" << std::endl;
        std::cout << "3. REMOVE" << std::endl;
        std::cout << "4. RANGE " << std::endl;
        std::cout << "5. SIZE " << std::endl;
        std::cout << "6. CLEAR " << std::endl;
        std::cout << "7. PRINT " << std::endl;
        std::cout << "8. HELP " << std::endl;
        std::cout << "9. QUIT" << std::endl;
        std::cin >> command;
        command--;
        Dispatch(command);
    } while (command != QUIT);
}

// ===== PRIVATE HELPERS ======

void REPL::Dispatch(int commandInt) {
    COMMAND command = static_cast<COMMAND>(commandInt);
    std::string key, value, low, high;
    std::optional<std::string> result;
    std::vector<std::pair<std::string, std::string>> range;
    bool rangeFirstTime = true;
    switch(command) {
        case PUT:
            std::cout << "Put <key> <value>: " << std::endl;
            std::cin >> key >> value;
            std::cin.ignore();
            if(m_store.Put(key, value)) {
                std::cout << "Added " << key << " : " << value << std::endl;
            } else {
                std::cout << "Could not add " << key << ", duplicate key exists" << std::endl;
            }
            
            break;
        case GET:
            std::cout << "Get <key>: " << std::endl;
            std::cin >> key;
            result = m_store.Get(key);
            if(result.has_value()) {
                std::cout << result.value() << std::endl;
            } else {
                std::cout << "Key not found." << std::endl;
            }
            break;
        case REMOVE:
            std::cout << "Remove <key>: " << std::endl;
            std::cin >> key;
            if(m_store.Remove(key)) {
                std::cout << "Removed " << key << std::endl;
            } else {
                std::cout << key << " was not found, could not remove." << std::endl;
            }
            break;
        case RANGE:
            if (rangeFirstTime) {
                std::cout << "DISCLAIMER: RANGE compares string keys, not numbers" << std::endl;
                rangeFirstTime = false;
            }
            std::cout << "Range <low> <high>" << std::endl;
            std::cin >> low >> high;
            std::cin.ignore();
            range = m_store.RangeQuery(low, high);
            for(auto& pair : range) {
                std::cout << pair.first << " : " << pair.second << std::endl;
            }
            range.clear();
            break;
        case SIZE:
            std::cout << "KVStore size: " << m_store.Size() << std::endl;
            break;
        case CLEAR:
            m_store.Clear();
            std::cout << "KVStore successfully cleared. " << std::endl;
            break;
        case PRINT:
            m_store.Print();
            break;
        case HELP:
            PrintHelp();
            break;
        case QUIT:
            break;
        default:
            std::cout << "Invalid Command. " << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            break;
    }
}

void REPL::PrintHelp() {
    std::cout << "===== KVStore COMMANDS ===== " << std::endl;
    std::cout << "1. PUT " << std::endl;
    std::cout << "2. GET" << std::endl;
    std::cout << "3. REMOVE" << std::endl;
    std::cout << "4. RANGE " << std::endl;
    std::cout << "5. SIZE " << std::endl;
    std::cout << "6. CLEAR " << std::endl;
    std::cout << "7. PRINT " << std::endl;
    std::cout << "8. HELP " << std::endl;
    std::cout << "9. QUIT" << std::endl;
}
