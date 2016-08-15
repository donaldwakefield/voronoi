#include <Model.h>

#include <limits>

QRectF Model::bounds() const
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

   return QRectF(QPointF(leftmost,bottommost), QPointF(rightmost,topmost));
}
