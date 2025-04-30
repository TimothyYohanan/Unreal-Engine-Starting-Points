#pragma once

template <typename T>
struct TIsNumeric
{
    enum { Value = false };
};

template <> struct TIsNumeric<int8>  { enum { Value = true }; };
template <> struct TIsNumeric<int16> { enum { Value = true }; };
template <> struct TIsNumeric<int32> { enum { Value = true }; };
template <> struct TIsNumeric<int64> { enum { Value = true }; };
template <> struct TIsNumeric<uint8>  { enum { Value = true }; };
template <> struct TIsNumeric<uint16> { enum { Value = true }; };
template <> struct TIsNumeric<uint32> { enum { Value = true }; };
template <> struct TIsNumeric<uint64> { enum { Value = true }; };
template <> struct TIsNumeric<float>       { enum { Value = true }; };
template <> struct TIsNumeric<double>      { enum { Value = true }; };
template <> struct TIsNumeric<long double> { enum { Value = true }; };

template <typename T> struct TIsNumeric<const          T> { enum { Value = TIsNumeric<T>::Value }; };
template <typename T> struct TIsNumeric<      volatile T> { enum { Value = TIsNumeric<T>::Value }; };
template <typename T> struct TIsNumeric<const volatile T> { enum { Value = TIsNumeric<T>::Value }; };
