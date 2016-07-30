#pragma once

/*!
 * \class Event forms the base protocol class for all event types.
 * \brief The sweepOrder method allows derived classes to say where
 *        they should fall in the queue
 */
class Event
{
public:

  Event() {};
  virtual ~Event() {}

  virtual double sweepOrder() = 0;
};
