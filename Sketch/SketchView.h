#pragma once

#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class SketchView: public QGraphicsView
{
    Q_OBJECT

public:
    SketchView(QWidget *parent = 0);

private:
    void setupScene();

private slots:
    void togglePopup();

private:

   QGraphicsScene m_scene;
   QGraphicsPixmapItem *m_pixmap;
};
