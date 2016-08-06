#include <SiteVec.h>

#include <stdint.h>
#include <stdlib.h>

#include <fstream>

SiteSet::SiteSet() :
  set_()
{
   // first iteration hard codes number of Sites, and the range of ordinates

  srand(12345); // use a fixed seed for now

  for (uint32_t i = 0; i < 20; ++i)
  {
    // arbitrary range. Tighten after we get an idea of workings...
    //
    double x = rand()*1000.0/RAND_MAX + 100;
    double y = rand()*1000.0/RAND_MAX + 100;

    set_.push_back(Site(x,y));
  }
}

SiteSet::~SiteSet()
{
}

void SiteSet::writeSites()
{
   std::ofstream os("/tmp/siteFile");

   SetIter iter, e_iter = set_.end();
   for (iter = set_.begin(); iter != e_iter; ++iter)
   {
      os << "S " << iter->xOrd() << "   " << iter->yOrd() << std::endl;
   }

   os.close();
}
