#ifndef REPL_H
#define REPL_H
#include "KeyValueStore.h"

// constants
enum COMMAND {PUT, GET, REMOVE, RANGE, SIZE, CLEAR, HELP, QUIT};

class REPL {
public:
    // default constructor
    REPL();

    ~REPL();

    void Run();

private:
    KeyValueStore m_store;

    // ===== PRIVATE FUNCTIONS =====
    
    void Dispatch(int commandInt);

    void PrintHelp();
};

#endif