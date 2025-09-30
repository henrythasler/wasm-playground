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
 * WebAssembly is a web standard that defines a binary format and a corresponding
 * assembly-like text format for executable code in Web pages. It is meant to
 * enable executing code nearly as fast as running native machine code.
 * \sa https://github.com/WebAssembly/design/blob/master/BinaryEncoding.md Source
 */

class webassembly_t : public kaitai::kstruct {

public:
    class code_section_t;
    class data_count_section_t;
    class data_section_t;
    class data_segment_type_t;
    class elem_segment_type_t;
    class element_section_t;
    class export_entry_type_t;
    class export_section_t;
    class func_type_t;
    class function_body_data_type_t;
    class function_body_type_t;
    class function_section_t;
    class global_section_t;
    class global_type_t;
    class global_variable_type_t;
    class import_entry_t;
    class import_section_t;
    class linking_custom_subsection_type_t;
    class linking_custom_type_t;
    class local_entry_type_t;
    class memory_section_t;
    class memory_type_t;
    class resizable_limits_type_t;
    class section_t;
    class section_header_t;
    class sections_t;
    class start_section_t;
    class symbol_table_type_t;
    class syminfo_data_t;
    class syminfo_ext_t;
    class syminfo_section_t;
    class syminfo_type_t;
    class table_section_t;
    class table_type_t;
    class type_section_t;
    class unimplemented_section_t;

    enum constructor_type_t {
        CONSTRUCTOR_TYPE_EMPTY_BLOCK = 64,
        CONSTRUCTOR_TYPE_FUNC = 96,
        CONSTRUCTOR_TYPE_ANYFUNC = 112,
        CONSTRUCTOR_TYPE_F64 = 124,
        CONSTRUCTOR_TYPE_F32 = 125,
        CONSTRUCTOR_TYPE_I64 = 126,
        CONSTRUCTOR_TYPE_I32 = 127
    };
    static bool _is_defined_constructor_type_t(constructor_type_t v);

private:
    static const std::set<constructor_type_t> _values_constructor_type_t;
    static std::set<constructor_type_t> _build_values_constructor_type_t();

public:

    enum elem_type_t {
        ELEM_TYPE_ANYFUNC = 112
    };
    static bool _is_defined_elem_type_t(elem_type_t v);

private:
    static const std::set<elem_type_t> _values_elem_type_t;
    static std::set<elem_type_t> _build_values_elem_type_t();

public:

    enum kind_type_t {
        KIND_TYPE_FUNCTION_KIND = 0,
        KIND_TYPE_TABLE_KIND = 1,
        KIND_TYPE_MEMORY_KIND = 2,
        KIND_TYPE_GLOBAL_KIND = 3
    };
    static bool _is_defined_kind_type_t(kind_type_t v);

private:
    static const std::set<kind_type_t> _values_kind_type_t;
    static std::set<kind_type_t> _build_values_kind_type_t();

public:

    enum linking_metadata_payload_type_t {
        LINKING_METADATA_PAYLOAD_TYPE_SEGMENT_INFO = 5,
        LINKING_METADATA_PAYLOAD_TYPE_INIT_FUNCS = 6,
        LINKING_METADATA_PAYLOAD_TYPE_COMDAT_INFO = 7,
        LINKING_METADATA_PAYLOAD_TYPE_SYMBOL_TABLE = 8
    };
    static bool _is_defined_linking_metadata_payload_type_t(linking_metadata_payload_type_t v);

private:
    static const std::set<linking_metadata_payload_type_t> _values_linking_metadata_payload_type_t;
    static std::set<linking_metadata_payload_type_t> _build_values_linking_metadata_payload_type_t();

public:

    enum mutability_flag_t {
        MUTABILITY_FLAG_IMMUTABLE = 0,
        MUTABILITY_FLAG_MUTABLE = 1
    };
    static bool _is_defined_mutability_flag_t(mutability_flag_t v);

private:
    static const std::set<mutability_flag_t> _values_mutability_flag_t;
    static std::set<mutability_flag_t> _build_values_mutability_flag_t();

public:

