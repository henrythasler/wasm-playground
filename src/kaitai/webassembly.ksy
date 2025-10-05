meta:
  id: webassembly
  title: Binary format for WebAssembly modules
  file-extension: wasm
  tags: 
    - webassembly
    - schema
  license: MIT
  ks-version: 0.9
  imports:
    - vlq_base128_le
  endian: le

doc: |
  This document describes the binary format of a WebAssembly module 
  following the version 1.0 of the core WebAssembly standard.

  * Naming of entities follows the official specification.
  * All integers are encoded using the LEB128 variable-length integer encoding (see vlq_base128_le.ksy).
  * The schema follows the KSY Style Guide
  * Requires ks-version 0.9+ because of attribute value validation

doc-ref: |
  * https://www.w3.org/TR/wasm-core-1/
  * https://doc.kaitai.io/ksy_style_guide.html

seq:
  - id: magic
    contents: [0x00, "asm"]
    doc: | 
      Magic number identifying the file as a WebAssembly module
      REF: https://www.w3.org/TR/wasm-core-1/#binary-magic
  - id: version
    type: u4
    doc: | 
      Version of the WebAssembly binary format
      REF: https://www.w3.org/TR/wasm-core-1/#binary-version
  - id: sections
    type: section
    repeat: eos
    doc: | 
      Sequence of sections in the module
      REF: https://www.w3.org/TR/wasm-core-1/#binary-module

types:
  section:
    doc: |
      REF: https://www.w3.org/TR/wasm-core-1/#sections%E2%91%A0
    seq:
      - id: section_id
        type: u1
        enum: section_id
        doc: Section identifier
      - id: len_content
        type: vlq_base128_le
        doc: Length of the section content in bytes
      - id: content
        size: len_content.value
        type: 
          switch-on: section_id
          cases:
            'section_id::custom': custom_section
            'section_id::type': type_section
            'section_id::import': dummy
            'section_id::function': function_section
            'section_id::table': dummy
            'section_id::memory': dummy
            'section_id::global': dummy
            'section_id::export': export_section
            'section_id::start': dummy
            'section_id::element': dummy
            'section_id::code': code_section
            'section_id::data': dummy
        doc: Section content

  custom_section:
    doc: (id 0) - Custom section whose content is application-specific and not defined by the WebAssembly specification.
    doc-ref: https://www.w3.org/TR/wasm-core-1/#binary-customsec
    seq:
      - id: name
        type: name
      - id: data
        size-eos: true
        doc: Custom section data

  name:
    doc: https://www.w3.org/TR/wasm-core-1/#binary-name
    seq:
      - id: len_name
        type: vlq_base128_le
      - id: name
        size: len_name.value
        type: str
        encoding: UTF-8

  type_section:
    doc: (id 1) - A vector of function types
    doc-ref: https://www.w3.org/TR/wasm-core-1/#binary-typesec
    seq:
      - id: num_functypes
        type: vlq_base128_le
      - id: functypes
        type: functype
        repeat: expr
        repeat-expr: num_functypes.value

  functype:
    doc: Byte `0x60` followed by a vector of parameters and results
    doc-ref: https://www.w3.org/TR/wasm-core-1/#binary-functype
    seq:
      - id: functype
        type: u1
        enum: types
        valid:
          eq: types::function
      - id: parameters
        type: vec_valtype
      - id: results
        type: vec_valtype

  vec_valtype:
    seq:
      - id: num_types
        type: vlq_base128_le
      - id: valtype
        type: u1
        enum: valtype
        repeat: expr
        repeat-expr: num_types.value        
  
  function_section:
    doc: (id 3) - Vector of type indices (see `Type Section`) for all functions in the `Code Section`
    doc-ref: https://www.w3.org/TR/wasm-core-1/#binary-funcsec
    seq:
      - id: num_typeidx
        type: vlq_base128_le
      - id: typeidx
        type: vlq_base128_le
        repeat: expr
        repeat-expr: num_typeidx.value     

  export_section:
    doc: (id 7) -
    doc-ref: https://www.w3.org/TR/wasm-core-1/#binary-exportsec
    seq:
      - id: num_exports
        type: vlq_base128_le
      - id: exports
        type: export
        repeat: eos

  export:
    seq:
      - id: name
        type: name
      - id: exportdesc
        type: u1
        enum: indices
      - id: idx
        type: vlq_base128_le    

  code_section:
    doc: (id 10) A vector of code entries
    doc-ref: https://www.w3.org/TR/wasm-core-1/#binary-codesec
    seq:
      - id: num_codes
        type: vlq_base128_le
      - id: codes
        type: code
        repeat: eos

  code:
    seq:
      - id: len_func
        type: vlq_base128_le
      - id: data
        size: len_func.value
        type: func

  func:
    seq:
      - id: locals
        type: locals
      - id: expr
        size-eos: true

  locals:
    seq:
      - id: num_locals
        type: vlq_base128_le
      - id: local
        type: local
        repeat: expr
        repeat-expr: num_locals.value        

  local:
    seq:
      - id: num_valtype
        type: vlq_base128_le
      - id: valtype
        type: u1
        enum: valtype

  dummy: {}

enums:
  section_id:
    0: custom
    1: type
    2: import
    3: function
    4: table
    5: memory
    6: global
    7: export
    8: start
    9: element
    10: code
    11: data

  valtype:
    0x7f: i32
    0x7E: i64
    0x7D: f32
    0x7C: f64

  types:
    0x60: function

  indices:
    0x00: func
    0x01: table
    0x02: mem
    0x03: global
