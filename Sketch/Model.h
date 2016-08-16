#pragma once

#include <QObject>
#include <QRectF>

#include <Site.h>
#include <SiteVec.h>

#include <vector>

/*!
 * \class Model is the protocol class for data models under a
 *        SketchScene
 * \brief Models are *square* (-ish), and follow standard cartesian
 *        coordinates (double x,y, ascending to the right and up). Not
 *        sure if QRectF will play nicely with this choice...
 */
class Model : public QObject
{
   Q_OBJECT

public:

   Model(const SiteVec &svec);
   virtual ~Model() {};

   const SiteVec &sites() { return siteVec_; }
   QRectF bounds() const { return bounds_; }

signals:

private:

   QRectF boundsCache();

   SiteVec        siteVec_;
   mutable QRectF bounds_;
};
