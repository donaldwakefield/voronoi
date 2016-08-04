#include <Circle.h>

#include <math.h>
#include <utility>

#include <iostream>

Circle::Circle(const Site &a, const Site &b, const Site &c) :
  a_(a),
  b_(b),
  c_(c),
  h_(0),
  k_(0),
  radius_(1000000)
{
  ensureMonotonicity();
  calculateCenter();
  calculateRadius();
}

bool Circle::valid() const
{
   const double delta(0.0001);

   double ax = a_.xOrd(), ay = a_.yOrd();
   double xdist = h_ - ax;
   double ydist = k_ - ay;
   double test_radius = sqrt(xdist*xdist + ydist*ydist);
   if (fabs(radius_ - test_radius) > delta) {
      std::cerr << "radius " << radius_ << " differs too much from point a " << test_radius << std::endl;
      return false;
   }

   double bx = b_.xOrd(), by = b_.yOrd();
   xdist = h_ - bx;
   ydist = k_ - by;
   test_radius = sqrt(xdist*xdist + ydist*ydist);
   if (fabs(radius_ - test_radius) > delta) {
      std::cerr << "radius " << radius_ << " differs too much from point b " << test_radius << std::endl;
      return false;
   }

   double cx = c_.xOrd(), cy = c_.yOrd();
   xdist = h_ - cx;
   ydist = k_ - cy;
   test_radius = sqrt(xdist*xdist + ydist*ydist);
   if (fabs(radius_ - test_radius) > delta) {
      std::cerr << "radius " << radius_ << " differs too much from point c " << test_radius << std::endl;
      return false;
   }

   return true;
}

double Circle::minimum() const
{
   return k_ - radius_;
}

void Circle::ensureMonotonicity()
{
   // simple bubble sort suffices for three members.
   //
   if (a_.xOrd() > b_.xOrd()) {
      std::swap(a_, b_);
   }

   if (b_.xOrd() > c_.xOrd()) {
      std::swap(b_, c_);
   }

   if (a_.xOrd() > b_.xOrd()) {
      std::swap(a_, b_);
   }
}

void Circle::calculateCenter()
{
   // TODO: dirty Cramer's Rule approach...

   std::cout << "calculateCenter():" << std::endl;
   std::cout << "  point a_: " << a_ << std::endl;
   std::cout << "  point b_: " << b_ << std::endl;
   std::cout << "  point c_: " << c_ << std::endl;

   double ax = a_.xOrd(), ay = a_.yOrd();
   double bx = b_.xOrd(), by = b_.yOrd();
   double cx = c_.xOrd(), cy = c_.yOrd();

   double n1 = -(ax*ax + ay*ay);
   double n2 = -(bx*bx + by*by);
   double n3 = -(cx*cx + cy*cy);

   std::cout << "  n1: " << n1 << std::endl;
   std::cout << "  n2: " << n2 << std::endl;
   std::cout << "  n3: " << n3 << std::endl;

   double denom = ax*by + ay*cx + bx*cy - cx*by - cy*ax - bx*ay;
   double cnum = n1*by + ay*n3 + n2*cy - n3*by - cy*n1 - bx*ay;
   double dnum = ax*n2 + n1*cx + bx*n3 - cx*n2 - n3*ax - bx*n1;

   double C = cnum/denom;
   double D = dnum/denom;

   std::cout << "  denom: " << denom << std::endl;
   std::cout << "  cnum:  " << cnum << std::endl;
   std::cout << "  dnum:  " << dnum << std::endl;
   std::cout << "  C:     " << C << std::endl;
   std::cout << "  D:     " << D << std::endl;

   h_ = C / -2.0;
   k_ = D / -2.0;
}

void Circle::calculateRadius()
{
   double ax = a_.xOrd(), ay = a_.yOrd();
   double xdist = h_ - ax;
   double ydist = k_ - ay;
   radius_ = sqrt(xdist*xdist + ydist*ydist);
}
