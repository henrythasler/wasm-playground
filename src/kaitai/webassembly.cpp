// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "webassembly.h"
#include "kaitai/exceptions.h"
std::set<webassembly_t::export_types_t> webassembly_t::_build_values_export_types_t() {
    std::set<webassembly_t::export_types_t> _t;
    _t.insert(webassembly_t::EXPORT_TYPES_FUNC);
    _t.insert(webassembly_t::EXPORT_TYPES_TABLE);
    _t.insert(webassembly_t::EXPORT_TYPES_MEM);
    _t.insert(webassembly_t::EXPORT_TYPES_GLOBAL);
    return _t;
}
const std::set<webassembly_t::export_types_t> webassembly_t::_values_export_types_t = webassembly_t::_build_values_export_types_t();
bool webassembly_t::_is_defined_export_types_t(webassembly_t::export_types_t v) {
    return webassembly_t::_values_export_types_t.find(v) != webassembly_t::_values_export_types_t.end();
}
std::set<webassembly_t::import_types_t> webassembly_t::_build_values_import_types_t() {
    std::set<webassembly_t::import_types_t> _t;
    _t.insert(webassembly_t::IMPORT_TYPES_FUNC);
    _t.insert(webassembly_t::IMPORT_TYPES_TABLE);
    _t.insert(webassembly_t::IMPORT_TYPES_MEM);
    _t.insert(webassembly_t::IMPORT_TYPES_GLOBAL);
    return _t;
}
const std::set<webassembly_t::import_types_t> webassembly_t::_values_import_types_t = webassembly_t::_build_values_import_types_t();
bool webassembly_t::_is_defined_import_types_t(webassembly_t::import_types_t v) {
    return webassembly_t::_values_import_types_t.find(v) != webassembly_t::_values_import_types_t.end();
}
std::set<webassembly_t::section_id_t> webassembly_t::_build_values_section_id_t() {
    std::set<webassembly_t::section_id_t> _t;
    _t.insert(webassembly_t::SECTION_ID_CUSTOM);
    _t.insert(webassembly_t::SECTION_ID_TYPE);
    _t.insert(webassembly_t::SECTION_ID_IMPORT);
    _t.insert(webassembly_t::SECTION_ID_FUNCTION);
    _t.insert(webassembly_t::SECTION_ID_TABLE);
    _t.insert(webassembly_t::SECTION_ID_MEMORY);
    _t.insert(webassembly_t::SECTION_ID_GLOBAL);
    _t.insert(webassembly_t::SECTION_ID_EXPORT);
    _t.insert(webassembly_t::SECTION_ID_START);
    _t.insert(webassembly_t::SECTION_ID_ELEMENT);
    _t.insert(webassembly_t::SECTION_ID_CODE);
    _t.insert(webassembly_t::SECTION_ID_DATA);
    return _t;
}
const std::set<webassembly_t::section_id_t> webassembly_t::_values_section_id_t = webassembly_t::_build_values_section_id_t();
bool webassembly_t::_is_defined_section_id_t(webassembly_t::section_id_t v) {
    return webassembly_t::_values_section_id_t.find(v) != webassembly_t::_values_section_id_t.end();
}
std::set<webassembly_t::types_t> webassembly_t::_build_values_types_t() {
    std::set<webassembly_t::types_t> _t;
    _t.insert(webassembly_t::TYPES_FUNCTION);
    _t.insert(webassembly_t::TYPES_ELEMENT);
    return _t;
}
const std::set<webassembly_t::types_t> webassembly_t::_values_types_t = webassembly_t::_build_values_types_t();
bool webassembly_t::_is_defined_types_t(webassembly_t::types_t v) {
    return webassembly_t::_values_types_t.find(v) != webassembly_t::_values_types_t.end();
}
std::set<webassembly_t::valtype_t> webassembly_t::_build_values_valtype_t() {
    std::set<webassembly_t::valtype_t> _t;
    _t.insert(webassembly_t::VALTYPE_F64);
    _t.insert(webassembly_t::VALTYPE_F32);
    _t.insert(webassembly_t::VALTYPE_I64);
    _t.insert(webassembly_t::VALTYPE_I32);
    return _t;
}
const std::set<webassembly_t::valtype_t> webassembly_t::_values_valtype_t = webassembly_t::_build_values_valtype_t();
bool webassembly_t::_is_defined_valtype_t(webassembly_t::valtype_t v) {
    return webassembly_t::_values_valtype_t.find(v) != webassembly_t::_values_valtype_t.end();
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
    m_sections = new std::vector<section_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_sections->push_back(new section_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::~webassembly_t() {
    _clean_up();
}

void webassembly_t::_clean_up() {
    if (m_sections) {
        for (std::vector<section_t*>::iterator it = m_sections->begin(); it != m_sections->end(); ++it) {
            delete *it;
        }
        delete m_sections; m_sections = 0;
    }
}

webassembly_t::code_t::code_t(kaitai::kstream* p__io, webassembly_t::code_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_len_func = 0;
    m_func = 0;
    m__io__raw_func = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::code_t::_read() {
    m_len_func = new vlq_base128_le_t(m__io);
    m__raw_func = m__io->read_bytes(len_func()->value());
    m__io__raw_func = new kaitai::kstream(m__raw_func);
    m_func = new func_t(m__io__raw_func, this, m__root);
}

webassembly_t::code_t::~code_t() {
    _clean_up();
}

void webassembly_t::code_t::_clean_up() {
    if (m_len_func) {
        delete m_len_func; m_len_func = 0;
    }
    if (m__io__raw_func) {
        delete m__io__raw_func; m__io__raw_func = 0;
    }
    if (m_func) {
        delete m_func; m_func = 0;
    }
}

webassembly_t::code_section_t::code_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_entries = 0;
    m_entries = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::code_section_t::_read() {
    m_num_entries = new vlq_base128_le_t(m__io);
    m_entries = new std::vector<code_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_entries->push_back(new code_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::code_section_t::~code_section_t() {
    _clean_up();
}

void webassembly_t::code_section_t::_clean_up() {
    if (m_num_entries) {
        delete m_num_entries; m_num_entries = 0;
    }
    if (m_entries) {
        for (std::vector<code_t*>::iterator it = m_entries->begin(); it != m_entries->end(); ++it) {
            delete *it;
        }
        delete m_entries; m_entries = 0;
    }
}

webassembly_t::custom_section_t::custom_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::custom_section_t::_read() {
    m_name = new name_t(m__io, this, m__root);
    m_data = m__io->read_bytes_full();
}

webassembly_t::custom_section_t::~custom_section_t() {
    _clean_up();
}

void webassembly_t::custom_section_t::_clean_up() {
    if (m_name) {
        delete m_name; m_name = 0;
    }
}

webassembly_t::data_section_t::data_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_data = 0;
    m_data_segments = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::data_section_t::_read() {
    m_num_data = new vlq_base128_le_t(m__io);
    m_data_segments = new std::vector<data_segment_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_data_segments->push_back(new data_segment_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::data_section_t::~data_section_t() {
    _clean_up();
}

void webassembly_t::data_section_t::_clean_up() {
    if (m_num_data) {
        delete m_num_data; m_num_data = 0;
    }
    if (m_data_segments) {
        for (std::vector<data_segment_t*>::iterator it = m_data_segments->begin(); it != m_data_segments->end(); ++it) {
            delete *it;
        }
        delete m_data_segments; m_data_segments = 0;
    }
}

webassembly_t::data_segment_t::data_segment_t(kaitai::kstream* p__io, webassembly_t::data_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_memidx = 0;
    m_num_init = 0;
    m_init = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::data_segment_t::_read() {
    m_memidx = new vlq_base128_le_t(m__io);
    {
        vlq_base128_le_t* _ = m_memidx;
        if (!(memidx()->value() == 0)) {
            throw kaitai::validation_expr_error<vlq_base128_le_t*>(m_memidx, m__io, std::string("/types/data_segment/seq/0"));
        }
    }
    m_offset = m__io->read_bytes_term(11, false, true, true);
    m_num_init = new vlq_base128_le_t(m__io);
    m_init = new std::vector<uint8_t>();
    const int l_init = num_init()->value();
    for (int i = 0; i < l_init; i++) {
        m_init->push_back(m__io->read_u1());
    }
}

webassembly_t::data_segment_t::~data_segment_t() {
    _clean_up();
}

void webassembly_t::data_segment_t::_clean_up() {
    if (m_memidx) {
        delete m_memidx; m_memidx = 0;
    }
    if (m_num_init) {
        delete m_num_init; m_num_init = 0;
    }
    if (m_init) {
        delete m_init; m_init = 0;
    }
}

webassembly_t::dummy_t::dummy_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::dummy_t::_read() {
}

webassembly_t::dummy_t::~dummy_t() {
    _clean_up();
}

void webassembly_t::dummy_t::_clean_up() {
}

webassembly_t::element_t::element_t(kaitai::kstream* p__io, webassembly_t::element_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_tableidx = 0;
    m_num_init = 0;
    m_init = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::element_t::_read() {
    m_tableidx = new vlq_base128_le_t(m__io);
    m_offset = m__io->read_bytes_term(11, false, true, true);
    m_num_init = new vlq_base128_le_t(m__io);
    m_init = new std::vector<vlq_base128_le_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_init->push_back(new vlq_base128_le_t(m__io));
            i++;
        }
    }
}

webassembly_t::element_t::~element_t() {
    _clean_up();
}

void webassembly_t::element_t::_clean_up() {
    if (m_tableidx) {
        delete m_tableidx; m_tableidx = 0;
    }
    if (m_num_init) {
        delete m_num_init; m_num_init = 0;
    }
    if (m_init) {
        for (std::vector<vlq_base128_le_t*>::iterator it = m_init->begin(); it != m_init->end(); ++it) {
            delete *it;
        }
        delete m_init; m_init = 0;
    }
}

webassembly_t::element_section_t::element_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_elements = 0;
    m_elements = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::element_section_t::_read() {
    m_num_elements = new vlq_base128_le_t(m__io);
    m_elements = new std::vector<element_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_elements->push_back(new element_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::element_section_t::~element_section_t() {
    _clean_up();
}

void webassembly_t::element_section_t::_clean_up() {
    if (m_num_elements) {
        delete m_num_elements; m_num_elements = 0;
    }
    if (m_elements) {
        for (std::vector<element_t*>::iterator it = m_elements->begin(); it != m_elements->end(); ++it) {
            delete *it;
        }
        delete m_elements; m_elements = 0;
    }
}

webassembly_t::export_t::export_t(kaitai::kstream* p__io, webassembly_t::export_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_name = 0;
    m_idx = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::export_t::_read() {
    m_name = new name_t(m__io, this, m__root);
    m_exportdesc = static_cast<webassembly_t::export_types_t>(m__io->read_u1());
    m_idx = new vlq_base128_le_t(m__io);
}

webassembly_t::export_t::~export_t() {
    _clean_up();
}

void webassembly_t::export_t::_clean_up() {
    if (m_name) {
        delete m_name; m_name = 0;
    }
    if (m_idx) {
        delete m_idx; m_idx = 0;
    }
}

webassembly_t::export_section_t::export_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_exports = 0;
    m_exports = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::export_section_t::_read() {
    m_num_exports = new vlq_base128_le_t(m__io);
    m_exports = new std::vector<export_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_exports->push_back(new export_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::export_section_t::~export_section_t() {
    _clean_up();
}

void webassembly_t::export_section_t::_clean_up() {
    if (m_num_exports) {
        delete m_num_exports; m_num_exports = 0;
    }
    if (m_exports) {
        for (std::vector<export_t*>::iterator it = m_exports->begin(); it != m_exports->end(); ++it) {
            delete *it;
        }
        delete m_exports; m_exports = 0;
    }
}

webassembly_t::func_t::func_t(kaitai::kstream* p__io, webassembly_t::code_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_locals = 0;
    m_locals = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::func_t::_read() {
    m_num_locals = new vlq_base128_le_t(m__io);
    m_locals = new std::vector<local_t*>();
    const int l_locals = num_locals()->value();
    for (int i = 0; i < l_locals; i++) {
        m_locals->push_back(new local_t(m__io, this, m__root));
    }
    m_expr = m__io->read_bytes_full();
}

webassembly_t::func_t::~func_t() {
    _clean_up();
}

void webassembly_t::func_t::_clean_up() {
    if (m_num_locals) {
        delete m_num_locals; m_num_locals = 0;
    }
    if (m_locals) {
        for (std::vector<local_t*>::iterator it = m_locals->begin(); it != m_locals->end(); ++it) {
            delete *it;
        }
        delete m_locals; m_locals = 0;
    }
}

webassembly_t::function_section_t::function_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_typeidx = 0;
    m_typeidx = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::function_section_t::_read() {
    m_num_typeidx = new vlq_base128_le_t(m__io);
    m_typeidx = new std::vector<vlq_base128_le_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_typeidx->push_back(new vlq_base128_le_t(m__io));
            i++;
        }
    }
}

webassembly_t::function_section_t::~function_section_t() {
    _clean_up();
}

void webassembly_t::function_section_t::_clean_up() {
    if (m_num_typeidx) {
        delete m_num_typeidx; m_num_typeidx = 0;
    }
    if (m_typeidx) {
        for (std::vector<vlq_base128_le_t*>::iterator it = m_typeidx->begin(); it != m_typeidx->end(); ++it) {
            delete *it;
        }
        delete m_typeidx; m_typeidx = 0;
    }
}

webassembly_t::functype_t::functype_t(kaitai::kstream* p__io, webassembly_t::type_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_parameters = 0;
    m_results = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::functype_t::_read() {
    m_functype = static_cast<webassembly_t::types_t>(m__io->read_u1());
    if (!(m_functype == webassembly_t::TYPES_FUNCTION)) {
        throw kaitai::validation_not_equal_error<webassembly_t::types_t>(webassembly_t::TYPES_FUNCTION, m_functype, m__io, std::string("/types/functype/seq/0"));
    }
    m_parameters = new vec_valtype_t(m__io, this, m__root);
    m_results = new vec_valtype_t(m__io, this, m__root);
}

webassembly_t::functype_t::~functype_t() {
    _clean_up();
}

void webassembly_t::functype_t::_clean_up() {
    if (m_parameters) {
        delete m_parameters; m_parameters = 0;
    }
    if (m_results) {
        delete m_results; m_results = 0;
    }
}

webassembly_t::global_t::global_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::global_t::_read() {
    m_valtype = static_cast<webassembly_t::valtype_t>(m__io->read_u1());
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
    m_num_globals = 0;
    m_globals = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::global_section_t::_read() {
    m_num_globals = new vlq_base128_le_t(m__io);
    m_globals = new std::vector<global_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_globals->push_back(new global_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::global_section_t::~global_section_t() {
    _clean_up();
}

void webassembly_t::global_section_t::_clean_up() {
    if (m_num_globals) {
        delete m_num_globals; m_num_globals = 0;
    }
    if (m_globals) {
        for (std::vector<global_t*>::iterator it = m_globals->begin(); it != m_globals->end(); ++it) {
            delete *it;
        }
        delete m_globals; m_globals = 0;
    }
}

webassembly_t::import_t::import_t(kaitai::kstream* p__io, webassembly_t::import_section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_module = 0;
    m_name = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::import_t::_read() {
    m_module = new name_t(m__io, this, m__root);
    m_name = new name_t(m__io, this, m__root);
    m_import_type = static_cast<webassembly_t::import_types_t>(m__io->read_u1());
    n_importdesc = true;
    switch (import_type()) {
    case webassembly_t::IMPORT_TYPES_FUNC: {
        n_importdesc = false;
        m_importdesc = new vlq_base128_le_t(m__io);
        break;
    }
    case webassembly_t::IMPORT_TYPES_GLOBAL: {
        n_importdesc = false;
        m_importdesc = new global_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::IMPORT_TYPES_MEM: {
        n_importdesc = false;
        m_importdesc = new memory_t(m__io, this, m__root);
        break;
    }
    case webassembly_t::IMPORT_TYPES_TABLE: {
        n_importdesc = false;
        m_importdesc = new table_t(m__io, this, m__root);
        break;
    }
    }
}

webassembly_t::import_t::~import_t() {
    _clean_up();
}

void webassembly_t::import_t::_clean_up() {
    if (m_module) {
        delete m_module; m_module = 0;
    }
    if (m_name) {
        delete m_name; m_name = 0;
    }
    if (!n_importdesc) {
        if (m_importdesc) {
            delete m_importdesc; m_importdesc = 0;
        }
    }
}

webassembly_t::import_section_t::import_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_imports = 0;
    m_imports = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::import_section_t::_read() {
    m_num_imports = new vlq_base128_le_t(m__io);
    m_imports = new std::vector<import_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_imports->push_back(new import_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::import_section_t::~import_section_t() {
    _clean_up();
}

void webassembly_t::import_section_t::_clean_up() {
    if (m_num_imports) {
        delete m_num_imports; m_num_imports = 0;
    }
    if (m_imports) {
        for (std::vector<import_t*>::iterator it = m_imports->begin(); it != m_imports->end(); ++it) {
            delete *it;
        }
        delete m_imports; m_imports = 0;
    }
}

webassembly_t::limits_t::limits_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_min = 0;
    m_max = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::limits_t::_read() {
    m_flags = m__io->read_u1();
    if (!( ((m_flags == 0) || (m_flags == 1)) )) {
        throw kaitai::validation_not_any_of_error<uint8_t>(m_flags, m__io, std::string("/types/limits/seq/0"));
    }
    m_min = new vlq_base128_le_t(m__io);
    n_max = true;
    if (flags() == 1) {
        n_max = false;
        m_max = new vlq_base128_le_t(m__io);
    }
}

webassembly_t::limits_t::~limits_t() {
    _clean_up();
}

void webassembly_t::limits_t::_clean_up() {
    if (m_min) {
        delete m_min; m_min = 0;
    }
    if (!n_max) {
        if (m_max) {
            delete m_max; m_max = 0;
        }
    }
}

webassembly_t::local_t::local_t(kaitai::kstream* p__io, webassembly_t::func_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_valtype = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::local_t::_read() {
    m_num_valtype = new vlq_base128_le_t(m__io);
    m_valtype = static_cast<webassembly_t::valtype_t>(m__io->read_u1());
}

webassembly_t::local_t::~local_t() {
    _clean_up();
}

void webassembly_t::local_t::_clean_up() {
    if (m_num_valtype) {
        delete m_num_valtype; m_num_valtype = 0;
    }
}

webassembly_t::memory_t::memory_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
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

void webassembly_t::memory_t::_read() {
    m_limits = new limits_t(m__io, this, m__root);
}

webassembly_t::memory_t::~memory_t() {
    _clean_up();
}

void webassembly_t::memory_t::_clean_up() {
    if (m_limits) {
        delete m_limits; m_limits = 0;
    }
}

webassembly_t::memory_section_t::memory_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_memories = 0;
    m_memories = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::memory_section_t::_read() {
    m_num_memories = new vlq_base128_le_t(m__io);
    m_memories = new std::vector<memory_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_memories->push_back(new memory_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::memory_section_t::~memory_section_t() {
    _clean_up();
}

void webassembly_t::memory_section_t::_clean_up() {
    if (m_num_memories) {
        delete m_num_memories; m_num_memories = 0;
    }
    if (m_memories) {
        for (std::vector<memory_t*>::iterator it = m_memories->begin(); it != m_memories->end(); ++it) {
            delete *it;
        }
        delete m_memories; m_memories = 0;
    }
}

webassembly_t::name_t::name_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_length = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::name_t::_read() {
    m_length = new vlq_base128_le_t(m__io);
    m_value = kaitai::kstream::bytes_to_str(m__io->read_bytes(length()->value()), "UTF-8");
}

webassembly_t::name_t::~name_t() {
    _clean_up();
}

void webassembly_t::name_t::_clean_up() {
    if (m_length) {
        delete m_length; m_length = 0;
    }
}

webassembly_t::section_t::section_t(kaitai::kstream* p__io, webassembly_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_len_content = 0;
    m__io__raw_content = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::section_t::_read() {
    m_id = static_cast<webassembly_t::section_id_t>(m__io->read_u1());
    m_len_content = new vlq_base128_le_t(m__io);
    n_content = true;
    switch (id()) {
    case webassembly_t::SECTION_ID_CODE: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new code_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_CUSTOM: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new custom_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_DATA: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new data_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_ELEMENT: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new element_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_EXPORT: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new export_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_FUNCTION: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new function_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_GLOBAL: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new global_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_IMPORT: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new import_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_MEMORY: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new memory_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_START: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new start_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_TABLE: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new table_section_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_TYPE: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new type_section_t(m__io__raw_content, this, m__root);
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
    if (m_len_content) {
        delete m_len_content; m_len_content = 0;
    }
    if (!n_content) {
        if (m__io__raw_content) {
            delete m__io__raw_content; m__io__raw_content = 0;
        }
        if (m_content) {
            delete m_content; m_content = 0;
        }
    }
}

webassembly_t::start_section_t::start_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_start = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::start_section_t::_read() {
    m_start = new vlq_base128_le_t(m__io);
}

webassembly_t::start_section_t::~start_section_t() {
    _clean_up();
}

void webassembly_t::start_section_t::_clean_up() {
    if (m_start) {
        delete m_start; m_start = 0;
    }
}

webassembly_t::table_t::table_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
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

void webassembly_t::table_t::_read() {
    m_elemtype = static_cast<webassembly_t::types_t>(m__io->read_u1());
    if (!(m_elemtype == webassembly_t::TYPES_ELEMENT)) {
        throw kaitai::validation_not_equal_error<webassembly_t::types_t>(webassembly_t::TYPES_ELEMENT, m_elemtype, m__io, std::string("/types/table/seq/0"));
    }
    m_limits = new limits_t(m__io, this, m__root);
}

webassembly_t::table_t::~table_t() {
    _clean_up();
}

void webassembly_t::table_t::_clean_up() {
    if (m_limits) {
        delete m_limits; m_limits = 0;
    }
}

webassembly_t::table_section_t::table_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_tables = 0;
    m_tables = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::table_section_t::_read() {
    m_num_tables = new vlq_base128_le_t(m__io);
    m_tables = new std::vector<table_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_tables->push_back(new table_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::table_section_t::~table_section_t() {
    _clean_up();
}

void webassembly_t::table_section_t::_clean_up() {
    if (m_num_tables) {
        delete m_num_tables; m_num_tables = 0;
    }
    if (m_tables) {
        for (std::vector<table_t*>::iterator it = m_tables->begin(); it != m_tables->end(); ++it) {
            delete *it;
        }
        delete m_tables; m_tables = 0;
    }
}

webassembly_t::type_section_t::type_section_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_functypes = 0;
    m_functypes = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::type_section_t::_read() {
    m_num_functypes = new vlq_base128_le_t(m__io);
    m_functypes = new std::vector<functype_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_functypes->push_back(new functype_t(m__io, this, m__root));
            i++;
        }
    }
}

webassembly_t::type_section_t::~type_section_t() {
    _clean_up();
}

void webassembly_t::type_section_t::_clean_up() {
    if (m_num_functypes) {
        delete m_num_functypes; m_num_functypes = 0;
    }
    if (m_functypes) {
        for (std::vector<functype_t*>::iterator it = m_functypes->begin(); it != m_functypes->end(); ++it) {
            delete *it;
        }
        delete m_functypes; m_functypes = 0;
    }
}

webassembly_t::vec_valtype_t::vec_valtype_t(kaitai::kstream* p__io, webassembly_t::functype_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_num_types = 0;
    m_valtype = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void webassembly_t::vec_valtype_t::_read() {
    m_num_types = new vlq_base128_le_t(m__io);
    m_valtype = new std::vector<valtype_t>();
    const int l_valtype = num_types()->value();
    for (int i = 0; i < l_valtype; i++) {
        m_valtype->push_back(static_cast<webassembly_t::valtype_t>(m__io->read_u1()));
    }
}

webassembly_t::vec_valtype_t::~vec_valtype_t() {
    _clean_up();
}

void webassembly_t::vec_valtype_t::_clean_up() {
    if (m_num_types) {
        delete m_num_types; m_num_types = 0;
    }
    if (m_valtype) {
        delete m_valtype; m_valtype = 0;
    }
}
