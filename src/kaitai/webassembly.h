#pragma once

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

class webassembly_t;

#include "kaitai/kaitaistruct.h"
#include <stdint.h>
#include <memory>
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
 * Repository: https://github.com/henrythasler/wasm-kaitai-struct
 * 
 * * Naming of entities follows the official specification.
 * * All integers are encoded using the LEB128 variable-length integer encoding (see vlq_base128_le.ksy).
 * * The schema follows the KSY Style Guide
 * * Requires ks-version 0.9+ because of attribute value validation
 * * types appear in the order in which they are required
 * \sa * https://www.w3.org/TR/wasm-core-1/
 */

class webassembly_t : public kaitai::kstruct {

public:
    class code_t;
    class code_section_t;
    class custom_section_t;
    class data_section_t;
    class data_segment_t;
    class element_t;
    class element_section_t;
    class export_t;
    class export_section_t;
    class expression_t;
    class func_t;
    class function_section_t;
    class functype_t;
    class global_t;
    class global_import_t;
    class global_section_t;
    class import_t;
    class import_section_t;
    class limits_t;
    class local_t;
    class memory_t;
    class memory_section_t;
    class name_t;
    class section_t;
    class start_section_t;
    class table_t;
    class table_section_t;
    class type_section_t;
    class vec_valtype_t;

    enum export_types_t {
        EXPORT_TYPES_FUNC_TYPE = 0,
        EXPORT_TYPES_TABLE_TYPE = 1,
        EXPORT_TYPES_MEM_TYPE = 2,
        EXPORT_TYPES_GLOBAL_TYPE = 3
    };
    static bool _is_defined_export_types_t(export_types_t v);

private:
    static const std::set<export_types_t> _values_export_types_t;

public:

    enum import_types_t {
        IMPORT_TYPES_FUNC_TYPE = 0,
        IMPORT_TYPES_TABLE_TYPE = 1,
        IMPORT_TYPES_MEM_TYPE = 2,
        IMPORT_TYPES_GLOBAL_TYPE = 3
    };
    static bool _is_defined_import_types_t(import_types_t v);

private:
    static const std::set<import_types_t> _values_import_types_t;

public:

    enum mutability_types_t {
        MUTABILITY_TYPES_CONST = 0,
        MUTABILITY_TYPES_VAR = 1
    };
    static bool _is_defined_mutability_types_t(mutability_types_t v);

private:
    static const std::set<mutability_types_t> _values_mutability_types_t;

public:

    enum section_id_t {
        SECTION_ID_CUSTOM_SECTION = 0,
        SECTION_ID_TYPE_SECTION = 1,
        SECTION_ID_IMPORT_SECTION = 2,
        SECTION_ID_FUNCTION_SECTION = 3,
        SECTION_ID_TABLE_SECTION = 4,
        SECTION_ID_MEMORY_SECTION = 5,
        SECTION_ID_GLOBAL_SECTION = 6,
        SECTION_ID_EXPORT_SECTION = 7,
        SECTION_ID_START_SECTION = 8,
        SECTION_ID_ELEMENT_SECTION = 9,
        SECTION_ID_CODE_SECTION = 10,
        SECTION_ID_DATA_SECTION = 11
    };
    static bool _is_defined_section_id_t(section_id_t v);

private:
    static const std::set<section_id_t> _values_section_id_t;

public:

    enum types_t {
        TYPES_FUNCTION = 96,
        TYPES_ELEMENT = 112
    };
    static bool _is_defined_types_t(types_t v);

private:
    static const std::set<types_t> _values_types_t;

public:

    enum val_types_t {
        VAL_TYPES_F64 = 124,
        VAL_TYPES_F32 = 125,
        VAL_TYPES_I64 = 126,
        VAL_TYPES_I32 = 127
    };
    static bool _is_defined_val_types_t(val_types_t v);

private:
    static const std::set<val_types_t> _values_val_types_t;

public:

    webassembly_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, webassembly_t* p__root = nullptr);

private:
    void _read();
    void _clean_up();

