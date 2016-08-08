#define BOOST_TEST_MODULE VoronoiTest

#include <boost/test/included/unit_test.hpp>

#include <Circle.h>
#include <CircleEvent.h>
#include <Site.h>
#include <SiteEvent.h>
#include <EventQueue.h>
#include <SiteVec.h>
#include <Voronoi.h>

#include <iostream>

BOOST_AUTO_TEST_CASE(first_test)
{
   double feedStock[] = { 6, 7, 0, 1, 4, 1, 8, 9, 2, 3 };
   std::vector<Site> siteVec;
   for (uint32_t i = 0; i < 9; i += 2) {
      siteVec.push_back(Site(feedStock[i], feedStock[i+1]));
   }

   EventQueue eq;
   std::vector<Site>::iterator iter, e_iter = siteVec.end();
   for (iter = siteVec.begin(); iter != e_iter; ++iter) {
      eq.push(EventPtr(new SiteEvent(*iter)));
   }

   Circle circle(siteVec[1], siteVec[4], siteVec[2]);
   BOOST_REQUIRE(circle.valid());
   BOOST_REQUIRE(circle.minimum() == -1);

   eq.push(EventPtr(new CircleEvent(circle)));

   EventPtr currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 9);

   eq.pop();
   currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 7);

   eq.pop();
   currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 3);

   eq.pop();
   currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 1);

   eq.pop();
   currPtr = eq.top();
   BOOST_REQUIRE(currPtr->sweepOrder() == 1);

   eq.pop();
   BOOST_CHECK(!eq.empty());
   currPtr = eq.top();
   eq.pop();
   BOOST_REQUIRE(eq.empty());
}

BOOST_AUTO_TEST_CASE(second_test)
{
   Site a(0, 1);
   Site b(1,2);
   Site c(2,1);

   Circle circle(a, b, c);
   BOOST_REQUIRE(circle.valid());
   BOOST_REQUIRE(circle.minimum() == 0);

#ifdef DEBUG
   std::cout << "Circle center is (" << circle.centerX() << ", " << circle.centerY()
             << ") with radius " << circle.radius() << std::endl;
#endif
}

BOOST_AUTO_TEST_CASE(third_test)
{
  SiteVec siteVec;
  fillSiteVec(siteVec);

  Voronoi vor(siteVec);
  vor.outputSVG("svgTest.html");

  siteVec.clear();
  fillCircularSiteVec(siteVec);
  Voronoi vor2(siteVec);
  vor2.outputSVG("svgCircTest.html");

  BOOST_REQUIRE(true);
}
