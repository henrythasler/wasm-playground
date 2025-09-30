// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "webassembly.h"
#include "kaitai/exceptions.h"
std::set<webassembly_t::constructor_type_t> webassembly_t::_build_values_constructor_type_t() {
    std::set<webassembly_t::constructor_type_t> _t;
    _t.insert(webassembly_t::CONSTRUCTOR_TYPE_EMPTY_BLOCK);
    _t.insert(webassembly_t::CONSTRUCTOR_TYPE_FUNC);
    _t.insert(webassembly_t::CONSTRUCTOR_TYPE_ANYFUNC);
    _t.insert(webassembly_t::CONSTRUCTOR_TYPE_F64);
    _t.insert(webassembly_t::CONSTRUCTOR_TYPE_F32);
    _t.insert(webassembly_t::CONSTRUCTOR_TYPE_I64);
    _t.insert(webassembly_t::CONSTRUCTOR_TYPE_I32);
    return _t;
}
const std::set<webassembly_t::constructor_type_t> webassembly_t::_values_constructor_type_t = webassembly_t::_build_values_constructor_type_t();
bool webassembly_t::_is_defined_constructor_type_t(webassembly_t::constructor_type_t v) {
    return webassembly_t::_values_constructor_type_t.find(v) != webassembly_t::_values_constructor_type_t.end();
}
std::set<webassembly_t::elem_type_t> webassembly_t::_build_values_elem_type_t() {
    std::set<webassembly_t::elem_type_t> _t;
    _t.insert(webassembly_t::ELEM_TYPE_ANYFUNC);
    return _t;
}
const std::set<webassembly_t::elem_type_t> webassembly_t::_values_elem_type_t = webassembly_t::_build_values_elem_type_t();
bool webassembly_t::_is_defined_elem_type_t(webassembly_t::elem_type_t v) {
    return webassembly_t::_values_elem_type_t.find(v) != webassembly_t::_values_elem_type_t.end();
}
std::set<webassembly_t::kind_type_t> webassembly_t::_build_values_kind_type_t() {
    std::set<webassembly_t::kind_type_t> _t;
    _t.insert(webassembly_t::KIND_TYPE_FUNCTION_KIND);
    _t.insert(webassembly_t::KIND_TYPE_TABLE_KIND);
    _t.insert(webassembly_t::KIND_TYPE_MEMORY_KIND);
    _t.insert(webassembly_t::KIND_TYPE_GLOBAL_KIND);
    return _t;
}
const std::set<webassembly_t::kind_type_t> webassembly_t::_values_kind_type_t = webassembly_t::_build_values_kind_type_t();
bool webassembly_t::_is_defined_kind_type_t(webassembly_t::kind_type_t v) {
    return webassembly_t::_values_kind_type_t.find(v) != webassembly_t::_values_kind_type_t.end();
}
std::set<webassembly_t::linking_metadata_payload_type_t> webassembly_t::_build_values_linking_metadata_payload_type_t() {
    std::set<webassembly_t::linking_metadata_payload_type_t> _t;
    _t.insert(webassembly_t::LINKING_METADATA_PAYLOAD_TYPE_SEGMENT_INFO);
    _t.insert(webassembly_t::LINKING_METADATA_PAYLOAD_TYPE_INIT_FUNCS);
    _t.insert(webassembly_t::LINKING_METADATA_PAYLOAD_TYPE_COMDAT_INFO);
    _t.insert(webassembly_t::LINKING_METADATA_PAYLOAD_TYPE_SYMBOL_TABLE);
    return _t;
}
const std::set<webassembly_t::linking_metadata_payload_type_t> webassembly_t::_values_linking_metadata_payload_type_t = webassembly_t::_build_values_linking_metadata_payload_type_t();
bool webassembly_t::_is_defined_linking_metadata_payload_type_t(webassembly_t::linking_metadata_payload_type_t v) {
    return webassembly_t::_values_linking_metadata_payload_type_t.find(v) != webassembly_t::_values_linking_metadata_payload_type_t.end();
}
std::set<webassembly_t::mutability_flag_t> webassembly_t::_build_values_mutability_flag_t() {
    std::set<webassembly_t::mutability_flag_t> _t;
    _t.insert(webassembly_t::MUTABILITY_FLAG_IMMUTABLE);
    _t.insert(webassembly_t::MUTABILITY_FLAG_MUTABLE);
    return _t;
}
const std::set<webassembly_t::mutability_flag_t> webassembly_t::_values_mutability_flag_t = webassembly_t::_build_values_mutability_flag_t();
bool webassembly_t::_is_defined_mutability_flag_t(webassembly_t::mutability_flag_t v) {
    return webassembly_t::_values_mutability_flag_t.find(v) != webassembly_t::_values_mutability_flag_t.end();
}
std::set<webassembly_t::payload_type_t> webassembly_t::_build_values_payload_type_t() {
    std::set<webassembly_t::payload_type_t> _t;
    _t.insert(webassembly_t::PAYLOAD_TYPE_CUSTOM_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_TYPE_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_IMPORT_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_FUNCTION_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_TABLE_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_MEMORY_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_GLOBAL_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_EXPORT_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_START_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_ELEMENT_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_CODE_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_DATA_PAYLOAD);
    _t.insert(webassembly_t::PAYLOAD_TYPE_DATA_COUNT_PAYLOAD);
    return _t;
}
const std::set<webassembly_t::payload_type_t> webassembly_t::_values_payload_type_t = webassembly_t::_build_values_payload_type_t();
bool webassembly_t::_is_defined_payload_type_t(webassembly_t::payload_type_t v) {
    return webassembly_t::_values_payload_type_t.find(v) != webassembly_t::_values_payload_type_t.end();
}
std::set<webassembly_t::symflag_t> webassembly_t::_build_values_symflag_t() {
    std::set<webassembly_t::symflag_t> _t;
    _t.insert(webassembly_t::SYMFLAG_BINDING_WEAK);
    _t.insert(webassembly_t::SYMFLAG_BINDING_LOCAL);
    _t.insert(webassembly_t::SYMFLAG_VISIBILITY_HIDDEN);
    _t.insert(webassembly_t::SYMFLAG_UNDEFINED);
    _t.insert(webassembly_t::SYMFLAG_EXPORTED);
    _t.insert(webassembly_t::SYMFLAG_EXPLICIT_NAME);
    _t.insert(webassembly_t::SYMFLAG_NO_STRIP);
    return _t;
}
const std::set<webassembly_t::symflag_t> webassembly_t::_values_symflag_t = webassembly_t::_build_values_symflag_t();
bool webassembly_t::_is_defined_symflag_t(webassembly_t::symflag_t v) {
    return webassembly_t::_values_symflag_t.find(v) != webassembly_t::_values_symflag_t.end();
}
std::set<webassembly_t::symtab_t> webassembly_t::_build_values_symtab_t() {
    std::set<webassembly_t::symtab_t> _t;
    _t.insert(webassembly_t::SYMTAB_FUNCTION);
    _t.insert(webassembly_t::SYMTAB_DATA);
    _t.insert(webassembly_t::SYMTAB_GLOBAL);
    _t.insert(webassembly_t::SYMTAB_SECTION);
    _t.insert(webassembly_t::SYMTAB_EVENT);
    _t.insert(webassembly_t::SYMTAB_TABLE);
    return _t;
}
const std::set<webassembly_t::symtab_t> webassembly_t::_values_symtab_t = webassembly_t::_build_values_symtab_t();
bool webassembly_t::_is_defined_symtab_t(webassembly_t::symtab_t v) {
    return webassembly_t::_values_symtab_t.find(v) != webassembly_t::_values_symtab_t.end();
}
std::set<webassembly_t::value_type_t> webassembly_t::_build_values_value_type_t() {
    std::set<webassembly_t::value_type_t> _t;
    _t.insert(webassembly_t::VALUE_TYPE_F64);
    _t.insert(webassembly_t::VALUE_TYPE_F32);
    _t.insert(webassembly_t::VALUE_TYPE_I64);
    _t.insert(webassembly_t::VALUE_TYPE_I32);
    return _t;
}
const std::set<webassembly_t::value_type_t> webassembly_t::_values_value_type_t = webassembly_t::_build_values_value_type_t();
bool webassembly_t::_is_defined_value_type_t(webassembly_t::value_type_t v) {
    return webassembly_t::_values_value_type_t.find(v) != webassembly_t::_values_value_type_t.end();
}

