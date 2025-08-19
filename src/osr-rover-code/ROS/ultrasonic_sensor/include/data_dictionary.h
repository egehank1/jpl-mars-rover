#ifndef HEADER_data_dictionary_h
#define HEADER_data_dictionary_h

/ Boolean type (avoid C++ keywords) /
typedef enum {
    GEN_FALSE = 0,
    GEN_TRUE = 1
} GEN_TYPE_boolean;

/ Primitive types /
typedef int GEN_TYPE_int;
typedef double GEN_TYPE_double;

/ Example enum /
typedef enum Enum_MyEnum {
    First_ID_672 = 0,
    Second_ID_673 = 1
} GEN_TYPE_MyEnum;

extern GEN_TYPE_MyEnum First();
extern GEN_TYPE_MyEnum Second();

extern char MyEnumToString(GEN_TYPE_MyEnum value);

/* Example struct */
typedef struct Struct_MyStruct {
    GEN_TYPE_int x;
    GEN_TYPE_int y;
} GEN_TYPE_MyStruct;

#endif
