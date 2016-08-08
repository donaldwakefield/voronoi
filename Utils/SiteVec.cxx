#include <SiteVec.h>

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#include <fstream>

void fillSiteVec(SiteVec &sites)
{
   // first iteration hard codes number of Sites, and the range of ordinates

   srand(12345); // use a fixed seed for now

   for (uint32_t i = 0; i < 12; ++i)
   {
      // arbitrary range. Tighten after we get an idea of workings...
      //
      double x = rand() % 950 + 150;
      double y = rand() % 950 + 150;

      sites.push_back(Site(x,y));
   }
}

void fillCircularSiteVec(SiteVec &sites)
{
   const double twoPi = atan(1.0)*8;
     
   srand(54321);

   for (uint32_t i = 0; i < 12; ++i)
   {
      // arbitrary range. Tighten after we get an idea of workings...
      //

      double sample = rand();
      double theta = sample/RAND_MAX * twoPi;  // [0, 2*pi)

      sample = rand();
      double radius = sample/RAND_MAX;  // [0, 1)

      double srad = sqrt(radius);

      // x and y in unit circle
      double x = srad*cos(theta);
      double y = srad*sin(theta);

      // scale similarly to square sampling
      x = x*475 + 625;
      y = y*475 + 625;

      sites.push_back(Site(x,y));
   }
}
