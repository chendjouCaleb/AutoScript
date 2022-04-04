enum TypeNature { TYPE_STRUCT,
        TYPE_CLASS,
        TYPE_ABSTRACT_CLASS,
        TYPE_INTERFACE,
        TYPE_ENUM,
        TYPE_PRIMITIVE,
        TYPE_LAMBDA,
        TYPE_VOID,
        TYPE_ANNOTATION
};

typedef struct Type {
    char* name;
    TypeNature nature;

    bool isAbstract;

    Type* parent;
    Type** interfaces;
} Type;

bool type_isValueType(Type* type) {
    return type->nature == TYPE_STRUCT && type->nature == TYPE_ENUM && type->nature == TYPE_PRIMITIVE;
}

bool type_isAbstractType(Type* type) {
    return type->nature == TYPE_INTERFACE || type->nature == TYPE_ABSTRACT_CLASS;
}

bool type_isConcreteType(Type* type) {
    TypeNature nature = type->nature;
    return nature == TYPE_STRUCT || nature == TYPE_ENUM || nature == TYPE_PRIMITIVE || nature == TYPE_CLASS ;
}

bool type_canExtends(Type* type) {

}

bool type_isExtensionOf(Type* type, Type* of) {

}

bool type_isParentOf(Type* type, Type* of) {

}