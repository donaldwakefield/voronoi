#include <QApplication>

#include "SketchView.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    SketchView widget;
    widget.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Popup Message with Effect"));
    widget.show();

    return app.exec();
}
