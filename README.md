Schema-driven Binary Order Entry (BOE) codec generator in C++ for learning exchange protocol design and binary message handling.

## Overview

`boe-codegen-cpp` is a clean-room educational project for generating C++ message types, encoders, and decoders from a protocol schema.

The goal of the project is to study how low-latency exchange connectivity software is structured: binary message layouts, protocol constraints, order-entry session semantics, and code generation from a single source of truth.

This project is focused on learning and systems design, not on building a complete production trading engine.

## Goals

- Learn how Binary Order Entry style protocols are structured.
- Represent protocol definitions in a schema format.
- Generate strongly-typed C++ message objects from that schema.
- Generate encoder and decoder code for binary wire messages.
- Explore low-latency design patterns used in exchange connectivity systems.
- Keep the implementation small, understandable, and testable.

## Non-Goals

- Building a full trading engine
- Implementing market-making or execution strategies
- Providing production-ready exchange connectivity
- Reproducing any third-party repository implementation line-for-line

## Project Structure

```text
boe-codegen-cpp/
├── README.md
├── LICENSE
├── .gitignore
├── CMakeLists.txt
├── docs/
│   ├── protocol-notes.md
│   ├── architecture.md
│   └── design-decisions.md
├── schema/
│   └── c1_boe_example.yaml
├── src/
│   ├── main.cpp
│   ├── parser/
│   ├── ir/
│   ├── generator/
│   └── runtime/
├── include/
│   └── boe_codegen/
├── generated/
├── tests/
└── examples/
```

## Architecture

The project is organized into four main stages:

1. **Schema parser**  
   Reads a protocol definition file and validates its structure.

2. **Intermediate representation (IR)**  
   Converts the raw schema into a normalized in-memory model that is easier to generate code from.

3. **Code generator**  
   Produces C++ headers and source files for:
   - message objects
   - encoders
   - decoders
   - utility helpers

4. **Runtime support**  
   Provides small handwritten utilities such as status handling, endian conversion, bounds checking, and shared codec helpers.

## Example Workflow

1. Define a BOE-style protocol schema in YAML.
2. Parse the schema into an internal representation.
3. Generate C++ code for the selected protocol version.
4. Compile the generated files.
5. Run tests against sample payloads.
