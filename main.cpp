#include "Controller.h"

int main() {
    Controller controller;

    controller.createDocument();
    controller.addPrimitive(std::make_shared<Rectangle>());
    controller.addPrimitive(std::make_shared<Circle>());
    controller.deletePrimitive(0);
    controller.exportDocument("output.vec");

    return 0;
}
