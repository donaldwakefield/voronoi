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
   const double twoPi = atan(1.0)*2;
     
   srand(54321);

  for (uint32_t i = 0; i < 12; ++i)
  {
    // arbitrary range. Tighten after we get an idea of workings...
    //

    double sample = rand();
    double theta = sample/RAND_MAX * twoPi;

    double radius = rand() % 150;

    double srad = sqrt(radius);
    double x = srad*cos(theta);
    double y = srad*sin(theta);

    sites.push_back(Site(x,y));
  }
}
