#pragma once

#include <Event.h>
#include <Circle.h>

/*!
 *
 */
class CircleEvent : public Event
{
public:

   CircleEvent(const Circle &circle) : circle_(circle) {};
   virtual ~CircleEvent() {};

   virtual double sweepOrder() const { return circle_.minimum(); }
   virtual double xLocation() const { return circle_.centerX(); }

private:

   Circle circle_;
};
