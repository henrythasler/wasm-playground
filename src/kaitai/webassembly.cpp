// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "webassembly.h"
#include "kaitai/exceptions.h"
std::set<webassembly_t::indices_t> webassembly_t::_build_values_indices_t() {
    std::set<webassembly_t::indices_t> _t;
    _t.insert(webassembly_t::INDICES_FUNC);
    _t.insert(webassembly_t::INDICES_TABLE);
    _t.insert(webassembly_t::INDICES_MEM);
    _t.insert(webassembly_t::INDICES_GLOBAL);
    return _t;
}
const std::set<webassembly_t::indices_t> webassembly_t::_values_indices_t = webassembly_t::_build_values_indices_t();
bool webassembly_t::_is_defined_indices_t(webassembly_t::indices_t v) {
    return webassembly_t::_values_indices_t.find(v) != webassembly_t::_values_indices_t.end();
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

webassembly_t::dummy_t::dummy_t(kaitai::kstream* p__io, webassembly_t::section_t* p__parent, webassembly_t* p__root) : kaitai::kstruct(p__io) {
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
    m_exportdesc = static_cast<webassembly_t::indices_t>(m__io->read_u1());
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
    const int l_typeidx = num_typeidx()->value();
    for (int i = 0; i < l_typeidx; i++) {
        m_typeidx->push_back(new vlq_base128_le_t(m__io));
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
        m_content = new dummy_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_ELEMENT: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new dummy_t(m__io__raw_content, this, m__root);
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
        m_content = new dummy_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_IMPORT: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new dummy_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_MEMORY: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new dummy_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_START: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new dummy_t(m__io__raw_content, this, m__root);
        break;
    }
    case webassembly_t::SECTION_ID_TABLE: {
        n_content = false;
        m__raw_content = m__io->read_bytes(len_content()->value());
        m__io__raw_content = new kaitai::kstream(m__raw_content);
        m_content = new dummy_t(m__io__raw_content, this, m__root);
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
    const int l_functypes = num_functypes()->value();
    for (int i = 0; i < l_functypes; i++) {
        m_functypes->push_back(new functype_t(m__io, this, m__root));
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
