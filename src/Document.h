#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "GraphicPrimitive.h"

class Document {
private:
    std::vector<std::shared_ptr<GraphicPrimitive>> primitives;
    static int documentCounter;
    int id;
public:
    Document();
    void addPrimitiveDoc(const std::shared_ptr<GraphicPrimitive>& primitive);
    void removePrimitiveDoc(int index);
    void importFromFileDoc(const std::string& filename);
    void exportToFileDoc(const std::string& filename);
    int getId() const;
};

#endif 