public:
    ~webassembly_t();

    class code_t : public kaitai::kstruct {

    public:

        code_t(kaitai::kstream* p__io, webassembly_t::code_section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~code_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_len_func;
        std::unique_ptr<func_t> m_func;
        webassembly_t* m__root;
        webassembly_t::code_section_t* m__parent;
        std::string m__raw_func;
        std::unique_ptr<kaitai::kstream> m__io__raw_func;

    public:
        vlq_base128_le_t* len_func() const { return m_len_func.get(); }
        func_t* func() const { return m_func.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::code_section_t* _parent() const { return m__parent; }
        std::string _raw_func() const { return m__raw_func; }
        kaitai::kstream* _io__raw_func() const { return m__io__raw_func.get(); }
    };

    /**
     * (id 10) A vector of code entries
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-codesec Source
     */

    class code_section_t : public kaitai::kstruct {

    public:

        code_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~code_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_entries;
        std::unique_ptr<std::vector<std::unique_ptr<code_t>>> m_entries;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_entries() const { return m_num_entries.get(); }
        std::vector<std::unique_ptr<code_t>>* entries() const { return m_entries.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    /**
     * (id 0) - Custom section whose content is application-specific and not defined by the WebAssembly specification.
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-customsec Source
     */

    class custom_section_t : public kaitai::kstruct {

    public:

        custom_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~custom_section_t();

    private:
        std::unique_ptr<name_t> m_name;
        std::string m_data;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        name_t* name() const { return m_name.get(); }

        /**
         * Custom section data; out of scope for this schema
         */
        std::string data() const { return m_data; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    /**
     * (11) - Vector of data segments
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-datasec Source
     */

    class data_section_t : public kaitai::kstruct {

    public:

        data_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~data_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_data;
        std::unique_ptr<std::vector<std::unique_ptr<data_segment_t>>> m_data_segments;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_data() const { return m_num_data.get(); }
        std::vector<std::unique_ptr<data_segment_t>>* data_segments() const { return m_data_segments.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class data_segment_t : public kaitai::kstruct {

    public:

        data_segment_t(kaitai::kstream* p__io, webassembly_t::data_section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~data_segment_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_data_memidx;
        std::unique_ptr<expression_t> m_offset_expr;
        std::unique_ptr<vlq_base128_le_t> m_num_init;
        std::string m_init_vec;
        webassembly_t* m__root;
        webassembly_t::data_section_t* m__parent;

    public:
        vlq_base128_le_t* data_memidx() const { return m_data_memidx.get(); }

        /**
         * The offset is given by a constant expression that DOES NOT include an end marker
         * \sa https://www.w3.org/TR/wasm-core-1/#valid-constant Source
         */
        expression_t* offset_expr() const { return m_offset_expr.get(); }
        vlq_base128_le_t* num_init() const { return m_num_init.get(); }
        std::string init_vec() const { return m_init_vec; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::data_section_t* _parent() const { return m__parent; }
    };

    class element_t : public kaitai::kstruct {

    public:

        element_t(kaitai::kstream* p__io, webassembly_t::element_section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~element_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_tableidx;
        std::unique_ptr<expression_t> m_offset_expr;
        std::unique_ptr<vlq_base128_le_t> m_num_init;
        std::unique_ptr<std::vector<std::unique_ptr<vlq_base128_le_t>>> m_init_vec;
        webassembly_t* m__root;
        webassembly_t::element_section_t* m__parent;

    public:
        vlq_base128_le_t* tableidx() const { return m_tableidx.get(); }

        /**
         * The offset is given by a constant expression that DOES NOT include an end marker
         * \sa https://www.w3.org/TR/wasm-core-1/#valid-constant Source
         */
        expression_t* offset_expr() const { return m_offset_expr.get(); }
        vlq_base128_le_t* num_init() const { return m_num_init.get(); }
        std::vector<std::unique_ptr<vlq_base128_le_t>>* init_vec() const { return m_init_vec.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::element_section_t* _parent() const { return m__parent; }
    };

    /**
     * (id 9) - Vector of element sections
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-elemsec Source
     */

    class element_section_t : public kaitai::kstruct {

    public:

        element_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~element_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_elements;
        std::unique_ptr<std::vector<std::unique_ptr<element_t>>> m_elements;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_elements() const { return m_num_elements.get(); }
        std::vector<std::unique_ptr<element_t>>* elements() const { return m_elements.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class export_t : public kaitai::kstruct {

    public:

        export_t(kaitai::kstream* p__io, webassembly_t::export_section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~export_t();

    private:
        std::unique_ptr<name_t> m_name;
        export_types_t m_exportdesc;
        std::unique_ptr<vlq_base128_le_t> m_idx;
        webassembly_t* m__root;
        webassembly_t::export_section_t* m__parent;

    public:
        name_t* name() const { return m_name.get(); }
        export_types_t exportdesc() const { return m_exportdesc; }
        vlq_base128_le_t* idx() const { return m_idx.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::export_section_t* _parent() const { return m__parent; }
    };

    /**
     * (id 7) - Exported entities
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-exportsec Source
     */

    class export_section_t : public kaitai::kstruct {

    public:

        export_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~export_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_exports;
        std::unique_ptr<std::vector<std::unique_ptr<export_t>>> m_exports;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_exports() const { return m_num_exports.get(); }
        std::vector<std::unique_ptr<export_t>>* exports() const { return m_exports.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class expression_t : public kaitai::kstruct {

    public:

        expression_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~expression_t();

    private:
        std::unique_ptr<std::vector<uint8_t>> m_bytes;
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        std::vector<uint8_t>* bytes() const { return m_bytes.get(); }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class func_t : public kaitai::kstruct {

    public:

        func_t(kaitai::kstream* p__io, webassembly_t::code_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~func_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_locals;
        std::unique_ptr<std::vector<std::unique_ptr<local_t>>> m_locals;
        std::string m_expr;
        webassembly_t* m__root;
        webassembly_t::code_t* m__parent;

    public:
        vlq_base128_le_t* num_locals() const { return m_num_locals.get(); }
        std::vector<std::unique_ptr<local_t>>* locals() const { return m_locals.get(); }
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

        function_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~function_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_typeidx;
        std::unique_ptr<std::vector<std::unique_ptr<vlq_base128_le_t>>> m_typeidx;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_typeidx() const { return m_num_typeidx.get(); }
        std::vector<std::unique_ptr<vlq_base128_le_t>>* typeidx() const { return m_typeidx.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    /**
     * Byte `0x60` followed by a vector of parameters and results
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-functype Source
     */

    class functype_t : public kaitai::kstruct {

    public:

        functype_t(kaitai::kstream* p__io, webassembly_t::type_section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~functype_t();

    private:
        types_t m_functype;
        std::unique_ptr<vec_valtype_t> m_parameters;
        std::unique_ptr<vec_valtype_t> m_results;
        webassembly_t* m__root;
        webassembly_t::type_section_t* m__parent;

    public:
        types_t functype() const { return m_functype; }
        vec_valtype_t* parameters() const { return m_parameters.get(); }
        vec_valtype_t* results() const { return m_results.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::type_section_t* _parent() const { return m__parent; }
    };

    class global_t : public kaitai::kstruct {

    public:

        global_t(kaitai::kstream* p__io, webassembly_t::global_section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~global_t();

    private:
        val_types_t m_valtype;
        mutability_types_t m_mutability;
        std::unique_ptr<expression_t> m_init_expr;
        webassembly_t* m__root;
        webassembly_t::global_section_t* m__parent;

    public:
        val_types_t valtype() const { return m_valtype; }
        mutability_types_t mutability() const { return m_mutability; }
        expression_t* init_expr() const { return m_init_expr.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::global_section_t* _parent() const { return m__parent; }
    };

    class global_import_t : public kaitai::kstruct {

    public:

        global_import_t(kaitai::kstream* p__io, webassembly_t::import_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~global_import_t();

    private:
        val_types_t m_valtype;
        mutability_types_t m_mutability;
        webassembly_t* m__root;
        webassembly_t::import_t* m__parent;

    public:
        val_types_t valtype() const { return m_valtype; }
        mutability_types_t mutability() const { return m_mutability; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::import_t* _parent() const { return m__parent; }
    };

    /**
     * (id 6) Vector of globals
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-memsec Source
     */

    class global_section_t : public kaitai::kstruct {

    public:

        global_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~global_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_globals;
        std::unique_ptr<std::vector<std::unique_ptr<global_t>>> m_globals;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_globals() const { return m_num_globals.get(); }
        std::vector<std::unique_ptr<global_t>>* globals() const { return m_globals.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    /**
     * An element of the import section
     */

    class import_t : public kaitai::kstruct {

    public:

        import_t(kaitai::kstream* p__io, webassembly_t::import_section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~import_t();

    private:
        std::unique_ptr<name_t> m_module;
        std::unique_ptr<name_t> m_name;
        import_types_t m_import_type;
        std::unique_ptr<kaitai::kstruct> m_importdesc;
        bool n_importdesc;

    public:
        bool _is_null_importdesc() { importdesc(); return n_importdesc; };

    private:
        webassembly_t* m__root;
        webassembly_t::import_section_t* m__parent;

    public:
        name_t* module() const { return m_module.get(); }
        name_t* name() const { return m_name.get(); }
        import_types_t import_type() const { return m_import_type; }
        kaitai::kstruct* importdesc() const { return m_importdesc.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::import_section_t* _parent() const { return m__parent; }
    };

    /**
     * (id 2) - Imported components
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-importsec Source
     */

    class import_section_t : public kaitai::kstruct {

    public:

        import_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~import_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_imports;
        std::unique_ptr<std::vector<std::unique_ptr<import_t>>> m_imports;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_imports() const { return m_num_imports.get(); }
        std::vector<std::unique_ptr<import_t>>* imports() const { return m_imports.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class limits_t : public kaitai::kstruct {

    public:

        limits_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~limits_t();

    private:
        uint8_t m_flags;
        std::unique_ptr<vlq_base128_le_t> m_min;
        std::unique_ptr<vlq_base128_le_t> m_max;
        bool n_max;

    public:
        bool _is_null_max() { max(); return n_max; };

    private:
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint8_t flags() const { return m_flags; }
        vlq_base128_le_t* min() const { return m_min.get(); }
        vlq_base128_le_t* max() const { return m_max.get(); }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class local_t : public kaitai::kstruct {

    public:

        local_t(kaitai::kstream* p__io, webassembly_t::func_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~local_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_valtype;
        val_types_t m_valtype;
        webassembly_t* m__root;
        webassembly_t::func_t* m__parent;

    public:
        vlq_base128_le_t* num_valtype() const { return m_num_valtype.get(); }
        val_types_t valtype() const { return m_valtype; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::func_t* _parent() const { return m__parent; }
    };

    class memory_t : public kaitai::kstruct {

    public:

        memory_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~memory_t();

    private:
        std::unique_ptr<limits_t> m_limits;
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        limits_t* limits() const { return m_limits.get(); }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * (id 5) Vector of memories
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-memsec Source
     */

    class memory_section_t : public kaitai::kstruct {

    public:

        memory_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~memory_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_memories;
        std::unique_ptr<std::vector<std::unique_ptr<memory_t>>> m_memories;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_memories() const { return m_num_memories.get(); }
        std::vector<std::unique_ptr<memory_t>>* memories() const { return m_memories.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    /**
     * UTF-8 encoded character sequence
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-name Source
     */

    class name_t : public kaitai::kstruct {

    public:

        name_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~name_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_length;
        std::string m_value;
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        vlq_base128_le_t* length() const { return m_length.get(); }
        std::string value() const { return m_value; }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * A specific section as part of a module
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-section Source
     */

    class section_t : public kaitai::kstruct {

    public:

        section_t(kaitai::kstream* p__io, webassembly_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~section_t();

    private:
        section_id_t m_id;
        std::unique_ptr<vlq_base128_le_t> m_len_content;
        std::unique_ptr<kaitai::kstruct> m_content;
        bool n_content;

    public:
        bool _is_null_content() { content(); return n_content; };

    private:
        webassembly_t* m__root;
        webassembly_t* m__parent;
        std::string m__raw_content;
        std::unique_ptr<kaitai::kstream> m__io__raw_content;

    public:

        /**
         * Section identifier
         */
        section_id_t id() const { return m_id; }

        /**
         * Length of the section content in bytes
         */
        vlq_base128_le_t* len_content() const { return m_len_content.get(); }

        /**
         * Section content
         */
        kaitai::kstruct* content() const { return m_content.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t* _parent() const { return m__parent; }
        std::string _raw_content() const { return m__raw_content; }
        kaitai::kstream* _io__raw_content() const { return m__io__raw_content.get(); }
    };

    /**
     * (id 8) - Start-function or -component of the module
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-startsec Source
     */

    class start_section_t : public kaitai::kstruct {

    public:

        start_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~start_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_start;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:

        /**
         * function index of the start-function
         */
        vlq_base128_le_t* start() const { return m_start.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class table_t : public kaitai::kstruct {

    public:

        table_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~table_t();

    private:
        types_t m_elemtype;
        std::unique_ptr<limits_t> m_limits;
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        types_t elemtype() const { return m_elemtype; }
        limits_t* limits() const { return m_limits.get(); }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * (id 4) Vector of tables
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-tablesec Source
     */

    class table_section_t : public kaitai::kstruct {

    public:

        table_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~table_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_tables;
        std::unique_ptr<std::vector<std::unique_ptr<table_t>>> m_tables;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_tables() const { return m_num_tables.get(); }
        std::vector<std::unique_ptr<table_t>>* tables() const { return m_tables.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    /**
     * (id 1) - A vector of function types
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-typesec Source
     */

    class type_section_t : public kaitai::kstruct {

    public:

        type_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~type_section_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_functypes;
        std::unique_ptr<std::vector<std::unique_ptr<functype_t>>> m_functypes;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* num_functypes() const { return m_num_functypes.get(); }
        std::vector<std::unique_ptr<functype_t>>* functypes() const { return m_functypes.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class vec_valtype_t : public kaitai::kstruct {

    public:

        vec_valtype_t(kaitai::kstream* p__io, webassembly_t::functype_t* p__parent = nullptr, webassembly_t* p__root = nullptr);

    private:
        void _read();
        void _clean_up();

    public:
        ~vec_valtype_t();

    private:
        std::unique_ptr<vlq_base128_le_t> m_num_types;
        std::unique_ptr<std::vector<val_types_t>> m_valtype;
        webassembly_t* m__root;
        webassembly_t::functype_t* m__parent;

    public:
        vlq_base128_le_t* num_types() const { return m_num_types.get(); }

        /**
         * Value Types
         * \sa https://www.w3.org/TR/wasm-core-1/#binary-valtype Source
         */
        std::vector<val_types_t>* valtype() const { return m_valtype.get(); }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::functype_t* _parent() const { return m__parent; }
    };

private:
    std::string m_magic;
    uint32_t m_version;
    std::unique_ptr<std::vector<std::unique_ptr<section_t>>> m_sections;
    webassembly_t* m__root;
    kaitai::kstruct* m__parent;

public:

    /**
     * Magic number identifying the file as a WebAssembly module
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-magic Source
     */
    std::string magic() const { return m_magic; }

    /**
     * Version of the WebAssembly binary format
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-version Source
     */
    uint32_t version() const { return m_version; }

    /**
     * A WebAssembly module is a set of sections
     * \sa https://www.w3.org/TR/wasm-core-1/#binary-module Source
     */
    std::vector<std::unique_ptr<section_t>>* sections() const { return m_sections.get(); }
    webassembly_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};