webassembly_t::webassembly_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root ? p__root : this;
    m_sections = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::_read() {
    m_magic = m__io->read_bytes(4);
    if (!(m_magic == std::string("\x00\x61\x73\x6D", 4))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x00\x61\x73\x6D", 4), m_magic, m__io, std::string("/seq/0"));
    }
    m_version = m__io->read_u4le();
    m_sections = new sections_t(m__io, this, m__root);
}

webassembly_t::~webassembly_t() {
    _clean_up();
}

void webassembly_t::_clean_up() {
    if (m_sections) {
        delete m_sections; m_sections = 0;
    }
}

webassembly_t::code_section_t::code_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_bodies = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::code_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_bodies = new std::vector<function_body_type_t*>();
    const int l_bodies = count()->value();
    for (int i = 0; i < l_bodies; i++) {
        m_bodies->push_back(new function_body_type_t(m__io, this, m__root));
    }
}

webassembly_t::code_section_t::~code_section_t() {
    _clean_up();
}

void webassembly_t::code_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (m_bodies) {
        for (std::vector<function_body_type_t*>::iterator it = m_bodies->begin(); it != m_bodies->end(); ++it) {
            delete *it;
        }
        delete m_bodies; m_bodies = 0;
    }
}

webassembly_t::data_count_section_t::data_count_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::data_count_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
}

webassembly_t::data_count_section_t::~data_count_section_t() {
    _clean_up();
}

void webassembly_t::data_count_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
}

