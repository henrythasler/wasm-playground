#ifndef VLQ_BASE128_LE_H_
#define VLQ_BASE128_LE_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

class vlq_base128_le_t;

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 11000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.11 or later is required"
#endif

/**
 * A variable-length unsigned integer using base128 encoding. 1-byte groups
 * consists of 1-bit flag of continuation and 7-bit value, and are ordered
 * least significant group first, i.e. in little-endian manner
 * (https://github.com/kaitai-io/kaitai_struct_formats/blob/master/common/vlq_base128_le.ksy)
 */

class vlq_base128_le_t : public kaitai::kstruct {

public:
    class group_t;

    vlq_base128_le_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, vlq_base128_le_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~vlq_base128_le_t();

    /**
     * One byte group, clearly divided into 7-bit "value" and 1-bit "has continuation
     * in the next byte" flag.
     */

    class group_t : public kaitai::kstruct {

    public:

        group_t(kaitai::kstream* p__io, vlq_base128_le_t* p__parent = 0, vlq_base128_le_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~group_t();

    private:
        bool f_has_next;
        bool m_has_next;

    public:

        /**
         * If true, then we have more bytes to read
         */
        bool has_next();

    private:
        bool f_value;
        int32_t m_value;

    public:

        /**
         * The 7-bit (base128) numeric value of this group
         */
        int32_t value();

    private:
        uint8_t m_b;
        vlq_base128_le_t* m__root;
        vlq_base128_le_t* m__parent;

    public:
        uint8_t b() const { return m_b; }
        vlq_base128_le_t* _root() const { return m__root; }
        vlq_base128_le_t* _parent() const { return m__parent; }
    };

private:
    bool f_len;
    int32_t m_len;

public:
    int32_t len();

private:
    bool f_value;
    int32_t m_value;

public:

    /**
     * Resulting value as normal integer
     */
    int32_t value();

private:
    std::vector<group_t*>* m_groups;
    vlq_base128_le_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::vector<group_t*>* groups() const { return m_groups; }
    vlq_base128_le_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // VLQ_BASE128_LE_H_
