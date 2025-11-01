#pragma once

#include <cstdint>
#include <sstream>
#include <stdexcept>

namespace decoder {
class LEB128Decoder {
public:
  // Decode unsigned LEB128 from stream
  static uint64_t decodeUnsigned(std::istringstream &stream) {
    uint64_t result = 0;
    unsigned shift = 0;

    while (stream.good()) {
      int byteInt = stream.get();

      if (byteInt == EOF) {
        throw std::runtime_error("LEB128: unexpected end of stream");
      }

      uint8_t byte = static_cast<uint8_t>(byteInt);

      // Check for overflow (more than 10 bytes for 64-bit)
      if (shift >= 64) {
        throw std::overflow_error("LEB128: unsigned value too large");
      }

      // Add the lower 7 bits to result
      result |= static_cast<uint64_t>(byte & 0x7F) << shift;
      shift += 7;

      // If high bit is 0, we're done
      if ((byte & 0x80) == 0) {
        return result;
      }
    }

    throw std::runtime_error("LEB128: unexpected end of stream");
  }

  // Decode signed LEB128 from stream
  static int64_t decodeSigned(std::istringstream &stream) {
    int64_t result = 0;
    unsigned shift = 0;
    uint8_t byte;

    while (stream.good()) {
      int byteInt = stream.get();

      if (byteInt == EOF) {
        throw std::runtime_error("LEB128: unexpected end of stream");
      }

      byte = static_cast<uint8_t>(byteInt);

      // Check for overflow
      if (shift >= 64) {
        throw std::overflow_error("LEB128: signed value too large");
      }

      // Add the lower 7 bits to result
      result |= static_cast<int64_t>(byte & 0x7F) << shift;
      shift += 7;

      // If high bit is 0, we're done
      if ((byte & 0x80) == 0) {
        // Sign extend if the sign bit (bit 6) of the last byte is set
        if (shift < 64 && (byte & 0x40)) {
          result |= -(1LL << shift);
        }
        return result;
      }
    }

    throw std::runtime_error("LEB128: unexpected end of stream");
  }
};
} // namespace decoder