    enum payload_type_t {
        PAYLOAD_TYPE_CUSTOM_PAYLOAD = 0,
        PAYLOAD_TYPE_TYPE_PAYLOAD = 1,
        PAYLOAD_TYPE_IMPORT_PAYLOAD = 2,
        PAYLOAD_TYPE_FUNCTION_PAYLOAD = 3,
        PAYLOAD_TYPE_TABLE_PAYLOAD = 4,
        PAYLOAD_TYPE_MEMORY_PAYLOAD = 5,
        PAYLOAD_TYPE_GLOBAL_PAYLOAD = 6,
        PAYLOAD_TYPE_EXPORT_PAYLOAD = 7,
        PAYLOAD_TYPE_START_PAYLOAD = 8,
        PAYLOAD_TYPE_ELEMENT_PAYLOAD = 9,
        PAYLOAD_TYPE_CODE_PAYLOAD = 10,
        PAYLOAD_TYPE_DATA_PAYLOAD = 11,
        PAYLOAD_TYPE_DATA_COUNT_PAYLOAD = 12
    };
    static bool _is_defined_payload_type_t(payload_type_t v);

private:
    static const std::set<payload_type_t> _values_payload_type_t;
    static std::set<payload_type_t> _build_values_payload_type_t();

public:

    enum symflag_t {
        SYMFLAG_BINDING_WEAK = 1,
        SYMFLAG_BINDING_LOCAL = 2,
        SYMFLAG_VISIBILITY_HIDDEN = 4,
        SYMFLAG_UNDEFINED = 16,
        SYMFLAG_EXPORTED = 32,
        SYMFLAG_EXPLICIT_NAME = 64,
        SYMFLAG_NO_STRIP = 128
    };
    static bool _is_defined_symflag_t(symflag_t v);

private:
    static const std::set<symflag_t> _values_symflag_t;
    static std::set<symflag_t> _build_values_symflag_t();

public:

    enum symtab_t {
        SYMTAB_FUNCTION = 0,
        SYMTAB_DATA = 1,
        SYMTAB_GLOBAL = 2,
        SYMTAB_SECTION = 3,
        SYMTAB_EVENT = 4,
        SYMTAB_TABLE = 5
    };
    static bool _is_defined_symtab_t(symtab_t v);

private:
    static const std::set<symtab_t> _values_symtab_t;
    static std::set<symtab_t> _build_values_symtab_t();

public:

    enum value_type_t {
        VALUE_TYPE_F64 = 124,
        VALUE_TYPE_F32 = 125,
        VALUE_TYPE_I64 = 126,
        VALUE_TYPE_I32 = 127
    };
    static bool _is_defined_value_type_t(value_type_t v);

private:
    static const std::set<value_type_t> _values_value_type_t;
    static std::set<value_type_t> _build_values_value_type_t();

public:

    webassembly_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, webassembly_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~webassembly_t();

    class code_section_t : public kaitai::kstruct {

    public:

        code_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~code_section_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<function_body_type_t*>* m_bodies;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<function_body_type_t*>* bodies() const { return m_bodies; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class data_count_section_t : public kaitai::kstruct {

    public:

        data_count_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~data_count_section_t();

    private:
        vlq_base128_le_t* m_count;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class data_section_t : public kaitai::kstruct {

    public:

        data_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~data_section_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<data_segment_type_t*>* m_entries;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<data_segment_type_t*>* entries() const { return m_entries; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class data_segment_type_t : public kaitai::kstruct {

    public:

        data_segment_type_t(kaitai::kstream* p__io, webassembly_t::data_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~data_segment_type_t();

    private:
        vlq_base128_le_t* m_type;
        uint8_t m_offset_expr_opcode;
        vlq_base128_le_t* m_offset_expr_arg;
        std::string m_terminator;
        vlq_base128_le_t* m_size;
        std::vector<uint8_t>* m_data;
        webassembly_t* m__root;
        webassembly_t::data_section_t* m__parent;

    public:
        vlq_base128_le_t* type() const { return m_type; }
        uint8_t offset_expr_opcode() const { return m_offset_expr_opcode; }
        vlq_base128_le_t* offset_expr_arg() const { return m_offset_expr_arg; }
        std::string terminator() const { return m_terminator; }
        vlq_base128_le_t* size() const { return m_size; }
        std::vector<uint8_t>* data() const { return m_data; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::data_section_t* _parent() const { return m__parent; }
    };

    class elem_segment_type_t : public kaitai::kstruct {

    public:

        elem_segment_type_t(kaitai::kstream* p__io, webassembly_t::element_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~elem_segment_type_t();

    private:
        vlq_base128_le_t* m_index;
        std::vector<uint8_t>* m_offset;
        vlq_base128_le_t* m_num_elem;
        std::vector<vlq_base128_le_t*>* m_elems;
        webassembly_t* m__root;
        webassembly_t::element_section_t* m__parent;

    public:
        vlq_base128_le_t* index() const { return m_index; }
        std::vector<uint8_t>* offset() const { return m_offset; }
        vlq_base128_le_t* num_elem() const { return m_num_elem; }
        std::vector<vlq_base128_le_t*>* elems() const { return m_elems; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::element_section_t* _parent() const { return m__parent; }
    };

    class element_section_t : public kaitai::kstruct {

    public:

        element_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~element_section_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<elem_segment_type_t*>* m_entries;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<elem_segment_type_t*>* entries() const { return m_entries; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class export_entry_type_t : public kaitai::kstruct {

    public:

        export_entry_type_t(kaitai::kstream* p__io, webassembly_t::export_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~export_entry_type_t();

    private:
        vlq_base128_le_t* m_field_len;
        std::string m_field_str;
        kind_type_t m_kind;
        vlq_base128_le_t* m_index;
        webassembly_t* m__root;
        webassembly_t::export_section_t* m__parent;

    public:
        vlq_base128_le_t* field_len() const { return m_field_len; }
        std::string field_str() const { return m_field_str; }
        kind_type_t kind() const { return m_kind; }
        vlq_base128_le_t* index() const { return m_index; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::export_section_t* _parent() const { return m__parent; }
    };

    class export_section_t : public kaitai::kstruct {

    public:

        export_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~export_section_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<export_entry_type_t*>* m_entries;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<export_entry_type_t*>* entries() const { return m_entries; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class func_type_t : public kaitai::kstruct {

    public:

        func_type_t(kaitai::kstream* p__io, webassembly_t::type_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~func_type_t();

    private:
        constructor_type_t m_form;
        uint8_t m_param_count;
        std::vector<value_type_t>* m_param_types;
        bool n_param_types;

    public:
        bool _is_null_param_types() { param_types(); return n_param_types; };

    private:
        uint8_t m_return_count;
        value_type_t m_return_type;
        bool n_return_type;

    public:
        bool _is_null_return_type() { return_type(); return n_return_type; };

    private:
        webassembly_t* m__root;
        webassembly_t::type_section_t* m__parent;

    public:
        constructor_type_t form() const { return m_form; }
        uint8_t param_count() const { return m_param_count; }
        std::vector<value_type_t>* param_types() const { return m_param_types; }
        uint8_t return_count() const { return m_return_count; }
        value_type_t return_type() const { return m_return_type; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::type_section_t* _parent() const { return m__parent; }
    };

    class function_body_data_type_t : public kaitai::kstruct {

    public:

        function_body_data_type_t(kaitai::kstream* p__io, webassembly_t::function_body_type_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~function_body_data_type_t();

    private:
        vlq_base128_le_t* m_local_count;
        std::vector<local_entry_type_t*>* m_locals;
        std::string m_code;
        webassembly_t* m__root;
        webassembly_t::function_body_type_t* m__parent;

    public:
        vlq_base128_le_t* local_count() const { return m_local_count; }
        std::vector<local_entry_type_t*>* locals() const { return m_locals; }
        std::string code() const { return m_code; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::function_body_type_t* _parent() const { return m__parent; }
    };

    class function_body_type_t : public kaitai::kstruct {

    public:

        function_body_type_t(kaitai::kstream* p__io, webassembly_t::code_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~function_body_type_t();

    private:
        vlq_base128_le_t* m_body_size;
        function_body_data_type_t* m_data;
        webassembly_t* m__root;
        webassembly_t::code_section_t* m__parent;
        std::string m__raw_data;
        kaitai::kstream* m__io__raw_data;

    public:
        vlq_base128_le_t* body_size() const { return m_body_size; }
        function_body_data_type_t* data() const { return m_data; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::code_section_t* _parent() const { return m__parent; }
        std::string _raw_data() const { return m__raw_data; }
        kaitai::kstream* _io__raw_data() const { return m__io__raw_data; }
    };

    class function_section_t : public kaitai::kstruct {

    public:

        function_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~function_section_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<vlq_base128_le_t*>* m_types;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<vlq_base128_le_t*>* types() const { return m_types; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class global_section_t : public kaitai::kstruct {

    public:

        global_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~global_section_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<global_variable_type_t*>* m_globals;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<global_variable_type_t*>* globals() const { return m_globals; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class global_type_t : public kaitai::kstruct {

    public:

        global_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~global_type_t();

    private:
        value_type_t m_content_type;
        mutability_flag_t m_mutability;
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        value_type_t content_type() const { return m_content_type; }
        mutability_flag_t mutability() const { return m_mutability; }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class global_variable_type_t : public kaitai::kstruct {

    public:

        global_variable_type_t(kaitai::kstream* p__io, webassembly_t::global_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~global_variable_type_t();

    private:
        global_type_t* m_type;
        std::vector<uint8_t>* m_init;
        webassembly_t* m__root;
        webassembly_t::global_section_t* m__parent;

    public:
        global_type_t* type() const { return m_type; }
        std::vector<uint8_t>* init() const { return m_init; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::global_section_t* _parent() const { return m__parent; }
    };

    class import_entry_t : public kaitai::kstruct {

    public:

        import_entry_t(kaitai::kstream* p__io, webassembly_t::import_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~import_entry_t();

    private:
        vlq_base128_le_t* m_module_len;
        std::string m_module_str;
        vlq_base128_le_t* m_field_len;
        std::string m_field_str;
        kind_type_t m_kind;
        kaitai::kstruct* m_type;
        bool n_type;

    public:
        bool _is_null_type() { type(); return n_type; };

    private:
        webassembly_t* m__root;
        webassembly_t::import_section_t* m__parent;

    public:
        vlq_base128_le_t* module_len() const { return m_module_len; }
        std::string module_str() const { return m_module_str; }
        vlq_base128_le_t* field_len() const { return m_field_len; }
        std::string field_str() const { return m_field_str; }
        kind_type_t kind() const { return m_kind; }
        kaitai::kstruct* type() const { return m_type; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::import_section_t* _parent() const { return m__parent; }
    };

    class import_section_t : public kaitai::kstruct {

    public:

        import_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~import_section_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<import_entry_t*>* m_entries;
        bool n_entries;

    public:
        bool _is_null_entries() { entries(); return n_entries; };

    private:
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<import_entry_t*>* entries() const { return m_entries; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class linking_custom_subsection_type_t : public kaitai::kstruct {

    public:

        linking_custom_subsection_type_t(kaitai::kstream* p__io, webassembly_t::linking_custom_type_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~linking_custom_subsection_type_t();

    private:
        uint8_t m_type;
        vlq_base128_le_t* m_payload_len;
        symbol_table_type_t* m_symbol_table;
        bool n_symbol_table;

    public:
        bool _is_null_symbol_table() { symbol_table(); return n_symbol_table; };

    private:
        std::vector<uint8_t>* m_payload_data;
        bool n_payload_data;

    public:
        bool _is_null_payload_data() { payload_data(); return n_payload_data; };

    private:
        webassembly_t* m__root;
        webassembly_t::linking_custom_type_t* m__parent;
        std::string m__raw_symbol_table;
        bool n__raw_symbol_table;

    public:
        bool _is_null__raw_symbol_table() { _raw_symbol_table(); return n__raw_symbol_table; };

    private:
        kaitai::kstream* m__io__raw_symbol_table;

    public:
        uint8_t type() const { return m_type; }
        vlq_base128_le_t* payload_len() const { return m_payload_len; }
        symbol_table_type_t* symbol_table() const { return m_symbol_table; }
        std::vector<uint8_t>* payload_data() const { return m_payload_data; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::linking_custom_type_t* _parent() const { return m__parent; }
        std::string _raw_symbol_table() const { return m__raw_symbol_table; }
        kaitai::kstream* _io__raw_symbol_table() const { return m__io__raw_symbol_table; }
    };

    class linking_custom_type_t : public kaitai::kstruct {

    public:

        linking_custom_type_t(kaitai::kstream* p__io, webassembly_t::unimplemented_section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~linking_custom_type_t();

    private:
        vlq_base128_le_t* m_version;
        std::vector<linking_custom_subsection_type_t*>* m_subsections;
        webassembly_t* m__root;
        webassembly_t::unimplemented_section_t* m__parent;

    public:
        vlq_base128_le_t* version() const { return m_version; }
        std::vector<linking_custom_subsection_type_t*>* subsections() const { return m_subsections; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::unimplemented_section_t* _parent() const { return m__parent; }
    };

    class local_entry_type_t : public kaitai::kstruct {

    public:

        local_entry_type_t(kaitai::kstream* p__io, webassembly_t::function_body_data_type_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~local_entry_type_t();

    private:
        vlq_base128_le_t* m_count;
        value_type_t m_type;
        webassembly_t* m__root;
        webassembly_t::function_body_data_type_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        value_type_t type() const { return m_type; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::function_body_data_type_t* _parent() const { return m__parent; }
    };

    class memory_section_t : public kaitai::kstruct {

    public:

        memory_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~memory_section_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<memory_type_t*>* m_entries;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<memory_type_t*>* entries() const { return m_entries; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class memory_type_t : public kaitai::kstruct {

    public:

        memory_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~memory_type_t();

    private:
        resizable_limits_type_t* m_limits;
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        resizable_limits_type_t* limits() const { return m_limits; }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class resizable_limits_type_t : public kaitai::kstruct {

    public:

        resizable_limits_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~resizable_limits_type_t();

    private:
        uint8_t m_flags;
        vlq_base128_le_t* m_initial;
        vlq_base128_le_t* m_maximum;
        bool n_maximum;

    public:
        bool _is_null_maximum() { maximum(); return n_maximum; };

    private:
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint8_t flags() const { return m_flags; }
        vlq_base128_le_t* initial() const { return m_initial; }
        vlq_base128_le_t* maximum() const { return m_maximum; }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class section_t : public kaitai::kstruct {

    public:

        section_t(kaitai::kstream* p__io, webassembly_t::sections_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~section_t();

    private:
        section_header_t* m_header;
        kaitai::kstruct* m_payload_data;
        bool n_payload_data;

    public:
        bool _is_null_payload_data() { payload_data(); return n_payload_data; };

    private:
        webassembly_t* m__root;
        webassembly_t::sections_t* m__parent;

    public:
        section_header_t* header() const { return m_header; }
        kaitai::kstruct* payload_data() const { return m_payload_data; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::sections_t* _parent() const { return m__parent; }
    };

    class section_header_t : public kaitai::kstruct {

    public:

        section_header_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~section_header_t();

    private:
        payload_type_t m_id;
        vlq_base128_le_t* m_payload_len;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        payload_type_t id() const { return m_id; }
        vlq_base128_le_t* payload_len() const { return m_payload_len; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class sections_t : public kaitai::kstruct {

    public:

        sections_t(kaitai::kstream* p__io, webassembly_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sections_t();

    private:
        std::vector<section_t*>* m_sections;
        webassembly_t* m__root;
        webassembly_t* m__parent;

    public:
        std::vector<section_t*>* sections() const { return m_sections; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t* _parent() const { return m__parent; }
    };

    class start_section_t : public kaitai::kstruct {

    public:

        start_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~start_section_t();

    private:
        vlq_base128_le_t* m_index;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* index() const { return m_index; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class symbol_table_type_t : public kaitai::kstruct {

    public:

        symbol_table_type_t(kaitai::kstream* p__io, webassembly_t::linking_custom_subsection_type_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~symbol_table_type_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<syminfo_type_t*>* m_infos;
        webassembly_t* m__root;
        webassembly_t::linking_custom_subsection_type_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<syminfo_type_t*>* infos() const { return m_infos; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::linking_custom_subsection_type_t* _parent() const { return m__parent; }
    };

    class syminfo_data_t : public kaitai::kstruct {

    public:

        syminfo_data_t(kaitai::kstream* p__io, webassembly_t::syminfo_type_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~syminfo_data_t();

    private:
        vlq_base128_le_t* m_name_len;
        std::string m_name_data;
        vlq_base128_le_t* m_index;
        bool n_index;

    public:
        bool _is_null_index() { index(); return n_index; };

    private:
        vlq_base128_le_t* m_offset;
        bool n_offset;

    public:
        bool _is_null_offset() { offset(); return n_offset; };

    private:
        vlq_base128_le_t* m_size;
        bool n_size;

    public:
        bool _is_null_size() { size(); return n_size; };

    private:
        webassembly_t* m__root;
        webassembly_t::syminfo_type_t* m__parent;

    public:
        vlq_base128_le_t* name_len() const { return m_name_len; }
        std::string name_data() const { return m_name_data; }
        vlq_base128_le_t* index() const { return m_index; }
        vlq_base128_le_t* offset() const { return m_offset; }
        vlq_base128_le_t* size() const { return m_size; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::syminfo_type_t* _parent() const { return m__parent; }
    };

    class syminfo_ext_t : public kaitai::kstruct {

    public:

        syminfo_ext_t(kaitai::kstream* p__io, webassembly_t::syminfo_type_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~syminfo_ext_t();

    private:
        vlq_base128_le_t* m_index;
        vlq_base128_le_t* m_name_len;
        bool n_name_len;

    public:
        bool _is_null_name_len() { name_len(); return n_name_len; };

    private:
        std::string m_name_data;
        bool n_name_data;

    public:
        bool _is_null_name_data() { name_data(); return n_name_data; };

    private:
        webassembly_t* m__root;
        webassembly_t::syminfo_type_t* m__parent;

    public:
        vlq_base128_le_t* index() const { return m_index; }
        vlq_base128_le_t* name_len() const { return m_name_len; }
        std::string name_data() const { return m_name_data; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::syminfo_type_t* _parent() const { return m__parent; }
    };

    class syminfo_section_t : public kaitai::kstruct {

    public:

        syminfo_section_t(kaitai::kstream* p__io, webassembly_t::syminfo_type_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~syminfo_section_t();

    private:
        vlq_base128_le_t* m_section;
        webassembly_t* m__root;
        webassembly_t::syminfo_type_t* m__parent;

    public:
        vlq_base128_le_t* section() const { return m_section; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::syminfo_type_t* _parent() const { return m__parent; }
    };

    class syminfo_type_t : public kaitai::kstruct {

    public:

        syminfo_type_t(kaitai::kstream* p__io, webassembly_t::symbol_table_type_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~syminfo_type_t();

    private:
        symtab_t m_kind;
        vlq_base128_le_t* m_flags;
        syminfo_data_t* m_data;
        bool n_data;

    public:
        bool _is_null_data() { data(); return n_data; };

    private:
        syminfo_ext_t* m_ext;
        bool n_ext;

    public:
        bool _is_null_ext() { ext(); return n_ext; };

    private:
        syminfo_section_t* m_section;
        bool n_section;

    public:
        bool _is_null_section() { section(); return n_section; };

    private:
        webassembly_t* m__root;
        webassembly_t::symbol_table_type_t* m__parent;

    public:
        symtab_t kind() const { return m_kind; }
        vlq_base128_le_t* flags() const { return m_flags; }
        syminfo_data_t* data() const { return m_data; }
        syminfo_ext_t* ext() const { return m_ext; }
        syminfo_section_t* section() const { return m_section; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::symbol_table_type_t* _parent() const { return m__parent; }
    };

    class table_section_t : public kaitai::kstruct {

    public:

        table_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~table_section_t();

    private:
        vlq_base128_le_t* m_count;
        std::vector<table_type_t*>* m_entries;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* count() const { return m_count; }
        std::vector<table_type_t*>* entries() const { return m_entries; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class table_type_t : public kaitai::kstruct {

    public:

        table_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~table_type_t();

    private:
        elem_type_t m_element_type;
        resizable_limits_type_t* m_limits;
        webassembly_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        elem_type_t element_type() const { return m_element_type; }
        resizable_limits_type_t* limits() const { return m_limits; }
        webassembly_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class type_section_t : public kaitai::kstruct {

    public:

        type_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~type_section_t();

    private:
        uint8_t m_count;
        std::vector<func_type_t*>* m_entries;
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        uint8_t count() const { return m_count; }
        std::vector<func_type_t*>* entries() const { return m_entries; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

    class unimplemented_section_t : public kaitai::kstruct {

    public:

        unimplemented_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent = 0, webassembly_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~unimplemented_section_t();

    private:
        vlq_base128_le_t* m_name_len;
        std::string m_name;
        std::vector<linking_custom_type_t*>* m_linking;
        bool n_linking;

    public:
        bool _is_null_linking() { linking(); return n_linking; };

    private:
        std::vector<uint8_t>* m_raw;
        bool n_raw;

    public:
        bool _is_null_raw() { raw(); return n_raw; };

    private:
        webassembly_t* m__root;
        webassembly_t::section_t* m__parent;

    public:
        vlq_base128_le_t* name_len() const { return m_name_len; }
        std::string name() const { return m_name; }
        std::vector<linking_custom_type_t*>* linking() const { return m_linking; }
        std::vector<uint8_t>* raw() const { return m_raw; }
        webassembly_t* _root() const { return m__root; }
        webassembly_t::section_t* _parent() const { return m__parent; }
    };

private:
    std::string m_magic;
    uint32_t m_version;
    sections_t* m_sections;
    webassembly_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::string magic() const { return m_magic; }
    uint32_t version() const { return m_version; }
    sections_t* sections() const { return m_sections; }
    webassembly_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // WEBASSEMBLY_H_
