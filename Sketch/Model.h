#pragma once

#include <QObject>
#include <QRectF>

#include <Site.h>
#include <SiteVec.h>

#include <vector>

/*!
 * \class Model is the protocol class for data models under a
 *        SketchScene
 * \brief Models are *square*, and follow standard cartesian
 *        coordinates (double x,y, ascending to the right and up).
 */
class Model : public QObject
{
   Q_OBJECT

public:

   Model(const SiteVec &svec) : siteVec_(svec) {};
   virtual ~Model() {};

   const SiteVec &sites() { return siteVec_; }
   QRectF bounds() const;

signals:

private:

   SiteVec siteVec_;
};
