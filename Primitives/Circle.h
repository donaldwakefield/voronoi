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

   explicit Circle(const Site &a, const Site &b, const Site &c) :
      a_(a), b_(b), c_(c), minimum_(-1000000) // TODO: calculate correct minimum
      {};
   ~Circle() {};

   bool valid() const { return true; }
   double minimum() const { return minimum_; }

private:

   Site   a_;
   Site   b_;
   Site   c_;
   double minimum_;
};
