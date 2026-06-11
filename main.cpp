#include "REPL.h"

int main() {
    //REPL repl;
    //repl.Run();
    RBTree<int, std::string> tree;

    tree.Insert(10, "ten");
    tree.Insert(5, "five");
    tree.Insert(15, "fifteen");
    tree.Insert(3, "three");
    tree.Insert(7, "seven");
    tree.Insert(12, "twelve");
    tree.Insert(20, "twenty");

    tree.InOrder();

    std::cout << "Size: " << tree.Size() << std::endl;
    std::cout << "IsEmpty: " << tree.IsEmpty() << std::endl;


    return 0;
}