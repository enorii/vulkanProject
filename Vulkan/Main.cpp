#include <memory>
#include "TriangleApplication.h"

int main(int argc, char* args[]) {
    TriangleApplication* applicationInstance;
    /// This would be a little more modern 
    ///std::unique_ptr<TriangleApplication>applicationInstance;
    
    if((applicationInstance = new TriangleApplication()) == nullptr){
        return EXIT_FAILURE;
    }

    try {
        applicationInstance->run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        ///  Bjarne Stroustrup would prefer RAII - TODO
        if(applicationInstance) delete applicationInstance;
        return EXIT_FAILURE;
    }
    if (applicationInstance) delete applicationInstance;
    return EXIT_SUCCESS;
}