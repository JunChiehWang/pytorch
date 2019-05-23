#pragma once

#include <torch/csrc/python_headers.h>

#include <c10/core/QScheme.h>

#include <string>

const int QSCHEME_NAME_LEN = 64;

struct THPQScheme {
  PyObject_HEAD
  at::QScheme qscheme;
  char name[QSCHEME_NAME_LEN + 1];
};

extern PyTypeObject THPQSchemeType;

inline bool THPQScheme_Check(PyObject *obj) {
  return Py_TYPE(obj) == &THPQSchemeType;
}

PyObject * THPQScheme_New(at::QScheme memory_format, const std::string& name);

void THPQScheme_init(PyObject *module);
