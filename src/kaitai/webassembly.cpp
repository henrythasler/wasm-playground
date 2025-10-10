// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "webassembly.h"
#include "kaitai/exceptions.h"
const std::set<webassembly_t::export_types_t> webassembly_t::_values_export_types_t{
    webassembly_t::EXPORT_TYPES_FUNC_TYPE,
    webassembly_t::EXPORT_TYPES_TABLE_TYPE,
    webassembly_t::EXPORT_TYPES_MEM_TYPE,
    webassembly_t::EXPORT_TYPES_GLOBAL_TYPE,
};
bool webassembly_t::_is_defined_export_types_t(webassembly_t::export_types_t v) {
    return webassembly_t::_values_export_types_t.find(v) != webassembly_t::_values_export_types_t.end();
}
const std::set<webassembly_t::import_types_t> webassembly_t::_values_import_types_t{
    webassembly_t::IMPORT_TYPES_FUNC_TYPE,
    webassembly_t::IMPORT_TYPES_TABLE_TYPE,
    webassembly_t::IMPORT_TYPES_MEM_TYPE,
    webassembly_t::IMPORT_TYPES_GLOBAL_TYPE,
};
bool webassembly_t::_is_defined_import_types_t(webassembly_t::import_types_t v) {
    return webassembly_t::_values_import_types_t.find(v) != webassembly_t::_values_import_types_t.end();
}
const std::set<webassembly_t::section_id_t> webassembly_t::_values_section_id_t{
    webassembly_t::SECTION_ID_CUSTOM_SECTION,
    webassembly_t::SECTION_ID_TYPE_SECTION,
    webassembly_t::SECTION_ID_IMPORT_SECTION,
    webassembly_t::SECTION_ID_FUNCTION_SECTION,
    webassembly_t::SECTION_ID_TABLE_SECTION,
    webassembly_t::SECTION_ID_MEMORY_SECTION,
    webassembly_t::SECTION_ID_GLOBAL_SECTION,
    webassembly_t::SECTION_ID_EXPORT_SECTION,
    webassembly_t::SECTION_ID_START_SECTION,
    webassembly_t::SECTION_ID_ELEMENT_SECTION,
    webassembly_t::SECTION_ID_CODE_SECTION,
    webassembly_t::SECTION_ID_DATA_SECTION,
};
bool webassembly_t::_is_defined_section_id_t(webassembly_t::section_id_t v) {
    return webassembly_t::_values_section_id_t.find(v) != webassembly_t::_values_section_id_t.end();
}
const std::set<webassembly_t::types_t> webassembly_t::_values_types_t{
    webassembly_t::TYPES_FUNCTION,
    webassembly_t::TYPES_ELEMENT,
};
bool webassembly_t::_is_defined_types_t(webassembly_t::types_t v) {
    return webassembly_t::_values_types_t.find(v) != webassembly_t::_values_types_t.end();
}
const std::set<webassembly_t::val_types_t> webassembly_t::_values_val_types_t{
    webassembly_t::VAL_TYPES_F64,
    webassembly_t::VAL_TYPES_F32,
    webassembly_t::VAL_TYPES_I64,
    webassembly_t::VAL_TYPES_I32,
};
bool webassembly_t::_is_defined_val_types_t(webassembly_t::val_types_t v) {
    return webassembly_t::_values_val_types_t.find(v) != webassembly_t::_values_val_types_t.end();
}

webassembly_t::webassembly_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root ? p__root : this;
    m_sections = nullptr;
    _read();
}

