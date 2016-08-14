#pragma once

#include <QGraphicsScene>

class SketchScene : public QGraphicsScene
{
    Q_OBJECT

public:
   SketchScene(const QRectF &rect, QObject *parent) : QGraphicsScene(rect, parent) {};
   ~SketchScene() {};

signals:

   void poke();

protected:
   virtual void mousePressEvent(QGraphicsSceneMouseEvent *);

private:
};
