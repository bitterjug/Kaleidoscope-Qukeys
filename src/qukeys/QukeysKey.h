// -*- c++ -*-

#pragma once

#include <Arduino.h>

#include "kaleidoscope/Key.h"
#include <assert.h>


namespace kaleidoscope {

__attribute__((weak)) extern
constexpr byte qukeys_type_id { 0b01000000 };


class QukeysKey {

 private:
  uint16_t index_ : 8, type_id_ : 8;

 public:
  byte index() const { return index_; }

  QukeysKey() : index_    (0),
                type_id_ (qukeys_type_id) {}

  constexpr explicit
  QukeysKey(byte index) : index_   (index),
                          type_id_ (qukeys_type_id) {}

  explicit
  QukeysKey(Key key) : index_   (uint16_t(key)     ),
                       type_id_ (uint16_t(key) >> 8)  {
    assert(type_id_ == qukeys_type_id);
  }

  constexpr
  operator Key() const {
    return Key( index_        |
                type_id_ << 8   );
  }

  static bool testType(Key key) {
    return ((uint16_t(key) >> 8) == qukeys_type_id);
  }
};

} // namespace kaleidoscope {
