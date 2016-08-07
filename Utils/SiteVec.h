#pragma once

#include <Site.h>

#include <vector>

typedef std::vector<Site> SiteVec;
typedef SiteVec::iterator SiteVecIter;

void fillSiteVec(SiteVec &sites);

/* class SiteVec */
/* { */
/* public: */
/*   typedef std::vector<Site> Set; */
/*   typedef Set::iterator     SetIter; */

/*   SiteVec(); */
/*   ~SiteVec(); */

/*   void writeSites(); */
/*   Set &getVec() { return set_; } */

/* private: */

/*   Set set_; */
/* }; */
