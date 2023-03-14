---
title: boost/multiprecision
documentation_of: //data-structure/boost-multiprecision.hpp
---

## 概要

`Bint` (`<boost/multiprecision/cpp_int.hpp>` `boost::multiprecision::cpp_int`)  
任意長整数型

`Real` (`<boost/multiprecision/cpp_dec_float.hpp>` `boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>`)  
仮数部が10進数で1024桁の浮動小数点数型

## 使い方

`x.str()` := `Bint` もしくは `Real` 型の変数 `x` を `string` 型に変換する  

`x.assign(string str) := `str` から `Bint` もしくは `Real` 型へと変換する