webassembly_t::data_section_t::data_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_entries = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::data_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_entries = new std::vector<data_segment_type_t*>();
    const int l_entries = count()->value();
    for (int i = 0; i < l_entries; i++) {
        m_entries->push_back(new data_segment_type_t(m__io, this, m__root));
    }
}

webassembly_t::data_section_t::~data_section_t() {
    _clean_up();
}

void webassembly_t::data_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (m_entries) {
        for (std::vector<data_segment_type_t*>::iterator it = m_entries->begin(); it != m_entries->end(); ++it) {
            delete *it;
        }
        delete m_entries; m_entries = 0;
    }
}

webassembly_t::data_segment_type_t::data_segment_type_t(kaitai::kstream* p__io, webassembly_t::data_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_type = 0;
    m_offset_expr_arg = 0;
    m_size = 0;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::data_segment_type_t::_read() {
    m_type = new vlq_base128_le_t(m__io);
    m_offset_expr_opcode = m__io->read_u1();
    m_offset_expr_arg = new vlq_base128_le_t(m__io);
    m_terminator = m__io->read_bytes(1);
    if (!(m_terminator == std::string("\x0B", 1))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x0B", 1), m_terminator, m__io, std::string("/types/data_segment_type/seq/3"));
    }
    m_size = new vlq_base128_le_t(m__io);
    m_data = new std::vector<uint8_t>();
    const int l_data = size()->value();
    for (int i = 0; i < l_data; i++) {
        m_data->push_back(m__io->read_u1());
    }
}

webassembly_t::data_segment_type_t::~data_segment_type_t() {
    _clean_up();
}

void webassembly_t::data_segment_type_t::_clean_up() {
    if (m_type) {
        delete m_type; m_type = 0;
    }
    if (m_offset_expr_arg) {
        delete m_offset_expr_arg; m_offset_expr_arg = 0;
    }
    if (m_size) {
        delete m_size; m_size = 0;
    }
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

webassembly_t::elem_segment_type_t::elem_segment_type_t(kaitai::kstream* p__io, webassembly_t::element_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = 0;
    m_offset = 0;
    m_num_elem = 0;
    m_elems = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::elem_segment_type_t::_read() {
    m_index = new vlq_base128_le_t(m__io);
    m_offset = new std::vector<uint8_t>();
    {
        int i = 0;
        uint8_t _;
        do {
            _ = m__io->read_u1();
            m_offset->push_back(_);
            i++;
        } while (!(_ == 11));
    }
    m_num_elem = new vlq_base128_le_t(m__io);
    m_elems = new std::vector<vlq_base128_le_t*>();
    const int l_elems = num_elem()->value();
    for (int i = 0; i < l_elems; i++) {
        m_elems->push_back(new vlq_base128_le_t(m__io));
    }
}

webassembly_t::elem_segment_type_t::~elem_segment_type_t() {
    _clean_up();
}

void webassembly_t::elem_segment_type_t::_clean_up() {
    if (m_index) {
        delete m_index; m_index = 0;
    }
    if (m_offset) {
        delete m_offset; m_offset = 0;
    }
    if (m_num_elem) {
        delete m_num_elem; m_num_elem = 0;
    }
    if (m_elems) {
        for (std::vector<vlq_base128_le_t*>::iterator it = m_elems->begin(); it != m_elems->end(); ++it) {
            delete *it;
        }
        delete m_elems; m_elems = 0;
    }
}

webassembly_t::element_section_t::element_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_entries = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::element_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_entries = new std::vector<elem_segment_type_t*>();
    const int l_entries = count()->value();
    for (int i = 0; i < l_entries; i++) {
        m_entries->push_back(new elem_segment_type_t(m__io, this, m__root));
    }
}

webassembly_t::element_section_t::~element_section_t() {
    _clean_up();
}

void webassembly_t::element_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (m_entries) {
        for (std::vector<elem_segment_type_t*>::iterator it = m_entries->begin(); it != m_entries->end(); ++it) {
            delete *it;
        }
        delete m_entries; m_entries = 0;
    }
}

webassembly_t::export_entry_type_t::export_entry_type_t(kaitai::kstream* p__io, webassembly_t::export_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_field_len = 0;
    m_index = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::export_entry_type_t::_read() {
    m_field_len = new vlq_base128_le_t(m__io);
    m_field_str = kaitai::kstream::bytes_to_str(m__io->read_bytes(field_len()->value()), "UTF-8");
    m_kind = static_cast<webassembly_t::kind_type_t>(m__io->read_u1());
    m_index = new vlq_base128_le_t(m__io);
}

webassembly_t::export_entry_type_t::~export_entry_type_t() {
    _clean_up();
}

void webassembly_t::export_entry_type_t::_clean_up() {
    if (m_field_len) {
        delete m_field_len; m_field_len = 0;
    }
    if (m_index) {
        delete m_index; m_index = 0;
    }
}

webassembly_t::export_section_t::export_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_entries = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::export_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_entries = new std::vector<export_entry_type_t*>();
    const int l_entries = count()->value();
    for (int i = 0; i < l_entries; i++) {
        m_entries->push_back(new export_entry_type_t(m__io, this, m__root));
    }
}

webassembly_t::export_section_t::~export_section_t() {
    _clean_up();
}

void webassembly_t::export_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (m_entries) {
        for (std::vector<export_entry_type_t*>::iterator it = m_entries->begin(); it != m_entries->end(); ++it) {
            delete *it;
        }
        delete m_entries; m_entries = 0;
    }
}

