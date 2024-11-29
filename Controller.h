#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include "Document.h"
#include "View.h"

class Controller {
private:
    std::shared_ptr<Document> document;
    View view;

public:
    Controller();
    void createDocument();
    void addPrimitive(const std::shared_ptr<GraphicPrimitive>& primitive);
    void deletePrimitive(int index);
    void importDocument(const std::string& filename);
    void exportDocument(const std::string& filename);
};

#endif
