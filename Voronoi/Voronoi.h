#pragma once

#include <Site.h>
#include <SiteVec.h>
#include <EventQueue.h>

class Voronoi
{
public:

   Voronoi(const SiteVec &sites);
   ~Voronoi() {};

   void outputSVG(const std::string &path);

private:

   SiteVec    sites_;
   EventQueue eq_;
};