webassembly_t::func_type_t::func_type_t(kaitai::kstream* p__io, webassembly_t::type_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_param_types = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::func_type_t::_read() {
    m_form = static_cast<webassembly_t::constructor_type_t>(m__io->read_u1());
    m_param_count = m__io->read_u1();
    n_param_types = true;
    if (param_count() > 0) {
        n_param_types = false;
        m_param_types = new std::vector<value_type_t>();
        const int l_param_types = param_count();
        for (int i = 0; i < l_param_types; i++) {
            m_param_types->push_back(static_cast<webassembly_t::value_type_t>(m__io->read_u1()));
        }
    }
    m_return_count = m__io->read_u1();
    n_return_type = true;
    if (return_count() == 1) {
        n_return_type = false;
        m_return_type = static_cast<webassembly_t::value_type_t>(m__io->read_u1());
    }
}

webassembly_t::func_type_t::~func_type_t() {
    _clean_up();
}

void webassembly_t::func_type_t::_clean_up() {
    if (!n_param_types) {
        if (m_param_types) {
            delete m_param_types; m_param_types = 0;
        }
    }
    if (!n_return_type) {
    }
}

webassembly_t::function_body_data_type_t::function_body_data_type_t(kaitai::kstream* p__io, webassembly_t::function_body_type_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_local_count = 0;
    m_locals = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::function_body_data_type_t::_read() {
    m_local_count = new vlq_base128_le_t(m__io);
    m_locals = new std::vector<local_entry_type_t*>();
    const int l_locals = local_count()->value();
    for (int i = 0; i < l_locals; i++) {
        m_locals->push_back(new local_entry_type_t(m__io, this, m__root));
    }
    m_code = m__io->read_bytes_full();
}

webassembly_t::function_body_data_type_t::~function_body_data_type_t() {
    _clean_up();
}

void webassembly_t::function_body_data_type_t::_clean_up() {
    if (m_local_count) {
        delete m_local_count; m_local_count = 0;
    }
    if (m_locals) {
        for (std::vector<local_entry_type_t*>::iterator it = m_locals->begin(); it != m_locals->end(); ++it) {
            delete *it;
        }
        delete m_locals; m_locals = 0;
    }
}

webassembly_t::function_body_type_t::function_body_type_t(kaitai::kstream* p__io, webassembly_t::code_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_body_size = 0;
    m_data = 0;
    m__io__raw_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::function_body_type_t::_read() {
    m_body_size = new vlq_base128_le_t(m__io);
    m__raw_data = m__io->read_bytes(body_size()->value());
    m__io__raw_data = new kaitai::kstream(m__raw_data);
    m_data = new function_body_data_type_t(m__io__raw_data, this, m__root);
}

webassembly_t::function_body_type_t::~function_body_type_t() {
    _clean_up();
}

void webassembly_t::function_body_type_t::_clean_up() {
    if (m_body_size) {
        delete m_body_size; m_body_size = 0;
    }
    if (m__io__raw_data) {
        delete m__io__raw_data; m__io__raw_data = 0;
    }
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

webassembly_t::function_section_t::function_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_types = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::function_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_types = new std::vector<vlq_base128_le_t*>();
    const int l_types = count()->value();
    for (int i = 0; i < l_types; i++) {
        m_types->push_back(new vlq_base128_le_t(m__io));
    }
}

webassembly_t::function_section_t::~function_section_t() {
    _clean_up();
}

void webassembly_t::function_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (m_types) {
        for (std::vector<vlq_base128_le_t*>::iterator it = m_types->begin(); it != m_types->end(); ++it) {
            delete *it;
        }
        delete m_types; m_types = 0;
    }
}

webassembly_t::global_section_t::global_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_globals = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::global_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_globals = new std::vector<global_variable_type_t*>();
    const int l_globals = count()->value();
    for (int i = 0; i < l_globals; i++) {
        m_globals->push_back(new global_variable_type_t(m__io, this, m__root));
    }
}

webassembly_t::global_section_t::~global_section_t() {
    _clean_up();
}

void webassembly_t::global_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (m_globals) {
        for (std::vector<global_variable_type_t*>::iterator it = m_globals->begin(); it != m_globals->end(); ++it) {
            delete *it;
        }
        delete m_globals; m_globals = 0;
    }
}

webassembly_t::global_type_t::global_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::global_type_t::_read() {
    m_content_type = static_cast<webassembly_t::value_type_t>(m__io->read_u1());
    m_mutability = static_cast<webassembly_t::mutability_flag_t>(m__io->read_u1());
}

webassembly_t::global_type_t::~global_type_t() {
    _clean_up();
}

void webassembly_t::global_type_t::_clean_up() {
}

