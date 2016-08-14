#include "SketchScene.h"

#include <iostream>

void SketchScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
   (void) mouseEvent;
   std::cout << "Mouse pressed" << std::endl;

   emit poke();
}
