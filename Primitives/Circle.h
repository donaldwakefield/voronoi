#pragma once

#include <Site.h>

/*!
 * \class Circle is represented by three sites. It will likely be
 *        changed to refer to Sites outside itself, but this gets us
 *        started.
 * \brief We'd like to enforce some invariants, such as
 *        - the Sites being montonic in x
 *        - the Circle's lowest y being below any of the Sites (so
 *          upward curving Sites being disallowed)
 *
 *        I really don't like the idea of introducing exceptions into
 *        this design, so the constructor is probably not the right
 *        place to do this. A predicate method is more likely.
 */
class Circle
{
public:

   explicit Circle(const Site &a, const Site &b, const Site &c);
   ~Circle() {};

   bool valid() const;
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
