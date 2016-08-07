#include <Voronoi.h>

#include <stdint.h>
#include <fstream>

Voronoi::Voronoi(const SiteVec &sites) :
  sites_(sites),
  eq_()
{
}

void Voronoi::outputSVG()
{
   std::ofstream os("./svgTest.html");

   os << "<!DOCTYPE html>" << std::endl << std::endl;

   os << "<html>" << std::endl;
   os << "<head>" << std::endl;
   os << "<title>SVG circle</title>" << std::endl;
   os << "</head>" << std::endl << std::endl;

   os << "<body>" << std::endl << std::endl;

   os << "<p>" << std::endl;
   os << "<svg height=\"1400\" width=\"1400\">" << std::endl;

   SiteVecIter iter, e_iter = sites_.end();
   for (iter = sites_.begin(); iter != e_iter; ++iter)
   {
      // <circle cx="200" cy="400" r="4" stroke="black" stroke-width="3" fill="red" />
      os << "<circle cx=\"" << static_cast<uint32_t>(iter->xOrd())
	 <<      "\" cy=\"" << static_cast<uint32_t>(iter->yOrd())
	 << "\" r=\"4\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" />" << std::endl;
   }

   os << "</svg>" << std::endl;
   os << "</p>" << std::endl << std::endl;

   os << "</body>" << std:: endl;

   os.close();
}
