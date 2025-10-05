#ifndef WEBASSEMBLY_H_
#define WEBASSEMBLY_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

class webassembly_t;

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include "vlq_base128_le.h"
#include <set>
#include <vector>

#if KAITAI_STRUCT_VERSION < 11000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.11 or later is required"
#endif

/**
 * This document describes the binary format of a WebAssembly module 
 * following the version 1.0 of the core WebAssembly standard.
 * 
 * * Naming of entities follows the official specification.
 * * All integers are encoded using the LEB128 variable-length integer encoding (see vlq_base128_le.ksy).
 * * The schema follows the KSY Style Guide
 * * Requires ks-version 0.9+ because of attribute value validation
 * \sa * https://www.w3.org/TR/wasm-core-1/
 * * https://doc.kaitai.io/ksy_style_guide.html
 */

class webassembly_t : public kaitai::kstruct {

public:
    class code_t;
    class code_section_t;
    class custom_section_t;
    class dummy_t;
    class export_t;
    class export_section_t;
    class func_t;
    class function_section_t;
    class functype_t;
    class local_t;
    class name_t;
    class section_t;
    class type_section_t;
    class vec_valtype_t;

    enum indices_t {
        INDICES_FUNC = 0,
        INDICES_TABLE = 1,
        INDICES_MEM = 2,
        INDICES_GLOBAL = 3
    };
    static bool _is_defined_indices_t(indices_t v);

private:
    static const std::set<indices_t> _values_indices_t;
    static std::set<indices_t> _build_values_indices_t();

public:

    enum section_id_t {
        SECTION_ID_CUSTOM = 0,
        SECTION_ID_TYPE = 1,
        SECTION_ID_IMPORT = 2,
        SECTION_ID_FUNCTION = 3,
        SECTION_ID_TABLE = 4,
        SECTION_ID_MEMORY = 5,
        SECTION_ID_GLOBAL = 6,
        SECTION_ID_EXPORT = 7,
        SECTION_ID_START = 8,
        SECTION_ID_ELEMENT = 9,
        SECTION_ID_CODE = 10,
        SECTION_ID_DATA = 11
    };
    static bool _is_defined_section_id_t(section_id_t v);

private:
    static const std::set<section_id_t> _values_section_id_t;
    static std::set<section_id_t> _build_values_section_id_t();

public:

    enum types_t {
        TYPES_FUNCTION = 96
    };
    static bool _is_defined_types_t(types_t v);

private:
    static const std::set<types_t> _values_types_t;
    static std::set<types_t> _build_values_types_t();

public:

    enum valtype_t {
        VALTYPE_F64 = 124,
        VALTYPE_F32 = 125,
        VALTYPE_I64 = 126,
        VALTYPE_I32 = 127
    };
    static bool _is_defined_valtype_t(valtype_t v);

private:
    static const std::set<valtype_t> _values_valtype_t;
    static std::set<valtype_t> _build_values_valtype_t();

public:

    webassembly_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, webassembly_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~webassembly_t();

    class code_t : public kaitai::kstruct {

    public:

