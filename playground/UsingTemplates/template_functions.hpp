#pragma once

template<typename Value>
bool circularShift(Value &value) {
  const bool firstSet = (value & 0b1u);
  value >>= 1;
  if (firstSet) {
    value |= static_cast<Value>(0b1u) << (sizeof(Value)*8-1);
  }
  return firstSet;
}