void webassembly_t::_read() {
    m_magic = m__io->read_bytes(4);
    if (!(m_magic == std::string("\x00\x61\x73\x6D", 4))) {
        throw kaitai::validation_not_equal_error<std::string>(std::string("\x00\x61\x73\x6D", 4), m_magic, m__io, std::string("/seq/0"));
    }
    m_version = m__io->read_u4le();
    m_sections = std::unique_ptr<std::vector<std::unique_ptr<section_t>>>(new std::vector<std::unique_ptr<section_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_sections->push_back(std::move(std::unique_ptr<section_t>(new section_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::~webassembly_t() {
    _clean_up();
}

void webassembly_t::_clean_up() {
}

webassembly_t::code_t::code_t(kaitai::kstream* p__io, webassembly_t::code_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_len_func = nullptr;
    m_func = nullptr;
    m__io__raw_func = nullptr;
    _read();
}

void webassembly_t::code_t::_read() {
    m_len_func = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m__raw_func = m__io->read_bytes(len_func()->value());
    m__io__raw_func = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_func));
    m_func = std::unique_ptr<func_t>(new func_t(m__io__raw_func.get(), this, m__root));
}

webassembly_t::code_t::~code_t() {
    _clean_up();
}

void webassembly_t::code_t::_clean_up() {
}

webassembly_t::code_section_t::code_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_entries = nullptr;
    m_entries = nullptr;
    _read();
}

void webassembly_t::code_section_t::_read() {
    m_num_entries = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_entries = std::unique_ptr<std::vector<std::unique_ptr<code_t>>>(new std::vector<std::unique_ptr<code_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_entries->push_back(std::move(std::unique_ptr<code_t>(new code_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::code_section_t::~code_section_t() {
    _clean_up();
}

void webassembly_t::code_section_t::_clean_up() {
}

webassembly_t::custom_section_t::custom_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = nullptr;
    _read();
}

void webassembly_t::custom_section_t::_read() {
    m_name = std::unique_ptr<name_t>(new name_t(m__io, this, m__root));
    m_data = m__io->read_bytes_full();
}

webassembly_t::custom_section_t::~custom_section_t() {
    _clean_up();
}

void webassembly_t::custom_section_t::_clean_up() {
}

webassembly_t::data_section_t::data_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_data = nullptr;
    m_data_segments = nullptr;
    _read();
}

void webassembly_t::data_section_t::_read() {
    m_num_data = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_data_segments = std::unique_ptr<std::vector<std::unique_ptr<data_segment_t>>>(new std::vector<std::unique_ptr<data_segment_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_data_segments->push_back(std::move(std::unique_ptr<data_segment_t>(new data_segment_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::data_section_t::~data_section_t() {
    _clean_up();
}

void webassembly_t::data_section_t::_clean_up() {
}

webassembly_t::data_segment_t::data_segment_t(kaitai::kstream* p__io, webassembly_t::data_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_data_memidx = nullptr;
    m_num_init = nullptr;
    _read();
}

void webassembly_t::data_segment_t::_read() {
    m_data_memidx = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_offset_expr = m__io->read_bytes_term(11, false, true, true);
    m_num_init = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_init_vec = m__io->read_bytes(num_init()->value());
}

webassembly_t::data_segment_t::~data_segment_t() {
    _clean_up();
}

void webassembly_t::data_segment_t::_clean_up() {
}

webassembly_t::element_t::element_t(kaitai::kstream* p__io, webassembly_t::element_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_tableidx = nullptr;
    m_num_init = nullptr;
    m_init_vec = nullptr;
    _read();
}

void webassembly_t::element_t::_read() {
    m_tableidx = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_offset_expr = m__io->read_bytes_term(11, false, true, true);
    m_num_init = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_init_vec = std::unique_ptr<std::vector<std::unique_ptr<vlq_base128_le_t>>>(new std::vector<std::unique_ptr<vlq_base128_le_t>>());
    const int l_init_vec = num_init()->value();
    for (int i = 0; i < l_init_vec; i++) {
        m_init_vec->push_back(std::move(std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io))));
    }
}

webassembly_t::element_t::~element_t() {
    _clean_up();
}

void webassembly_t::element_t::_clean_up() {
}

webassembly_t::element_section_t::element_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_elements = nullptr;
    m_elements = nullptr;
    _read();
}

void webassembly_t::element_section_t::_read() {
    m_num_elements = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_elements = std::unique_ptr<std::vector<std::unique_ptr<element_t>>>(new std::vector<std::unique_ptr<element_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_elements->push_back(std::move(std::unique_ptr<element_t>(new element_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::element_section_t::~element_section_t() {
    _clean_up();
}

void webassembly_t::element_section_t::_clean_up() {
}

webassembly_t::export_t::export_t(kaitai::kstream* p__io, webassembly_t::export_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = nullptr;
    m_idx = nullptr;
    _read();
}

void webassembly_t::export_t::_read() {
    m_name = std::unique_ptr<name_t>(new name_t(m__io, this, m__root));
    m_exportdesc = static_cast<webassembly_t::export_types_t>(m__io->read_u1());
    m_idx = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
}

webassembly_t::export_t::~export_t() {
    _clean_up();
}

void webassembly_t::export_t::_clean_up() {
}

webassembly_t::export_section_t::export_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_exports = nullptr;
    m_exports = nullptr;
    _read();
}

void webassembly_t::export_section_t::_read() {
    m_num_exports = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_exports = std::unique_ptr<std::vector<std::unique_ptr<export_t>>>(new std::vector<std::unique_ptr<export_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_exports->push_back(std::move(std::unique_ptr<export_t>(new export_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::export_section_t::~export_section_t() {
    _clean_up();
}

void webassembly_t::export_section_t::_clean_up() {
}

webassembly_t::func_t::func_t(kaitai::kstream* p__io, webassembly_t::code_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_locals = nullptr;
    m_locals = nullptr;
    _read();
}

void webassembly_t::func_t::_read() {
    m_num_locals = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_locals = std::unique_ptr<std::vector<std::unique_ptr<local_t>>>(new std::vector<std::unique_ptr<local_t>>());
    const int l_locals = num_locals()->value();
    for (int i = 0; i < l_locals; i++) {
        m_locals->push_back(std::move(std::unique_ptr<local_t>(new local_t(m__io, this, m__root))));
    }
    m_expr = m__io->read_bytes_full();
}

webassembly_t::func_t::~func_t() {
    _clean_up();
}

void webassembly_t::func_t::_clean_up() {
}

webassembly_t::function_section_t::function_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_typeidx = nullptr;
    m_typeidx = nullptr;
    _read();
}

void webassembly_t::function_section_t::_read() {
    m_num_typeidx = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_typeidx = std::unique_ptr<std::vector<std::unique_ptr<vlq_base128_le_t>>>(new std::vector<std::unique_ptr<vlq_base128_le_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_typeidx->push_back(std::move(std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io))));
            i++;
        }
    }
}

webassembly_t::function_section_t::~function_section_t() {
    _clean_up();
}

void webassembly_t::function_section_t::_clean_up() {
}

webassembly_t::functype_t::functype_t(kaitai::kstream* p__io, webassembly_t::type_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_parameters = nullptr;
    m_results = nullptr;
    _read();
}

void webassembly_t::functype_t::_read() {
    m_functype = static_cast<webassembly_t::types_t>(m__io->read_u1());
    if (!(m_functype == webassembly_t::TYPES_FUNCTION)) {
        throw kaitai::validation_not_equal_error<webassembly_t::types_t>(webassembly_t::TYPES_FUNCTION, m_functype, m__io, std::string("/types/functype/seq/0"));
    }
    m_parameters = std::unique_ptr<vec_valtype_t>(new vec_valtype_t(m__io, this, m__root));
    m_results = std::unique_ptr<vec_valtype_t>(new vec_valtype_t(m__io, this, m__root));
}

webassembly_t::functype_t::~functype_t() {
    _clean_up();
}

void webassembly_t::functype_t::_clean_up() {
}

webassembly_t::global_t::global_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    _read();
}

void webassembly_t::global_t::_read() {
    m_valtype = static_cast<webassembly_t::val_types_t>(m__io->read_u1());
    m_is_mutable = m__io->read_u1();
}

webassembly_t::global_t::~global_t() {
    _clean_up();
}

void webassembly_t::global_t::_clean_up() {
}

webassembly_t::global_section_t::global_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_globals = nullptr;
    m_globals = nullptr;
    _read();
}

void webassembly_t::global_section_t::_read() {
    m_num_globals = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_globals = std::unique_ptr<std::vector<std::unique_ptr<global_t>>>(new std::vector<std::unique_ptr<global_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_globals->push_back(std::move(std::unique_ptr<global_t>(new global_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::global_section_t::~global_section_t() {
    _clean_up();
}

void webassembly_t::global_section_t::_clean_up() {
}

webassembly_t::import_t::import_t(kaitai::kstream* p__io, webassembly_t::import_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_module = nullptr;
    m_name = nullptr;
    _read();
}

void webassembly_t::import_t::_read() {
    m_module = std::unique_ptr<name_t>(new name_t(m__io, this, m__root));
    m_name = std::unique_ptr<name_t>(new name_t(m__io, this, m__root));
    m_import_type = static_cast<webassembly_t::import_types_t>(m__io->read_u1());
    n_importdesc = true;
    switch (import_type()) {
    case webassembly_t::IMPORT_TYPES_FUNC_TYPE: {
        n_importdesc = false;
        m_importdesc = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
        break;
    }
    case webassembly_t::IMPORT_TYPES_GLOBAL_TYPE: {
        n_importdesc = false;
        m_importdesc = std::unique_ptr<global_t>(new global_t(m__io, this, m__root));
        break;
    }
    case webassembly_t::IMPORT_TYPES_MEM_TYPE: {
        n_importdesc = false;
        m_importdesc = std::unique_ptr<memory_t>(new memory_t(m__io, this, m__root));
        break;
    }
    case webassembly_t::IMPORT_TYPES_TABLE_TYPE: {
        n_importdesc = false;
        m_importdesc = std::unique_ptr<table_t>(new table_t(m__io, this, m__root));
        break;
    }
    }
}

webassembly_t::import_t::~import_t() {
    _clean_up();
}

void webassembly_t::import_t::_clean_up() {
    if (!n_importdesc) {
    }
}

webassembly_t::import_section_t::import_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_imports = nullptr;
    m_imports = nullptr;
    _read();
}

void webassembly_t::import_section_t::_read() {
    m_num_imports = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_imports = std::unique_ptr<std::vector<std::unique_ptr<import_t>>>(new std::vector<std::unique_ptr<import_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_imports->push_back(std::move(std::unique_ptr<import_t>(new import_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::import_section_t::~import_section_t() {
    _clean_up();
}

void webassembly_t::import_section_t::_clean_up() {
}

webassembly_t::limits_t::limits_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_min = nullptr;
    m_max = nullptr;
    _read();
}

void webassembly_t::limits_t::_read() {
    m_flags = m__io->read_u1();
    if (!( ((m_flags == 0) || (m_flags == 1)) )) {
        throw kaitai::validation_not_any_of_error<uint8_t>(m_flags, m__io, std::string("/types/limits/seq/0"));
    }
    m_min = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    n_max = true;
    if (flags() == 1) {
        n_max = false;
        m_max = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    }
}

webassembly_t::limits_t::~limits_t() {
    _clean_up();
}

void webassembly_t::limits_t::_clean_up() {
    if (!n_max) {
    }
}

webassembly_t::local_t::local_t(kaitai::kstream* p__io, webassembly_t::func_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_valtype = nullptr;
    _read();
}

void webassembly_t::local_t::_read() {
    m_num_valtype = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_valtype = static_cast<webassembly_t::val_types_t>(m__io->read_u1());
}

webassembly_t::local_t::~local_t() {
    _clean_up();
}

void webassembly_t::local_t::_clean_up() {
}

webassembly_t::memory_t::memory_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_limits = nullptr;
    _read();
}

void webassembly_t::memory_t::_read() {
    m_limits = std::unique_ptr<limits_t>(new limits_t(m__io, this, m__root));
}

webassembly_t::memory_t::~memory_t() {
    _clean_up();
}

void webassembly_t::memory_t::_clean_up() {
}

webassembly_t::memory_section_t::memory_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_memories = nullptr;
    m_memories = nullptr;
    _read();
}

void webassembly_t::memory_section_t::_read() {
    m_num_memories = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_memories = std::unique_ptr<std::vector<std::unique_ptr<memory_t>>>(new std::vector<std::unique_ptr<memory_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_memories->push_back(std::move(std::unique_ptr<memory_t>(new memory_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::memory_section_t::~memory_section_t() {
    _clean_up();
}

void webassembly_t::memory_section_t::_clean_up() {
}

webassembly_t::name_t::name_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_length = nullptr;
    _read();
}

void webassembly_t::name_t::_read() {
    m_length = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_value = kaitai::kstream::bytes_to_str(m__io->read_bytes(length()->value()), "UTF-8");
}

webassembly_t::name_t::~name_t() {
    _clean_up();
}

void webassembly_t::name_t::_clean_up() {
}

webassembly_t::section_t::section_t(kaitai::kstream* p__io, webassembly_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_len_content = nullptr;
    m__io__raw_content = nullptr;
    _read();
}

void webassembly_t::section_t::_read() {
    m_id = static_cast<webassembly_t::section_id_t>(m__io->read_u1());
    m_len_content = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    n_content = true;
    switch (id()) {
    case webassembly_t::SECTION_ID_CODE_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<code_section_t>(new code_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_CUSTOM_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<custom_section_t>(new custom_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_DATA_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<data_section_t>(new data_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_ELEMENT_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<element_section_t>(new element_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_EXPORT_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<export_section_t>(new export_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_FUNCTION_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<function_section_t>(new function_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_GLOBAL_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<global_section_t>(new global_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_IMPORT_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<import_section_t>(new import_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_MEMORY_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<memory_section_t>(new memory_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_START_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<start_section_t>(new start_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_TABLE_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<table_section_t>(new table_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    case webassembly_t::SECTION_ID_TYPE_SECTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = std::unique_ptr<kaitai::kstream>(new kaitai::kstream(m__raw_content));
        m_content = std::unique_ptr<type_section_t>(new type_section_t(m__io__raw_content.get(), this, m__root));
        break;
    }
    default: {
        m__raw_content = m__io->read_bytes(len_content()->value());
        break;
    }
    }
}

webassembly_t::section_t::~section_t() {
    _clean_up();
}

void webassembly_t::section_t::_clean_up() {
    if (!n_content) {
    }
}

webassembly_t::start_section_t::start_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_start = nullptr;
    _read();
}

void webassembly_t::start_section_t::_read() {
    m_start = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
}

webassembly_t::start_section_t::~start_section_t() {
    _clean_up();
}

void webassembly_t::start_section_t::_clean_up() {
}

webassembly_t::table_t::table_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_limits = nullptr;
    _read();
}

void webassembly_t::table_t::_read() {
    m_elemtype = static_cast<webassembly_t::types_t>(m__io->read_u1());
    if (!(m_elemtype == webassembly_t::TYPES_ELEMENT)) {
        throw kaitai::validation_not_equal_error<webassembly_t::types_t>(webassembly_t::TYPES_ELEMENT, m_elemtype, m__io, std::string("/types/table/seq/0"));
    }
    m_limits = std::unique_ptr<limits_t>(new limits_t(m__io, this, m__root));
}

webassembly_t::table_t::~table_t() {
    _clean_up();
}

void webassembly_t::table_t::_clean_up() {
}

webassembly_t::table_section_t::table_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_tables = nullptr;
    m_tables = nullptr;
    _read();
}

void webassembly_t::table_section_t::_read() {
    m_num_tables = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_tables = std::unique_ptr<std::vector<std::unique_ptr<table_t>>>(new std::vector<std::unique_ptr<table_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_tables->push_back(std::move(std::unique_ptr<table_t>(new table_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::table_section_t::~table_section_t() {
    _clean_up();
}

void webassembly_t::table_section_t::_clean_up() {
}

webassembly_t::type_section_t::type_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_functypes = nullptr;
    m_functypes = nullptr;
    _read();
}

void webassembly_t::type_section_t::_read() {
    m_num_functypes = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_functypes = std::unique_ptr<std::vector<std::unique_ptr<functype_t>>>(new std::vector<std::unique_ptr<functype_t>>());
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_functypes->push_back(std::move(std::unique_ptr<functype_t>(new functype_t(m__io, this, m__root))));
            i++;
        }
    }
}

webassembly_t::type_section_t::~type_section_t() {
    _clean_up();
}

void webassembly_t::type_section_t::_clean_up() {
}

webassembly_t::vec_valtype_t::vec_valtype_t(kaitai::kstream* p__io, webassembly_t::functype_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_types = nullptr;
    m_valtype = nullptr;
    _read();
}

void webassembly_t::vec_valtype_t::_read() {
    m_num_types = std::unique_ptr<vlq_base128_le_t>(new vlq_base128_le_t(m__io));
    m_valtype = std::unique_ptr<std::vector<val_types_t>>(new std::vector<val_types_t>());
    const int l_valtype = num_types()->value();
    for (int i = 0; i < l_valtype; i++) {
        m_valtype->push_back(std::move(static_cast<webassembly_t::val_types_t>(m__io->read_u1())));
    }
}

webassembly_t::vec_valtype_t::~vec_valtype_t() {
    _clean_up();
}

void webassembly_t::vec_valtype_t::_clean_up() {
}
