cimport cython
import cython
from libcpp.vector cimport vector
from libcpp.string cimport string
from libc.stdint cimport *

cdef extern from "ctrereg.hpp" nogil :
    ctypedef struct result:
        int64_t position
        int64_t length
        string match
    vector[result] find_ip_addresses(size_t)

cpdef regex_find_ip_addresses(str s):
    cdef:
        const char* ptr_s = s
        size_t addr_s = <size_t>ptr_s
    return find_ip_addresses(addr_s)

