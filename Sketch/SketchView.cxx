#include "SketchView.h"

#include <QtGui>

const qreal ViewWidth(1000);
const qreal ViewHeight(1000);
const QRectF ViewRect(0, 0, ViewHeight, ViewWidth);

SketchView::SketchView(QWidget *parent): QGraphicsView(parent),
                                         m_scene(ViewRect, this),
                                         m_pixmap(0)
{
   setScene(&m_scene);
   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   setupScene();

   setRenderHint(QPainter::Antialiasing, true);
   setFrameStyle(QFrame::NoFrame);

   setMinimumWidth(ViewWidth + 50);
   setMinimumHeight(ViewHeight + 50);
}

const qreal Least(0);
const qreal SceneWidth(999);
const qreal PenWidth(3);

QPixmap createGrid()
{
   QPixmap pm(ViewWidth, ViewHeight);
   pm.fill();

   QPainter *paint = new QPainter(&pm);
   QPen pen;
   pen.setWidth(PenWidth);
   paint->setPen(pen);
   paint->drawRect(Least,Least,SceneWidth,SceneWidth);
   delete paint;

   return pm;
}

static int yplus(0);
void SketchView::togglePopup()
{
   QPixmap pixmap(createGrid());

   QPainter *paint = new QPainter(&pixmap);
   paint->setPen(QColor(255,34,255,255));
   paint->drawRect(15,415+yplus,100,100); yplus += 10;
   delete paint;

   m_pixmap->setPixmap(pixmap);
}

void SketchView::setupScene()
{
   QPixmap pm(createGrid());

   m_pixmap = m_scene.addPixmap(pm);

   QFont font;
   font.setPointSize(font.pointSize() * 2);
   font.setBold(true);
   QFontMetrics fontMetrics(font);

   QPushButton *press = new QPushButton;
   press->setText(tr("Press me"));
   connect(press, SIGNAL(clicked()), SLOT(togglePopup()));
   m_scene.addWidget(press);

   press->move(905, 905);
}
