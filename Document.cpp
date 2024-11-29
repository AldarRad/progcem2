#include "Document.h"

int Document::documentCounter = 0;

Document::Document() : id(++documentCounter) {
    std::cout << "Document #" << id << " created." << std::endl;
}

void Document::addPrimitive(const std::shared_ptr<GraphicPrimitive>& primitive) {
    primitives.push_back(primitive);
    std::cout << "Primitive added to document #" << id << std::endl;
}

void Document::removePrimitive(int index) {
    if (index < 0 || index >= primitives.size()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    primitives.erase(primitives.begin() + index);
    std::cout << "Primitive removed from document #" << id << std::endl;
}

void Document::importFromFile(const std::string& filename) {
    std::cout << "Document #" << id << " imported from file: " << filename << std::endl;
}

void Document::exportToFile(const std::string& filename) {
    std::cout << "Document #" << id << " exported to file: " << filename << std::endl;
}

int Document::getId() const {
    return id;
}
