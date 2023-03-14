#pragma once
#include "../template/template.hpp"

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using Bint = boost::multiprecision::cpp_int;
using Real = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>;