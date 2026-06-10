#ifndef REPL_H
#define REPL_H
#include "KeyValueStore.h"

class REPL {
public:
    // default constructor
    REPL();

    ~REPL();

    void Run();

private:
    KeyValueStore m_store;

    // ===== PRIVATE FUNCTIONS =====
    
    void Dispatch(std::string command);

    void PrintHelp();
};

#endif