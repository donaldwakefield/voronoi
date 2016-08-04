#pragma once

#include <Site.h>

/*!
 * \class Circle is represented by three sites. It will likely be
 *        changed to refer to Sites outside itself, but this gets us
 *        started.
 * \brief constructor reorders Sites for x-monotonicity (if needed)
 */
class Circle
{
public:

   explicit Circle(const Site &a, const Site &b, const Site &c);
   ~Circle() {};

   bool   valid() const;
   double minimum() const;

   double centerX() const { return h_; }
   double centerY() const { return k_; }
   double radius() const { return radius_; }

private:

   void ensureMonotonicity();
   void calculateCenter();
   void calculateRadius();

private:
   
   Site   a_;
   Site   b_;
   Site   c_;

   double h_, k_;   // ordinates of calculated center
   double radius_;
};
