#include <Model.h>

#include <limits>

Model::Model(const SiteVec &svec) :
   siteVec_(svec),
   bounds_(boundsCache())
{
}

QRectF Model::boundsCache()
{
   if (bounds_.isNull())
   {
      qreal rightmost = -std::numeric_limits<qreal>::max();
      qreal topmost = -std::numeric_limits<qreal>::max();

      qreal leftmost = std::numeric_limits<qreal>::max();
      qreal bottommost = std::numeric_limits<qreal>::max();

      SiteVecCIter iter, e_iter = siteVec_.end();
      for (iter = siteVec_.begin(); iter != e_iter; ++iter)
      {
         qreal x = iter->xOrd();
         qreal y = iter->yOrd();

         if (x < leftmost) {
            leftmost = x;
         }
         else if (x > rightmost) {
            rightmost = x;
         }

         if (y < bottommost) {
            bottommost = y;
         }
         else if (y > topmost) {
            topmost = y;
         }
      }

      qreal width  = rightmost - leftmost;
      qreal height = topmost - bottommost;

      // the bounding box must be square...
      if (width > height)
      {
         // expand height to match (approximately)

         qreal delta = (width - height) / 2.0;

         bottommost -= delta;
         topmost    += delta;

         height = topmost - bottommost;
      }
      else if (height > width)
      {
         // expand width to match (approximately)

         qreal delta = (height - width) / 2.0;

         leftmost  -= delta;
         rightmost += delta;

         width  = rightmost - leftmost;
      }

      // the bounding box is padded by 10% on each edge...
      qreal pad = width / 10.0;

      bounds_ = QRectF(QPointF(leftmost-pad,bottommost-pad), QPointF(rightmost+pad,topmost+pad));
   }

   return bounds_;
}