webassembly_t::global_variable_type_t::global_variable_type_t(kaitai::kstream* p__io, webassembly_t::global_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_type = 0;
    m_init = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::global_variable_type_t::_read() {
    m_type = new global_type_t(m__io, this, m__root);
    m_init = new std::vector<uint8_t>();
    {
        int i = 0;
        uint8_t _;
        do {
            _ = m__io->read_u1();
            m_init->push_back(_);
            i++;
        } while (!(_ == 11));
    }
}

webassembly_t::global_variable_type_t::~global_variable_type_t() {
    _clean_up();
}

void webassembly_t::global_variable_type_t::_clean_up() {
    if (m_type) {
        delete m_type; m_type = 0;
    }
    if (m_init) {
        delete m_init; m_init = 0;
    }
}

webassembly_t::import_entry_t::import_entry_t(kaitai::kstream* p__io, webassembly_t::import_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_module_len = 0;
    m_field_len = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::import_entry_t::_read() {
    m_module_len = new vlq_base128_le_t(m__io);
    m_module_str = kaitai::kstream::bytes_to_str(m__io->read_bytes(module_len()->value()), "UTF-8");
    m_field_len = new vlq_base128_le_t(m__io);
    m_field_str = kaitai::kstream::bytes_to_str(m__io->read_bytes(field_len()->value()), "UTF-8");
    m_kind = static_cast<webassembly_t::kind_type_t>(m__io->read_u1());
    n_type = true;
    switch (kind()) {
    case webassembly_t::KIND_TYPE_FUNCTION_KIND: {
        n_type = false;
        m_type = new vlq_base128_le_t(m__io);
        break;
    }
    case webassembly_t::KIND_TYPE_GLOBAL_KIND: {
        n_type = false;
        m_type = new global_type_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::KIND_TYPE_MEMORY_KIND: {
        n_type = false;
        m_type = new memory_type_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::KIND_TYPE_TABLE_KIND: {
        n_type = false;
        m_type = new table_type_t(m__io, this, m__root);
        break;
    }
    }
}

webassembly_t::import_entry_t::~import_entry_t() {
    _clean_up();
}

void webassembly_t::import_entry_t::_clean_up() {
    if (m_module_len) {
        delete m_module_len; m_module_len = 0;
    }
    if (m_field_len) {
        delete m_field_len; m_field_len = 0;
    }
    if (!n_type) {
        if (m_type) {
            delete m_type; m_type = 0;
        }
    }
}

webassembly_t::import_section_t::import_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_entries = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::import_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    n_entries = true;
    if (count()->value() > 0) {
        n_entries = false;
        m_entries = new std::vector<import_entry_t*>();
        const int l_entries = count()->value();
        for (int i = 0; i < l_entries; i++) {
            m_entries->push_back(new import_entry_t(m__io, this, m__root));
        }
    }
}

webassembly_t::import_section_t::~import_section_t() {
    _clean_up();
}

void webassembly_t::import_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (!n_entries) {
        if (m_entries) {
            for (std::vector<import_entry_t*>::iterator it = m_entries->begin(); it != m_entries->end(); ++it) {
                delete *it;
            }
            delete m_entries; m_entries = 0;
        }
    }
}

webassembly_t::linking_custom_subsection_type_t::linking_custom_subsection_type_t(kaitai::kstream* p__io, webassembly_t::linking_custom_type_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_payload_len = 0;
    m_symbol_table = 0;
    m__io__raw_symbol_table = 0;
    m_payload_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::linking_custom_subsection_type_t::_read() {
    m_type = m__io->read_u1();
    m_payload_len = new vlq_base128_le_t(m__io);
    n_symbol_table = true;
    if (type() == webassembly_t::LINKING_METADATA_PAYLOAD_TYPE_SYMBOL_TABLE) {
        n_symbol_table = false;
        m__raw_symbol_table = m__io->read_bytes(payload_len()->value());
        m__io__raw_symbol_table = new kaitai::kstream(m__raw_symbol_table);
        m_symbol_table = new symbol_table_type_t(m__io__raw_symbol_table, this, m__root);
    }
    n_payload_data = true;
    if (type() != webassembly_t::LINKING_METADATA_PAYLOAD_TYPE_SYMBOL_TABLE) {
        n_payload_data = false;
        m_payload_data = new std::vector<uint8_t>();
        const int l_payload_data = payload_len()->value();
        for (int i = 0; i < l_payload_data; i++) {
            m_payload_data->push_back(m__io->read_u1());
        }
    }
}

webassembly_t::linking_custom_subsection_type_t::~linking_custom_subsection_type_t() {
    _clean_up();
}

void webassembly_t::linking_custom_subsection_type_t::_clean_up() {
    if (m_payload_len) {
        delete m_payload_len; m_payload_len = 0;
    }
    if (!n_symbol_table) {
        if (m__io__raw_symbol_table) {
            delete m__io__raw_symbol_table; m__io__raw_symbol_table = 0;
        }
        if (m_symbol_table) {
            delete m_symbol_table; m_symbol_table = 0;
        }
    }
    if (!n_payload_data) {
        if (m_payload_data) {
            delete m_payload_data; m_payload_data = 0;
        }
    }
}

webassembly_t::linking_custom_type_t::linking_custom_type_t(kaitai::kstream* p__io, webassembly_t::unimplemented_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_version = 0;
    m_subsections = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::linking_custom_type_t::_read() {
    m_version = new vlq_base128_le_t(m__io);
    m_subsections = new std::vector<linking_custom_subsection_type_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_subsections->push_back(new linking_custom_subsection_type_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::linking_custom_type_t::~linking_custom_type_t() {
    _clean_up();
}

void webassembly_t::linking_custom_type_t::_clean_up() {
    if (m_version) {
        delete m_version; m_version = 0;
    }
    if (m_subsections) {
        for (std::vector<linking_custom_subsection_type_t*>::iterator it = m_subsections->begin(); it != m_subsections->end(); ++it) {
            delete *it;
        }
        delete m_subsections; m_subsections = 0;
    }
}

webassembly_t::local_entry_type_t::local_entry_type_t(kaitai::kstream* p__io, webassembly_t::function_body_data_type_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::local_entry_type_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_type = static_cast<webassembly_t::value_type_t>(m__io->read_u1());
}

webassembly_t::local_entry_type_t::~local_entry_type_t() {
    _clean_up();
}

void webassembly_t::local_entry_type_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
}

webassembly_t::memory_section_t::memory_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_entries = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::memory_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_entries = new std::vector<memory_type_t*>();
    const int l_entries = count()->value();
    for (int i = 0; i < l_entries; i++) {
        m_entries->push_back(new memory_type_t(m__io, this, m__root));
    }
}

webassembly_t::memory_section_t::~memory_section_t() {
    _clean_up();
}

void webassembly_t::memory_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (m_entries) {
        for (std::vector<memory_type_t*>::iterator it = m_entries->begin(); it != m_entries->end(); ++it) {
            delete *it;
        }
        delete m_entries; m_entries = 0;
    }
}

webassembly_t::memory_type_t::memory_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_limits = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::memory_type_t::_read() {
    m_limits = new resizable_limits_type_t(m__io, this, m__root);
}

webassembly_t::memory_type_t::~memory_type_t() {
    _clean_up();
}

void webassembly_t::memory_type_t::_clean_up() {
    if (m_limits) {
        delete m_limits; m_limits = 0;
    }
}

webassembly_t::resizable_limits_type_t::resizable_limits_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_initial = 0;
    m_maximum = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::resizable_limits_type_t::_read() {
    m_flags = m__io->read_u1();
    m_initial = new vlq_base128_le_t(m__io);
    n_maximum = true;
    if (flags() == 1) {
        n_maximum = false;
        m_maximum = new vlq_base128_le_t(m__io);
    }
}

webassembly_t::resizable_limits_type_t::~resizable_limits_type_t() {
    _clean_up();
}

void webassembly_t::resizable_limits_type_t::_clean_up() {
    if (m_initial) {
        delete m_initial; m_initial = 0;
    }
    if (!n_maximum) {
        if (m_maximum) {
            delete m_maximum; m_maximum = 0;
        }
    }
}

webassembly_t::section_t::section_t(kaitai::kstream* p__io, webassembly_t::sections_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_header = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::section_t::_read() {
    m_header = new section_header_t(m__io, this, m__root);
    n_payload_data = true;
    switch (header()->id()) {
    case webassembly_t::PAYLOAD_TYPE_CODE_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new code_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_CUSTOM_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new unimplemented_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_DATA_COUNT_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new data_count_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_DATA_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new data_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_ELEMENT_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new element_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_EXPORT_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new export_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_FUNCTION_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new function_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_GLOBAL_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new global_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_IMPORT_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new import_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_MEMORY_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new memory_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_START_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new start_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_TABLE_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new table_section_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::PAYLOAD_TYPE_TYPE_PAYLOAD: {
        n_payload_data = false;
        m_payload_data = new type_section_t(m__io, this, m__root);
        break;
    }
    }
}

webassembly_t::section_t::~section_t() {
    _clean_up();
}

void webassembly_t::section_t::_clean_up() {
    if (m_header) {
        delete m_header; m_header = 0;
    }
    if (!n_payload_data) {
        if (m_payload_data) {
            delete m_payload_data; m_payload_data = 0;
        }
    }
}

webassembly_t::section_header_t::section_header_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_payload_len = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::section_header_t::_read() {
    m_id = static_cast<webassembly_t::payload_type_t>(m__io->read_u1());
    m_payload_len = new vlq_base128_le_t(m__io);
}

webassembly_t::section_header_t::~section_header_t() {
    _clean_up();
}

void webassembly_t::section_header_t::_clean_up() {
    if (m_payload_len) {
        delete m_payload_len; m_payload_len = 0;
    }
}

webassembly_t::sections_t::sections_t(kaitai::kstream* p__io, webassembly_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_sections = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::sections_t::_read() {
    m_sections = new std::vector<section_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_sections->push_back(new section_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::sections_t::~sections_t() {
    _clean_up();
}

void webassembly_t::sections_t::_clean_up() {
    if (m_sections) {
        for (std::vector<section_t*>::iterator it = m_sections->begin(); it != m_sections->end(); ++it) {
            delete *it;
        }
        delete m_sections; m_sections = 0;
    }
}

webassembly_t::start_section_t::start_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::start_section_t::_read() {
    m_index = new vlq_base128_le_t(m__io);
}

webassembly_t::start_section_t::~start_section_t() {
    _clean_up();
}

void webassembly_t::start_section_t::_clean_up() {
    if (m_index) {
        delete m_index; m_index = 0;
    }
}

webassembly_t::symbol_table_type_t::symbol_table_type_t(kaitai::kstream* p__io, webassembly_t::linking_custom_subsection_type_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_infos = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::symbol_table_type_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_infos = new std::vector<syminfo_type_t*>();
    const int l_infos = count()->value();
    for (int i = 0; i < l_infos; i++) {
        m_infos->push_back(new syminfo_type_t(m__io, this, m__root));
    }
}

webassembly_t::symbol_table_type_t::~symbol_table_type_t() {
    _clean_up();
}

void webassembly_t::symbol_table_type_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (m_infos) {
        for (std::vector<syminfo_type_t*>::iterator it = m_infos->begin(); it != m_infos->end(); ++it) {
            delete *it;
        }
        delete m_infos; m_infos = 0;
    }
}

webassembly_t::syminfo_data_t::syminfo_data_t(kaitai::kstream* p__io, webassembly_t::syminfo_type_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name_len = 0;
    m_index = 0;
    m_offset = 0;
    m_size = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::syminfo_data_t::_read() {
    m_name_len = new vlq_base128_le_t(m__io);
    m_name_data = kaitai::kstream::bytes_to_str(m__io->read_bytes(name_len()->value()), "UTF-8");
    n_index = true;
    if ((_parent()->flags()->value() & webassembly_t::SYMFLAG_UNDEFINED) == 0) {
        n_index = false;
        m_index = new vlq_base128_le_t(m__io);
    }
    n_offset = true;
    if ((_parent()->flags()->value() & webassembly_t::SYMFLAG_UNDEFINED) == 0) {
        n_offset = false;
        m_offset = new vlq_base128_le_t(m__io);
    }
    n_size = true;
    if ((_parent()->flags()->value() & webassembly_t::SYMFLAG_UNDEFINED) == 0) {
        n_size = false;
        m_size = new vlq_base128_le_t(m__io);
    }
}

webassembly_t::syminfo_data_t::~syminfo_data_t() {
    _clean_up();
}

void webassembly_t::syminfo_data_t::_clean_up() {
    if (m_name_len) {
        delete m_name_len; m_name_len = 0;
    }
    if (!n_index) {
        if (m_index) {
            delete m_index; m_index = 0;
        }
    }
    if (!n_offset) {
        if (m_offset) {
            delete m_offset; m_offset = 0;
        }
    }
    if (!n_size) {
        if (m_size) {
            delete m_size; m_size = 0;
        }
    }
}

webassembly_t::syminfo_ext_t::syminfo_ext_t(kaitai::kstream* p__io, webassembly_t::syminfo_type_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_index = 0;
    m_name_len = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::syminfo_ext_t::_read() {
    m_index = new vlq_base128_le_t(m__io);
    n_name_len = true;
    if ((_parent()->flags()->value() & webassembly_t::SYMFLAG_UNDEFINED) == 0) {
        n_name_len = false;
        m_name_len = new vlq_base128_le_t(m__io);
    }
    n_name_data = true;
    if ((_parent()->flags()->value() & webassembly_t::SYMFLAG_UNDEFINED) == 0) {
        n_name_data = false;
        m_name_data = kaitai::kstream::bytes_to_str(m__io->read_bytes(name_len()->value()), "UTF-8");
    }
}

webassembly_t::syminfo_ext_t::~syminfo_ext_t() {
    _clean_up();
}

void webassembly_t::syminfo_ext_t::_clean_up() {
    if (m_index) {
        delete m_index; m_index = 0;
    }
    if (!n_name_len) {
        if (m_name_len) {
            delete m_name_len; m_name_len = 0;
        }
    }
    if (!n_name_data) {
    }
}

webassembly_t::syminfo_section_t::syminfo_section_t(kaitai::kstream* p__io, webassembly_t::syminfo_type_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_section = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::syminfo_section_t::_read() {
    m_section = new vlq_base128_le_t(m__io);
}

webassembly_t::syminfo_section_t::~syminfo_section_t() {
    _clean_up();
}

void webassembly_t::syminfo_section_t::_clean_up() {
    if (m_section) {
        delete m_section; m_section = 0;
    }
}

webassembly_t::syminfo_type_t::syminfo_type_t(kaitai::kstream* p__io, webassembly_t::symbol_table_type_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_flags = 0;
    m_data = 0;
    m_ext = 0;
    m_section = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::syminfo_type_t::_read() {
    m_kind = static_cast<webassembly_t::symtab_t>(m__io->read_u1());
    m_flags = new vlq_base128_le_t(m__io);
    n_data = true;
    if (kind() == webassembly_t::SYMTAB_DATA) {
        n_data = false;
        m_data = new syminfo_data_t(m__io, this, m__root);
    }
    n_ext = true;
    if ( ((kind() == webassembly_t::SYMTAB_FUNCTION) || (kind() == webassembly_t::SYMTAB_GLOBAL) || (kind() == webassembly_t::SYMTAB_EVENT) || (kind() == webassembly_t::SYMTAB_TABLE)) ) {
        n_ext = false;
        m_ext = new syminfo_ext_t(m__io, this, m__root);
    }
    n_section = true;
    if (kind() == webassembly_t::SYMTAB_SECTION) {
        n_section = false;
        m_section = new syminfo_section_t(m__io, this, m__root);
    }
}

webassembly_t::syminfo_type_t::~syminfo_type_t() {
    _clean_up();
}

void webassembly_t::syminfo_type_t::_clean_up() {
    if (m_flags) {
        delete m_flags; m_flags = 0;
    }
    if (!n_data) {
        if (m_data) {
            delete m_data; m_data = 0;
        }
    }
    if (!n_ext) {
        if (m_ext) {
            delete m_ext; m_ext = 0;
        }
    }
    if (!n_section) {
        if (m_section) {
            delete m_section; m_section = 0;
        }
    }
}

webassembly_t::table_section_t::table_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_count = 0;
    m_entries = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::table_section_t::_read() {
    m_count = new vlq_base128_le_t(m__io);
    m_entries = new std::vector<table_type_t*>();
    const int l_entries = count()->value();
    for (int i = 0; i < l_entries; i++) {
        m_entries->push_back(new table_type_t(m__io, this, m__root));
    }
}

webassembly_t::table_section_t::~table_section_t() {
    _clean_up();
}

void webassembly_t::table_section_t::_clean_up() {
    if (m_count) {
        delete m_count; m_count = 0;
    }
    if (m_entries) {
        for (std::vector<table_type_t*>::iterator it = m_entries->begin(); it != m_entries->end(); ++it) {
            delete *it;
        }
        delete m_entries; m_entries = 0;
    }
}

webassembly_t::table_type_t::table_type_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_limits = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::table_type_t::_read() {
    m_element_type = static_cast<webassembly_t::elem_type_t>(m__io->read_u1());
    m_limits = new resizable_limits_type_t(m__io, this, m__root);
}

webassembly_t::table_type_t::~table_type_t() {
    _clean_up();
}

void webassembly_t::table_type_t::_clean_up() {
    if (m_limits) {
        delete m_limits; m_limits = 0;
    }
}

webassembly_t::type_section_t::type_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_entries = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::type_section_t::_read() {
    m_count = m__io->read_u1();
    m_entries = new std::vector<func_type_t*>();
    const int l_entries = count();
    for (int i = 0; i < l_entries; i++) {
        m_entries->push_back(new func_type_t(m__io, this, m__root));
    }
}

webassembly_t::type_section_t::~type_section_t() {
    _clean_up();
}

void webassembly_t::type_section_t::_clean_up() {
    if (m_entries) {
        for (std::vector<func_type_t*>::iterator it = m_entries->begin(); it != m_entries->end(); ++it) {
            delete *it;
        }
        delete m_entries; m_entries = 0;
    }
}

webassembly_t::unimplemented_section_t::unimplemented_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name_len = 0;
    m_linking = 0;
    m_raw = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::unimplemented_section_t::_read() {
    m_name_len = new vlq_base128_le_t(m__io);
    m_name = kaitai::kstream::bytes_to_str(m__io->read_bytes(name_len()->value()), "UTF-8");
    n_linking = true;
    if (name() == std::string("linking")) {
        n_linking = false;
        m_linking = new std::vector<linking_custom_type_t*>();
        {
            int i = 0;
            while (!m__io->is_eof()) {
                m_linking->push_back(new linking_custom_type_t(m__io, this, m__root));
                i++;
            }
        }
    }
    n_raw = true;
    if (name() != std::string("linking")) {
        n_raw = false;
        m_raw = new std::vector<uint8_t>();
        const int l_raw = (_parent()->header()->payload_len()->value() - name_len()->value()) - name_len()->len();
        for (int i = 0; i < l_raw; i++) {
            m_raw->push_back(m__io->read_u1());
        }
    }
}

webassembly_t::unimplemented_section_t::~unimplemented_section_t() {
    _clean_up();
}

void webassembly_t::unimplemented_section_t::_clean_up() {
    if (m_name_len) {
        delete m_name_len; m_name_len = 0;
    }
    if (!n_linking) {
        if (m_linking) {
            for (std::vector<linking_custom_type_t*>::iterator it = m_linking->begin(); it != m_linking->end(); ++it) {
                delete *it;
            }
            delete m_linking; m_linking = 0;
        }
    }
    if (!n_raw) {
        if (m_raw) {
            delete m_raw; m_raw = 0;
        }
    }
}