        code_t(kaitai::kstream* p__io, webassembly_t::code_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~code_t();

    private:
        vlq_base128_le_t* m_len_func;
        func_t* m_func;
        webassembly_t* m__root;
        webassembly_t::code_section_t* m__parent;
        std::string m__raw_func;
        kaitai::kstream* m__io__raw_func;

    public:
        vlq_base128_le_t* len_func() const { return m_len_func; }
        func_t* func() const { return m_func; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::code_section_t* _parent() const { return m__parent; }
        std::string _raw_func() const { return m__raw_func; }
        kaitai::kstream* _io__raw_func() const { return m__io__raw_func; }
    };

    /**
     * (id 10) A vector of code entries
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-codesec Source
     */

    class code_section_t : public kaitai::kstruct {

    public:

        code_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~code_section_t();

    private:
        vlq_base128_le_t* m_num_entries;
        std::vector<code_t*>* m_entries;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_entries() const { return m_num_entries; }
        std::vector<code_t*>* entries() const { return m_entries; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    /**
     * (id 0) - Custom section whose content is application-specific and not defined by the WebAssembly specification.
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-customsec Source
     */

    class custom_section_t : public kaitai::kstruct {

    public:

        custom_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~custom_section_t();

    private:
        name_t* m_name;
        std::string m_data;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        name_t* name() const { return m_name; }

        /**
         * Custom section data
         */
        std::string data() const { return m_data; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class dummy_t : public kaitai::kstruct {

    public:

        dummy_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~dummy_t();

    private:
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class export_t : public kaitai::kstruct {

    public:

        export_t(kaitai::kstream* p__io, webassembly_t::export_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~export_t();

    private:
        name_t* m_name;
        indices_t m_exportdesc;
        vlq_base128_le_t* m_idx;
        webassembly_t* m__root;
        webassembly_t::export_section_t* m__parent;

    public:
        name_t* name() const { return m_name; }
        indices_t exportdesc() const { return m_exportdesc; }
        vlq_base128_le_t* idx() const { return m_idx; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::export_section_t* _parent() const { return m__parent; }
    };

    /**
     * (id 7) -
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-exportsec Source
     */

    class export_section_t : public kaitai::kstruct {

    public:

        export_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~export_section_t();

    private:
        vlq_base128_le_t* m_num_exports;
        std::vector<export_t*>* m_exports;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_exports() const { return m_num_exports; }
        std::vector<export_t*>* exports() const { return m_exports; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class func_t : public kaitai::kstruct {

    public:

        func_t(kaitai::kstream* p__io, webassembly_t::code_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~func_t();

    private:
        vlq_base128_le_t* m_num_locals;
        std::vector<local_t*>* m_locals;
        std::string m_expr;
        webassembly_t* m__root;
        webassembly_t::code_t* m__parent;

    public:
        vlq_base128_le_t* num_locals() const { return m_num_locals; }
        std::vector<local_t*>* locals() const { return m_locals; }
        std::string expr() const { return m_expr; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::code_t* _parent() const { return m__parent; }
    };

    /**
     * (id 3) - Vector of type indices (see `Type Section`) for all functions in the `Code Section`
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-funcsec Source
     */

    class function_section_t : public kaitai::kstruct {

    public:

        function_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~function_section_t();

    private:
        vlq_base128_le_t* m_num_typeidx;
        std::vector<vlq_base128_le_t*>* m_typeidx;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_typeidx() const { return m_num_typeidx; }
        std::vector<vlq_base128_le_t*>* typeidx() const { return m_typeidx; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    /**
     * Byte `0x60` followed by a vector of parameters and results
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-functype Source
     */

    class functype_t : public kaitai::kstruct {

    public:

        functype_t(kaitai::kstream* p__io, webassembly_t::type_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~functype_t();

    private:
        types_t m_functype;
        vec_valtype_t* m_parameters;
        vec_valtype_t* m_results;
        webassembly_t* m__root;
        webassembly_t::type_section_t* m__parent;

    public:
        types_t functype() const { return m_functype; }
        vec_valtype_t* parameters() const { return m_parameters; }
        vec_valtype_t* results() const { return m_results; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::type_section_t* _parent() const { return m__parent; }
    };

    class local_t : public kaitai::kstruct {

    public:

        local_t(kaitai::kstream* p__io, webassembly_t::func_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~local_t();

    private:
        vlq_base128_le_t* m_num_valtype;
        valtype_t m_valtype;
        webassembly_t* m__root;
        webassembly_t::func_t* m__parent;

    public:
        vlq_base128_le_t* num_valtype() const { return m_num_valtype; }
        valtype_t valtype() const { return m_valtype; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::func_t* _parent() const { return m__parent; }
    };

    /**
     * https://www.w3.org/TR/wasm-core-1/#binary-name
     */

    class name_t : public kaitai::kstruct {

    public:

        name_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~name_t();

    private:
        vlq_base128_le_t* m_length;
        std::string m_value;
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        vlq_base128_le_t* length() const { return m_length; }
        std::string value() const { return m_value; }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * REF: https://www.w3.org/TR/wasm-core-1/#sections%E2%91%A0
     */

    class section_t : public kaitai::kstruct {

    public:

        section_t(kaitai::kstream* p__io, webassembly_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~section_t();

    private:
        section_id_t m_id;
        vlq_base128_le_t* m_len_content;
        kaitai::kstruct* m_content;
        bool n_content;

    public:
        bool _is_null_content() { content(); return n_content; };

    private:
        webassembly_t* m__root;
        webassembly_t* m__parent;
        std::string m__raw_content;
        kaitai::kstream* m__io__raw_content;

    public:

        /**
         * Section identifier
         */
        section_id_t id() const { return m_id; }

        /**
         * Length of the section content in bytes
         */
        vlq_base128_le_t* len_content() const { return m_len_content; }

        /**
         * Section content
         */
        kaitai::kstruct* content() const { return m_content; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t* _parent() const { return m__parent; }
        std::string _raw_content() const { return m__raw_content; }
        kaitai::kstream* _io__raw_content() const { return m__io__raw_content; }
    };

    /**
     * (id 1) - A vector of function types
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-typesec Source
     */

    class type_section_t : public kaitai::kstruct {

    public:

        type_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~type_section_t();

    private:
        vlq_base128_le_t* m_num_functypes;
        std::vector<functype_t*>* m_functypes;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_functypes() const { return m_num_functypes; }
        std::vector<functype_t*>* functypes() const { return m_functypes; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class vec_valtype_t : public kaitai::kstruct {

    public:

        vec_valtype_t(kaitai::kstream* p__io, webassembly_t::functype_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~vec_valtype_t();

    private:
        vlq_base128_le_t* m_num_types;
        std::vector<valtype_t>* m_valtype;
        webassembly_t* m__root;
        webassembly_t::functype_t* m__parent;

    public:
        vlq_base128_le_t* num_types() const { return m_num_types; }
        std::vector<valtype_t>* valtype() const { return m_valtype; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::functype_t* _parent() const { return m__parent; }
    };

private:
    std::string m_magic;
    uint32_t m_version;
    std::vector<section_t*>* m_sections;
    webassembly_t* m__root;
    kaitai::kstruct* m__parent;

public:

    /**
     * Magic number identifying the file as a WebAssembly module
     * REF: https://www.w3.org/TR/wasm-core-1/#binary-magic
     */
    std::string magic() const { return m_magic; }

    /**
     * Version of the WebAssembly binary format
     * REF: https://www.w3.org/TR/wasm-core-1/#binary-version
     */
    uint32_t version() const { return m_version; }

    /**
     * Sequence of sections in the module
     * REF: https://www.w3.org/TR/wasm-core-1/#binary-module
     */
    std::vector<section_t*>* sections() const { return m_sections; }
    webassembly_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // WEBASSEMBLY_H_
