#ifndef MOREDUINO__WIREDEVICE_H__
#define MOREDUINO__WIREDEVICE_H__

#include "Wire.h"

class WireDevice {
private:
  uint8_t m_address;
  TwoWire &m_wire;
};

#endif // MOREDUINO__WIREDEVICE_H__
