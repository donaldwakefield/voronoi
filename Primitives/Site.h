#pragma once

#include <iostream>

/*!
 * \class Site represents a single point in the Voronoi
 *        diagram. Coordinates are in real number units.
 *
 * \brief It is not clear yet how tightly we want to control copying
 *        or indeed default construction, as these will likely be
 *        going into the priority queue by value...
 */
class Site
{
public:

   explicit Site(double x, double y) : x_(x), y_(y) {};
   ~Site() {};

   double xOrd() const { return x_; }
   double yOrd() const { return y_; }

   friend std::ostream &operator<<(std::ostream &os, const Site &site) {
      os << "Site(" << site.xOrd() << "," << site.yOrd() << ")" << std::endl;
      return os;
   }

private:

   double x_;
   double y_;
};
