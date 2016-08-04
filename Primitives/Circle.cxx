#include <Circle.h>

#include <math.h>
#include <utility>

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
   // Not actually sure this can mean anything yet...
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

   double ax = a_.xOrd(), ay = a_.yOrd();
   double bx = b_.xOrd(), by = b_.yOrd();
   double cx = c_.xOrd(), cy = c_.yOrd();

   double n1 = -(ax*ax + ay*ay);
   double n2 = -(bx*bx + by*by);
   double n3 = -(cx*cx + cy*cy);

   double denom = ax*by + ay*cx + bx*cy - cx*by - cy*ax - bx*ay;
   double cnum = n1*by + ay*n3 + n2*cy - n3*by - cy*n1 - bx*ay;
   double dnum = ax*n2 + n1*cx + bx*n3 - cx*n2 - n3*ax - bx*n1;

   double C = cnum/denom;
   double D = dnum/denom;

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
