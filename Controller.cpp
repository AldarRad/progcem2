#include "Controller.h"

Controller::Controller() : document(nullptr) {}

void Controller::createDocument() {
    document = std::make_shared<Document>();
    view.log("New document created.");
}

void Controller::addPrimitive(const std::shared_ptr<GraphicPrimitive>& primitive) {
    if (document) {
        document->addPrimitiveDoc(primitive);
        view.log("Primitive added.");
    } else {
        view.log("No document to add a primitive to.");
    }
}

void Controller::deletePrimitive(int index) {
    if (document) {
        document->removePrimitiveDoc(index);
        view.log("Primitive deleted.");
    } else {
        view.log("No document to delete a primitive from.");
    }
}

void Controller::importDocument(const std::string& filename) {
    if (document) {
        document->importFromFileDoc(filename);
        view.log("Document imported.");
    } else {
        view.log("No document to import into.");
    }
}

void Controller::exportDocument(const std::string& filename) {
    if (document) {
        document->exportToFileDoc(filename);
        view.log("Document exported.");
    } else {
        view.log("No document to export.");
    }
}
