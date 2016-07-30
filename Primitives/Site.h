#pragma once

// We will use our /usr/local/lib boost install for prototyping
//
#include <boost/noncopyable.hpp>

/*!
 * \class Site represents a single point in the Voronoi
 *        diagram. Coordinates are in real number units.
 *
 * \brief It is not clear yet how tightly we want to control copying
 *        or indeed default construction, as these will likely be
 *        going into the priority queue by value...
 */
class Site : private boost::noncopyable
{
public:

   explicit Site(double x, double y) : x_(x), y_(y) {};
   ~Site() {};

   double xOrd() { return x_; }
   double yOrd() { return y_; }

private:

   double x_;
   double y_;
};
